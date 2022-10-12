#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    printf("Before the fork system call");
    printf("\n");
    sleep(5);
    int pid = fork();
    if (pid)
    {
        printf("RESOLVED");
        wait(NULL);
        printf("We are in Parent Process ");
        printf("Parent Prcoess ID %d", getpid());
    }
    else
    {
        printf("We are in child process");
        printf("\n");
        printf("Child Process ID %d", getpid());
        printf("\n");
    }
    return 0;
}