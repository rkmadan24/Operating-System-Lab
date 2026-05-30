#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    int n, head, max_cyl, dir, i;

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

    printf("Enter max cylinder number: ");
    scanf("%d", &max_cyl);

    printf("Enter direction (0 = towards 0, 1 = towards max): ");
    scanf("%d", &dir);

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

    if(dir == 0)
    {
        for(i = left_count - 1; i >= 0; i--)
        {
            total_movement += abs(head - req[i]);

            head = req[i];

            printf(" -> %d", head);
        }

        total_movement += head;

        head = 0;

        printf(" -> 0");

        for(i = left_count; i < n; i++)
        {
            total_movement += abs(head - req[i]);

            head = req[i];

            printf(" -> %d", head);
        }
    }
    else
    {
        for(i = left_count; i < n; i++)
        {
            total_movement += abs(head - req[i]);

            head = req[i];

            printf(" -> %d", head);
        }

        total_movement += abs(max_cyl - head);

        head = max_cyl;

        printf(" -> %d", max_cyl);

        for(i = left_count - 1; i >= 0; i--)
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
