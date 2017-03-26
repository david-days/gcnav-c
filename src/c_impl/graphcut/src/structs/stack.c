/*
 * stack.c
 *
 *  Created on: Oct 19, 2013
 *      Author: david
 */
#include <structs/stack.h>

/**
 * Push the given node onto the stack, returning a pointer to the new top of the stack.
 * Memory Management:  Producer of node structures
 */
node * stackPush(size_t n, node *stack) {
    node *top = (node *) malloc(sizeof(node));
    top->next = stack;
    top->node = n;
    return top;
}

/**
 * Peek a the top of the node without actually removing top item
 */
size_t stackPeek(node *stack) {
    return stack->node;
}

/**
 * Pop off the top of item of the stack
 */
node * stackPop(node *stack, size_t *n) {

    node *top = stack;
    *n = stack->node;
    stack = stack->next;
    //stack->prev = NULL;
    free(top);
    return stack;
}

/**
 * Determine if the stack has items remaining
 */
bool stackEmpty(node *stack) {
    return stack == NULL;
}


