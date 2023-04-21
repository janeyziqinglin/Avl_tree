#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "avl_tree.h"

void test_createNode() {
    struct AVLNode *node = createNode(1);
    assert(node != NULL);
    assert(node->key == 1);
    assert(node->left == NULL);
    assert(node->right == NULL);
    assert(node->height == 1);
    free(node);
}

void test_getHeight() {
    struct AVLNode *node = createNode(1);
    assert(getHeight(node) == 1);
    
    node->left = createNode(2);
    assert(getHeight(node) == 2);
    
    node->right = createNode(3);
    assert(getHeight(node) == 2);
    
    node->left->left = createNode(4);
    assert(getHeight(node) == 3);
    
    node->right->right = createNode(5);
    assert(getHeight(node) == 3);
    
    free(node->left->left);
    free(node->left);
    free(node->right->right);
    free(node->right);
    free(node);
}


void test_getBalanceFactor() {
    struct AVLNode *node = createNode(1);
    assert(getBalanceFactor(node) == 0);
    node->left = createNode(2);
    assert(getBalanceFactor(node) == 1);
    node->left->left = createNode(3);
    assert(getBalanceFactor(node) == 2);
    free(node->left->left);
    free(node->left);
    free(node);
}

void test_updateHeight() {
    struct AVLNode *node = createNode(1);
    updateHeight(node);
    assert(node->height == 1);
    node->left = createNode(2);
    updateHeight(node);
    assert(node->height == 2);
    node->right = createNode(3);
    updateHeight(node);
    assert(node->height == 2);
    free(node->left);
    free(node->right);
    free(node);
}

void test_rightRotate() {
    struct AVLNode *node = createNode(2);
    node->left = createNode(1);
    node->right = createNode(3);
    node = rightRotate(node);
    assert(node->key == 1);
    assert(node->right->key == 2);
    assert(node->right->right->key == 3);
    free(node->right->right);
    free(node->right);
    free(node->left);
    free(node);
}

void test_leftRotate() {
    struct AVLNode *node = createNode(3);
    node->right = createNode(2);
    node->right->right = createNode(1);
    node = leftRotate(node);
    assert(node->key == 2);
    assert(node->left->key == 3);
    assert(node->right->key == 1);
    free(node->left);
    free(node->right);
    free(node);
}

void test_rebalance() {
    struct AVLNode *node = createNode(3);
    node->left = createNode(2);
    node->left->left = createNode(1);
    node = rebalance(node);
    assert(node->key == 2);
    assert(node->left->key == 1);
    assert(node->right->key == 3);
    free(node->left);
    free(node->right);
    free(node);
}

void test_insert() {
    // Test 1: Inserting a node into an empty tree
    struct AVLNode *root = NULL;
    int swaps = 0;
    root = insert(root, 5, &swaps);
    assert(root->key == 5);

    // Test 2: Inserting a node with a smaller key than the root
    root = insert(root, 3, &swaps);
    assert(root->key == 5);
    assert(root->left->key == 3);

    // Test 3: Inserting a node with a larger key than the root
    root = insert(root, 7, &swaps);
    assert(root->key == 5);
    assert(root->right->key == 7);

    // Test 4: Inserting a node with the same key as the root
    root = insert(root, 5, &swaps);
    assert(root->key == 5);
    assert(root->left->key == 3);
    assert(root->right->key == 7);
}

void test_find() {
    // Test 1: Finding a node in an empty tree
    struct AVLNode *root = NULL;
    struct AVLNode *node = find(root, 5);
    assert(node == NULL);
    int swaps = 0;

    // Test 2: Finding a node that doesn't exist in the tree
    root = insert(root, 5, &swaps);
    root = insert(root, 3, &swaps);
    root = insert(root, 7, &swaps);
    node = find(root, 6);
    assert(node == NULL);

    // Test 3: Finding a node that exists in the tree
    node = find(root, 7);
    assert(node->key == 7);
}


void test_delete() {
    // Create an AVL tree
    struct AVLNode *root = createNode(4);
    int swaps = 0;
    root = insert(root, 2, &swaps);
    root = insert(root, 6, &swaps);
    root = insert(root, 1, &swaps);
    root = insert(root, 3, &swaps);
    root = insert(root, 5, &swaps);
    root = insert(root, 7, &swaps);

    // Test deleting a leaf node
    root = delete(root, 1, &swaps);
    assert(root->left->key == 2);
    assert(root->left->left == NULL);

    // Test deleting a node with one child
    root = delete(root, 6, &swaps);
    assert(root->right->key == 7);

    // Test deleting a node with two children
    root = delete(root, 2, &swaps);
    assert(root->left->key == 3);
    assert(root->left->left == NULL);
    assert(root->left->right == NULL);

    // Free memory
    delete(root, 3, &swaps);
    delete(root, 4, &swaps);
    delete(root, 5, &swaps);
    delete(root, 7, &swaps);
}

int main() {
    test_createNode();
    test_getHeight();
    test_getBalanceFactor();
    test_updateHeight();
    test_rightRotate();
    test_leftRotate();
    test_rebalance();
    test_insert();
    test_find();
    test_delete();
    printf("All tests passed!\n");
    return 0;
}

