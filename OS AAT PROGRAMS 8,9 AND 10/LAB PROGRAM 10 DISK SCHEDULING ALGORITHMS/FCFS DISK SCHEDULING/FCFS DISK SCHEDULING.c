#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    int n, head, i;

    int total_movement = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the request queue: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder serviced: %d", head);

    for(i = 0; i < n; i++)
    {
        total_movement += abs(req[i] - head);

        head = req[i];

        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement: %d cylinders\n",
           total_movement);

    return 0;
}
