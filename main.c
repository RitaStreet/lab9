#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define OS_TYPE linux
#ifdef OS_TYPE
#define maxlen 256
#endif // OS_TYPE
#include "h_files\struct.h"

int main()
{
    animals *node = NULL, *p = NULL;
    head *ddd = NULL;
    int slen, i, n, count, choice;
    char s1[maxlen];
    char **s2 = NULL;
    char sep;
    FILE *df;

    printf("Enter your separator symbol: \n");
    scanf("%c", &sep);

    if (sep != ';')
    {
        while (sep != ';')
        {
            puts("Enter right separator!");
            scanf("%s", &sep);
        }
    }
    df = fopen("csv.txt", "r");
    if (df != NULL)
    {
        n = 0;
        ddd = make_head();//создаём голову списка
        while (fgets(s1, maxlen, df) != NULL)//считаем кол-во строк
            n++;

        rewind(df);//после подсчёта строчек переводим указатель на начало

        for (i = 0, count = 1; i < n; i++, count++)
        {
            fgets(s1, maxlen, df);
            slen = strlen(s1);
            s1[slen - 1] = '\0';
            slen = strlen(s1);
            s2 = simple_split(s1, slen, sep);
            node = create_node(s2, count);
            //строчки до for считывают строчки, разделяют текст и создают из него элемент списка
            if (i != 0)//если элемент не первый, то записываем его не в голову
                p -> next = node;
            else
            {
                ddd -> nose = node;
                ddd -> inc = count;
            }

            p = node;
        }
    }
    else puts("File error!");
    ddd -> tail = node;
    ddd -> inc = node -> numb;

    return 0;
}
