#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl_tree.h"

// Function prototypes
struct AVLNode *createNode(int key);
int getHeight(struct AVLNode *node);
int getBalanceFactor(struct AVLNode *node);
void updateHeight(struct AVLNode *node);
struct AVLNode *rightRotate(struct AVLNode *node);
struct AVLNode *leftRotate(struct AVLNode *node);
struct AVLNode *rebalance(struct AVLNode *node);
struct AVLNode *insert(struct AVLNode *node, int key, int *swaps);
struct AVLNode *find(struct AVLNode *node, int key);
struct AVLNode *delete(struct AVLNode *node, int key, int *swaps);

int main() {
    struct AVLNode *root = NULL;
    int swaps = 0;
    clock_t start, end;
    double cpu_time_used;
    int numNodes = 25000;
    int keyList[] = {24997,24998,24999};

    // Insert 500 nodes into the tree and record the time
    start = clock();
    srand(time(NULL));
    for (int i = 0; i < numNodes; i++) {
        int key = rand() % 1000 + 1;
        root = insert(root, key, &swaps);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the number of swaps and the time taken
    printf("Number of swaps random: %d\n", swaps);
    printf("Time taken: %f seconds\n", cpu_time_used);
    printf("\n");



    // Insert 500 nodes into the tree and record the time
    start = clock();
    for (int i = 1; i <= numNodes; i++) {
        root = insert(root, i, &swaps);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the number of swaps and the time taken
    printf("Number of swaps ascending: %d\n", swaps);
    printf("Time taken insert: %f seconds\n", cpu_time_used);
    printf("\n");

    // // Print the tree in-order
    // printf("Tree in-order:\n");
    // printTree(root);
    // printf("\n");

    // Record the time to search for three random nodes
    start = clock();
    for (int i = 1; i <= sizeof(keyList) / sizeof(keyList[0]); i++) {
        int key = keyList[i-1];
        // int key = rand() % numNodes + 1;
        struct AVLNode *foundNode = find(root, key);
        if (foundNode != NULL) {
            printf("Node with key %d found.\n", key);
        } else {
            printf("Node with key %d not found.\n", key);
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the time taken
    printf("Time taken search: %f seconds\n", cpu_time_used);

    // // Insert nodes into the tree
    // root = insert(root, 10, &swaps);
    // root = insert(root, 20, &swaps);
    // root = insert(root, 30, &swaps);
    // root = insert(root, 40, &swaps);
    // root = insert(root, 50, &swaps);

    // // Print the original tree
    // printf("Original tree:\n");
    // printTree(root);
    // printf("\n");

    // // Delete a node
    // root = delete(root, 20, &swaps);

    // // Print the updated tree
    // printf("Updated tree:\n");
    // printTree(root);
    // printf("\n");

    // // Search for a node
    // struct AVLNode *foundNode = find(root, 30);
    // if (foundNode != NULL) {
    //     printf("Node with key 30 found.\n");
    // } else {
    //     printf("Node with key 30 not found.\n");
    // }

    // // Delete a node
    // root = delete(root, 20, &swaps);

    // // Print the number of swaps
    // printf("Number of swaps: %d\n", swaps);

    return 0;
}
