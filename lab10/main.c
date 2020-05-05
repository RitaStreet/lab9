#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define OS_TYPE linux
#ifdef OS_TYPE
#define maxlen 256
#endif // OS_TYPE

struct animals
{
    int numb;
    char *name;
    char *kind;
    int lifespan;
    int quantity;
    float weight;//average
    float height;//average
    int numbers[3];
    struct animals *next;
};
/* define types */
typedef struct animals animals;

typedef struct Head
{
    int inc;
    animals *nose;
    animals *tail;
} Head;

/* function to split string to array by separator */
char **simple_split(char *str, int length, char sep);//раздел€ем текст дл€ записи его в структуру

/* function to print header string without data */
void print_header();

/* function to output structure fields on console */
void struct_out(animals *str0);//выводим структуру

animals *create_node(char **str, int numb);//создаЄм элемент списка

Head *make_head();//создаЄм голову списка

void node_free(Head **head);

void node_out(Head **head);//выводим список

void delete_penultimate(Head **head, int n, animals *p);//удал€ем предпоследний элемент

void free_nodes(Head **head);//отчистка пам€ти

int main()
{
    animals *node = NULL, *p = NULL;
    Head *ddd = NULL;
    int slen, i, n, count, choice;
    char s1[maxlen];
    char **s2 = NULL;
    char sep;
    FILE *df;
    choice = 1;

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
        ddd = make_head();//создаЄм голову списка
        while (fgets(s1, maxlen, df) != NULL)//считаем кол-во строк
            n++;

        rewind(df);//после подсчЄта строчек переводим указатель на начало

        for (i = 0, count = 1; i < n; i++, count++)
        {
            fgets(s1, maxlen, df);
            slen = strlen(s1);
            s1[slen - 1] = '\0';
            slen = strlen(s1);
            s2 = simple_split(s1, slen, sep);
            node = create_node(s2, count);
            //строчки до for считывают строчки, раздел€ют текст и создают из него элемент списка
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

    node_out(&ddd);
    printf("\n");
    while (choice == 1)
   {
        puts("Wanna delete penultimate struct?\n1 - Yes\n2 - No\n");
        scanf("%d", &choice);
        puts("\n");
        if (choice == 1)
        {
            if (n != 1)
            {
                delete_penultimate(&ddd, n, p);
                n--;
                node_out(&ddd);
            }
            else
            {
                puts("Need more elements!\nError!");
                break;
            }
        }
        else
            puts("Bye-bye");
   }
   free_nodes(&ddd);
   puts("Press any key when ready");
   getchar();
   getchar();
   return 0;
}

Head *make_head()
{
    Head *ddd = NULL;
    ddd = (Head *) malloc(sizeof(Head));

    if (ddd != NULL)
    {
        ddd -> inc = 0;
        ddd -> nose = NULL;
        ddd -> tail = NULL;
    }
    return ddd;
}

animals *create_node(char **str, int numb)
{
    animals *node = NULL;
    node = (animals *) malloc(sizeof(animals));
    node -> numb = numb;
    node -> name = str[0];
    node -> kind = str[1];
    node -> lifespan = atoi(str[2]);
    node -> quantity = atoi(str[3]);
    node -> weight = atof(str[4]);
    node -> height = atof(str[5]);
    node -> numbers[0] = atoi(str[6]);
    node -> numbers[1] = atoi(str[7]);
    node -> numbers[2] = atoi(str[8]);
    node -> next = NULL;

    return node;
}

void node_out(Head **head)
{
    print_header();
    animals *node = NULL;
    node = (head -> nose);

    while (node != NULL)
    {
        struct_out(node);
        node = node -> next;
    }
}

void delete_penultimate(Head **head, int n, animals *p)
{
    if (head -> tail == head -> nose)
    {
        puts("Error!\nProgram need more structures!\nBye-bye!");
    }
    p = head -> nose;
    if (n != 2)
    {
        while (p -> numb != n - 2)
            p = p -> next;
        p -> next -> name = NULL;
        p -> next -> kind = NULL;
        free(p -> next);
        p -> next = NULL;
        p -> next = head -> tail;
        head -> tail -> numb = head -> tail -> numb - 1;
    }

    else//если осталось 2 элемента, то мы не можем использовать верхний вариант, поэтому просто "носу" присваиваем "хвост"
    {
        head -> nose = head -> tail;
        head -> nose -> numb = head -> nose -> numb - 1;
    }
}

void print_header()
{
    printf("|%s|%20s |%10s |%6s |%10s |%8s |%10s |%10s|%10s|%10s|\n", "num", "fullname", "kind", "lifespan", "quantity", "weight", "height", "Species", "Countries", "Continents" );
    printf("+---+---------------------+-----------+---------+-----------+---------+-----------+----------+----------+----------+\n");
}

void struct_out(animals *str0)
{
    printf("|%2d |%20s |%10s |  %6d |%10d |%8f |%10f |%9d |%9d |%9d |\n",
       str0 -> numb, str0 -> name, str0 -> kind, str0 -> lifespan, str0 -> quantity, str0 -> weight, str0 -> height, str0 -> numbers[0], str0 -> numbers[1], str0 -> numbers[2]);
}

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
void free_nodes(Head **head)
{
    animals *p;
    if (head -> nose == head -> tail)
        free(head -> nose);
   else
   {
        while(head -> nose -> next != NULL)
        {
            p = head -> nose -> next;
            free(head -> nose);
            head -> nose = p;
        }
   }
}
