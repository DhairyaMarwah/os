#include <stdio.h>

struct process{
  int pr,at,bt;
};


int main()
{
  int n;
  int i=0;
  struct process temp;

  //total process
  printf("Enter the total no. of process: ");
  scanf("%d",&n);

  //array of structures and input
  struct process p[n];
  for(i=0 ; i<n ; i++)
  {
    printf("Enter the arrival time and burst time of process %d: ",i+1);
    p[i].pr=i+1;
    scanf("%d %d",&p[i].at,&p[i].bt);
  }

  for(i=1 ; i<n ; i++)
  {
    if(p[i].at<p[0].at)
    {
      temp=p[i];
      p[i]=p[0];
      p[0]=temp;
    }
  }
  //to start from least arrival time
  for(int i=0 ; i<n ; i++)
  {
    printf("%d . %d %d \n",p[i].pr,p[i].at,p[i].bt);
  }

  //sort according to burst time
  for(int i=1 ; i<n ; i++)
  {
    for(int j=i+1 ; j<n ; j++)
    {
      if(p[i].bt<p[j].bt)
      {
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
      }
    }
   }


   //calculating start time and completion time
   int st[n],ct[n];
   i=0;
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

   printf("\nThe process, arrival time, burst time, start time and completion time are :\n");
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

   printf("\nAverage resonse time: %f\n",totRt/n);
   printf("Average through put time: %f\n",totTat/n);
   printf("Average waiting time: %f\n",totWt/n);


   return 0;

}