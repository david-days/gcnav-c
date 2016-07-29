//
// Created by david on 7/29/16.
//

#ifndef GCNAV_C_STACK_H
#define GCNAV_C_STACK_H


#include "../graphstructs.h"

#include <stdlib.h>
#include <stdbool.h>

/**
 * Push the given node onto the stack, returning a pointer to the new top of the stack
 */
node * stackPush(size_t n, node *stack);

/**
 * Peek a the top of the node without actually removing top item
 */
size_t stackPeek(node *stack);

/**
 * Pop off the top of item of the stack
 */
node * stackPop(node *stack, size_t *n);

/**
 * Determine if the stack has items remaining
 */
bool stackEmpty(node *stack);

#endif //GCNAV_C_STACK_H
