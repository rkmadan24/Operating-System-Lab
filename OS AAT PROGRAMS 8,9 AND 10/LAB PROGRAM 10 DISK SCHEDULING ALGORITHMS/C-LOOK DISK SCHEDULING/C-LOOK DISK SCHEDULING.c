#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

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

    qsort(req, n, sizeof(int), compare);

    int left_count = 0;

    for(i = 0; i < n; i++)
    {
        if(req[i] < head)
        {
            left_count++;
        }
    }

    printf("\nOrder serviced: %d", head);

    for(i = left_count; i < n; i++)
    {
        total_movement += abs(head - req[i]);

        head = req[i];

        printf(" -> %d", head);
    }

    if(left_count > 0)
    {
        total_movement += abs(head - req[0]);

        head = req[0];

        printf(" -> %d", head);

        for(i = 1; i < left_count; i++)
        {
            total_movement += abs(head - req[i]);

            head = req[i];

            printf(" -> %d", head);
        }
    }

    printf("\nTotal Head Movement: %d cylinders\n",
           total_movement);

    return 0;
}
