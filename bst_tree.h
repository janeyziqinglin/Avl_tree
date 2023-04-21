#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function prototypes
struct BSTNode *createNode(int key);
struct BSTNode *add(struct BSTNode *root, int key);
struct BSTNode *search(struct BSTNode *root, int key);
struct BSTNode *delete(struct BSTNode *root, int key);

// Create a new BST node with the given key
struct BSTNode *createNode(int key) {
    struct BSTNode *node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Add a node with the given key to the BST
struct BSTNode *add(struct BSTNode *root, int key) {
    if (root == NULL) {
        return createNode(key);
    } else if (key < root->key) {
        root->left = add(root->left, key);
    } else if (key > root->key) {
        root->right = add(root->right, key);
    }
    return root;
}

// Search for a node with the given key in the BST
struct BSTNode *search(struct BSTNode *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Delete a node with the given key from the BST
struct BSTNode *delete(struct BSTNode *root, int key) {
    if (root == NULL) {
        return root;
    } else if (key < root->key) {
        root->left = delete(root->left, key);
    } else if (key > root->key) {
        root->right = delete(root->right, key);
    } else {
        if (root->left == NULL) {
            struct BSTNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        struct BSTNode *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}

// Print the BST using in-order traversal
void printTree(struct BSTNode *node) {
    if (node == NULL) {
        return;
    }
    printTree(node->left);
    printf("%d ", node->key);
    printTree(node->right);
}
