//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_MATHUTILS_H
#define GCNAV_C_MATHUTILS_H



#include <stdlib.h>

/**
 * Return the min value of the two given capacities
 */
double * minCapacity(double *capx, double *capy);

/**
 * Return the max value of the two given capacities
 */
double * maxCapacity(double *capx, double *capy);

/**
 * Return the min value of the two whole numbers
 */
size_t * min(size_t *u, size_t *v);

/**
 * Return the max value of the two whole numbers
 */
size_t * max(size_t *u, size_t *v);

/**
 * Return an array with the grid coordinates of the given position
 * TODO:  Implemented for 2D cartesian grid; need to convert for arbitray dimensional array.
 * @param pos position value within the graph structure
 * @param dimsize Number of dimensions in the coordinate system
 * @param dims array with the dimensions of the grid in question
 * @return NULL pointer if the value is not within the grid structure; otherwise, an array of dimsize giving the cartesian coordinates of the pos value
 */
size_t * coordinates(size_t pos, size_t dimsize, size_t *dims);

#endif //GCNAV_C_MATHUTILS_H
