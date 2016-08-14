/*
 * graphcut.c
 *
 *  Created on: Oct 21, 2013
 *      Author: david
 */

#include <graphcut.h>
#include <graphstructs.h>

//structures to run algorithm
#include <structs/queue.h>
#include <structs/stack.h>
#include <structs/unionfind.h>

//utility functions
#include <utils/edgeutils.h>
#include <utils/mathutils.h>
#include <gmgt/graphmgt.h>



//Internal data structures
/**
 * Navigation graph structure
 */
agraph *navgraph;


/**
 * Create an arraygraph structure for 2D navigation with the given parameters
 * @param xdim Width/Breadths of the graph
 * @param ydim Height/Depth of the graph
 * @return Pointer to the navgraph structure
 */
agraph *init2dNavGraph(size_t xdim, size_t ydim){
    navgraph = malloc(sizeof(agraph));
    if (navgraph == NULL) exit(1);
    size_t *dimarr = malloc(sizeof(size_t)*2);
    if (dimarr == NULL) exit(1);
    dimarr[0] = xdim;
    dimarr[1] = ydim;
    //Total number of nodes is width*height + 2 label nodes
    size_t numnodes = xdim*ydim;

    //Fill the navgraph structure with basic dimensional data
    navgraph->numdimensions = 2;
    navgraph->dimensions = dimarr;
    navgraph->ntype = TWO_DIMENSIONAL;
    navgraph->nnodes = numnodes;

    //Create and fill the labels array
    size_t *labarr = malloc(sizeof(size_t)*2);
    if (labarr == NULL) exit(1);
    labarr[0] = numnodes;
    labarr[1] = numnodes+1;
    navgraph->nlabels = 2;
    navgraph->labels = labarr;

   initNavGraph(navgraph);

    return navgraph;
}

/**
 * Returns a linked-list of _all_ edges
 * wherein the ends have different labels
 * returns: a pointer to the first element of the linked
 * list or a null pointer.
 */
nedge * borders() {
	nedge *blist; //return value
	nedge *curr; //placeholder for walking through list
	nedge *te; //new edge placeholder
	seg *cedge; //placeholder for neighbors list
	size_t n; //index for node list
	blist = NULL;
	curr = NULL;
	for (n=0;n<nnodes;n++) {
		cedge = neighbors[n];
		while (cedge != NULL) {
			if (!sameTree(&cedge->u, &cedge->v)) {
				te = (nedge *) malloc(sizeof(nedge));
				te->u = cedge->u;
				te->v = cedge->v;
				te->next = NULL;
				if (blist == NULL) blist = te;
				if (curr != NULL) {
					curr->next = te;
				}
				curr = te;
			}
		}
	}
	return blist;
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


/**
 * Add the given edge to the graph structure.
 *
 * Node identifiers are zero-based index values.
 *
 * parameter u: node at one end of the edge for the graph
 * parameter v: node at the opposing end of the edge
 * parameter capacity: initial capacity for the graph.
 */
void insertEdge(size_t *u, size_t *v, double *capacity) {
	gt_add_edge (u,v,capacity);
}

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
 * Interrogate the graph cut solution to determine
 * the labeling for a given node
 *
 * parameter n:  zero-based index of the node to be checked
 * returns: label for the node in question
 */
size_t * label(size_t *n) {
	return find(n);
}


/**
 * Returns a linked-list of all n-link edges
 * wherein the ends have different labels
 * returns: a pointer to the first element of the linked
 * list or a null pointer.
 */
nedge * nborders() {
	nedge *blist; //return value
	nedge *curr; //placeholder for walking through list
	nedge *te; //new edge placeholder
	seg *cedge; //placeholder for neighbors list
	size_t n; //index for node list
	blist = NULL;
	curr = NULL;
	for (n=0;n<nnodes;n++) {
		cedge = neighbors[n];
		while (cedge != NULL) {
			if (!isLabel(&cedge->v)) {
				if (!sameTree(&cedge->u, &cedge->v)) {
					te = (nedge *) malloc(sizeof(nedge));
					te->u = cedge->u;
					te->v = cedge->v;
					te->next = NULL;
					if (blist == NULL) blist = te;
					if (curr != NULL) {
						curr->next = te;
					}
					curr = te;
				}
			}
		}
	}
	return blist;
}

/**
 * Add flow to a particular edge
 */
void addCapacity(size_t *u, size_t *v, double *capval) {

}

/**
 * Closes out the graph structure and frees up
 * all associated memory
 */
void closeGraph() {
	destroyGraph(navgraph);
}