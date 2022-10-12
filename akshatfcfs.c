#include<stdio.h>

typedef struct process
{
    int id;
    int arr_time;
    int burst_time;
} process;

int main()
{
    process p[10];

    int n;
    printf("Enter total number of processes: ");
    scanf("%d",&n);

    for(int i=0; i<n ; i++)
    {
        printf("Enter process id, arrival time and burst time: ");
        scanf("%d%d%d",&p[i].id, &p[i].arr_time, &p[i].burst_time);
    }

    //sorting on the basis of arrival time

    for(int i=1;i<n;i++)
    {
        for(int j=0; j<n-i;j++)
        {
            if(p[j].arr_time > p[j+1].arr_time)
            {
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // creating array for waiting time and turn around time
    int wait_time[n], tat[n], comp_time[n];

    wait_time[0] = 0; // for the first process
    comp_time[0] = p[0].burst_time;
    tat[0] = comp_time[0];

    for(int i=1;i<n;i++)
    {
        wait_time[i] = comp_time[i-1] - p[i].arr_time;
        comp_time[i] = comp_time[i-1]+ p[i].burst_time;
        tat[i] = comp_time[i] - p[i].arr_time;
    }

    printf("Process id\tarrival time\tburst time\twaiting time\tcompletion time\tturn around time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].arr_time,p[i].burst_time,wait_time[i],comp_time[i],tat[i]);
    }
}