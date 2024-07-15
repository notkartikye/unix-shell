#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void printCurrentTime(time_t t) {
    printf("Current time:%s", ctime(&t));
}

int main(int argc, char *argv[]) {
    if(argc == 2)
    {
        time_t Time;
        time(&Time);
        printCurrentTime(Time);
    }
    else
    {
        printf("Invalid Syntax or Arguments passed\n");
        exit(1);
    }
}