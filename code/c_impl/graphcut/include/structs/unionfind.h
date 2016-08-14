//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_UNIONFIND_H
#define GCNAV_C_UNIONFIND_H


#include <graphstructs.h>

#include <stdbool.h>
#include <stdlib.h>


/*
 * Determine root of tree for the given node
 */
size_t * find(size_t *n);


/*
 * Make v a child of u
 */
void join(size_t *par, size_t *child);

/*
 * Return a path between the given node and the root of the tree, inclusive.
 * If the given node is the root, return a NULL pointer.
 * Memory Mgt:  Producer of edge/seg structures via malloc.
 */
seg * pathToRoot(size_t *n);

/*
 * True if the nodes designated by *u and *v have the same root.
 */
bool sameTree(size_t *u, size_t *v);

/**
 * Return the list of nodes that do no have a label as a root.
 */
node * orphans();

/*
 * Is the node in the label array
 */
bool isLabel(size_t *n);

/*
 * Does the given node have a root that is a label
 */
bool isLabelled(size_t *n);

#endif //GCNAV_C_UNIONFIND_H
