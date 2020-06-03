#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdlib.h>

typedef struct animals
{
    char *name;
    char *kind;
    int lifespan;
    float characteristic[2];//average
}animals;

typedef struct node
{
    int id;
    animals *structure;
    struct node *next;
    struct node *prev;
}Node;

typedef struct Head
{
    int cnt;
    struct node *first;
    struct node *last;
}Head;



#endif // STRUCT_H_INCLUDED
