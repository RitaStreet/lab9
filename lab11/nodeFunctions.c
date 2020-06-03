#include "headers/nodeFunctions.h"

/*void add_first(Head *my_head, Node *new_node)
{
    if(my_head&&new_node)
    {
        my_head->first = new_node;
        my_head->last = new_node;
        my_head->cnt++;
    }
}

void add_last(Head *ddd)
{
    Node *temp = NULL;

    temp = malloc(sizeof(Node));

    temp -> next = NULL;
    temp -> id = ddd -> cnt + 1;
    temp -> prev = ddd -> last;

    ddd -> last -> next = temp;
    ddd -> last = temp;
}

void delete_node(Node *temp, Head *ddd)
{
    ddd -> cnt -= 1;
    temp = temp -> next;

    if((temp -> next) != NULL)
    {
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
    }
    else
    {
        ddd -> last = temp -> prev;
        ddd -> last -> next = NULL;
    }

    free_Node(temp);
}*/

Head *make_head()
{
    Head *ddd = NULL;
    ddd = (Head*)malloc(sizeof(Head));

    if (ddd)
    {
        //ddd -> cnt = 1;
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
    //ddd -> cnt++;
    return node;
}

void fill_node(Head *ddd)
{
    FILE *df;
    int slen, i, n, choice;
    char **s2 = NULL;
    char s1[maxlen];
    char sep;
    //Head *ddd = NULL;
    Node *node = NULL, *p = NULL;

    sep = ';';
    //ddd = make_head();

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
    puts("\nList:\n");
    node_out(ddd);
    puts("\nList Reverse:\n");
    node_out_reverse(ddd);
    puts("\n");
    puts("Wanna delete penultimate structure?\n1 - Yes\n2 - No");
    scanf("%d", &choice);
    while ((choice == 1)&(n > 0))
    {
        delete_penultimate(ddd, n);
        if (n > 1){
            puts("\nList:\n");
            node_out(ddd);
            puts("\nList Reverse:\n");
            node_out_reverse(ddd);
            puts("\nWanna delete penultimate structure?\n1 - Yes\n2 - No");
            scanf("%d", &choice);
            }
        n--;
    }
    puts("\nBye-Bye!\n");
}
void delete_penultimate(Head *ddd, int n)
{
    if(n > 2){
        Node *temp = NULL, *p = NULL;
        temp = ddd -> last;
        temp = temp -> prev;
        p = temp;
        temp = temp -> prev;
        temp -> next = ddd -> last;
        ddd -> last -> prev = temp;
        free_Node(p);
    }
    else if (n == 2)
    {
        Node *temp = NULL;
        temp = ddd -> first;
        ddd -> last -> prev = NULL;
        ddd -> last -> next = NULL;
        ddd -> first = ddd -> last;
        free_Node(temp);
    }
    if (n == 1)
    {
        puts("\nNeeds more elements!");
    }
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
