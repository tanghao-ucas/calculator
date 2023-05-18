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
        printf("Vector Warning: insert position is greater than current length, new data will be insert at back\n");
        return vector_backin(v, c);
    }
    for(int i = v->length++; i > pos; i--)
        strcpy(v->data[i], v->data[i-1]);
    return true;
}