#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_INDEX 5

int disk[MAX_BLOCKS];

void displayDisk()
{
    int i;

    printf("\n%-10s %-10s\n", "Block No.", "Status");
    printf("----------------------------\n");

    for(i = 0; i < MAX_BLOCKS; i++)
    {
        printf("%-10d %-10s\n",
               i,
               disk[i] ? "Allocated" : "Free");
    }
}

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    int i, indexBlock, numData, canAllocate;

    int indexTable[MAX_INDEX];

    for(i = 0; i < MAX_BLOCKS; i++)
    {
        disk[i] = 0;
    }

    printf("=== Indexed File Allocation ===");

    displayDisk();

    printf("\nEnter index block number: ");
    scanf("%d", &indexBlock);

    if(indexBlock < 0 || indexBlock >= MAX_BLOCKS)
    {
        printf("Error: Invalid block number.\n");
        return 1;
    }

    if(disk[indexBlock] == 1)
    {
        printf("Error: Index block already allocated.\n");
        return 1;
    }

    disk[indexBlock] = 1;

    printf("Index block %d allocated.\n", indexBlock);

    printf("Enter number of data blocks needed: ");
    scanf("%d", &numData);

    if(numData <= 0 || numData > MAX_INDEX)
    {
        printf("Error: Invalid number of blocks.\n");

        disk[indexBlock] = 0;

        return 1;
    }

    printf("Enter the block numbers for the data blocks:\n");

    for(i = 0; i < numData; i++)
    {
        printf("Data block %d: ", i + 1);

        scanf("%d", &indexTable[i]);
    }

    canAllocate = 1;

    for(i = 0; i < numData; i++)
    {
        int b = indexTable[i];

        if(b < 0 || b >= MAX_BLOCKS ||
           b == indexBlock ||
           disk[b] == 1)
        {
            printf("Error: Block %d is invalid or already allocated.\n", b);

            canAllocate = 0;

            break;
        }
    }

    if(canAllocate)
    {
        for(i = 0; i < numData; i++)
        {
            disk[indexTable[i]] = 1;
        }

        printf("\nFile Allocated Successfully!\n");

        printf("Index Block : %d\n", indexBlock);

        printf("Data Blocks : ");

        for(i = 0; i < numData; i++)
        {
            printf("%d ", indexTable[i]);
        }

        printf("\n");
    }
    else
    {
        printf("\nAllocation Failed.\n");

        disk[indexBlock] = 0;
    }

    displayDisk();

    return 0;
}
