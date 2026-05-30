#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define MAX_CHILDREN 10

typedef struct Node
{
    char name[NAME_LEN];

    int isDir;

    struct Node *children[MAX_CHILDREN];

    int childCount;

} Node;

Node *createNode(char *name, int isDir)
{
    Node *n;

    n = (Node *)malloc(sizeof(Node));

    strcpy(n->name, name);

    n->isDir = isDir;

    n->childCount = 0;

    return n;
}

Node *findChild(Node *parent, char *name)
{
    int i;

    for(i = 0; i < parent->childCount; i++)
    {
        if(strcmp(parent->children[i]->name, name) == 0)
        {
            return parent->children[i];
        }
    }

    return NULL;
}

void insert(Node *root,
            char *parentName,
            char *childName,
            int isDir)
{
    Node *queue[100];

    int front = 0;
    int rear = 0;
    int i;

    queue[rear++] = root;

    while(front < rear)
    {
        Node *curr = queue[front++];

        if(strcmp(curr->name, parentName) == 0
           && curr->isDir)
        {
            if(findChild(curr, childName))
            {
                printf("Already exists.\n");
                return;
            }

            curr->children[curr->childCount++] =
                createNode(childName, isDir);

            printf("%s '%s' created under '%s'.\n",
                   isDir ? "Directory" : "File",
                   childName,
                   parentName);

            return;
        }

        for(i = 0; i < curr->childCount; i++)
        {
            if(curr->children[i]->isDir)
            {
                queue[rear++] = curr->children[i];
            }
        }
    }

    printf("Parent directory not found.\n");
}

void display(Node *node, int level)
{
    int i;

    for(i = 0; i < level; i++)
    {
        printf("  ");
    }

    printf("%s %s\n",
           node->isDir ? "[DIR]" : "[FILE]",
           node->name);

    for(i = 0; i < node->childCount; i++)
    {
        display(node->children[i], level + 1);
    }
}

int main()
{
    printf("\n\tNAME : R K MADAN\tUSN : 1WA24CS225\tSECTION : 'O'\n\n");

    Node *root;

    int choice;

    char parent[NAME_LEN];
    char child[NAME_LEN];

    root = createNode("root", 1);

    do
    {
        printf("\n1.Add Directory");
        printf("\n2.Add File");
        printf("\n3.Display");
        printf("\n0.Exit");

        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("Enter parent directory: ");
                scanf("%s", parent);

                printf("Enter new directory name: ");
                scanf("%s", child);

                insert(root, parent, child, 1);

                break;

            case 2:

                printf("Enter parent directory: ");
                scanf("%s", parent);

                printf("Enter file name: ");
                scanf("%s", child);

                insert(root, parent, child, 0);

                break;

            case 3:

                printf("\n--- Hierarchical Directory ---\n");

                display(root, 0);

                break;
        }

    } while(choice != 0);

    return 0;
}
