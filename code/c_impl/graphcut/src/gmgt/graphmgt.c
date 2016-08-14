/*
 * graphmgt.c
 *
 *  Created on: Nov 3, 2013
 *      Author: david
 */

#include <gmgt/graphmgt.h>
#include <graphstructs.h>
#include <structs/unionfind.h>

/**
 * Initialize the parents array
 * @param navgraph Graph structure to be initialized
 */
static void initParents(agraph *navgraph)
{
    size_t psize = navgraph->nnodes + navgraph->nlabels;
    size_t *parents = malloc(psize*sizeof(size_t));
    if (parents == NULL) exit(1);
    for (int i=0;i<psize;i++) parents[i] = i;
    navgraph->parents = parents;
}



/**
 * Clear out the parents array
 * @param navgraph Graph structure whose parents are to be cleared
 */
static void destroyParents(agraph *navgraph) {
    free(navgraph->parents);
    navgraph->parents = NULL;
}

/**
 * Clear out the labels array
 * @param navgraph Graph structure whose labels are to be cleared
 */
static void destroyLabels(agraph *navgraph) {
    free(navgraph->labels);
    navgraph->labels = NULL;
}

/**
 * Clear out the edges and capacities array
 * @param navgraph
 */
static void destroyEdges(agraph *navgraph) {
    //start by walking through the edges
    size_t nsize = navgraph->nnodes+navgraph->nlabels;
    size_t i; //index
    double *caparr;
    size_t *earr;
    for (i=0;i<nsize;i++) {
        earr = navgraph->edges[i];
        caparr = navgraph->capacities[i];
        free(earr);
        free(caparr);
    }
    //now free the array
    free(navgraph->edges);
    free(navgraph->capacities);
    navgraph->edges = NULL;
    navgraph->capacities = NULL;
}


/**
 * Initialize navigation graph
 * @param navgraph structure to be filled in
 */
void initNavGraph(agraph *navgraph) {
    initParents(navgraph);
}

/**
 * Reset the graph values (edge capacities) to zero
 * @param navgraph Graph structure to be reset
 */
void resetGraph(agraph *navgraph) {

}


/**
 * Clear out the graph structure and free up all associated memory
 * @param navgraph Graph structure and pointers to be cleared out cleanly.
 */
void destroyGraph(agraph *navgraph) {
    destroyParents(navgraph);
    destroyEdges(navgraph);
    destroyLabels(navgraph);
    free(navgraph);
    navgraph = NULL;
}


