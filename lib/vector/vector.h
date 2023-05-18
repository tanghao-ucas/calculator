#ifndef CALCULATOR_VECTOR
#define CALCULATOR_VECTOR

#include "structure.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

vector vector_init();

int vector_length(vector v);
bool vector_full(vector v);
bool vector_empty(vector v);

bool vector_backin(vector *v, char *c);
bool vector_backout(vector *v, char *c);

bool vector_insert(vector *v, int pos, char *c);



#endif