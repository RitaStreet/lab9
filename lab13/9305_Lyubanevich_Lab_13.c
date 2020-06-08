#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct SHOP
{
    char *Name; //название товара
    int price:32; //цена
    char *country; //страна производства
    unsigned short existance:1; //наличие в магазине
    unsigned short standart:1; //соответствие стандартам РФ
    unsigned short top:1; //товар месяца
};
typedef  struct SHOP SHOP;

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

char **simple_split(char *str, int length, char sep)
{
    char **str_array=NULL;
    int i,j,k,m;
    int key,count;
    for(j=0,m=0;j<length;j++)
    {
        if(str[j]==sep) m++;
    }

    key=0;
    str_array=(char**)malloc((m+1)*sizeof(char*));
    if(str_array!=NULL)
    {
        for(i=0,count=0;i<=m;i++,count++)
        {
            str_array[i]=(char*)malloc(length*sizeof(char));
            if(str_array[i]!=NULL) key=1;
            else
            {
                key=0;
                i=m;
            }
        }
        if(key)
        {
            k=0;
            m=0;
            for(j=0;j<length;j++)
            {
                if(str[j]!=sep) str_array[m][j-k]=str[j];
                else
                {
                    str_array[m][j-k]='\0';
                    k=j+1;
                    m++;
                }
            }
            str_array[m][j-k]='\0';
        }
        else
        {
            clear_str_array(str_array,count);
        }
     }
     return str_array;
}

void new_gets(char *s, int lim)
{
    char c;
    int i;
    i=0;
    while(((c=getchar())!='\n')&&(i<lim-1))
    {
        s[i]=c;
        i++;
    }
    s[i]='\0';
}

char **add()
{
    enum {maxlen=128};
    char *s11=NULL;
    char *s12=NULL;
    char *s13=NULL;
    char *s14=NULL;
    char *s15=NULL;
    char *s16=NULL;
    char **s2=NULL;
    s11=(char*)malloc(maxlen*sizeof(char));
    s12=(char*)malloc(maxlen*sizeof(char));
    s13=(char*)malloc(maxlen*sizeof(char));
    s14=(char*)malloc(maxlen*sizeof(char));
    s15=(char*)malloc(maxlen*sizeof(char));
    s16=(char*)malloc(maxlen*sizeof(char));
    s2=(char**)malloc(7*sizeof(char*));
    printf("Name:\n>");
    new_gets(s11, maxlen);
    s2[0]=(char*)malloc((strlen(s11))*sizeof(char));
    strcpy(s2[0],s11);
    printf("Name is %s\n", s2[0]);
    printf("Price:\n>");
    new_gets(s12, maxlen);
    s2[1]=(char*)malloc((strlen(s12))*sizeof(char));
    strcpy(s2[1],s12);
    printf("Price is %s\n",s2[1]);
    printf("Country:\n>");
    new_gets(s13, maxlen);
    s2[2]=(char*)malloc((strlen(s13))*sizeof(char));
    strcpy(s2[2],s13);
    printf("country is %s\n",s2[2]);
    printf("presence or not:\n>");
    new_gets(s14, maxlen);
    s2[3]=(char*)malloc((strlen(s14))*sizeof(char));
    strcpy(s2[3],s14);
    printf("presence is %s\n",s2[3]);
    printf("Standart or not:\n>");
    new_gets(s15, maxlen);
    s2[4]=(char*)malloc((strlen(s15))*sizeof(char));
    strcpy(s2[4],s15);
    printf("Standart is %s\n",s2[4]);
    printf("Top or not :\n>");
    new_gets(s16, maxlen);
    s2[5]=(char*)malloc((strlen(s16))*sizeof(char));
    strcpy(s2[5],s16);
    printf("top is %s\n",s2[5]);
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
    free(s16);
    s16=NULL;
    return s2;
}

SHOP *fill_prod(char **str)
{
    SHOP *str0 = NULL;
    int t;
    t = 0;
    str0 = (SHOP*)malloc(sizeof(SHOP));
    if((str0 != NULL))
    {
        str0 -> Name = str[0];
        str0 -> price = atof(str[1]);
        str0 -> country = (str[2]);
        str0 -> existance = atof(str[3]);
        str0 -> standart = atof(str[4]);
        str0 -> top = atof(str[5]);
    }
    return str0;
}

void struct_out (SHOP *str0)
{
    printf("|%12s | %5d | %10s | %2d | %2d | %2d |\n", str0 -> Name, str0 -> price, str0 -> country, str0 -> existance, str0 -> standart, str0 -> top);
}


int main()
{
    enum {maxlen = 128,M = 100};
    int n, count, i, slen, num, f, par;
    char s1[maxlen], **s2;
    char sep;
    SHOP **PROD = NULL;
    FILE *df;
    sep = ';';
    f = 5;
    df = fopen("csv.txt","r");
    if(df != NULL)
    {
        n = 0;
        while((fgets(s1, maxlen, df))!= NULL) n++;
        {
            rewind(df);
            PROD = (SHOP**)malloc(M * sizeof(SHOP*));
            if(PROD != NULL)
            {
                for(i = 0, count = 0; i < n; i++, count++)
                {
                    fgets(s1, maxlen, df);
                    slen = strlen(s1);
                    s1[slen - 1] = '\0';
                    slen = strlen(s1);
                    s2 = simple_split(s1, slen, sep);
                    if(s2 != NULL)
                    {
                        PROD[i] = fill_prod(s2);
                        if(PROD[i] != NULL) struct_out(PROD[i]);
                        if(PROD[i] == NULL)
                        {
                            i=n;
                        }
                    }
                }
            }
        }
        fclose(df);
        par = n;
        puts("HOW MANY PRODUCTS ARE YOU ABOUT TO ADD?");
        scanf("%d", &num);
        f = f + num;
        getchar();
        for (i = 0; i < num; i++)
        {
            printf("Product number %d:\n", i + 1);
            s2 = add();
            PROD[par] = fill_prod(s2);
            printf("Product is %d in the list of all products\n", par+1);
            par = par+1;
        }
        puts("Here's your array:");
        for(i = 0; i < par; i++)
        {
            struct_out(PROD[i]);
        }
        puts("THERE ARE PRODUCTS WICH DON'T MEET THE STANDART, BUT THEY ARE IN THE STOCK:");
        for (i = 0; i < f; i++)
        {
            if((PROD[i]->existance == 1)&&(PROD[i] -> standart == 0))
            {
                struct_out(PROD[i]);
            }
        }
        if(PROD != NULL)
        {
            free(PROD);
            PROD = NULL;
        }
    }
}
