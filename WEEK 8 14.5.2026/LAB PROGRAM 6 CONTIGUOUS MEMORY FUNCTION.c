#include <stdio.h>

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");
    int b[20], p[20];
    int temp[20];
    int i, j, n, m;
    int allocation[20];

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    printf("Enter sizes of %d memory blocks:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &m);

    printf("Enter sizes of %d processes:\n", m);
    for(i = 0; i < m; i++)
    {
        scanf("%d", &p[i]);
    }

    // FIRST FIT

    for(i = 0; i < n; i++)
        temp[i] = b[i];

    for(i = 0; i < m; i++)
        allocation[i] = -1;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(temp[j] >= p[i])
            {
                allocation[i] = j;
                temp[j] = -1;
                break;
            }
        }
    }

    printf("\n--- First Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, p[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    // BEST FIT

    for(i = 0; i < n; i++)
        temp[i] = b[i];

    for(i = 0; i < m; i++)
        allocation[i] = -1;

    for(i = 0; i < m; i++)
    {
        int best = -1;

        for(j = 0; j < n; j++)
        {
            if(temp[j] >= p[i])
            {
                if(best == -1 || temp[j] < temp[best])
                {
                    best = j;
                }
            }
        }

        if(best != -1)
        {
            allocation[i] = best;
            temp[best] = -1;
        }
    }

    printf("\n--- Best Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, p[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    // WORST FIT

    for(i = 0; i < n; i++)
        temp[i] = b[i];

    for(i = 0; i < m; i++)
        allocation[i] = -1;

    for(i = 0; i < m; i++)
    {
        int worst = -1;

        for(j = 0; j < n; j++)
        {
            if(temp[j] >= p[i])
            {
                if(worst == -1 || temp[j] > temp[worst])
                {
                    worst = j;
                }
            }
        }

        if(worst != -1)
        {
            allocation[i] = worst;
            temp[worst] = -1;
        }
    }

    printf("\n--- Worst Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, p[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
