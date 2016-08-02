//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_DIGRAPH_H
#define GCNAV_C_DIGRAPH_H


#include <graphstructs.h>
//#include <structs/unionfind.h>

#include <stdlib.h>
#include <stdbool.h>


/**
 * With the given informatioin, add a new edge
 * Returns false if there is a malloc problem; otherwise, true.
 * Memory Mgt:  Producer of edge structures for the neighbors array
 */
void dg_addEdge(size_t *u, size_t *v, double *cap);

/**
 * Find the edge between the given nodes.  If no edge is found, return a NULL pointer
 */
seg * dg_findEdge(size_t *u, size_t *v);

/**
 * Add the flow to the given edge.
 */
void dg_addFlow(size_t *u, size_t *v, double *flow);

/**
 * Return a copy of the flow available for a particular edge.
 * returns:  available flow for the requested edge; otherwise, 0.00
 */
double dg_getCapacity(size_t *u, size_t *v);

/**
 * Augment the given path fully (bi-directionally)
 */
void dg_augmentPath(seg *path, double *flow);


#endif //GCNAV_C_DIGRAPH_H
