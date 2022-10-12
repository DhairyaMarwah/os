#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int a, b, c;
    printf("Before the fork system call");
    int pid = fork();
    if (pid == 0)
    {
        sleep(10);
        printf("Child Process : %d", getpid());
        printf("Enter a number");
        scanf("%d", &a);
        if (a % 2 == 0)
            printf("Even Number\n");
        else
            printf("Odd Number");
    }
    else
    {
        printf("Parent Process : %d", getpid());
        printf("calculating the larger of the two numbers ");
        printf("Enter the two numbers : ");
        scanf("%d%d", &b, &c);
        if (b > c)
            printf("Larger of the two numbers is : %d", b);
        else
            printf("Larger of the two numbers is : %d", c);
    }
    return 0;
}
