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
    char* name;
    char* kind;
    int lifespan;
    int quantity;
    float weight;//average
    float height;//average
    int numbers[3];
};
/* define types */
typedef struct animals animals;

typedef float(*sorting)(animals**, int);


/* function to clear array of string */
void ClearStringArray(char** str, int n);

/* function to split string to array by separator */
char** simple_split(char* str, int length, char sep);

/* function to print header string without data */
void print_header();

/* function to output structure fields on console */
void struct_out(animals* str0);

/* function to create structure by array of strings*/
animals* struct_fill(char** str);

/* function to clear memory from structure */
void ClearStructure(animals* str0);

/* functions to get values for sort */
float ValueLifespan(animals** str0, int i0);

float ValueQuantity(animals** str0, int i0);

float ValueWeight(animals** str0, int i0);

float ValueHeight(animals** str0, int i0);

void SortKind(int n, animals** str0, float (*funcName)(animals**, int));

void sort_struct(sorting *kind, animals **stud0, int n, int count, int sd);

void find(char **names, animals **stud0, int n);

int main()
{
    animals** stud0 = NULL;
    sorting* kind = NULL;
    int slen, i, n, count, choice, sd, j, ch1;
    char** s2 = NULL;
    char** names = NULL;
    char s1[maxlen];
    char s11[maxlen];
    char sep;
    FILE* df;

    kind = (sorting*)malloc(4 * sizeof(sorting));

    printf("Enter your separator symbol: \n");
    printf("Please enter \;\n");
    scanf("%c", &sep);

    printf("Wanna add more struct?\n");
    printf("Yes - press 1, No - 2\n");
    scanf("%d", &choice);
    sd = 0;
    if (choice == 1)
    {
        printf("\nHow structs you wanna add?\n");
        scanf("%d", &sd);
    }

    df = fopen("csv.txt", "r");
    if (df != NULL)
    {
        n = 0;
        while ((fgets(s1, maxlen, df)) != NULL)
            n++;

        rewind(df);
        stud0 = (animals**)malloc((n + sd) * sizeof(animals*));
        names = (char**)malloc((n + sd) * sizeof(char*));

        if (stud0 != NULL)
        {
            puts("Initial array:");
            print_header();
            for (i = 0, count = 0; i < n; i++, count++)
            {
                fgets(s1, maxlen, df);
                slen = strlen(s1);
                s1[slen - 1] = '\0';
                slen = strlen(s1);
                s2 = simple_split(s1, slen, sep);
                names[i] = s2[0];
                if (s2 != NULL)
                {
                    stud0[i] = struct_fill(s2);
                    if (stud0[i] != NULL)
                    {
                        struct_out(stud0[i]);
                    }
                    else
                    {
                        puts("Structure not allocated!");
                        i = n;
                    }
                }
                else
                    puts("Error at data reading!");
            }
        }
        else
            puts("No memory allocation!");

        fclose(df);
        getchar();
        printf("\nPress enter when ready...\n");
        getchar();

        if (choice == 1)
        {
            printf("Enter struct alternately, as shown in the example above with \; and without space\n");
            for (i = 0; i < sd; i++)
            {
                fgets(s11, maxlen, stdin);
                slen = strlen(s11);
                s11[slen - 1] = '\0';
                slen = strlen(s11);
                s2 = simple_split(s11, slen, sep);
                names[i + n] = s2[0];
                if (s2 != NULL)
                {
                    stud0[n + i] = struct_fill(s2);
                    if (stud0[n + i] != NULL)
                    {
                        struct_out(stud0[i + n]);
                    }
                    else
                    {
                        puts("Structure not allocated!");
                        i = n;
                    }
                }
            }
            printf("\nNew list\n");

            for (i = 0; i < n + sd; i++)
                struct_out(stud0[i]);
        }

        n += sd;
        j = 0;

        printf("\nWant to find some kind of structure?\n");
        printf("Yes - 1, No - 2\n");
        scanf("%d", &ch1);
        if (ch1 == 1)
            find(names, stud0, n);

        if ((stud0 != NULL) && (kind != NULL))
            sort_struct(kind, stud0, n, count, sd);
        else puts("Unable to make functions!");

        if (kind != NULL)
        {
            free(kind);
            kind = NULL;
        }

        for (i = 0; i < n; i++)
            ClearStructure(stud0[i]);

        if (stud0 != NULL)
            {
                free(stud0);
                stud0 = NULL;
            }
    }
    else
        puts("File not found!");

    puts("Bye-bye");
    return 0;
}


void ClearStringArray(char** str, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        free(str[i]);
        str[i] = NULL;
    }
    free(str);
    str = NULL;

}

char** simple_split(char* str, int length, char sep)
{
    char** str_array = NULL;
    int i, j, k, m;
    int key, count;
    for (j = 0, m = 0; j < length; j++)
    {
        if (str[j] == sep)
            m++;
    }

    key = 0;
    str_array = (char**)malloc((m + 1) * sizeof(char*));
    if (str_array != NULL)
    {
        for (i = 0, count = 0; i <= m; i++, count++)
        {
            str_array[i] = (char*)malloc(length * sizeof(char));

            if (str_array[i] != NULL)
                key = 1;

            else
            {
                key = 0;
                i = m;
            }
        }

        if (key)
        {
            k = 0;
            m = 0;

            for (j = 0; j < length; j++)
            {
                if (str[j] != sep)
                    str_array[m][j - k] = str[j];

                else
                {
                    str_array[m][j - k] = '\0';
                    k = j + 1;
                    m++;
                }
            }
        }
        else
        {
            ClearStringArray(str_array, count);
        }
    }
    return str_array;
}

void print_header()
{
    printf("|%10s |%10s |%6s |%10s |%8s |%10s |%10s|%10s|%10s|\n", "name", "kind", "lifespan", "quantity", "weight", "height", "Species", "Countries", "Continents" );
    printf("+-----------+-----------+---------+-----------+---------+-----------+----------+----------+----------+\n");
}

void struct_out(animals *str0)
{
    printf("|%10s |%10s |  %6d |%10d |%8f |%10f |%9d |%9d |%9d |\n",
       str0 -> name, str0 -> kind, str0 -> lifespan, str0 -> quantity, str0 -> weight, str0 -> height, str0 -> numbers[0], str0 -> numbers[1], str0 -> numbers[2]);
}

animals* struct_fill(char** str)
{
    animals* str0 = NULL;

    str0 = (animals*)malloc(sizeof(animals));
    if (str0 != NULL)
    {
        str0->name = str[0];
        str0->kind = str[1];
        str0->lifespan = atoi(str[2]);
        str0->quantity = atoi(str[3]);
        str0->weight = atof(str[4]);
        str0->height = atof(str[5]);
        str0->numbers[0] = atoi(str[6]);
        str0->numbers[1] = atoi(str[7]);
        str0->numbers[2] = atoi(str[8]);
    }
    return str0;
}

float ValueLifespan(animals** str0, int i0)
{
    return str0[i0]->lifespan;
}

float ValueQuantity(animals** str0, int i0)
{
    return str0[i0]->quantity;
}

float ValueWeight(animals** str0, int i0)
{
    return (int)str0[i0]->weight;
}

float ValueHeight(animals** str0, int i0)
{
    return (int)str0[i0]->height;
}

void SortKind(int n, animals** str0, float (*funcName)(animals**, int))
{
    animals* tmp_struct;
    int i, j;

    for (i = 0; i < n; i = i + 1)
    {
        for (j = 0; j < n - i - 1; j = j + 1)
        {
            if (funcName(str0, j) > funcName(str0, j + 1))
            {
                tmp_struct = str0[j];
                str0[j] = str0[j + 1];
                str0[j + 1] = tmp_struct;
            }
        }
    }
}

void ClearStructure(animals* str0)
{
    free(str0->name);
    free(str0->kind);
    str0->name = NULL;
    str0->kind = NULL;
    free(str0);
    str0 = NULL;
}

void sort_struct(sorting *kind, animals **stud0, int n, int count, int sd)
{
        int option, i;
        kind[0] = ValueLifespan;
        kind[1] = ValueQuantity;
        kind[2] = ValueWeight;
        kind[3] = ValueHeight;

        do
        {
            printf("Kinds of sort:\n");
            printf("1 - by lifespan\n");
            printf("2 - by quantity\n");
            printf("3 - by weight\n");
            printf("4 - by Height\n");
            printf("Enter your choice: ");

            scanf("%d", &option);
        } while ((option < 1) || (option > 4));

        puts("");
        puts("Sorted array:");
        print_header();
        SortKind(n, stud0, kind[option - 1]);

        for (i = 0; i < count + sd; i++)
            struct_out(stud0[i]);
}
void find(char **names, animals **stud0, int n)
{
    int ch1, ll, schet, i, j;
    char namename[256];
    ch1 = 1;
    schet = 0;

    printf("Which name of structure that you want to find?\n");
    scanf("%s", &namename);

    ll = strlen(namename);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < ll; j++)
        {
            if (names[i][j] == namename[j])
                schet++;
        }
        if (schet == ll)
        {
            struct_out(stud0[i]);
            ch1++;
        }
        schet = 0;
    }
    if (ch1 == 1)
        printf("\nCan`t find\n");
}
