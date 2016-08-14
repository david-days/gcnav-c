//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_QUEUE_H
#define GCNAV_C_QUEUE_H


#include <graphstructs.h>

#include <stdlib.h>
#include <stdbool.h>

/**
 * Push a value onto the queue
 */
node * queuePush(size_t n, node *queue);

/*
 * Retrieve, without removing, the next item on the queue
 */
size_t queuePeek(node *queue);

/*
 * Determine if there are items in the queue
 */
bool queueEmpty(node *queue);

/**
 * Remove and retrieve the next value in the queue
 */
node * queuePop(node *queue, size_t *n);

#endif //GCNAV_C_QUEUE_H
