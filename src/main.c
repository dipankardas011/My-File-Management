#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS_IN_DIRECTORY 11

/**
 * using b+tree structure
 */

typedef struct folders{
    int folderName;
    struct folders *fileLinks[MAX_ITEMS_IN_DIRECTORY];    // store the folder name as integer values at first
    int currSize;
} Folders;

Folders *createMemory(int folderName) {
    Folders *tmp = (Folders *)malloc(sizeof(Folders));
    tmp->folderName = folderName;
    tmp->currSize = 1;
    for (int i = 0; i < MAX_ITEMS_IN_DIRECTORY; i++)
        tmp->fileLinks[i] = NULL;

    return tmp;
}

void createFileFolders(Folders **root) {
    // folder name 1 is the root
    if (!(*root)) {
        *root = createMemory(1);
    }
}

// traversal level order fashion

// require queue dataStructure
// for printing


int main(int argc, char const *argv[])
{
    Folders *root = NULL;
    createFileFolders(&root);
    return EXIT_SUCCESS;
}
