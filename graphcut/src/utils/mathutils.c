
/**
 * mathutils.c
 *
 *  Created on: Oct 23, 2013
 *      Author: david
 */
#include <stddef.h>
#include "mathutils.h"

/**
 * Return the min value of the two given capacities
 */
double * minCapacity(double *capx, double *capy) {
    return *capx < *capy ? capx:capy;
}

/**
 * Return the max value of the two given capacities
 */
double * maxCapacity(double *capx, double *capy) {
    return *capx > *capy ? capx:capy;
}

/**
 * Return the min value of the two whole numbers
 */
size_t * min(size_t *u, size_t *v) {
    return *u < *v ? u:v;
}

/**
 * Return the max value of the two whole numbers
 */
size_t * max(size_t *u, size_t *v) {
    return *u > *v ? u:v;
}

