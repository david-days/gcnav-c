//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_BORDERCUT_H
#define GCNAV_C_BORDERCUT_H


#include <graphstructs.h>


#include <stdlib.h>


struct nodepair {
    size_t u;
    size_t v;
    struct nodepair *next;
};

typedef struct nodepair nedge;


// defined in src/gcprocess.c

/**
 * Find the max-flow/min-cut solution to the graph
 *
 * returns:  max-flow value for the solution.
 */
extern double solve();

/**
 * Performs a single step of the solution process
 * Primarily used for analysis and use of intermediate steps
 *
 * returns: max-flow value from the single step performed.
 */
extern double step();

// defined in src/gccheck.c

/**
 * Interrogate the graph cut solution to determine
 * the labeling for a given node
 *
 * parameter n:  zero-based index of the node to be checked
 * returns: label for the node in question
 */
extern size_t * label(size_t *n);

/**
 * Returns a linked-list of all n-link edges
 * wherein the ends have different labels
 * returns: a pointer to the first element of the linked
 * list or a null pointer.
 */
extern nedge * nborders();

// defined in gcupdate.c

/**
 * Add flow to a particular edge
 */
extern void addCapacity(size_t *u, size_t *v, double *capval);

// defined in src/gcinit.c

/**
 * Pointer to a navigation graph structure
 */
extern agraph *navgraph;

/**
 * Initialize
 * @param numnodes
 * @param numlabels
 * @return Pointer to the initialized arraygraph structure
 */
extern agraph *init2dNavGraph(size_t xdim, size_t ydim);


/**
 * Closes out the graph structure and frees up
 * all associated memory
 */
extern void closeGraph();


#endif //GCNAV_C_BORDERCUT_H
