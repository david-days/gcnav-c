/*
 * queue.c
 *
 *  Created on: Oct 20, 2013
 *      Author: david
 */


#include <structs/queue.h>


node * queuePush(size_t n, node *queue) {
    node *tail = (node *) malloc(sizeof(node));
    tail->next = NULL;
    tail->node = n;
    if (queue == NULL) {
        queue = tail;
    } else {
        node *end;
        end = queue;
        while (end->next != NULL) end = end->next;
        end->next = tail;
    }
    return queue;
}

size_t queuePeek(node *queue) {
    return queue->node;
}

bool queueEmpty(node *queue) {
    return queue == NULL;
}

node * queuePop(node *queue, size_t *n) {
    node *tmp = queue;
    *n = queue->node;
    queue = queue->next;
    free(tmp);
    return queue;
}
