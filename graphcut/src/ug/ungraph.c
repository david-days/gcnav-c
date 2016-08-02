
/**
 * ungraph.c
 *
 *  Created on: Nov 3, 2013
 *      Author: david
 */

#include <ug/ungraph.h>
#include <utils/mathutils.h>
#include <gmgt/graphmgt.h>


/**
 * With the given information, add a new edge
 * Returns false if there is a malloc problem; otherwise, true.
 * Memory Mgt:  Producer of edge structures for the neighbors array
 */
void ug_addEdge(size_t *u, size_t *v, double *cap) {
    size_t lu, lv; //local u, local v values
    lu = *min(u,v);
    lv = *max(u,v);
    createAndInsert(&lu,&lv,cap);
}

/**
 * Find the edge between the given nodes.  If no edge is found, return a NULL pointer
 */
seg * ug_findEdge(size_t *u, size_t *v) {
    size_t lu, lv; //local u, local v values
    lu = *min(u,v);
    lv = *max(u,v);
    seg *uedge = neighbors[lu];
    while (uedge != NULL) {
        if (uedge->v == lv) {
            break;
        }
        uedge = uedge->next;
    }
    return uedge;
}

/**
 * Add the flow to the given edge.
 */
void ug_addFlow(size_t *u, size_t *v, double *flow) {
    seg *fedge = ug_findEdge(u,v);
    if (fedge != NULL) {
        fedge->capacity = fedge->capacity - *flow;
    }
}

/**
 * Return a copy of the flow available for a particular edge.
 * returns:  available flow for the requested edge; otherwise, 0.00
 */
double ug_getCapacity(size_t *u, size_t *v) {
    size_t lu, lv; //local u, local v values
    lu = *min(u,v);
    lv = *max(u,v);
    seg *fedge;
    double cap;
    cap = 0.00;
    fedge = ug_findEdge(&lu,&lv);
    if (fedge != NULL) cap = fedge->capacity;
    return cap;

}

/**
 * Augment the given path with the given flow
 */
void ug_augmentPath(seg *path, double *flow) {
    seg *curr;//pointer to current position
    curr = path;
    while (curr != NULL) {
        ug_addFlow(&curr->u,&curr->v, flow);
        curr = curr->next;
    }
}