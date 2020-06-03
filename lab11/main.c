#include <stdio.h>
#include <stdlib.h>
#include "headers/structs.h"
#include "headers/nodeFunctions.h"
#include "headers/structFunctions.h"
#include "headers/textFunctions.h"
#define maxlen 128

int main()
{
    Head *ddd = NULL;

    ddd = make_head();

    fill_node(ddd);

    free_list(ddd);


    return 0;
}
