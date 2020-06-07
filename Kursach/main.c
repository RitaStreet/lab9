#include <stdio.h>
#include <stdlib.h>
#include "headers/structs.h"
#include "headers/nodeFunctions.h"
#include "headers/structFunctions.h"
#include "headers/textFunctions.h"
#include "headers/Menu.h"
#define maxlen 128
#define OS_TYPE windows
#ifdef OS_TYPE
    #define CLS system("cls")
#else
    #define CLS system("clear")
#endif

int main()
{
    Head *ddd = NULL;

    ddd = make_head();

    fill_node(ddd);

    menu(ddd);

    free_list(ddd);

    return 0;
}
