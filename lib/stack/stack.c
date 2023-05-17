#include "stack.h"

stack stack_init()
{
    stack s;
    s.top = -1;
    memset(s.data, 0, sizeof(s.data));
    return s;
}

bool stack_empty(stack s)
{
    return s.top < 0;
}

bool stack_full(stack s)
{
    return s.top == (MAX_LENGTH - 1);
}

bool stack_push(stack *s, char c[])
{
    if(stack_full(*s)){
        printf("Stack Error: stack is full, nothing can push in\n");
        return false;
    }
    else{
        strcpy(s->data[++s->top],  c);
        printf("Stack Operation: Pushing %s\n", c);
        return true;
    }
}

bool stack_pop(stack *s, char c[])
{
    if(stack_empty(*s)){
        printf("Stack Error: stack is empty, nothing to pop out\n");
        return false;
    }
    else{
        strcpy(c, s->data[s->top--]);
        printf("Stack Operation: Poping %s\n", c);
        return true;
    }
}

char* stack_top(stack *s)
{
    if(stack_empty(*s)){
        printf("Stack Error: stack is empty\n");
        return NULL;
    }
    return s->data[s->top];
}