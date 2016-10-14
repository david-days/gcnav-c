#include <graphcut.h>
#include <graphstructs.h>

//structures to run algorithm
#include <structs/queue.h>
#include <structs/stack.h>
#include <structs/unionfind.h>

//utility functions
#include <utils/edgeutils.h>
#include <utils/mathutils.h>

/**
 * Find the max-flow/min-cut solution to the graph
 *
 * returns:  max-flow value for the solution.
 */
double solve() {
	double rval; //total return value
	double stepval; //value for this step
	rval = 0.0;
	stepval = 1.0; //initialize to start the loop
	while (stepval > 0) {
		breakTrees();
		buildTrees();
		stepval = borderProcess();
		rval += stepval;
	}
	return rval;
}


/**
 * Performs a single step of the solution process
 *
 * returns: max-flow value from the single step performed.
 */
double step() {
	breakTrees();
	buildTrees();
	return borderProcess();
}


/**
 * process a border edge
 */
static double processBorder(nedge *border) {
	seg *upath; //path from u to root
	seg *bpath; //edge across the border
	seg *vpath; //path from v to root
	double umin; //min capacity for upath
	double vmin; //min capacity for vpath
	double bmin; //capacity across order
	double min;

	//find the appropriate parts and values
	upath = pathToRoot(&border->u);
	vpath = pathToRoot(&border->v);
	bpath = gt_find_edge (&border->u,&border->v);
	umin = minAvailable(upath);
	vmin = minAvailable(vpath);
	bmin = minAvailable(bpath);

	//Figure out the min flow
	min = *(minCapacity(&umin,&vmin));
	min = *(minCapacity(&min,&bmin));
	if (min > 0) {
		gt_augment_path (upath, &min);
		gt_augment_path (vpath, &min);
		gt_augment_path (bpath,&min);
	}
	//"consume" the created edges so that they are not hogging the memory
	freePath(upath);
	freePath(vpath);
	return min;
}

/**
 * Find border edges and process them accordingly
 */
static double borderProcess() {
	nedge *b; //pointer to border listing
	nedge *curr; //border being currently processed
	nedge *tmp; //holder for free
	double accum; //accumulator for processed edges
	accum = 0.0;
	b = borders();
	curr = b;
	while (curr != NULL) {
		tmp = curr;
		accum += processBorder(curr);
		curr = tmp->next;
		free(tmp);
	}
	return accum;
}

static void buildTrees() {
	node *nqueue; //queue of orphans
	size_t cu; //current u
	size_t cv; //current v
	seg *cedge; //current edge
	//setup queue and push the labels
	nqueue = NULL;
	size_t nlength = nnodes+nlabels;
	for (cu = nnodes;cu < nlength;cu++) {
		nqueue = queuePush(cu,nqueue);
	}
	while (!queueEmpty(nqueue)) {
		nqueue = queuePop(nqueue, &cu);
		cedge = neighbors[cu];
		while (cedge != NULL) {
			cv = cedge->v;
			if (cedge->capacity > 0.00) {
				if (!isLabelled(&cv)) {
					//orphan--claim and add to queue
					join(&cu,&cv);
				}
			}
			if (parents[cv] == cu) nqueue = queuePush(cv,nqueue);
			cedge = cedge->next;
		}
	}
}

/**
 * Walk through the tree structure.  If any link between
 * a child and its parent has zero capacity left, "break"
 * the link by setting the child to it's own parent
 */
static void breakTrees() {
	size_t n; //array indexer
	size_t c; //child node
	size_t p; //parent node
	size_t b; //child to break;
	seg *plink;
	for (n=0;n<nnodes;n++) {
		c = n;
		while (parents[c] != c) {
			p = parents[c];
			plink = gt_find_edge (&c,&p);
			c = p;
			if (plink->capacity <= 0.0) {
				b = c;
				parents[b] = b;
			}
		}
	}
}


