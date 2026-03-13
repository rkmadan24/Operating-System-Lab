#include <stdio.h>

int main()
{
    int n,i;
    int pid[10],at[10],bt[10],pr[10];
    int ct[10],tat[10],wt[10];
    int finished[10]={0};
    int current_time=0,completed=0,max;
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

    printf("Enter Priority:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pr[i]);

    while(completed<n)
    {
        max=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=current_time && finished[i]==0)
            {
                if(max==-1 || pr[i]>pr[max])
                    max=i;
            }
        }

        if(max==-1)
            current_time++;
        else
        {
            ct[max]=current_time+bt[max];
            tat[max]=ct[max]-at[max];
            wt[max]=tat[max]-bt[max];

            current_time=ct[max];

            finished[max]=1;
            completed++;

            avg_tat+=tat[max];
            avg_wt+=wt[max];
        }
    }

    printf("\nPriority Scheduling (Higher number = Higher priority)\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        {
            printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            pid[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
        }  
        

    printf("\nAverage Turnaround Time = %.2f",avg_tat/n);
    printf("\nAverage Waiting Time = %.2f\n",avg_wt/n);

    return 0;
}


