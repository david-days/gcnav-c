//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_GRAPHMGT_H
#define GCNAV_C_GRAPHMGT_H


#include "../graphstructs.h"

#include <stdlib.h>
/*
 * Initialize the necessary structures
 */
void initStructures(size_t numnodes, size_t numlabels);

/*
 * Create the given edge and insert it into the neighbors array
 */
void createAndInsert(const size_t *u, const size_t *v, const double *cap);

/*
 * Destroy the structures cleanly, cleaning up the memory
 */
void destroyGraph();

/**
 * Remove zero-capacity t-links from the graph in order to reduce processing time.
 * returns:  count of edges removed
 */
size_t pruneGraph();


#endif //GCNAV_C_GRAPHMGT_H
