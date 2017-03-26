#include <graphcut.h>
#include <graphstructs.h>

//utility functions
#include <utils/edgeutils.h>
#include <utils/mathutils.h>

/**
 * Interrogate the graph cut solution to determine
 * the labeling for a given node
 *
 * parameter n:  zero-based index of the node to be checked
 * returns: label for the node in question
 */
size_t * label(size_t *n) {
	return find(n);
}


/**
 * Returns a linked-list of all n-link edges
 * wherein the ends have different labels
 * returns: a pointer to the first element of the linked
 * list or a null pointer.
 */
nedge * nborders() {
	nedge *blist; //return value
	nedge *curr; //placeholder for walking through list
	nedge *te; //new edge placeholder
	seg *cedge; //placeholder for neighbors list
	size_t n; //index for node list
	blist = NULL;
	curr = NULL;
	for (n=0;n<nnodes;n++) {
		cedge = neighbors[n];
		while (cedge != NULL) {
			if (!isLabel(&cedge->v)) {
				if (!sameTree(&cedge->u, &cedge->v)) {
					te = (nedge *) malloc(sizeof(nedge));
					te->u = cedge->u;
					te->v = cedge->v;
					te->next = NULL;
					if (blist == NULL) blist = te;
					if (curr != NULL) {
						curr->next = te;
					}
					curr = te;
				}
			}
		}
	}
	return blist;
}


/**
 * Returns a linked-list of _all_ edges
 * wherein the ends have different labels
 * returns: a pointer to the first element of the linked
 * list or a null pointer.
 */
nedge * borders() {
	nedge *blist; //return value
	nedge *curr; //placeholder for walking through list
	nedge *te; //new edge placeholder
	seg *cedge; //placeholder for neighbors list
	size_t n; //index for node list
	blist = NULL;
	curr = NULL;
	for (n=0;n<nnodes;n++) {
		cedge = neighbors[n];
		while (cedge != NULL) {
			if (!sameTree(&cedge->u, &cedge->v)) {
				te = (nedge *) malloc(sizeof(nedge));
				te->u = cedge->u;
				te->v = cedge->v;
				te->next = NULL;
				if (blist == NULL) blist = te;
				if (curr != NULL) {
					curr->next = te;
				}
				curr = te;
			}
		}
	}
	return blist;
}


