//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_GRAPHSTRUCTS_H
#define GCNAV_C_GRAPHSTRUCTS_H

#include <stdlib.h>


/**
 * Graph type designation
 */
enum GRAPHTYPE {
    UNDIRECTED=1,
    DIRECTED=2,
    ARRAYGRAPH=3
};

/**
 * Navigation Problem Type
 */
enum NAVTYPE {
    TWO_DIMENSIONAL = 1,
    THREE_DIMENSIONAL = 2,
    FOUR_DIMENSIONAL = 4
};

/*
 * Basic structure to hold edge and path data
 * Linked-list structure to pass around references to edges
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

//graph states

/**
 * Struct used to hold reference to graph definition and state
 * TODO:  Initially set up for 2D cartesian graph coordinates.  Need to change to n-dimensional in next iteration or so.
 */
struct arraygraph {
    size_t numdimensions; //Number of dimensions in graph structure
    size_t *dimensions; //sizes of the array in whole unites
    size_t nnodes;  //number of in-graph vertices
    size_t nlabels; //number of label nodes
    size_t *labels; //array of label entries
    size_t **edges; //edge adjacency arrays
    double **capacities; //capacity adjacency arrays
    size_t *parents; //tree tracking array
};


typedef struct arraygraph agraph;


#endif //GCNAV_C_GRAPHSTRUCTS_H
