#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS_IN_DIRECTORY 11

/**
 * using b+tree structure
 */

typedef struct folders
{
    int folderName;
    struct folders *fileLinks[MAX_ITEMS_IN_DIRECTORY]; // store the folder name as integer values at first
} Folders;
#include "../src/queue.h"

Folders *createMemory(int folderName)
{
    Folders *tmp = (Folders *)malloc(sizeof(Folders));
    tmp->folderName = folderName;
    for (int i = 0; i < MAX_ITEMS_IN_DIRECTORY; i++)
        tmp->fileLinks[i] = NULL;

    return tmp;
}

void createFileFolders(Folders **root)
{
    // folder name 1 is the root
    if (!(*root))
    {
        *root = createMemory(1);
    }
    (*root)->fileLinks[0] = createMemory(2);
    (*root)->fileLinks[1] = createMemory(3);
    (*root)->fileLinks[2] = createMemory(4);
    (*root)->fileLinks[3] = createMemory(5);
    (*root)->fileLinks[4] = createMemory(6);
    (*root)->fileLinks[5] = createMemory(7);
    // testing it
    (*root)->fileLinks[0]->fileLinks[0] = createMemory(221);

    (*root)->fileLinks[5]->fileLinks[0] = createMemory(551);

    (*root)->fileLinks[0]->fileLinks[0]->fileLinks[0] = createMemory(222221);
}

// traversal level order fashion

// require queue dataStructure
// for printing

char *findDirectory(char *path, int level)
{
    //extract the path, level no
    /**
     * 1/2/3/4
     * at level 1 -> 1
     * at level 2 -> 2
     * at level 3 -> 3
     */
    int currLevel = 0;
    int pointer = 0;
    char *subStr = 0;
    int i = 0;
    while (pointer < strlen(path))
    {
        if (path[pointer] == '/')
        {
            currLevel++;
            if (currLevel == level)
            {
                // send the subst
                // cpy the pinter to th
                //i .. (pointer-1)
                int k = i;
                int cc = 0;
                subStr = (char *)malloc(sizeof(char) * (pointer - i + 1));
                // 1 2 /
                // 8 9 10
                // 10-8 = 2 +1 for '\0'
                while (k < pointer)
                {
                    subStr[cc] = path[k];
                    k++;
                    cc++;
                }
                subStr[cc] = '\0';
                return subStr;
            } else {
                i = pointer + 1;
                pointer++;
            }
        }
        else
        {
            pointer++;
        }
    }
}

void displayFoldersLevelOrder(Folders *root)
{

    push(root);

    while (!isEmpty())
    {
        // display();
        root = (Folders *)peek();
        pop();

        // print it
        printf("%d ", root->folderName);

        for (int i = 0; i < MAX_ITEMS_IN_DIRECTORY; i++)
        {
            if (root->fileLinks[i] != NULL)
            {
                push(root->fileLinks[i]);
            } else {
                break;
            }
        }
    }
    printf("\n");
}

void deleteDStruct(Folders *r) {}

int main(int argc, char const *argv[])
{
    Folders *root = NULL;
    createFileFolders(&root);
    // intermediate step is to index it
    // indexingNo_of_Folder(&root); // for now only the root has children

    // display
    displayFoldersLevelOrder(root);

    // check the path
    char path[100];
    scanf("%s",path);
    int level;
    scanf("%d",&level);
    printf("Path reached: %s\n",findDirectory(path,level));

    deleteDStruct(root);
    return EXIT_SUCCESS;
}
