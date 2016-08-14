/*
 * edgeutils.c
 *
 *  Created on: Oct 23, 2013
 *      Author: david
 */

#include <utils/edgeutils.h>

#include <utils/mathutils.h>


#include <math.h>
#include <stdlib.h>

/**
 * Return the min available value along a path represented by *path
 * @param path Linked-list of segments representing a path between two nodes
 * @return Double value of the minimum available along the path
 */
double minAvailable(seg *path) {
    double mincap = 0.00;
    if (path != NULL) {
        mincap = INFINITY;
        seg *cseg; //current segment
        cseg = path;
        while (cseg != NULL) {
            mincap = *minCapacity(&mincap, &cseg->capacity);
            cseg = cseg->next;
        }
    }
    return mincap;
}

/**
 * Free up the memory held by the elements of the linked-list path representation
 * @param path Linked-list representation of path between two nodes
 */
void freePath(seg *path) {
    seg *curr;
    seg *next;
    curr = path;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
}
