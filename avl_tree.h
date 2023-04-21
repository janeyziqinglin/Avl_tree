#include <stdio.h>
#include <stdlib.h>

// AVL tree node structure
struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

// Create a new node with the given key
struct AVLNode *createNode(int key) {
    struct AVLNode *newNode = (struct AVLNode*) malloc(sizeof(struct AVLNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Get the height of the node
int getHeight(struct AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


// Get the balance factor of the node
int getBalanceFactor(struct AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Update the height of the node
void updateHeight(struct AVLNode *node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Right rotate the node
struct AVLNode *rightRotate(struct AVLNode *node) {
    struct AVLNode *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// Left rotate the node
struct AVLNode *leftRotate(struct AVLNode *node) {
    struct AVLNode *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// Rebalance the node
struct AVLNode *rebalance(struct AVLNode *node) {
    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    } else if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    return node;
}

// Insert a node with the given key
struct AVLNode *insert(struct AVLNode *node, int key, int *swaps) {
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key, swaps);
    } else if (key > node->key) {
        node->right = insert(node->right, key, swaps);
    }
    node = rebalance(node);
    (*swaps)++;
    return node;
}

// Find the node with the given key
struct AVLNode *find(struct AVLNode *node, int key) {
    if (node == NULL || node->key == key) {
        return node;
    } else if (key < node->key) {
        return find(node->left, key);
    } else {
        return find(node->right, key);
    }
}


// Find the node with the minimum value in the tree rooted at the given node
struct AVLNode *findMin(struct AVLNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Delete the node with the given key
struct AVLNode *delete(struct AVLNode *node, int key, int *swaps) {
    if (node == NULL) {
        return NULL;
    }
    if (key < node->key) {
        node->left = delete(node->left, key, swaps);
    } else if (key > node->key) {
        node->right = delete(node->right, key, swaps);
    } else {
        if (node->left == NULL || node->right == NULL) {
            struct AVLNode *temp = node->left ? node->left : node->right;
            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }
            free(temp);
        } else {
            struct AVLNode *successor = node->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            node->key = successor->key;
            node->right = delete(node->right, successor->key, swaps);
        }
    }
    if (node == NULL) {
        return node;
    }
    node = rebalance(node);
    (*swaps)++;
    return node;
}


// Print the AVL tree using in-order traversal
void printTree(struct AVLNode *node) {
    if (node == NULL) {
        return;
    }
    printTree(node->left);
    printf("%d ", node->key);
    printTree(node->right);
}
