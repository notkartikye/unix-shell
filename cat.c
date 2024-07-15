#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *f = NULL;
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            printf("Couldnot open file...");
            exit(1);
        }
        char a;
        a = fgetc(f);
        while(a != EOF)
        {
            printf("%c", a);
            a = fgetc(f);
        }
    }
    else if (argc == 3 && strcmp(argv[1], "-n") == 0)
    {
        FILE *f = NULL;
        f = fopen(argv[2], "r");
        if (f == NULL)
        {
            printf("Could not open file...");
            exit(1);
        }
        char a;
        a = fgetc(f);
        printf("1)");
        int i = 1;
        while(a != EOF)
        {
            if (a  == '\n')
            {
                i++;
                printf("%c", a);
                printf("%d)", i);
                a=fgetc(f);
            }
            printf("%c", a);
            a = fgetc(f);
        }
        printf("\n");
    }
    else if (argc == 3&& strcmp(argv[1], "-e") == 0)
    {
        FILE *f = NULL;
        f = fopen(argv[2], "r");
        if (f == NULL)
        {
            printf("Couldnot open file...");
            exit(1);
        }
        char a;
        a = fgetc(f);
        
        int i = 1;
        while(a != EOF)
        {
            if (a == '\n')
            {
                printf(" $");
                printf("%c", a);
                a=fgetc(f);

            }
            printf("%c", a);
            a = fgetc(f);
        }
        printf("\n");
    }
    else
    {
        printf("Inavalid syntax");
        exit(1);
    }
}