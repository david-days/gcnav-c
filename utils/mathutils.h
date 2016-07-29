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

#endif //GCNAV_C_MATHUTILS_H
