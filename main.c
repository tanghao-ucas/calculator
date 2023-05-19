#include <stdio.h>
#include "calculator.h"
#include "stack.h"
#include "vector.h"

vector input()
{
    char str[MAX_LENGTH * MAX_SIZE];
    printf("Input the expression:\n");
    scanf("%[^\n]", str);
    vector expr = preprocess(str);
    return expr;
}

int main(int argc, char* argv[])
{   
    vector expr = input();
    vector_print(expr);

    printf("answer: %f\n", process(expr));

    return 0;
}
