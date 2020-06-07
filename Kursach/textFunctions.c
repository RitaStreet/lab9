#include "headers/textFunctions.h"

char **simple_split(char *str, int length, char sep)
{
    char **str_array = NULL;
    int i, j, k, m;
    int key, count;
    for(j = 0, m = 0; j < length; j++)
    {
        if(str[j] == sep)
            m++;
    }

    key = 0;
    str_array = (char**)malloc((m + 1) * sizeof(char*));
    if(str_array != NULL)
    {
        for(i = 0, count = 0; i <= m; i++, count++)
        {
            str_array[i] = (char*)malloc(length * sizeof(char));

            if(str_array[i] != NULL)
                key=1;

            else
            {
                key=0;
                i=m;
            }
        }

        if(key)
        {
            k = 0;
            m = 0;

            for(j = 0; j < length; j++)
            {
                if(str[j] != sep)
                    str_array[m][j - k] = str[j];

                else
                {
                    str_array[m][j - k] = '\0';
                    k = j + 1;
                    m++;
                }
            }
        }
     }
     return str_array;
}

void clear_str_array(char **str, int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        free(str[i]);
        str[i]=NULL;
    }
    free(str);
    str=NULL;
}

char **add()
{
    enum {len = 128};
    char *s11=NULL;
    char *s12=NULL;
    char *s13=NULL;
    char *s14=NULL;
    char *s15=NULL;
    char **s2=NULL;
    s11=(char*)malloc(len*sizeof(char));
    s12=(char*)malloc(len*sizeof(char));
    s13=(char*)malloc(len*sizeof(char));
    s14=(char*)malloc(len*sizeof(char));
    s15=(char*)malloc(len*sizeof(char));
    s2=(char**)malloc(6*sizeof(char*));
    printf("Name: ");
    scanf("%s", s11);
    s2[0]=(char*)malloc((strlen(s11))*sizeof(char));
    strcpy(s2[0],s11);
    printf("Kind: ");
    scanf("%s", s12);
    s2[1]=(char*)malloc((strlen(s12))*sizeof(char));
    strcpy(s2[1],s12);
    printf("Lifespan: ");
    scanf("%s", s13);
    s2[2]=(char*)malloc((strlen(s12))*sizeof(char));
    strcpy(s2[2],s13);
    printf("Weight: ");
    scanf("%s", s14);
    s2[3]=(char*)malloc((strlen(s13))*sizeof(char));
    strcpy(s2[3],s14);
    printf("Height: ");
    scanf("%s", s15);
    s2[4]=(char*)malloc((strlen(s14))*sizeof(char));
    strcpy(s2[4],s15);
    free(s11);
    s11=NULL;
    free(s12);
    s12=NULL;
    free(s13);
    s13=NULL;
    free(s14);
    s14=NULL;
    free(s15);
    s15=NULL;
    return s2;
}

void sort_by_lifespan(Head *ddd)
{
    Node *tmp = NULL, *temp = NULL;
    animals *struct1;
    int check = 1;
    while(check > 0)
    {
        check = 0;
        temp = ddd -> first;
        do
        {
            if(temp -> structure -> lifespan > temp -> next -> structure -> lifespan)
            {
                check = 1;
                struct1 = temp -> structure;
                temp -> structure = temp -> next -> structure;
                temp -> next -> structure = struct1;
            }
            temp = temp -> next;
        }while(temp != ddd -> last);
     }
}
void sort_by_weight(Head *ddd)
{
    Node *tmp = NULL, *temp = NULL;
    animals *struct1;
    int check = 1;
    while(check > 0)
    {
        check = 0;
        temp = ddd -> first;
        do
        {
            if(temp -> structure -> characteristic[0] > temp -> next -> structure -> characteristic[0])
            {
                check = 1;
                struct1 = temp -> structure;
                temp -> structure = temp -> next -> structure;
                temp -> next -> structure = struct1;
            }
            temp = temp -> next;
        }while(temp != ddd -> last);
     }
}

void sort_by_height(Head *ddd)
{
    Node *tmp = NULL, *temp = NULL;
    animals *struct1;
    int check = 1;
    while(check > 0)
    {
        check = 0;
        temp = ddd -> first;
        do
        {
            if(temp -> structure -> characteristic[1] > temp -> next -> structure -> characteristic[1])
            {
                check = 1;
                struct1 = temp -> structure;
                temp -> structure = temp -> next -> structure;
                temp -> next -> structure = struct1;
            }
            temp = temp -> next;
        }while(temp != ddd -> last);
     }
}
