#include "calculator.h"

int priority(char c)
{
    switch(c){
        case '+': 
        case '-': return 1;
        case '*': 
        case '/': return 2;
        case '(': return 0;
        default : return -1;
    }
}

void preprocess(char expr[100], char translate[100][10])
{
    stack s = stack_init();
    char tmp[10];
    int i = 0, j = 0, k = 0;
    
    while(i < strlen(expr)){
        memset(tmp, 0, sizeof(tmp));
        if(isdigit(expr[i])){
            do{
                tmp[j++] = expr[i++];
            }while(i < strlen(expr) && isdigit(expr[i]));
            j = 0;
            strcpy(translate[k++], tmp);
        }
        else{
            tmp[0] = expr[i];
            switch(expr[i]){
                case '(': 
                    stack_push(&s, tmp);
                    break;
                case ')':
                    while(*stack_top(&s) != '('){
                        stack_pop(&s, translate[k++]);
                    }
                    stack_pop(&s, tmp);
                    break;
                case '*':
                case '/':
                case '+':
                case '-':
                    while(!stack_empty(s) && priority(*stack_top(&s)) >= priority(expr[i])){
                        stack_pop(&s, translate[k++]);
                    }
                    stack_push(&s, tmp);
                    break;
            }
            i++;
        }
    }
    while(!stack_empty(s)){
        stack_pop(&s, translate[k++]);
    }
}

float add(float num1, float num2)
{
    return num1 + num2;
}

float sub(float num1, float num2)
{
    return num1 - num2;
}

float mul(float num1, float num2)
{
    return num1 * num2;
}

float div(float num1, float num2)
{
    return num1 / num2;
}