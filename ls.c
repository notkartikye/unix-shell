#include<stdio.h>
#include<errno.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        struct dirent *dir;
        DIR *d=opendir(".");
        if (!d)
        {
            printf("Directory does not exist");
            exit(1);

        }
        dir = readdir(d);
        while(dir != NULL)
        {
            printf("%s ", dir->d_name);
            dir = readdir(d);
        }
    }
    else if (argc  ==  3 && argv[2][0] != '-')
    {
        struct dirent *dir;
        DIR *d=opendir(argv[2]);
        if (!d)
        {
            printf("Directory doesnot exist");
            exit(1);

        }
        dir = readdir(d);
        while(dir != NULL)
        {
            printf("%s ", dir->d_name);
            dir = readdir(d);
        }
    }
    else if (argc == 3 && strcmp(argv[2], "-1") == 0)
    {
        struct dirent *dir;
        DIR *d=opendir(".");
        if (!d)
        {
            printf("Directory doesnot exist");
            exit(1);

        }
        dir = readdir(d);
        while(dir != NULL)
        {
            printf("%s \n", dir->d_name);
            dir = readdir(d);
        }

    }
    else if (argc  == 3 && strcmp(argv[2], "-Q") == 0)
    {
        struct dirent *dir;
        DIR *d=opendir(".");
        if (!d)
        {
            printf("Directory doesnot exist");
            exit(1);

        }
        dir = readdir(d);
        while(dir != NULL)
        {
            printf("\"%s\" ", dir->d_name);
            dir = readdir(d);
        }
    }
    else if (argc == 4 && strcmp(argv[2], "-1") == 0 && argv[3][0] != '-')
    {
        struct dirent *dir;
        DIR *d=opendir(argv[3]);
        if (!d)
        {
            printf("Directory doesnot exist");
            exit(1);

        }
        dir = readdir(d);
        while(dir != NULL)
        {
            printf("%s \n", dir->d_name);
            dir = readdir(d);
        }
    }
    else if (argc == 4 && strcmp(argv[2], "-Q") == 0 && argv[3][0] != '-')
    {
        struct dirent *dir;
        DIR *d=opendir(argv[3]);
        if (!d)
        {
            printf("Directory doesnot exist");
            exit(1);

        }
        dir = readdir(d);
        while(dir != NULL)
        {
            printf("\"%s\" ", dir->d_name);
            dir = readdir(d);
        }

    }
    else
    {
        printf("Invalid Syntax");
    }
}

