#ifndef TEXTFUNCTIONS_H_INCLUDED
#define TEXTFUNCTIONS_H_INCLUDED
#include "structs.h"
#include "structFunctions.h"
#include "nodeFunctions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define maxlen 128

char **simple_split(char *str, int length, char sep);

void text(int slen, int n, char **s2, Head *ddd, FILE *df, animals **anim);

void clear_str_array(char **str, int n);

char **add();

void new_gets(char *s, int lim);

void sort_by_lifespan(Head *ddd);

void sort_by_weight(Head *ddd);

void sort_by_height(Head *ddd);

#endif // TEXTFUNCTIONS_H_INCLUDED
