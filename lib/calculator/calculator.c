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

float string_to_number(char *str)
{
    float ans = 0;
    int decimal = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '.'){
            decimal = 1; 
            continue;
        }
        ans *= 10;
        ans += str[i] - '0';
        decimal *= 10;
    }
    return decimal ? ans / decimal : ans;
}

void number_to_string(float num, char *str)
{
    sprintf(str, "%f", num);
}

void compute(char *str1, char *str2, char *str3, char operate)
{
    float num1 = string_to_number(str1);
    float num2 = string_to_number(str2);
    float num3;
    switch (operate)
    {
    case '+':
        num3 = add(num1, num2);
        break;
    case '-':
        num3 = sub(num1, num2);
        break;
    case '*':
        num3 = mul(num1, num2);
        break;
    case '/':
        num3 = div(num1, num2);
        break;    
    default:
        break;
    }
    number_to_string(num3, str3);
}

vector preprocess(char *expr)
{
    vector v = vector_init();
    stack s = stack_init();
    char tmp[MAX_SIZE];
    
    for(int i = 0; i < strlen(expr); i++){
        if(expr[i] == ' ')
            continue;
        memset(tmp, 0, sizeof(tmp));
        if(isdigit(expr[i])){
            int j = 0;
            for(; i + j < strlen(expr) && isdigit(expr[i + j]); j++){
                tmp[j] = expr[i + j];
            }
            i += (j - 1);
            vector_backin(&v, tmp);
        }
        else{
            switch (expr[i])
            {
                case '(': 
                    tmp[0] = expr[i];
                    stack_push(&s, tmp);
                    break;
                case ')':
                    while(*stack_top(&s) != '('){
                        stack_pop(&s, tmp);
                        vector_backin(&v, tmp);
                    }
                    stack_pop(&s, tmp);
                    break;
                case '*':
                case '/':
                case '+':
                case '-':
                    while(!stack_empty(s) && priority(*stack_top(&s)) >= priority(expr[i])){
                        stack_pop(&s, tmp);
                        vector_backin(&v, tmp);
                    }
                    tmp[0] = expr[i];
                    tmp[1] = 0;
                    stack_push(&s, tmp);
                    break;
            }
        }
    }
    while(!stack_empty(s)){
        stack_pop(&s, tmp);
        vector_backin(&v, tmp);
    }
    return v;
}

float process(vector expr)
{
    stack s = stack_init();
    char num1[MAX_SIZE], num2[MAX_SIZE], num3[MAX_SIZE];
    
    for(int i = 0; i < expr.length; i++){
        if(!isdigit(*expr.data[i])){
            stack_pop(&s, num2);
            stack_pop(&s, num1);
            compute(num1, num2, num3, *expr.data[i]);
            stack_push(&s, num3);
        }
        else{
            stack_push(&s, expr.data[i]);
        }
    }
    stack_pop(&s, num3);
    return string_to_number(num3);
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