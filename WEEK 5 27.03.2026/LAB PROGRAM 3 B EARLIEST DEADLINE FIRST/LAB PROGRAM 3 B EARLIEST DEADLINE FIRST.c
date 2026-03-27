#include <stdio.h>

int main()
{
    int n, i;

    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    int bt[n], dl[n], p[n], rem[n];
    printf("Enter Burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem[i] = 0; // initially no job released
    }

    printf("Enter Deadlines:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &dl[i]);
    }

    printf("Enter Periods:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("\nPID\tBurst\tDeadline\tPeriod\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\n", i + 1, bt[i], dl[i], p[i]);
    }

    int total_time = p[0];
    for (i = 1; i < n; i++) {
        if (p[i] > total_time)
            total_time = p[i];
    }

    printf("\nScheduling occurs for %d ms\n\n", total_time);

    int prev_idle = 0;


    for (int time = 0; time < total_time; time++) {
        for (i = 0; i < n; i++) {
            if (time % p[i] == 0) {
                rem[i] = bt[i];
            }
        }

// Select task with earliest deadline
        int selected = -1;
        int min_deadline = 9999;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                if (dl[i] < min_deadline) {
                    min_deadline = dl[i];
                    selected = i;
                }
            }
        }

// Print timeline
        if (selected == -1) {
            if (!prev_idle) {
                printf("%dms onwards: CPU is idle.\n", time);
                prev_idle = 1;
            }
        } else {
            printf("%dms onwards: Task %d is running.\n", time, selected + 1);
            rem[selected]--;
            prev_idle = 0;
        }
    }

    return 0;
}
