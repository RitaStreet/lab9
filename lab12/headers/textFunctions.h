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

#endif // TEXTFUNCTIONS_H_INCLUDED
