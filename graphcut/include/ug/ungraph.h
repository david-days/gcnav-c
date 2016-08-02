//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_UNGRAPH_H
#define GCNAV_C_UNGRAPH_H


#include "../graphstructs.h"
#include "../structs/unionfind.h"

#include <stdlib.h>
#include <stdbool.h>


/*
 * With the given informatioin, add a new edge
 * Returns false if there is a malloc problem; otherwise, true.
 * Memory Mgt:  Producer of edge structures for the neighbors array
 */
void ug_addEdge(const size_t *u, const size_t *v, const double *cap);

/**
 * Find the edge between the given nodes.  If no edge is found, return a NULL pointer
 */
seg * ug_findEdge(const size_t *u, const size_t *v);

/**
 * Add the flow to the given edge.
 */
void ug_addFlow(const size_t *u, const size_t *v, const double *flow);

/*
 * Return a copy of the flow available for a particular edge.
 * returns:  available flow for the requested edge; otherwise, 0.00
 */
double ug_getCapacity(const size_t *u, const size_t *v);

/*
 * Augment the given path with the given flow
 */
void ug_augmentPath(seg *path, double *flow);


#endif //GCNAV_C_UNGRAPH_H
