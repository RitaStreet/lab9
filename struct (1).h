#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdlib.h>

typedef struct animals
{
    char *name;
    int lifespan;
    float weight;//average
    float height;//average
}animals;

typedef struct node
{
    int id;
    animals *kind;
    struct node *next;
    struct node *prev;
}node;

typedef struct Head
{
    int numb;
    struct node *nose;
    struct node tail;
}head;



#endif // STRUCT_H_INCLUDED
