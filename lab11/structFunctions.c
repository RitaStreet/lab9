#include "headers/structFunctions.h"


void print_header()
{
    printf("|%3s |%9s |%10s |%8s |%10s |%10s |\n", "num", "name", "kind", "lifespan", "weight", "height");
    printf("+----+----------+-----------+---------+-----------+-----------+\n");
}

void struct_out(Node *str0)
{
    printf("|%3d | %8s |%10s |%8d |%10f |%10f |\n",
       str0 -> id, str0 -> structure -> name, str0 -> structure -> kind, str0 -> structure ->  lifespan, str0 -> structure ->  characteristic[0], str0 -> structure ->  characteristic[1]);
}
