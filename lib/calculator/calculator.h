#ifndef CALCULATOR
#define CALCULATOR

#include "structure.h"
#include "stack.h"
#include "vector.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int priority(char c);

float string_to_number(char *str);

void number_to_string(float num, char *str);

void compute(char *str1, char *str2, char *str3, char operate);

vector preprocess(char *str);

float process(vector expr);

float add(float num1, float num2);

float sub(float num1, float num2);

float mul(float num1, float num2);

float div(float num1, float num2);

#endif
