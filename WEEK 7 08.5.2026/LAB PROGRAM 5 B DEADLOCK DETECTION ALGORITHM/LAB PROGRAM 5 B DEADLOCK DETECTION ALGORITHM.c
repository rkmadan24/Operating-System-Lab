#include <stdio.h>

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");
    int n, m, i, j, k;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m];
    int avail[m];

    printf("Enter the allocation matrix:\n");

    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i);

        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the request matrix:\n");

    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i);

        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter the available resources: ");

    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    int finish[n], safeSeq[n], work[m];

    for(i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }

    for(i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            break;
        }
    }

    if(count == n)
    {
        printf("\nSystem is in safe state.\n");
        printf("Safe Sequence is: ");

        for(i = 0; i < n; i++)
        {
            printf("P%d ", safeSeq[i]);
        }
    }
    else
    {
        printf("\nDeadlock detected.\n");
    }

    return 0;
}
