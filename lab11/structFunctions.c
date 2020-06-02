#include "headers/structFunctions.h"


void print_header()
{
    printf("|%10s |%10s |%6s |%10s |%8s |\n", "name", "kind", "lifespan", "weight", "height");
    printf("+----------------+-----------+---------+-----------+---------+\n");
}

void struct_out(Node *str0)
{
    printf("| %20s |%10s |%6d |%10f |%8f \n",
       str0 -> structure -> name, str0 -> structure -> kind, str0 -> structure ->  lifespan, str0 -> structure ->  characteristic[0], str0 -> structure ->  characteristic[1]);
}
