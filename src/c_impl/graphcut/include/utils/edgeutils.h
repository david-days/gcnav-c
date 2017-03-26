//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_EDGEUTILS_H
#define GCNAV_C_EDGEUTILS_H


#include <graphstructs.h>

/**
 * Return the min available value along a path represented by *path
 * @param path Linked-list of segments representing a path between two nodes
 * @return Double value of the minimum available along the path
 */
double minAvailable(seg *path);



/**
 * Free up the memory held by the elements of the linked-list path representation
 * @param path Linked-list representation of path between two nodes
 */
void freePath(seg *path);



#endif //GCNAV_C_EDGEUTILS_H
