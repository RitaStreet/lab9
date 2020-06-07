#include "headers/structFunctions.h"


void print_header()
{
    printf("|%3s |%9s |%10s |%8s |%10s |%10s |\n", "num", "name", "kind", "lifespan", "weight", "height");
    printf("+----+-----------+-----------+---------+-----------+-----------+\n");
}

void struct_out(Node *str0)
{
    printf("|%3d | %9s |%10s |%8d |%10f |%10f |\n",
       str0 -> id, str0 -> structure -> name, str0 -> structure -> kind, str0 -> structure ->  lifespan, str0 -> structure ->  characteristic[0], str0 -> structure ->  characteristic[1]);
}

void find_name(Head *ddd)
{
    int ch1, schet, ll, j;
    char namename[256];
    Node *temp = NULL;
    ch1 = 1;
    schet = 0;

    temp = ddd -> first;

    printf("Which name of animals that you want to find?\n>");
    scanf("%s", namename);

    ll = strlen(namename);
    while (temp != NULL)
    {
        for (j = 0; j < ll; j++)
        {
            if (temp -> structure -> name[j] == namename[j])
                schet++;
        }
        if (schet == ll)
        {
            struct_out(temp);
            ch1++;
        }
        schet = 0;
        temp = temp -> next;
    }
    if (ch1 == 1)
        printf("\nCan`t find\n");
}

void find_kind(Head *ddd)
{
    int ch1, schet, ll, j;
    char namename[256];
    Node *temp = NULL;
    ch1 = 1;
    schet = 0;

    temp = ddd -> first;

    printf("Which kind of animals that you want to find?\n>");
    scanf("%s", namename);

    ll = strlen(namename);
    while (temp != NULL)
    {
        for (j = 0; j < ll; j++)
        {
            if (temp -> structure -> kind[j] == namename[j])
                schet++;
        }
        if (schet == ll)
        {
            struct_out(temp);
            ch1++;
        }
        schet = 0;
        temp = temp -> next;
    }
    if (ch1 == 1)
        printf("\nCan`t find\n");
}

void find_lifespan(Head *ddd)
{
    int schet, poisk;
    Node *temp = NULL;
    schet = 0;

    temp = ddd -> first;

    printf("Which lifespan of animals that you want to find?\n>");
    scanf("%d", &poisk);

    while (temp != NULL)
    {
        if (temp -> structure -> lifespan == poisk){
            struct_out(temp);
            schet++;
        }
        temp = temp -> next;
    }
    if (schet == 0)
        printf("\nCan`t find\n");
}

void find_weight(Head *ddd)
{
    int schet;
    float poisk;
    Node *temp = NULL;
    schet = 0;

    temp = ddd -> first;

    printf("Which weight of animals that you want to find?\n>");
    scanf("%f", &poisk);

    while (temp != NULL)
    {
        if (temp -> structure -> characteristic[0] == poisk){
            struct_out(temp);
            schet++;
        }
        temp = temp -> next;
    }
    if (schet == 0)
        printf("\nCan`t find\n");
}

void find_height(Head *ddd)
{
    int schet;
    float poisk;
    Node *temp = NULL;
    schet = 0;

    temp = ddd -> first;

    printf("Which height of animals that you want to find?\n>");
    scanf("%f", &poisk);

    while (temp != NULL)
    {
        if (temp -> structure -> characteristic[1] == poisk){
            struct_out(temp);
            schet++;
        }
        temp = temp -> next;
    }
    if (schet == 0)
        printf("\nCan`t find\n");
}
