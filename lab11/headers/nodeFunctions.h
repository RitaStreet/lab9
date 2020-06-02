#ifndef NODEFUNCTIONS_H_INCLUDED
#define NODEFUNCTIONS_H_INCLUDED
#include "structs.h"
#include "structFunctions.h"
#include "textFunctions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define maxlen 128

Head *make_head();

Node *create_node(Head *ddd, char **str, int i, Node *p);

void add_first(Head *my_head, Node *new_node);

void add_last(Head *ddd);

void delete_node(Node *temp, Head *ddd);

void fill_node();

void free_Node(Node *temp);

void node_out(Head *head);


#endif // NODEFUNCTIONS_H_INCLUDED
