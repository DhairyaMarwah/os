#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    printf("Sum of Odd and Even Numbers\n");
    int a;
    printf("Enter the Number : ");
    scanf("%d", &a);
    int pid = fork();
    if (pid == 0)
    {
        int sum = 0;
        for (int i = 0; i < a; i += 2)
            sum += i;
        printf("Child :->%d", sum);
    }
    else
    {
        int sum1 = 0;
        for (int i = 1; i < a; i += 2)
        {
            sum1 += i;
        }
        printf("Parent :->%d", sum1);
    }
    printf("\n");
    return 0;
}