#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define NAME_LEN 20

char directory[MAX_FILES][NAME_LEN];

int fileCount = 0;

void createFile(char *name)
{
    int i;

    for(i = 0; i < fileCount; i++)
    {
        if(strcmp(directory[i], name) == 0)
        {
            printf("Error: File '%s' already exists.\n", name);
            return;
        }
    }

    strcpy(directory[fileCount++], name);

    printf("File '%s' created.\n", name);
}

void deleteFile(char *name)
{
    int i, j;

    for(i = 0; i < fileCount; i++)
    {
        if(strcmp(directory[i], name) == 0)
        {
            for(j = i; j < fileCount - 1; j++)
            {
                strcpy(directory[j], directory[j + 1]);
            }

            fileCount--;

            printf("File '%s' deleted.\n", name);

            return;
        }
    }

    printf("Error: File '%s' not found.\n", name);
}

void listFiles()
{
    int i;

    printf("\n--- Single Level Directory ---\n");

    if(fileCount == 0)
    {
        printf("Directory is empty.\n");
        return;
    }

    for(i = 0; i < fileCount; i++)
    {
        printf("%d. %s\n", i + 1, directory[i]);
    }
}

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    int choice;

    char name[NAME_LEN];

    do
    {
        printf("\n1.Create File");
        printf("\n2.Delete File");
        printf("\n3.List Files");
        printf("\n0.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("Enter file name: ");
                scanf("%s", name);

                createFile(name);

                break;

            case 2:

                printf("Enter file name: ");
                scanf("%s", name);

                deleteFile(name);

                break;

            case 3:

                listFiles();

                break;
        }

    } while(choice != 0);

    return 0;
}
