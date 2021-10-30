#include <stdio.h>
#include <stdlib.h>


#define MAX_ITEMS_IN_DIRECTORY 11

/**
 * using b+tree structure
 */

typedef struct folders{
    int folderName;
    struct folders *fileLinks[MAX_ITEMS_IN_DIRECTORY];    // store the folder name as integer values at first
    int noOfFiles;
} Folders;
#include "../src/queue.h"

Folders *createMemory(int folderName) {
    Folders *tmp = (Folders *)malloc(sizeof(Folders));
    tmp->folderName = folderName;
    tmp->noOfFiles = 0;
    for (int i = 0; i < MAX_ITEMS_IN_DIRECTORY; i++)
        tmp->fileLinks[i] = NULL;

    return tmp;
}

void indexingNo_of_Folder(Folders **folder) {
    for(int i=0; i<MAX_ITEMS_IN_DIRECTORY; i++) {
        if ((*folder)->fileLinks[i]!=NULL)
            (*folder)->noOfFiles++;
        else
            return;
    }
}

void createFileFolders(Folders **root) {
    // folder name 1 is the root
    if (!(*root)) {
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
    (*root)->fileLinks[0]->noOfFiles++;

    (*root)->fileLinks[5]->fileLinks[0] = createMemory(551);
    (*root)->fileLinks[5]->noOfFiles++;

    (*root)->fileLinks[0]->fileLinks[0]->fileLinks[0] = createMemory(222221);
    (*root)->fileLinks[0]->fileLinks[0]->noOfFiles++;
}

// traversal level order fashion

// require queue dataStructure
// for printing

void displayFoldersLevelOrder(Folders *root) {
    push(root);

    while(!isEmpty()) {
        // display();
        root = (Folders *)peek();
        pop();

        // print it
        printf("%d ",root->folderName);

        for(int i =0 ;i < root->noOfFiles; i++) {
            if (root->fileLinks[i]!=NULL){
                push(root->fileLinks[i]);
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
    indexingNo_of_Folder(&root); // for now only the root has children

    // display
    displayFoldersLevelOrder(root);

    deleteDStruct(root);
    return EXIT_SUCCESS;
}
