/**
 * to create file structure like linux
 * just to display and store the file structure
 * @author Dipankar Das
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS_IN_DIRECTORY 11
#define MAX_STRING_FILE_NAME 30
/**
 * using b+ tree structure or 11 child tree 
 */

typedef struct folders
{
    char folderName[MAX_STRING_FILE_NAME];
    struct folders *fileLinks[MAX_ITEMS_IN_DIRECTORY]; // store the folder name as integer values at first
} Folders;
#include "../src/queue.h"

Folders *createMemory(char *folderName)
{
    Folders *tmp = (Folders *)malloc(sizeof(Folders));
    // tmp->folderName = folderName;
    strncpy(tmp->folderName,folderName,MAX_STRING_FILE_NAME);
    for (int i = 0; i < MAX_ITEMS_IN_DIRECTORY; i++)
        tmp->fileLinks[i] = NULL;

    return tmp;
}

void createFileFolders(Folders **root)
{
    if (!(*root)) {
        *root = createMemory("root");
    }

    (*root)->fileLinks[0] = createMemory("usr");
    (*root)->fileLinks[1] = createMemory("sys");
    (*root)->fileLinks[2] = createMemory("bin");
    (*root)->fileLinks[3] = createMemory("mnt");
    (*root)->fileLinks[4] = createMemory("tmp");
    (*root)->fileLinks[5] = createMemory("etc");
    // testing it
    (*root)->fileLinks[0]->fileLinks[0] = createMemory("include");

    (*root)->fileLinks[5]->fileLinks[0] = createMemory("passwd");

    (*root)->fileLinks[0]->fileLinks[0]->fileLinks[0] = createMemory("linux");
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
    return '\0';
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
        printf("%s ", root->folderName);

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

int countLevel(char* path) {
    int level = 0;
    for(int i = 0; path[i]; i++) {
        if(path[i]=='/')
            level++;
    }
    return level;
}

void deleteDStruct(Folders *r) {
    // follow the postorder removal
    if (r) {
        for (int i =0; i<MAX_ITEMS_IN_DIRECTORY;i++) {
            if (r->fileLinks[i]) {
                deleteDStruct(r->fileLinks[i]);
            }else {
                break;
            }
        }
        // all the children are in the stack remove the root
        // printf("Removing the folder name: %d\n",r->folderName);
        free(r);
    }
}

void displayAdvance(Folders *root) {
    if (root) {
        // using the preorder printing the root first then all the children
        printf("|- %s\n",root->folderName);

        for(int i = 0; i<MAX_ITEMS_IN_DIRECTORY && root->fileLinks[i];i++) {
            printf("|  |- %s\n",root->fileLinks[i]->folderName);
        }
        printf("|\n");
        for(int i = 0; i<MAX_ITEMS_IN_DIRECTORY && root->fileLinks[i];i++) {
            displayAdvance(root->fileLinks[i]);
        }
    }
}

void welcomePage() {
    system("clear");
    printf("Rules:\n");
    printf("1. no spaces allowed\n");
    printf("2. if directory then end with /\n\t|- eg. home/user/Desktop/\n");
    printf("3. Any folder can contain only 11 files inside it\n");
    printf("------------------------\n");
}

int main(int argc, char const *argv[])
{
    welcomePage();
    Folders *root = NULL;
    createFileFolders(&root);
    // displayFoldersLevelOrder(root);

    // check the path length is max 100
    char path[100];
    printf("Demo to pick the file to search..");
    printf("Enter the path -> ");
    scanf("%s",path);
    // 12121/12121/ => count the number of /
    int level = countLevel(path);
    printf("Path reached: %s\n",findDirectory(path,level));


    /**
     * testing the new Display
     */
    displayAdvance(root);

    deleteDStruct(root);
    return EXIT_SUCCESS;
}
