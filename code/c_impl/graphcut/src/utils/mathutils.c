
/**
 * mathutils.c
 *
 *  Created on: Oct 23, 2013
 *      Author: david
 */
#include <stddef.h>
#include <utils/mathutils.h>

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


/**
 * Return an array with the grid coordinates of the given position
 * @param pos position value within the graph structure
 * @param dimsize Number of dimensions in the coordinate system
 * @param dims array with the dimensions of the grid in question
 * @return NULL pointer if the dimensions are empty or the dimsize == 0; otherwise, an array of dimsize giving the cartesian coordinates of the pos value
 */
size_t * coordinates(size_t pos, size_t dimsize, size_t *dims) {
    size_t *cartarray = NULL;


/**
 * Return an array index-value for the given set of coordinates located within the defined cartesian field
 * @param coords array of coordinates
 * @param dimsize number of dimensions of interest for both coordinates and given dimensions
 * @param dim dimensions of the zero-based cartesian region of interest
 * @return equivalent index value of the array, based on the coordinates given.
 */
size_t coordinatesToIndex(size_t *coords, size_t dimsize, size_t *dims) {
    size_t idx = 0;
    size_t mult = 1;
    for (int i=0;i<dimsize;i++) {
        idx += mult*coords[i];
        mult *= dims[i];
    }
    return idx;
}
    
