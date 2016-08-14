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
 */
struct arraygraph {
    enum NAVTYPE ntype;
    double azimuth;
    size_t numdimensions;
    size_t *dimensions;
    size_t nnodes;
    size_t nlabels;
    size_t *labels;
    size_t **edges;
    double **capacities;
    size_t *parents;
};


typedef struct arraygraph agraph;


#endif //GCNAV_C_GRAPHSTRUCTS_H
