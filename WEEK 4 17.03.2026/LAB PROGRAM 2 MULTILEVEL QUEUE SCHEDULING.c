#include <stdio.h>

int main()
{
    int n,i;
    int at[10],bt[10],rt[10],q[10];
    int ct[10],tat[10],wt[10];
    int tq,current_time=0,completed=0;

    float avg_tat=0,avg_wt=0;

    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }

    printf("Enter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    printf("Enter Queue Number :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);


    while(completed < n)
    {
        int executed = 0;

// FIRST: QUEUE 1 (ROUND ROBIN)
        for(i=0;i<n;i++)
        {
            if(q[i]==1 && rt[i]>0 && at[i] <= current_time)
            {
                executed = 1;

                if(rt[i] > tq)
                {
                    current_time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    current_time += rt[i];
                    rt[i] = 0;

                    ct[i] = current_time;
                    completed++;
                }
            }
        }

        if(executed == 0)
        {
            // SECOND: QUEUE 2 (FCFS)

            for(i=0;i<n;i++)
            {
                if(q[i]==2 && rt[i]>0 && at[i] <= current_time)
                {
                    current_time += rt[i];
                    rt[i] = 0;

                    ct[i] = current_time;
                    completed++;

                    executed = 1;
                    break;
                }
            }
        }


        if(executed == 0)
            current_time++;
    }

// calculating average TAT and WT
    for(i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nProcess\tQ\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,q[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f",avg_tat/n);
    printf("\nAverage Waiting Time = %.2f\n",avg_wt/n);

    return 0;
}
