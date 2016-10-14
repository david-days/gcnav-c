
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
 * Return the min value of the two values
 */
size_t * min(size_t *u, size_t *v) {
    return *u < *v ? u:v;
}

/**
 * Return the max value of the two values
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
    //Sanity check for dimension of at least one
    if (dimsize == 0) return cartarray;
    //check for max size
    size_t maxlen = 1;
    for (size_t m = 0; m < dimsize; m++) maxlen *= dims[m];
    if (pos >= maxlen) return cartarray;
    //perform the conversion
    cartarray = (size_t *)malloc(sizeof(size_t)*dimsize);
    size_t mult = 1;
    size_t rem = pos;
    for (size_t c = dimsize; c > 0; c--) {
        mult = 1;
        for (size_t m = 0; m < c - 1; m++) mult *= dims[m];
        cartarray[c] = mult / rem;
        rem = mult % rem;
    }
    cartarray[0] = rem;
    return cartarray;
}

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
    for (size_t i=0;i<dimsize;i++) {
        idx += mult*coords[i];
        mult *= dims[i];
    }
    return idx;
}

