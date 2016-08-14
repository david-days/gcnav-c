//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_GRAPHMGT_H
#define GCNAV_C_GRAPHMGT_H


#include <graphstructs.h>

#include <stdlib.h>


/**
 * Fill in the data structures for the navigation graph
 * @param navgraph Pointer to navigation graph structure to be initialized
 */
void initNavGraph(agraph *navgraph);


/**
 * Reset the graph values (edge cacities) to zero
 * @param navgraph Graph structure to be reset
 */
void resetGraph(agraph *navgraph);


/**
 * Destroy the graph structure, cleaning up all memory usage and setting all references to null
 * @param navgraph Graph structure whose memory should be freed
 */
void destroyGraph(agraph *navgraph);

/**
 * Add the given value (
 * @param u Pointer to edge beginning identifier
 * @param v  Pointer to edge ending identifire
 * @param capval Capacity value to be added
 * @param navgraph  Graph structure to be manipulated
 */
void addCapacity(size_t *u, size_t *v, double *capval, agraph *navgraph);


#endif //GCNAV_C_GRAPHMGT_H
