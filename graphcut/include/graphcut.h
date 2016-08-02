//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_BORDERCUT_H
#define GCNAV_C_BORDERCUT_H


#include <graphstructs.h>


#include <stdlib.h>

enum GRAPHTYPE {
    UNDIRECTED=1,
    DIRECTED=2
};


struct nodepair {
    size_t u;
    size_t v;
    struct nodepair *next;
};

typedef struct nodepair nedge;

/**
 * Pointer to label array created after initializing the graph.
 * This array is the same size as the labels value passed to the initialize function
 * and contains the label designations created in the intialization.
 */
extern size_t *labels;

/**
 * Initialize the graph, using the size values that are given.
 *
 * The nodes will be represented by a zero-based array of length nodes.
 *
 * parameter nodes:  # of non-label nodes in the graph
 * parameter labels: # number of label values for this graph
 */
extern void initGraph(size_t nodes, size_t labels, enum GRAPHTYPE gt);

/**
 * Add the given edge to the graph structure.
 *
 * Node identifiers are zero-based index values.
 *
 * parameter u: pointer to node at one end of the edge for the graph
 * parameter v: pointer to node at the opposing end of the edge
 * parameter capacity: pointer to initial capacity for the graph.
 */
extern void insertEdge(size_t *u, size_t *v, double *capacity);

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

/**
 * Closes out the graph structure and frees up
 * all associated memory
 */
extern void closeGraph();

#endif //GCNAV_C_BORDERCUT_H
