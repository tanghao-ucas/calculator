#ifndef CALCULATOR_STACK
#define CALCULATOR_STACK

#include "structure.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

stack stack_init();

bool stack_empty(stack s);

bool stack_full(stack s);

bool stack_push(stack *s, char *c);

bool stack_pop(stack *s, char *c);

char* stack_top(stack *s);

#endif