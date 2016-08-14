//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_GRAPHSTRUCTS_H
#define GCNAV_C_GRAPHSTRUCTS_H

#include <stdlib.h>


/*
 * Basic structure to hold edge and path data
 */
struct edge {
    struct edge *next;
    size_t u;
    size_t v;
    double capacity;
};

/*
 * Rename typedef for usage in paths and functions
 */
typedef struct edge seg;

/**
 * Item structure for stacks, queues, and lists
 */
struct nodeitem {
    struct nodeitem *next;
    size_t node;
};

typedef struct nodeitem node;

//dimensions of the graph
/**
 * Number of non-label nodes in the graph
 */
size_t nnodes;
/**
 * Number of labels for the graph
 */
size_t nlabels;


//graph states
/**
 * Array pointer for the labels
 */
size_t *labels;
/**
 * Adjacency list for nodes
 */
seg **neighbors;
/**
 * Parents array
 */
size_t *parents;


/**
 * Struct used to hold reference to graph definition and state
 */
struct arraygraph {
    size_t nnodes;
    size_t nlabels;
    size_t *labels;
    size_t **edges;
    double **capacities;
    size_t *parents;
};

typedef struct arraygraph agraph;

#endif //GCNAV_C_GRAPHSTRUCTS_H
