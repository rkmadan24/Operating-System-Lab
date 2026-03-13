#include <stdio.h>

int main()
{
    int n,i;
    int pid[10],at[10],bt[10],pr[10],rt[10];
    int ct[10],tat[10],wt[10];
    int completed=0,current_time=0,min;
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
    {
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    printf("Enter Priority:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pr[i]);

    while(completed<n)
    {
        min=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=current_time && rt[i]>0)
            {
                if(min==-1 || pr[i] < pr[min])
                    min=i;
            }
        }

        if(min==-1)
            current_time++;
        else
        {
            rt[min]--;
            current_time++;

            if(rt[min]==0)
            {
                ct[min]=current_time;
                tat[min]=ct[min]-at[min];
                wt[min]=tat[min]-bt[min];

                completed++;

                avg_tat+=tat[min];
                avg_wt+=wt[min];
            }
        }
    }

    printf("\nPriority Scheduling (Preemptive) Higher the Number, Higher the Priority\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

    printf("\nAverage Turnaround Time = %.2f",avg_tat/n);
    printf("\nAverage Waiting Time = %.2f\n",avg_wt/n);

    return 0;
}


