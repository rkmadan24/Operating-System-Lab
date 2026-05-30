#include <stdio.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_FILES 10
#define NAME_LEN 20

typedef struct
{
    char username[NAME_LEN];
    char files[MAX_FILES][NAME_LEN];
    int fileCount;

} UserDirectory;

UserDirectory mfd[MAX_USERS];

int userCount = 0;

int findUser(char *username)
{
    int i;

    for(i = 0; i < userCount; i++)
    {
        if(strcmp(mfd[i].username, username) == 0)
        {
            return i;
        }
    }

    return -1;
}

void addUser(char *username)
{
    if(findUser(username) != -1)
    {
        printf("User already exists.\n");
        return;
    }

    strcpy(mfd[userCount].username, username);

    mfd[userCount].fileCount = 0;

    userCount++;

    printf("User '%s' added.\n", username);
}

void createFile(char *username, char *filename)
{
    int u, i;

    u = findUser(username);

    if(u == -1)
    {
        printf("User not found.\n");
        return;
    }

    for(i = 0; i < mfd[u].fileCount; i++)
    {
        if(strcmp(mfd[u].files[i], filename) == 0)
        {
            printf("File already exists.\n");
            return;
        }
    }

    strcpy(mfd[u].files[mfd[u].fileCount++], filename);

    printf("File '%s' created for user '%s'.\n",
           filename,
           username);
}

void listFiles()
{
    int i, j;

    printf("\n--- Master File Directory ---\n");

    for(i = 0; i < userCount; i++)
    {
        printf("\nUser : %s\n", mfd[i].username);

        if(mfd[i].fileCount == 0)
        {
            printf("No files\n");
        }

        for(j = 0; j < mfd[i].fileCount; j++)
        {
            printf("  %s\n", mfd[i].files[j]);
        }
    }
}

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    int choice;

    char uname[NAME_LEN];
    char fname[NAME_LEN];

    do
    {
        printf("\n1.Add User");
        printf("\n2.Create File");
        printf("\n3.List Files");
        printf("\n0.Exit");

        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("Enter username: ");
                scanf("%s", uname);

                addUser(uname);

                break;

            case 2:

                printf("Enter username: ");
                scanf("%s", uname);

                printf("Enter file name: ");
                scanf("%s", fname);

                createFile(uname, fname);

                break;

            case 3:

                listFiles();

                break;
        }

    } while(choice != 0);

    return 0;
}
