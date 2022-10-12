#include <stdio.h>

struct process{
  int pr,at,bt;
};


int main()
{

  int n;
  struct process temp;

  //total process
  printf("Enter the total no. of process: ");
  scanf("%d",&n);

  //array of structures and input
  struct process p[n];
  for(int i=0 ; i<n ; i++)
  {
    printf("Enter the process, arrival time and burst time of process: ");

    scanf("%d %d %d",&p[i].pr,&p[i].at,&p[i].bt);
  }

  //display of array of structures
  // for(int i=0 ; i<n ; i++)
  // {
  //   printf("%d . %d %d \n",p[i].pr,p[i].at,p[i].bt);
  // }

  // sorting on basis of at
  for(int i=0 ; i<n ; i++)
  {
    for(int j=i+1 ; j<n ; j++)
    {
      if(p[i].at>p[j].at)
      {
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
      }
    }
  }

  //calculating start time and completion time
  int i=0;
  int st[n],ct[n];
  st[i]=p[i].at;
  ct[i]=p[i].bt;

  for(i=1 ; i<n ; i++)
  {
    if(ct[i-1]>=p[i].at)
    {
      st[i]=ct[i-1];
      ct[i]=p[i].bt + ct[i-1];
    }
    else
    {
      st[i]=p[i].at;
      ct[i]=p[i].bt+st[i];
    }
  }

  printf("\n\nThe process, arrival time, burst time, start time and completion time are :\n");
  for(i=0 ; i<n ; i++)
  {
    printf("P%d %d %d %d %d\n",p[i].pr,p[i].at,p[i].bt,st[i],ct[i] );
  }

  //to calculate avg RT,TAT and WT
  float totRt=0,totTat=0,totWt=0;
  int btt=0;
  for(i=0 ; i<n ; i++)
  {
    totRt+=st[i]-p[i].at;
    totTat+=ct[i]-p[i].at;
    btt+=p[i].bt;
  }
  totWt=totTat-btt;

  printf("Average resonse time: %f\n",totRt/n);
  printf("Average through put time: %f\n",totTat/n);
  printf("Average waiting time: %f\n",totWt/n);

return 0;
}