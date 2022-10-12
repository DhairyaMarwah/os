#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    printf("Before the fork system call");
    printf("\n");
    int pid = fork();
    if (pid)
    {
        sleep(10); // sleep for 10 sec
        printf("We are in Parent Process ");
        printf("\n");
        printf("Parent Prcoess ID %d", getpid());
        printf("\n");
    }
    else
    {

        printf("We are in child process");
        printf("\n");
        printf("Child Process ID %d", getpid());
        printf("\n");
    }
    printf("\n");
    return 0;
}