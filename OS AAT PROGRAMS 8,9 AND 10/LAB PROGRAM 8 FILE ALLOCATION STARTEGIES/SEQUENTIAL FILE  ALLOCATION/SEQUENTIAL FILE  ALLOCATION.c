#include <stdio.h>

#define MAX_BLOCKS 10

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

    int i, start, length, canAllocate;

    for(i = 0; i < MAX_BLOCKS; i++)
    {
        disk[i] = 0;
    }

    printf("=== Sequential (Contiguous) File Allocation ===");

    displayDisk();

    printf("\nEnter starting block number: ");
    scanf("%d", &start);

    printf("Enter number of blocks required (length): ");
    scanf("%d", &length);

    if(start < 0 || start + length > MAX_BLOCKS)
    {
        printf("\nError: Block range exceeds disk size.\n");
        return 1;
    }

    canAllocate = 1;

    for(i = start; i < start + length; i++)
    {
        if(disk[i] == 1)
        {
            canAllocate = 0;
            break;
        }
    }

    if(canAllocate)
    {
        for(i = start; i < start + length; i++)
        {
            disk[i] = 1;
        }

        printf("\nFile Allocated Successfully!\n");

        printf("Blocks used: %d to %d\n",
               start,
               start + length - 1);
    }
    else
    {
        printf("\nAllocation Failed: Blocks not contiguous or already in use.\n");
    }

    displayDisk();

    return 0;
}
