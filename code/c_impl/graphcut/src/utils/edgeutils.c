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

/*
 * Given a list of edge segments, return
 * the minimum available capacity value.
 *
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

/*
 * Free up the given linked list of segments
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
