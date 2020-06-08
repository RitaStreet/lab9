#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define OS_TYPE linux
#define maxlen 256

typedef struct stroka
{
    char *str;
    struct stroka *next;
}stroka;

stroka *push(stroka *head, char *s1, int slen)//������� ����������� ������� �����
{
    stroka *p = (stroka*)malloc(sizeof(stroka));
    p -> str = (char*)malloc(slen * sizeof(char));
    if (p != NULL)
    {
        p -> next = head;
        p -> str = s1;
        head = p;//������� ���������� �������, ��� ����� ������� ������ ����� � ������� ���������� ������ ����� �� ���
    }
    else
        puts("Error!");
    return head;
}

stroka *pop(stroka *head)//������� "���������" ������� �����
{
    if (head != NULL)
        head = head -> next;//������� ������ ������ ����� �� 1
    else
        puts("Error!");

    return head;
}

int main()
{
    stroka *head = NULL;
    FILE *df, *mf;
    int sumstr, n, i, slen, *a = NULL;
    char s1[maxlen];
    sumstr = 0;

    df = fopen("csv.txt", "r");//��������� ���� �� ����� �������� ����������� ����
    mf = fopen("res.txt", "w");//������ ���� � ������� ����� �������� �������� �����
    if (df != NULL)
    {
        n = 0;
        while ((fgets(s1, maxlen, df)) != NULL) n++;
        rewind(df);
        a = malloc(n * sizeof(int));

        for (i = 0; i < n; i++)
        {
            fgets(s1, maxlen, df);
            slen = strlen(s1);
            s1[slen - 1] = '\0';
            slen = strlen(s1);
            a[i] = slen;
            sumstr += slen;
            head = push(head, s1, slen);//��������� ������� � ����
            printf("%s\n", head -> str);
        }
        head = pop(head);
        head = pop(head);//������� 2 �������� �� �������
        while(head != NULL)
        {
            fprintf(mf, "%s\n", head -> str);
            head = pop(head);
        }
    }
    sumstr = sumstr - a[n - 1] - a[n - 2];
    printf("Dlina strok tekushego steka = %d", sumstr);
    rewind(df);//��������� ��������� ��� �������
    return 0;
}
