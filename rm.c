#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
    if (argc <= 2)
    {
        printf("Enter some file arguments");
    }
    else if (argc == 3 && strcmp(argv[2], "-i") != 0 &&strcmp(argv[2], "-f") != 0)
    {
        FILE *f = NULL;
        f = fopen(argv[2], "w");
        if (f == NULL)
        {
            printf("File is write protected or File is not available");
            exit(1);
        }
        int y = remove(argv[2]);
        if (y != 0)
        {
            printf("Error occured");
            exit(1);
        }
    }
    else if (argc == 4 && strcmp(argv[2], "-i") == 0)
    {
        char c;
        printf("You want to remove filename:%s (y/n)?", argv[3]);
        scanf("%c", &c);
        if (c == 'y')
        {
            FILE *f = NULL;
            f = fopen(argv[3], "w");
            if (f == NULL)
            {
                printf("File is write protected or File not availbale \n");
                exit(1);
            }
            int y=remove(argv[3]);
            if (y != 0)
            {
                printf("Error occured");
                exit(1);
            }
        }
        else if (c == 'n')
        {
            exit(0);
        }
        else{
            printf("Inavlid input");
        } 
    }
    else if (argc == 4 && strcmp(argv[2], "-v") == 0)
    {
        FILE *f = NULL;
        f = fopen(argv[3], "w");
        if (f == NULL)
        {
            printf("File is write protected or File is not available");
            exit(1);
        }
        int y=remove(argv[3]);
        if (y != 0)
        {
            printf("Error occured");
            exit(1);
        }
        printf("File : %s removed..", argv[3]);   
    }
}
