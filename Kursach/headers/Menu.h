#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "structs.h"
#include "nodeFunctions.h"
#include "structFunctions.h"
#include "textFunctions.h"
#define maxlen 128
void menu(Head *ddd);

void inform_menu();

void case0(Head *ddd);

void case1(Head *ddd);

void case2(Head *ddd);

void case3(Head *ddd);

void case4(Head *ddd);

void case5(Head *ddd);

void case6(Head *ddd);

void case7(Head *ddd);

void back_to_menu(Head *ddd);

int correct(Head *ddd, int a, int b);

#endif // MENU_H_INCLUDED
