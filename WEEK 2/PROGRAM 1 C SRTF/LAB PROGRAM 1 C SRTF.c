#include <stdio.h>

int main()
{
    int n,i,time=0,completed=0;
    int pid[10],at[10],bt[10],rt[10];
    int ct[10],tat[10],wt[10];
    int idx,min_rt;
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

    while(completed<n)
    {
        idx=-1;
        min_rt=9999;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0 && rt[i]<min_rt)
            {
                min_rt=rt[i];
                idx=i;
            }
        }

        if(idx==-1)
        {
            time++;
        }
        else
        {
            rt[idx]--;
            time++;

            if(rt[idx]==0)
            {
                ct[idx]=time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];

                avg_tat+=tat[idx];
                avg_wt+=wt[idx];
                completed++;
            }
        }
    }

    printf("\nSJF Preemptive Scheduling (SRTF)\n");
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
