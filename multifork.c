#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    sleep(5);
    printf("Before the System Call");
    int pid = getpid();
    fork();
    fork();
    fork();
    if (pid == 0)
    {
        printf("Child Process %d", getpid());
    }
    else
    {
        printf("Parent Process %d", getpid());
    }

    printf("\n");
    return 0;
}
