#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

    printf("Before the system call ");
    int pid = fork();
    sleep(5);
    if (pid == 0)
    {

        printf("We are in the child process");
        printf("\n");
        printf("\n");
        printf("Child Process %d", getpid());
    }

    else
    {
        printf("We are in Parent Process");
        printf("\n");
        printf("\n");
        printf("Parent Process %d", getpid());
    }

    printf("\n");

    return 0;
}