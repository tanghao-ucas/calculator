#ifndef CALCULATOR
#define CALCULATOR

#include "stack.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int priority(char c);

void preprocess(char expr[MAX_LENGTH], char translate[MAX_LENGTH][MAX_SIZE]);

float add(float num1, float num2);

float sub(float num1, float num2);

float mul(float num1, float num2);

float div(float num1, float num2);

#endif
