//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_EDGEUTILS_H
#define GCNAV_C_EDGEUTILS_H


#include "../graphstructs.h"

/*
 * Given a list of edge segments, return
 * the minimum available capacity value.
 *
 */
double minAvailable(seg *path);

/*
 * Free up the given linked list of segments
 */
void freePath(seg *path);


#endif //GCNAV_C_EDGEUTILS_H
