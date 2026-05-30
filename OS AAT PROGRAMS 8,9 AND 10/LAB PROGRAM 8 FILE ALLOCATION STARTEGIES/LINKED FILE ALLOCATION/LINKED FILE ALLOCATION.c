#include <stdio.h>

#define MAX_BLOCKS 10

struct Block
{
    int allocated;
    int next;
};

struct Block disk[MAX_BLOCKS];

void initDisk()
{
    int i;

    for(i = 0; i < MAX_BLOCKS; i++)
    {
        disk[i].allocated = 0;
        disk[i].next = -1;
    }
}

void displayDisk()
{
    int i;

    printf("\n%-10s %-12s %-12s\n",
           "Block No.",
           "Status",
           "Next Block");

    printf("----------------------------------------\n");

    for(i = 0; i < MAX_BLOCKS; i++)
    {
        printf("%-10d %-12s",
               i,
               disk[i].allocated ? "Allocated" : "Free");

        if(disk[i].allocated)
        {
            printf("%d", disk[i].next);
        }

        printf("\n");
    }
}

int findFreeBlock()
{
    int i;

    for(i = 0; i < MAX_BLOCKS; i++)
    {
        if(disk[i].allocated == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    int numBlocks;
    int i, prev, curr, start;

    initDisk();

    printf("=== Linked File Allocation ===");

    displayDisk();

    printf("\nEnter number of blocks to allocate: ");
    scanf("%d", &numBlocks);

    start = findFreeBlock();

    if(start == -1)
    {
        printf("\nAllocation Failed: No free blocks available.\n");

        return 1;
    }

    disk[start].allocated = 1;

    prev = start;

    for(i = 1; i < numBlocks; i++)
    {
        curr = findFreeBlock();

        if(curr == -1)
        {
            printf("\nAllocation Failed: Not enough free blocks.\n");

            return 1;
        }

        disk[curr].allocated = 1;

        disk[prev].next = curr;

        prev = curr;
    }

    disk[prev].next = -1;

    printf("\nFile Allocated Successfully!\n");

    printf("Linked chain: ");

    curr = start;

    while(curr != -1)
    {
        printf("[Block %d]", curr);

        if(disk[curr].next != -1)
        {
            printf(" -> ");
        }

        curr = disk[curr].next;
    }

    printf(" -> NULL\n");

    displayDisk();

    return 0;
}
