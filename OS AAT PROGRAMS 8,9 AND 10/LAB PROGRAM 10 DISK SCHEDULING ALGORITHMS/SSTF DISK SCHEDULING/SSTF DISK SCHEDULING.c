#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    int n, head, i, count;

    int total_movement = 0;

    printf("Enter number of disk requests: ");

    scanf("%d", &n);

    int req[n];
    int visited[n];

    printf("Enter the request queue: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);

        visited[i] = 0;
    }

    printf("Enter initial head position: ");

    scanf("%d", &head);

    printf("\nOrder serviced: %d", head);

    for(count = 0; count < n; count++)
    {
        int min_dist = INT_MAX;

        int min_idx = -1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i] &&
               abs(req[i] - head) < min_dist)
            {
                min_dist = abs(req[i] - head);

                min_idx = i;
            }
        }

        visited[min_idx] = 1;

        total_movement += min_dist;

        head = req[min_idx];

        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement: %d cylinders\n",
           total_movement);

    return 0;
}
