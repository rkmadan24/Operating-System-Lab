#include <stdio.h>

int main()
{
    int n,i,j;
    int pid[10],at[10],bt[10],ct[10],tat[10],wt[10];
    int finished[10]={0};
    int current_time=0,completed=0,min;
    float avg_tat=0,avg_wt=0;

    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");
    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        pid[i]=i+1;
        scanf("%d",&at[i]);
    }

    printf("Enter Burst Time:\n");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);


//Sorting according to arrival time
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                int temp;

                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
            }
        }
    }

//Scheduling
    while(completed<n)
    {
        min=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=current_time && finished[i]==0)
            {
                if(min==-1 || bt[i]<bt[min])
                    min=i;
            }
        }

        if(min==-1)
        {
            current_time++;
        }
        else
        {
            ct[min]=current_time+bt[min];
            tat[min]=ct[min]-at[min];
            wt[min]=tat[min]-bt[min];

            current_time=ct[min];

            finished[min]=1;
            completed++;

            avg_tat+=tat[min];
            avg_wt+=wt[min];
        }
    }

    printf("\nSJF Non-Preemptive Scheduling\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f",avg_tat/n);
    printf("\nAverage Waiting Time = %.2f\n",avg_wt/n);

    return 0;
}
