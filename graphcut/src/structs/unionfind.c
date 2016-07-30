/*
 * unionfind.c
 *
 *  Created on: Oct 11, 2013
 *      Author: david
 */

#include "unionfind.h"

/**
 * The UnionFind operations handle all operations relating to the
 * tree structure.
 */

/*
 * Parents array to be manipulated
 */
extern size_t *parents;

/*
 * Labels array
 */
extern size_t *labels;

/*
 * Size of labels array
 */
extern size_t nlabels;

/*
 * Number of nodes
 */
extern size_t nnodes;

/**
 * Find the root parent for a particular node.
 */
size_t * find(size_t *n)
{

    if (parents[*n] == *n)
    {
        return n;
    }
    else
    {
        return find(&parents[*n]);
    }
}

/**
 * Set the parent for a particular node.  So named because union is a keyword in C.
 */
void join(size_t *par, size_t *child)
{
    parents[*child] = *par;
}

/**
 * Returns a path to root, or a null pointer if there is no path.
 * Return value is a pointer to the first segment in the page.
 */
seg * pathToRoot(size_t *n)
{
    seg *path;
    if (parents[*n] == *n) {
        //There is no path--return a null pointer
        path = NULL;
    } else {
        //create the first link
        path = (seg*) malloc(sizeof(seg));
        path->u = *n;
        path->v = parents[*n];
        path->capacity = -1.0;
        seg *npath;
        npath = pathToRoot(&path->v);
        path->next = npath;
    }
    return path;
}

/**
 * Determines if two given nodes are in the same tree.
 * True if both have the same root; otherwise, false.
 */
bool sameTree(size_t *u, size_t *v) {
    return *find(u) == *find(v);
}

bool isLabel(size_t *node) {
    bool rval = false;
    for (int i=0;i<nlabels;i++) {
        if (*(labels+i)==*node) {
            rval = true;
            break;
        }
    }
    return rval;
}

/**
 * Scan the parents array and, using the labels array,
 * create a list of nodes that are not in the label tree.
 * Otherwise, return a null pointer.
 */
node * orphans() {
    node *orphanlist = NULL;
    node *curr,*next;
    size_t *r; //found root
    size_t n; //node in question
    for (n=0;n<nnodes;n++) {
        r = find(&n);
        if (!isLabel(r)) {
            next = (node *) malloc(sizeof(node));
            next->next = NULL;
            next->node = n;
            if (orphanlist == NULL) {
                //first in the list
                orphanlist = next;
                curr = orphanlist;
            } else {
                curr->next = next;
                curr = next;
            }
        }
    }
    return orphanlist;
}

/*
 * Does the given node have a root that is a label
 */
bool isLabelled(size_t *n) {
    size_t *r;
    r = find(n);
    return isLabel(r);
}
