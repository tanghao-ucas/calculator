#ifndef CALCULATOR_STRUCTURE
#define CALCULATOR_STRUCTURE

#define MAX_LENGTH 100
#define MAX_SIZE 20

/*
 * struct stack 
 */
typedef struct Stack stack;
struct Stack{
    char data[MAX_LENGTH][MAX_SIZE];
    int top;
};

/*
 * struct vector
 */
typedef struct Vector vector;
struct Vector{
    char data[MAX_LENGTH][MAX_SIZE];
    int length;
};

/*
 * struct queue
 */
typedef struct Queue queue;
struct Queue{
    char data[MAX_LENGTH][MAX_SIZE];
    int head;
    int tail;
};

#endif