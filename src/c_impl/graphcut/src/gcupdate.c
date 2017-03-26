#include <graphcut.h>
#include <graphstructs.h>
#include <gmgt/graphmgt.h>

//utility functions
#include <utils/edgeutils.h>
#include <utils/mathutils.h>

/**
 * Add flow to a particular edge
 */
void addCapacity(size_t *u, size_t *v, double *capval) {

}


/**
 * Add the given edge to the graph structure.
 *
 * Node identifiers are zero-based index values.
 *
 * parameter u: node at one end of the edge for the graph
 * parameter v: node at the opposing end of the edge
 * parameter capacity: initial capacity for the graph.
 */
void insertEdge(size_t *u, size_t *v, double *capacity) {
	gt_add_edge (u,v,capacity);
}

