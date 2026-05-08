#include <stdio.h>
#include <stdlib.h>

int queue[100], front = -1, rear = -1, max;
int itemCounter = 0;

void produce()
{
    if (rear == max - 1)
    {
        printf("Buffer is full! Cannot produce more items.\n");
        return;
    }

    if (front == -1)
        front = 0;

    itemCounter++;
    queue[++rear] = itemCounter;
    printf("producer has produced: item %d\n", itemCounter);
}


void consume()
{
    if (front == -1 || rear == -1)
    {
        printf("Buffer is empty\n");
        return;
    }

    printf("Consumer has consumed : item %d\n", queue[rear--]);

    if (rear < front)
        front = rear = -1;
}

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");
    int choice;

    printf("Enter the size of the buffer: ");
    scanf("%d", &max);

    if (max > 100)
    {
        printf("Max size is 100.\n");
        return 0;
    }

    while (1)
    {
        printf("\nEnter \n1. Producer \n2. Consumer \n3.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            produce();
            break;

        case 2:
            consume();
            break;

        case 3:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
