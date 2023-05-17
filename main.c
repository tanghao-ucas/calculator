#include <stdio.h>
#include "calculator.h"
#include "stack.h"

void input(char expr[100], char translate[100][10])
{
    printf("Input the expression:\n");
    scanf("%s", expr);
    preprocess(expr, translate);
}

int main(int argc, char* argv[])
{   
    char expr[MAX_LENGTH];
    char translate[MAX_LENGTH][MAX_SIZE];
    
    input(expr, translate);

    return 0;
}
