#include <graphcut.h>
#include <graphstructs.h>
#include <gmgt/graphmgt.h>

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
 * Closes out the graph structure and frees up
 * all associated memory
 */
void closeGraph() {
	destroyGraph(navgraph);
}
