#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<dirent.h>

void printdirectories()
{
    system("dir");
}

void printDirectory(char *argv[], int argc)
{
    if (argc == 2)
    {
        char st[100];
        if (getcwd(st, 100) == NULL)
        {
            printf("could not fetch the directory\n");
            exit(1);
        }
        printf("Current directory:%s\n", getcwd(st, 100));
    }
    else
    {
        char st[100];
        printf("Current directory:%s\n", getcwd(st, 100));
    }
}
void changeDirectory( char *argv[] )
{
    if (strcmp(argv[2], "..") == 0)
    {
        char di[100];
        chdir("..");
        printf("Directory changed to %s", getcwd(di, 100));
    }
    else
    {
        if (chdir(argv[2]) != 0)
        {
            printf("Error occured");
            exit(1);
        }
        else
        {
            char st [100];
            chdir(argv[2]);
            printf("Directory changed to: %s", getcwd(st, 100));
        }
    }
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Enter some arguments");
    }
    else
    {
        // command for echo(internal command);
        if (strcmp(argv[1], "echo") == 0)
        {
            if (argc == 2)
            {
                printf("Enter something to print");
                exit(1);
            }
            if (argc >= 3 && argv[2][0] != '-')
            {
                int x = 2;
                for(; x<argc; x++)
                {
                    printf("%s ", argv[x]);
                }
                printf("\n");

            }
            else if (argc >= 4 && strcmp(argv[2], "-n") == 0)
            {
                int x = 3;
                for(; x<argc; x++)
                {
                    printf("%s ", argv[x]);
                }
                
            }
            else if (argc >= 4 && strcmp(argv[2], "-E") == 0)
            {
                int x = 3;
                for(; x<argc; x++)
                {
                    if (argv[x][0] == '\\')
                    {
                        char c1='\\';
                        char c2=argv[x][0];
                        printf("%c%c", c1, c2);
                    }
                    else
                    {
                        printf("%s ", argv[x]);
                    }
                }
            }
            else
            {
                printf("Invalid syntax");
            }
        }
        
        if (strcmp(argv[1], "cd") == 0)
        {
            if (argc == 2)
            {
                printf("");
            }
            else if (strcmp(argv[2], "..") == 0)
            {
                // change to parent directory;  
                changeDirectory(argv);
            }
            else if (strcmp(argv[2], "..") != 0)
            {
                // change to given directory;
                changeDirectory(argv);
            }
        }
        if (strcmp(argv[1], "pwd") == 0)
        {
            // print current directery
            if (argc == 2)
            {
                //print current directory..
                printDirectory(argv, argc);
            }
            
            else if (argc == 3 && strcmp(argv[2], "-L"))
            {
                //print current directory...
                printDirectory(argv, argc);
            }
            else if (argc == 3 && strcmp(argv[2], "-P"))
            {
                //print current directory...
                printDirectory(argv, argc);
            }

            else
            {
                printf("Invalid arguments...\n");
                exit(1);
            }
        }
        if (strcmp(argv[1], "cat") == 0 && strcmp(argv[argc-1], "&t") != 0)
        {
            int x=fork();
            if (x < 0)
            {
                printf("Fork failed");
                exit(1);
            }
            else if (x == 0)
            {
                if (argc == 3)
                {
                    execl("/home/sushane/assignment/sus/cat", "cat", argv[2], NULL);
                }
                else if (argc == 4)
                {
                    execl("/home/sushane/assignment/sus/cat", "cat", argv[2], argv[3], NULL);
                }
                else
                {
                    printf("Invalid sysntax");
                    exit(1);
                }
                

            }
            else
            {
                int x_wait=wait(NULL);
            }

        }
        if (strcmp(argv[1], "cat") == 0 && strcmp(argv[argc-1], "&t") == 0)
        {
            if (argc == 3)
            {
                printf("Enter some files..");
            }
            else if (argc == 4 && argv[2][0] != '-')
            {
                pthread_t p;
                char args[100]="/home/sushane/assignment/sus/cat cat %s", argv[2];
                int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                pthread_join(p, NULL);
            }
            else if (argc == 5 && strcmp(argv[2], "-n") == 0)
            {
                pthread_t p;
                char args[100]="/home/sushane/assignment/sus/cat cat -n %s", argv[3];
                int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                pthread_join(p, NULL);

            }
            else if (argc == 5 && strcmp(argv[2], "-e") == 0)
            {
                pthread_t p;
                char args[100]="/home/sushane/assignment/sus/cat cat -e %s", argv[3];
                int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                pthread_join(p, NULL);
            }
            else
            {
                printf("Invalid syntax");
            }
        }
        if (strcmp(argv[1], "mkdir") == 0 && strcmp(argv[argc-1], "&t") != 0)
        {
            if (argc < 2)
            {
                printf("Enter a directory name");
                exit(1);
            }
            else if (argc >= 3 && strcmp(argv[2], "-v") != 0)
            {
               for(int i=2;i < argc;i++)
               {
                    int x=fork();
                
                    if (x < 0)
                    {
                        printf("Fork failed");
                        exit(1);
                    }
                    else if (x == 0)
                    {
                        execl("/home/sushane/assignment/sus/mkdir", "./mkdir", "mkdir", argv[i], NULL);

                }
                    else
                    {
                        int x_wait=wait(NULL);
                    }
                    

                }
                system("dir");

            }
            else if (argc >= 4&& strcmp(argv[2], "-v") == 0)
            {
                for(int i=3;i < argc;i++)
                {
                    int x=fork();
                
                    if (x < 0)
                    {
                        printf("Fork failed");
                        exit(1);
                    }
                    else if (x == 0)
                    {
                        execl("/home/sushane/assignment/sus/mkdir", "./mkdir", "mkdir", "-v", argv[i], NULL);

                }
                    else
                    {
                        int x_wait=wait(NULL);
                    }
                    

                }
                system("dir");
                
                 

            }
            else
            {
                printf("Invalid syntax...");
                exit(1);
            }
        }
        if (strcmp(argv[1], "mkdir") == 0 && strcmp(argv[argc-1], "&t") == 0)
        {
            if (argc == 3)
            {
                printf("Invalid syntax");
                exit(1);

            }
            else if (argc >= 4 && argv[2][0] != '-')
            {
                for(int i=2;i < argc-1;i++)
                {
                    pthread_t p;
                    char args[100]="/home/sushane/assignment/sus/mkdir ./mkdir mkdir %s", argv[i];
                    int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                    pthread_join(p, NULL);

                }
            }
            else if (argc >= 5 && strcmp(argv[2], "-v") == 0)
            {
                for(int i=3;i < argc-1;i++)
                {
                    pthread_t p;
                    char args[100]="/home/sushane/assignment/sus/mkdir ./mkdir mkdir -v %s", argv[i];
                    int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                    pthread_join(p, NULL);

                }
                
            }
            else
            {
                printf("Invalid syntax");
            }
        }
        if (strcmp(argv[1], "date") == 0 && strcmp(argv[argc-1], "&t") != 0)
        {
            if (argc == 2)
            {
                int x=fork();
                if (x < 0)
                {
                    printf("Fork failed");
                    exit(1);
                
                }
                else if (x == 0)
                {
                    execl("/home/sushane/assignment/sus/date", "./date", "date", NULL);
                }
                else
                {
                    int x_wait=wait(NULL);
                }

            }
            else
            {
                printf("Invalid Syntax");
                exit(1);
            }
        }
        if (strcmp(argv[1], "date") == 0 && strcmp(argv[argc-1], "&t") == 0)
        {
            if (argc == 3)
            {
                pthread_t p;
                    char args[100]="/home/sushane/assignment/sus/date ./date date";
                    int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                    pthread_join(p, NULL);
                
            }
            else
            {
                printf("Invalid syntax");
            }
        }
        if (strcmp(argv[1], "rm") == 0 && strcmp(argv[argc-1], "&t") != 0)
        {
            if (argc == 2)
            {
                printf("Enter some arguments");
                exit(1);

            }
            else if (argc >= 3 && strcmp(argv[2], "-i") != 0 && strcmp(argv[2], "-f") != 0 && argv[2][0] != '-')
            {
                for(int i=2;i < argc;i++)
                {
                    int x= fork();
                    if (x < 0)
                    {
                        printf("Fork failed");
                    }
                    else if (x == 0)
                    {
                        execl("/home/sushane/assignment/sus/rm", "./rm", "rm", argv[i], NULL);
                    }
                    else
                    {
                        int x_wait=wait(NULL);
                    }
                }
            }
            else if (argc >= 4 && strcmp(argv[2], "-i") == 0 && strcmp(argv[2], "-v") != 0)
            {
                for(int i=3;i < argc;i++)
                {
                    int x= fork();
                    if (x < 0)
                    {
                        printf("Fork failed");
                    }
                    else if (x == 0)
                    {
                        execl("/home/sushane/assignment/sus/rm", "./rm", "rm", "-i", argv[i], NULL);
                    }
                    else
                    {
                        int x_wait=wait(NULL);
                    }
                }
            }
            else if (argc >= 4 && strcmp(argv[2], "-i") != 0 && strcmp(argv[2], "-v") == 0)
            {
                for(int i=3;i < argc;i++)
                {
                    int x= fork();
                    if (x < 0)
                    {
                        printf("Fork failed");
                    }
                    else if (x == 0)
                    {
                        execl("/home/sushane/assignment/sus/rm", "./rm", "rm", "-v", argv[i], NULL);
                    }
                    else
                    {
                        int x_wait=wait(NULL);
                    }
                }

            }
            else
            {
                printf("Inavlid syntax");
            }
        }
        if (strcmp(argv[1], "rm") == 0 && strcmp(argv[argc-1], "&t") == 0)
        {
            if (argc == 3)
            {
                printf("Enter some arguments..");
                exit(1);
            }
            else if (argc >= 4 && argv[2][0] != '-')
            {
                for(int i=2;i < argc-1;i++)
                {
                    pthread_t p;
                    char args[100]="/home/sushane/assignment/sus/rm ./rm rm %s", argv[i];
                    int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                    pthread_join(p, NULL);

                }


            }
            else if (argc >= 5 && strcmp(argv[2], "-i") == 0)
            {
                for(int i=3;i < argc-1;i++)
                {
                    pthread_t p;
                    char args[100]="/home/sushane/assignment/sus/rm ./rm rm -i %s", argv[i];
                    int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                    pthread_join(p, NULL);

                }
                
                
            }
            else if (argc >= 5 && strcmp(argv[2], "-v") == 0)
            {
                for(int i=3;i < argc-1;i++)
                {
                    pthread_t p;
                    char args[100]="/home/sushane/assignment/sus/rm ./rm rm -v %s", argv[i];
                    int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                    pthread_join(p, NULL);

                }
                
                
            }
            else
            {
                printf("Invalid syntax");
                exit(1);
            }
        }
        if (strcmp(argv[1], "ls") == 0 && strcmp(argv[argc-1], "&t") != 0)
        {
            if (argc == 2)
            {
                int x= fork();
                if (x < 0)
                {
                    printf("Fork failed");
                    exit(1);
                }
                else if (x == 0)
                {
                    execl("/home/sushane/assignment/sus/ls", "./ls", "ls", NULL);

                }
                else
                {
                    int x_wait=wait(NULL);
                }

            }
            else if (argc  ==  3 && argv[2][0] != '-')
            {
                int x= fork();
                if (x < 0)
                {
                    printf("Fork failed");
                    exit(1);
                }
                else if (x == 0)
                {
                    execl("/home/sushane/assignment/sus/ls", "./ls", "ls", argv[2], NULL);

                }
                else
                {
                    int x_wait=wait(NULL);
                }

            }
            else if (argc == 3 && strcmp(argv[2], "-1") == 0)
            {
                int x= fork();
                if (x < 0)
                {
                    printf("Fork failed");
                    exit(1);
                }
                else if (x == 0)
                {
                    execl("/home/sushane/assignment/sus/ls", "./ls", "ls", "-1", NULL);

                }
                else
                {
                    int x_wait=wait(NULL);
                }

            }
            else if (argc  == 3 && strcmp(argv[2], "-Q") == 0)
            {
                int x= fork();
                if (x < 0)
                {
                    printf("Fork failed");
                    exit(1);
                }
                else if (x == 0)
                {
                    execl("/home/sushane/assignment/sus/ls", "./ls", "ls", "-Q", NULL);

                }
                else
                {
                    int x_wait=wait(NULL);
                }

            }
            else if (argc == 4 && strcmp(argv[2], "-1") == 0 && argv[3][0] != '-')
            {
                int x= fork();
                if (x < 0)
                {
                    printf("Fork failed");
                    exit(1);
                }
                else if (x == 0)
                {
                    execl("/home/sushane/assignment/sus/ls", "./ls", "ls", "-1", argv[3], NULL);

                }
                else
                {
                    int x_wait=wait(NULL);
                }

            }
            else if (argc == 4 && strcmp(argv[2], "-Q") == 0 && argv[3][0] != '-')
            {
                int x= fork();
                if (x < 0)
                {
                    printf("Fork failed");
                    exit(1);
                }
                else if (x == 0)
                {
                    execl("/home/sushane/assignment/sus/ls", "./ls", "ls", "-Q", argv[3], NULL);

                }
                else
                {
                    int x_wait=wait(NULL);
                }

            }
            else
            {
                printf("Inavalid syntax");
                exit(1);
            }
        
        }
        if (strcmp(argv[1], "ls") == 0 && strcmp(argv[argc-1], "&t") == 0)
        {
            if (argc == 3)
            {
                pthread_t p;
                char args[100]="/home/sushane/assignment/sus/ls ./ls ls";
                int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                pthread_join(p, NULL);

            }
            else if (argc == 4 && argv[2][0] != '-')
            {
                pthread_t p;
                char args[100]="/home/sushane/assignment/sus/ls ./ls ls %s", argv[2];
                int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                pthread_join(p, NULL);

            }
            else if (argc == 4 && strcmp(argv[2], "-1") == 0)
            {
                pthread_t p;
                char args[100]="/home/sushane/assignment/sus/ls ./ls ls -1";
                int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                pthread_join(p, NULL);
            }
            else if (argc == 4 && strcmp(argv[2], "-Q") == 0)
            {
                pthread_t p;
                char args[100]="/home/sushane/assignment/sus/ls ./ls ls -Q";
                int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                pthread_join(p, NULL);
                
            }
            
            else if (argc == 5 && strcmp(argv[2], "-1") == 0)
            {
                pthread_t p;
                char args[100]="/home/sushane/assignment/sus/ls ./ls ls -1 %s", argv[3];
                int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                pthread_join(p, NULL);
            }
            
            else if (argc == 5 && strcmp(argv[2], "-Q") == 0)
            {
                pthread_t p;
                char args[100]="/home/sushane/assignment/sus/ls ./ls ls -Q %s", argv[3];
                int x= pthread_create(&p, NULL, (void*)(*system), (void*)args);
                pthread_join(p, NULL);
            }
            else
            {
                printf("Invalid Syntax");
            }
        }   
    }
}