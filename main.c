#include <stdio.h>
#include "calculator.h"
#include "stack.h"
#include "vector.h"

void input(char *expr, char *translate[])
{
    printf("Input the expression:\n");
    scanf("%s", expr);
    preprocess(expr, translate);
}

int main(int argc, char* argv[])
{   
    char expr[MAX_LENGTH];
    char translate[MAX_LENGTH][MAX_SIZE];
    vector v = vector_init();
    
    input(expr, translate);

    return 0;
}
