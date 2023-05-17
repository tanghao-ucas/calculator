#ifndef CALCULATOR_STACK
#define CALCULATOR_STACK

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_LENGTH 100
#define MAX_SIZE 10
typedef struct Stack stack;
struct Stack{
    char data[MAX_LENGTH][MAX_SIZE];
    int top;
};

stack stack_init();

bool stack_empty(stack s);

bool stack_full(stack s);

bool stack_push(stack *s, char c[]);

bool stack_pop(stack *s, char c[]);

char* stack_top(stack *s);

#endif