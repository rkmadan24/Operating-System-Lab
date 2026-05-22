#include <stdio.h>

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");
    int pages[50], frames[10];
    int n, f;
    int i, j, k;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // ---------------- FIFO ----------------

    int faults = 0;
    int next = 0;
    int found;

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
    }

    printf("\n--- FIFO Page Replacement ---\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            frames[next] = pages[i];
            next = (next + 1) % f;
            faults++;
        }

        printf("Page %d -> [", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] != -1)
            {
                printf("%d", frames[j]);

                if(j != f - 1)
                {
                    printf(" ");
                }
            }
        }

        printf("]\n");
    }

    printf("Total Page Faults (FIFO): %d\n", faults);

    // ---------------- LRU ----------------

    int time[10];
    int count = 0;
    faults = 0;

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\n--- LRU Page Replacement ---\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                count++;
                time[j] = count;
                break;
            }
        }

        if(found == 0)
        {
            int pos = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
            {
                pos = 0;

                for(j = 1; j < f; j++)
                {
                    if(time[j] < time[pos])
                    {
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;
        }

        printf("Page %d -> [", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] != -1)
            {
                printf("%d", frames[j]);

                if(j != f - 1)
                {
                    printf(" ");
                }
            }
        }

        printf("]\n");
    }

    printf("Total Page Faults (LRU): %d\n", faults);

    // ---------------- OPTIMAL ----------------

    faults = 0;

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
    }

    printf("\n--- Optimal Page Replacement ---\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int pos = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
            {
                int farthest = -1;
                int index;

                for(j = 0; j < f; j++)
                {
                    int found_future = 0;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            if(k > farthest)
                            {
                                farthest = k;
                                pos = j;
                            }

                            found_future = 1;
                            break;
                        }
                    }

                    if(found_future == 0)
                    {
                        pos = j;
                        break;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        printf("Page %d -> [", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] != -1)
            {
                printf("%d", frames[j]);

                if(j != f - 1)
                {
                    printf(" ");
                }
            }
        }

        printf("]\n");
    }

    printf("Total Page Faults (Optimal): %d\n", faults);

    return 0;
}

