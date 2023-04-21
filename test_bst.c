#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst_tree.h"

void test_createNode() {
    struct BSTNode *node = createNode(1);
    assert(node->key == 1);
    assert(node->left == NULL);
    assert(node->right == NULL);
    free(node);
}

void test_add() {
    struct BSTNode *root = add(NULL, 1);
    assert(root->key == 1);
    assert(root->left == NULL);
    assert(root->right == NULL);

    add(root, 2);
    add(root, 3);
    add(root, 4);
    add(root, 5);
    add(root, 6);
    add(root, 7);

    assert(search(root, 2)->key == 2);
    assert(search(root, 5)->key == 5);
    assert(search(root, 7)->key == 7);

    free(root);
}


void test_search() {
    struct BSTNode *root = add(NULL, 1);
    add(root, 2);
    add(root, 3);
    add(root, 4);
    add(root, 5);
    add(root, 6);
    add(root, 7);

    assert(search(root, 2)->key == 2);
    assert(search(root, 5)->key == 5);
    assert(search(root, 7)->key == 7);

    free(root);
}

void test_delete() {
    struct BSTNode *root = add(NULL, 1);
    add(root, 2);
    add(root, 3);
    add(root, 4);
    add(root, 5);
    add(root, 6);
    add(root, 7);

    root = delete(root, 4);
    assert(search(root, 4) == NULL);
    assert(search(root, 3)->key == 3);
    assert(search(root, 5)->key == 5);

    root = delete(root, 1);
    assert(search(root, 1) == NULL);
    assert(search(root, 2)->key == 2);

    free(root);
}

void test_printTree() {
    struct BSTNode *root = add(NULL, 4);
    add(root, 2);
    add(root, 6);
    add(root, 1);
    add(root, 3);
    add(root, 5);
    add(root, 7);

    printf("Expected: 1 2 3 4 5 6 7\n");
    printf("Actual:   ");
    printTree(root);
    printf("\n");

    free(root);
}

int main() {
    test_createNode();
    test_add();
    test_search();
    test_delete();
    test_printTree();
    printf("All tests passed!\n");
    return 0;
}
