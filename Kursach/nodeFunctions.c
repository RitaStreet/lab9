#include "headers/nodeFunctions.h"

void add_first(Head *ddd)
{
    char **s2 = NULL;
    s2=add();
    Node *node = NULL, *p = NULL;
    node = (Node*)malloc(sizeof(Node));
    p = (Node*)malloc(sizeof(Node));
    p = ddd -> first;
    if((node != NULL))
    {
        node -> structure = (animals*)malloc(sizeof(animals));
        node -> structure -> name = (char*)malloc(sizeof(char));
        node -> structure -> kind = (char*)malloc(sizeof(char));
        node -> structure -> name = s2[0];
        node -> structure -> kind = s2[1];
        node -> structure -> lifespan = atoi(s2[2]);
        node -> structure -> characteristic[0] = atof(s2[3]);
        node -> structure -> characteristic[1] = atof(s2[4]);
        node -> next = ddd -> first;
    }
    while (p != NULL)
    {
        p -> id = p -> id + 1;
        p = p -> next;
    }
    ddd -> cnt++;
    ddd -> first -> prev = node;
    node -> id = 1;
    node -> prev = NULL;
    ddd -> first = node;
    puts("\nStructure was added!\n");
    free(p);
}

void add_last(Head *ddd)
{
    char **s2 = NULL;
    s2=add();
    Node *node = NULL;
    node = (Node*)malloc(sizeof(Node));
    node -> structure = (animals*)malloc(sizeof(animals));
    node -> structure -> name = (char*)malloc(sizeof(char));
    node -> structure -> kind = (char*)malloc(sizeof(char));
    node -> structure -> name = s2[0];
    node -> structure -> kind = s2[1];
    node -> structure -> lifespan = atoi(s2[2]);
    node -> structure -> characteristic[0] = atof(s2[3]);
    node -> structure -> characteristic[1] = atof(s2[4]);
    node -> next = NULL;

    node -> id = ddd -> cnt;
    node -> prev = ddd -> last;
    ddd -> last -> next = node;
    ddd -> cnt++;
    ddd -> last = node;
}

void delete_node(Head *ddd, int choice)
{
    ddd -> cnt -= 1;
    Node *temp = NULL;
    /*if (choice == 1)
    {
        temp = ddd -> first -> next;
        free(ddd -> first);
        temp -> prev = NULL;
        ddd -> first = temp;
    }*/

    if((ddd -> cnt) != choice && choice != 1)
    {
        temp = ddd -> first;
        for(int i = 0; i < choice - 1; i++)
            temp = temp -> next;
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        temp = ddd -> first;
        while (temp -> id != choice + 1)
        {
            temp = temp -> next;
        }
        while (temp != NULL)
        {
            temp -> id = temp -> id - 1;
            temp = temp -> next;
        }
    }
    else if(choice == 1)
    {
        temp = ddd -> first;
        temp = temp -> next;
        ddd -> first = temp;
        free_Node(temp -> prev);
        ddd -> first -> prev =NULL;
        temp = ddd -> first;
        while (temp != NULL)
        {
            temp -> id = temp -> id - 1;
            temp = temp -> next;
        }
    }
    else
    {
        temp = ddd -> last;
        ddd -> last = temp -> prev;
        ddd -> last -> next = NULL;
    }
    //free(temp);
}

Head *make_head()
{
    Head *ddd = NULL;
    ddd = (Head*)malloc(sizeof(Head));

    if (ddd)
    {
        ddd -> cnt = 1;
        ddd -> first = NULL;
        ddd -> last = NULL;
    }
    return ddd;
}

Node *create_node(char **str, int i, Node *p, Head *ddd)
{
    Node *node = NULL;
    node = (Node*)malloc(sizeof(Node));
    if((node != NULL))
    {
        node -> structure = (animals*)malloc(sizeof(animals));
        node -> structure -> name = (char*)malloc(sizeof(char));
        node -> structure -> kind = (char*)malloc(sizeof(char));
        node -> structure -> name = str[0];
        node -> structure -> kind = str[1];
        node -> structure -> lifespan = atoi(str[2]);
        node -> structure -> characteristic[0] = atof(str[3]);
        node -> structure -> characteristic[1] = atof(str[4]);
        node -> next = NULL;
    }
    if (i != 0)
    {
        node -> prev = p;
    }
    node -> id = ddd -> cnt;
    ddd -> cnt++;
    return node;
}

void fill_node(Head *ddd)
{
    FILE *df;
    int slen, i, n;
    char **s2 = NULL;
    char s1[maxlen];
    char sep;
    Node *node = NULL, *p = NULL;

    sep = ';';

    df = fopen("csv.txt", "r");
    if (df != NULL)
    {
        n = 0;
        while ((fgets(s1, maxlen, df)) != NULL) n++;
        rewind(df);

        for (i = 0; i < n; i++)
        {
            fgets(s1, maxlen, df);
            slen = strlen(s1);
            s1[slen - 1] = '\0';
            slen = strlen(s1);
            s2 = simple_split(s1, slen, sep);
            node = create_node(s2, i, p, ddd);
            if (i != 0){
                p -> next = node;
                ddd -> last = p;
            }
            else
            {
                node -> prev = NULL;
                ddd -> first = node;
                ddd -> last = node;
            }
            p = node;
        }
    }
    else puts("CSV file error!");
    ddd -> last = p;
}

void free_Node(Node *temp)
{
    temp -> next = NULL;
    temp -> prev = NULL;
    free(temp -> structure -> name);
    free(temp -> structure -> kind);
    free(temp -> structure);
    temp = NULL;
    free(temp);
}

void node_out(Head *head)
{
    print_header();
    Node *node = NULL;
    node = (Node*)malloc(sizeof(Node));
    node -> structure = (animals*)malloc(sizeof(animals));
    node -> structure -> name = (char*)malloc(sizeof(char));
    node -> structure -> kind = (char*)malloc(sizeof(char));
    node = head -> first;

    while (node != NULL)
    {
        struct_out(node);
        node = node -> next;
    }
}
void node_out_reverse(Head *head)
{
    print_header();
    Node *node = NULL;
    node = (Node*)malloc(sizeof(Node));
    node -> structure = (animals*)malloc(sizeof(animals));
    node -> structure -> name = (char*)malloc(sizeof(char));
    node -> structure -> kind = (char*)malloc(sizeof(char));
    node = head -> last;

    while (node != NULL)
    {
        struct_out(node);
        node = node -> prev;
    }
}

void free_list(Head *ddd)
{
    Node *temp = NULL, *node = NULL;
    temp = ddd -> first -> next;

    while (temp != NULL)
    {
        node = temp;
        temp = temp -> next;
        free_Node(node);
    }
}

void edit_structure(Head *ddd, int choice, int ch1)
{
    Node *temp = NULL;
    temp = ddd -> first;
    for(int i = 0; i < choice - 1; i++)
            temp = temp -> next;
    printf("\nEnter your change!\n>");
    switch(ch1)
    {
    case 1:
        scanf("%s", temp -> structure -> name);
        break;
    case 2:
        scanf("%s", temp -> structure -> kind);
        break;
    case 3:
        scanf("%d", &temp -> structure -> lifespan);
        break;
    case 4:
        scanf("%f", &temp -> structure -> characteristic[0]);
        break;
    case 5:
        scanf("%f", &temp -> structure -> characteristic[1]);
        break;
    }

}
