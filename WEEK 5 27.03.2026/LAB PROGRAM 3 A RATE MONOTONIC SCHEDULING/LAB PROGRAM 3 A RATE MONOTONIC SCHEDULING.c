#include <stdio.h>
#include <math.h>

//TO CALCULATE GCD
int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

//TO CALCULATE LCM
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int n, i;
    int bt[10], pt[10], rt[10];
    int hyper, time = 0;

    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Times:\n");
    for (i = 0; i < n; i++)
        {
            scanf("%d", &bt[i]);
            rt[i] = 0; // initially no job released
        }

    printf("Enter Periods:\n");
    for (i = 0; i < n; i++)
        {
            scanf("%d", &pt[i]);
        }

// Calculate hyperperiod = LCM of all periods
    hyper = pt[0];
    for (i = 1; i < n; i++)
        {
            hyper = lcm(hyper, pt[i]);
        }

    printf("LCM=%d\n\n", hyper);

    printf("Rate Monotone Scheduling:\n");
    printf("PID   Burst   Period\n");
    for (i = 0; i < n; i++)
        {
            printf("%d     %d      %d\n", i+1, bt[i], pt[i]);
        }

// Utilization check
    double U = 0;
    for (i = 0; i < n; i++)
        {
            U += (double)bt[i] / pt[i];
        }
    double bound = n * (pow(2.0, 1.0/n) - 1);

    printf("\n%.6f <= %.6f => %s\n", U, bound, (U <= bound) ? "true" : "false");
    printf("Scheduling occurs for %d ms\n\n", hyper);

// Timeline simulation (block-style)
    int current_running = -1;
    while (time < hyper)
        {
// Release jobs
        for (i = 0; i < n; i++) {
            if (time % pt[i] == 0) {
                rt[i] = bt[i];
            }
        }

// Pick highest priority (smallest period)
        int min_period = 9999, index = -1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && pt[i] < min_period) {
                min_period = pt[i];
                index = i;
            }
        }

        // Print only when event changes
        if (index != current_running)
            {
            if (index != -1)
            {
                printf("%dms onwards: Process %d running\n", time, index+1);
            }
        else
            {
                printf("%dms onwards: CPU is idle\n", time);
            }
            current_running = index;
            }

        // Execute one unit if a process is running
        if (index != -1)
            {
                rt[index]--;
            }

        time++;
    }

    return 0;
}
