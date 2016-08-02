/*
 * graphmgt.c
 *
 *  Created on: Nov 3, 2013
 *      Author: david
 */

#include <gmgt/graphmgt.h>
#include <structs/unionfind.h>

//dimensions of the graph
/**
 * Number of non-label nodes in the graph
 */
extern size_t nnodes;
/**
 * Number of labels for the graph
 */
extern size_t nlabels;


//graph states
/**
 * Array pointer for the labels
 */
extern size_t *labels;
/**
 * Adjacency list for nodes
 */
extern seg **neighbors;
/**
 * Parents array
 */
extern size_t *parents;


/*
 * Initializes parents array to nnodes+nlabels length
 * and sets each position to itself as root.
 */
static void initParents()
{
    size_t psize = nnodes+nlabels;
    parents = malloc(psize*sizeof(size_t));
    if (parents == NULL) exit(1);
    for (int i=0;i<psize;i++) parents[i] = i;
}

/*
 * Initializes the neighbors array, based upon previously given parameters.
 */
static void initNeighbors()
{
    size_t nbrsize = nnodes+nlabels; //array size for primary neighbor array


    //principal neighbors array
    neighbors = malloc((nbrsize)* sizeof(size_t));
    if (neighbors == NULL)
    {
        //original  call failed
        exit(1);
    }
    for (int i=0;i<nbrsize;i++)
    {
        neighbors[i] = NULL;
    }
}

/*
 * Initializes the labels array
 */
static void initLabels()
{
    labels = malloc(nlabels * sizeof(size_t));
    if (labels == NULL)
    {
        //allocation failure
        exit(1);
    }
    //set label positions
    for (size_t i=0;i<nlabels;i++) labels[i] = nnodes+i;
}

/*
 * Initialize the necessary structures
 */
void initStructures(size_t numnodes, size_t numlabels)
{
    nnodes = numnodes;
    nlabels = numlabels;
    initNeighbors();
    initLabels();
    initParents();
}

/*
 * Create the given edge and insert it into the neighbors array
 */
void createAndInsert(const size_t *u, const size_t *v, const double *cap) {
    //allocate memory
    seg *nseg;
    nseg = malloc(sizeof(seg));
    if (nseg == NULL) exit(1);
    nseg->u = *u;
    nseg->v = *v;
    nseg->capacity = *cap;
    nseg->next = NULL;

    seg *list;
    list = neighbors[nseg->u];
    if (list == NULL)
    {
        //No other in list--set as first
        neighbors[nseg->u] = nseg;
    }
    else
    {
        //not the first--walk to the end of the list
        seg *par;
        par = list;
        while (par->next != NULL)
        {
            par = par->next;
        }
        //Attach this one to the end
        par->next = nseg;
    }

}


static void destroyParents() {
    free(parents);
    parents = NULL;
}

static void destroyLabels() {
    free(labels);
    labels = NULL;
}

static void destroyNeighbors() {
    //start by walking through the edges
    size_t nsize = nnodes+nlabels;
    size_t i; //index
    seg *curredge; //current working edge
    seg *fedge; //edge to be freed
    for (i=0;i<nsize;i++) {
        curredge = neighbors[i];
        while (curredge != NULL) {
            fedge = curredge;
            curredge = curredge->next;
            free(fedge);
        }
    }
    //now free the array
    free(neighbors);
    neighbors = NULL;
}
/*
 * Destroy the structures cleanly, clearing up the memory
 */
void destroyGraph() {
    destroyParents();
    destroyLabels();
    destroyNeighbors();
}

/**
 * Remove zero-capacity t-links from the graph in order to reduce processing time.
 */
size_t pruneGraph() {
    size_t rcount = 0;
    size_t n; //node index
    size_t nsize = nnodes+nlabels; //full size of the neighbors array
    seg *hedge; //head of edge list
    seg *cedge = NULL; //current edge
    seg *pedge = NULL; //previous edge
    //Walk through adjacency lists
    for (n = 0;n<nsize;n++) {
        pedge = NULL;
        hedge = neighbors[n];
        cedge = hedge;
        while (cedge != NULL) {
            if (cedge->capacity <= 0.00 && (isLabel(&cedge->u) || isLabel(&cedge->v))) {
                //remove the current edge
                seg *redge = cedge;
                cedge = cedge->next;
                if (pedge == NULL) {
                    //we're still at the head of the list
                    //move the pointer to the next edge
                    hedge = cedge;
                }
                //free memory
                free(redge);
                rcount++;
            } else {
                pedge = cedge;
                cedge = cedge->next;
            }
        }
        //set the head of the adjacency list
        neighbors[n] = hedge;
    }
    return rcount;
}
