#include <stdio.h>

int main()
{
    int n,i;
    int pid[10],at[10],bt[10],rt[10];
    int ct[10],tat[10],wt[10];
    int tq,current_time=0,completed=0;
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

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int done;
    while(completed<n)
    {
        done=1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=current_time && rt[i]>0)
            {
                done=0;

                if(rt[i] > tq)
                {
                    current_time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    current_time += rt[i];
                    rt[i]=0;

                    ct[i]=current_time;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];

                    completed++;

                    avg_tat+=tat[i];
                    avg_wt+=wt[i];
                }
            }
        }

        if(done==1)
        {
           current_time++;
        }

    }

    printf("\nRound Robin Scheduling\n");
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



