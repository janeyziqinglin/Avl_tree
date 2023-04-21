#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst_tree.h"

int main() {
    struct BSTNode *root = NULL;
    clock_t start, end;
    double cpu_time_used;
    int numNodes = 1000;
    int keyList[] = {996,997,998};
    // Insert 500 nodes with random keys into the BST
    start = clock();
    srand(time(NULL));
    for (int i = 1; i <= numNodes; i++) {
        root = add(root, i);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to insert %d nodes: %f seconds\n", numNodes, cpu_time_used);

    // // Print the tree in-order
    // printf("Tree in-order:\n");
    // printTree(root);
    // printf("\n");

    // Search for three random nodes in the BST
    start = clock();
    for (int i = 1; i <= sizeof(keyList) / sizeof(keyList[0]); i++) {
        int key = keyList[i-1];
        // int key = rand() % numNodes + 1;
        struct BSTNode *foundNode = search(root, key);
        if (foundNode != NULL) {
            printf("Node with key %d found.\n", key);
        } else {
            printf("Node with key %d not found.\n", key);
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to search for 3 nodes: %f seconds\n", cpu_time_used);

    return 0;
}






// int main() {
//     struct BSTNode *root = NULL;

//     // Add nodes to the BST
//     root = add(root, 50);
//     root = add(root, 30);
//     root = add(root, 20);
//     root = add(root, 40);
//     root = add(root, 70);
//     root = add(root, 60);
//     root = add(root, 80);

//     // Print the original BST
//     printf("Original BST:\n");
//     printTree(root);
//     printf("\n");

//     // Search for nodes in the BST
//     struct BSTNode *foundNode = search(root, 40);
//     if (foundNode != NULL) {
//         printf("Node with key 40 found.\n");
//     } else {
//         printf("Node with key 40 not found.\n");
//     }


//     // Delete nodes from the BST
//     root = delete(root, 20);


//     // Print the updated BST
//     printf("Updated BST:\n");
//     printTree(root);
//     printf("\n");

//     // Search for nodes in the updated BST
//     foundNode = search(root, 20);
//     if (foundNode != NULL) {
//         printf("Node with key 40 found.\n");
//     } else {
//         printf("Node with key 40 not found.\n");
//     }

//     return 0;
// }
