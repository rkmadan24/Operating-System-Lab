#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], rt[n];
    float avg_tat = 0, avg_wt = 0, avg_rt = 0;

    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = wt[i];   // FCFS: RT = WT

        avg_tat += tat[i];
        avg_wt += wt[i];
        avg_rt += rt[i];
    }

    avg_tat /= n;
    avg_wt /= n;
    avg_rt /= n;

    printf("\nProcess\tAT\tBT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Response Time = %.2f", avg_rt);

    return 0;
}


