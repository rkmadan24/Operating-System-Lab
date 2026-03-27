// Proportional Share Scheduling (Lottery Scheduling)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define Process structure
typedef struct {
    char name[5];
    int tickets;
} Process;

int main() {
    int n, total_tickets = 0;
    float total_T = 0.0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    Process p[n];
    srand(time(NULL)); // Seed random number generator

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        sprintf(p[i].name, "P%d", i + 1);

        printf("Tickets: ");
        scanf("%d", &p[i].tickets);

        total_tickets += p[i].tickets;
        total_T += p[i].tickets;
    }

    printf("\n--- Proportional Share Scheduling ---\n");

    // Input scheduling time period
    int m;
    printf("Enter the Time Period for scheduling: ");
    scanf("%d", &m);

    // Lottery scheduling simulation
    for (int i = 0; i < m; i++) {
        int winning_ticket = rand() % total_tickets + 1;
        int accumulated_tickets = 0;
        int winner_index = -1;

        for (int j = 0; j < n; j++) {
            accumulated_tickets += p[j].tickets;
            if (winning_ticket <= accumulated_tickets) {
                winner_index = j;
                break;
            }
        }

        printf("Tickets picked: %d, Winner: %s\n",
               winning_ticket, p[winner_index].name);
    }

    // Print proportional share of CPU time
    for (int i = 0; i < n; i++) {
        printf("\nThe Process: %s gets %.2f%% of Processor Time.\n",
               p[i].name, ((p[i].tickets / total_T) * 100));
    }

    return 0;
}
