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
