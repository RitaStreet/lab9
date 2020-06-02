#include "headers/nodeFunctions.h"

void add_first(Head *my_head, Node *new_node)
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
}

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

Node *create_node(Head *ddd, char **str, int i, Node *p)
{
    Node *node = NULL;
    node = (Node*)malloc(sizeof(Node));
    if((node != NULL))
    {
        node -> structure -> name = str[0];
        node -> structure -> kind = str[1];
        node -> structure -> lifespan = atoi(str[2]);
        node -> structure -> characteristic[0] = atof(str[3]);
        node -> structure -> characteristic[1] = atof(str[4]);
        node -> prev = ddd -> last;
        //ddd -> last -> next = p;
        node -> next = NULL;
        ddd -> last = node;
        printf("%s", node -> structure -> name);
    }
    if (i == 1)
        ddd -> first -> next = node;
    //else
        //node -> prev -> next = p;
    //ddd -> cnt++;
    return node;
}

void fill_node()
{
    FILE *df;
    int slen, i, n;
    char **s2 = NULL;
    char s1[maxlen];
    char sep;
    Head *ddd = NULL;
    Node *node = NULL, *p = NULL;

    sep = ';';
    ddd = make_head();
    p = (Node*)malloc(sizeof(Node));

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
            printf("Tochka1");
            s2 = simple_split(s1, slen, sep);
            printf("Tochka2");
            if (i != 0){
                p = node;
                node = create_node(ddd, s2, i, p);
                //node -> prev -> next = p;
            }
            printf("Tochka3\n");
            if (i == 0)
            {
                node = (Node*)malloc(sizeof(Node));
                if((node != NULL))
                {
                    node -> structure -> name = s2[0];
                    node -> structure -> kind = s2[1];
                    node -> structure -> lifespan = atoi(s2[2]);
                    node -> structure -> characteristic[0] = atof(s2[3]);
                    node -> structure -> characteristic[1] = atof(s2[4]);
                    node -> prev = NULL;
                    node -> next = NULL;
                    ddd -> last = node;
                    ddd -> first = node;
                }
            }
            //node -> id = i + 1;
            //printf("\n%d\n", node -> id);
        }
    }
    else puts("CSV file error!");
    //ddd -> last = node;
    //ddd -> cnt = node -> id;
    node_out(ddd);
}

void free_Node(Node *temp)
{
    temp -> next = NULL;
    temp -> prev = NULL;

    free(temp);
}

void node_out(Head *head)
{
    print_header();
    Node *node = NULL;
    node = head -> first;

    while (node != NULL)
    {
        struct_out(node);
        printf("\n%d\n", node -> structure -> lifespan);
        node = node -> next;
    }
}
