#include "vector.h"

vector vector_init()
{
    vector v;
    v.length = 0;
    memset(v.data, 0, sizeof(v.data));
    return v;
}

int vector_length(vector v)
{
    return v.length;
}

bool vector_full(vector v)
{
    return v.length >= MAX_LENGTH;
}

bool vector_empty(vector v)
{
    return v.length <= 0;
}

void vector_print(vector v)
{
    printf("length of vector is: %d\n", v.length);
    for(int i = 0; i < v.length; i++){
        printf("%d: %s\n", i + 1, v.data[i]);
    }
}

bool vector_backin(vector *v, char *c)
{
    if(vector_full(*v)){
        printf("Vector Error: vector is full\n"); 
        return false;
    }
    strcpy(v->data[v->length++], c);
    return true;
}

bool vector_backout(vector *v, char *c)
{
    if(vector_empty(*v)){
        printf("Vector Error: vector is empty\n");
        return false;
    }
    strcpy(c, v->data[--v->length]);
    return true;
}

bool vector_insert(vector *v, int pos, char *c)
{
    if(vector_full(*v)){
        printf("Vector Error: vector is full\n");
        return false;
    }
    if(pos > v->length - 1){
        printf("Vector Warning: insert position is greater than current length, new data will be inserted at back\n");
        return vector_backin(v, c);
    }
    for(int i = v->length++; i > pos; i--)
        strcpy(v->data[i], v->data[i-1]);
    return true;
}

bool vector_remove(vector *v, int pos, char *c)
{
    if(vector_empty(*v)){
        printf("Vector Error: vector is empty\n");
        return 0;
    }
    if(pos > v->length - 1){
        printf("Vector Warning: remove position is greater than current length, old data will be removed from back\n");
        return vector_backout(v, c);
    }
    for(int i = pos; i < v->length - 1; i++)
        strcpy(v->data[i], v->data[i + 1]);
    return true;
}