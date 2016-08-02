/*
 * graph.c
 *
 *  Created on: Oct 11, 2013
 *      Author: david
 */

#include <dg/digraph.h>
#include <gmgt/graphmgt.h>


/**
 * Augment the given path fully (bi-directionally)
 */
void dg_augmentPath(seg *path, double *flow) {
    seg *curr;//pointer to current position
    curr = path;
    while (curr != NULL) {
        dg_addFlow(&curr->u,&curr->v, flow);
        dg_addFlow(&curr->v,&curr->u, flow);
        curr = curr->next;
    }
}



void dg_addEdge(const size_t *u, const size_t *v, const double *cap)
{
    createAndInsert(u,v,cap);
}

seg * dg_findEdge(const size_t *u, const size_t *v) {
    seg *uedge = neighbors[*u];
    while (uedge != NULL) {
        if (uedge->v == *v) {
            break;
        }
        uedge = uedge->next;
    }
    return uedge;
}

/**
 * Return a copy of the flow available for a particular edge.
 * returns:  available flow for the requested edge; otherwise, 0.00
 */
double dg_getCapacity(const size_t *u, const size_t *v) {
    seg *fedge;
    double cap;
    cap = 0.00;
    fedge = dg_findEdge(u,v);
    if (fedge != NULL) cap = fedge->capacity;
    return cap;
}


/**
 * Add the flow to the given edge.
 */
void dg_addFlow(const size_t *u, const size_t *v, const double *flow) {
    seg *fedge = dg_findEdge(u,v);
    if (fedge != NULL) {
        fedge->capacity = fedge->capacity - *flow;
    }
}

