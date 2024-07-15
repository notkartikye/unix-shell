#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Type a directory name.");
        exit(1);
    }
    else if (argc >= 3 && strcmp(argv[2], "-v") != 0)
    {
        int i = 2;
        int a;
        for(; i < argc; i++)
        {
            a = mkdir(argv[i], 0777);
            if (a != 0)
            {
                printf("Unable to create directory.\n Directory may already exist\n");
                exit;
            }
            else
            {
                continue;
            }   
        }
    }
    else if (argc >= 4 && strcmp(argv[2], "-v") == 0)
    {
        int i = 3;
        int a;
        for(; i < argc; i++)
        {
            a = mkdir(argv[i], 0777);
            if (a == 0)
            {
                printf("Directory created: '%s'\n", argv[i]);
            }
            else
            {
                printf("Directory already exist.");
                exit(1);
            }   
        }
    }
}
