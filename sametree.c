#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if two trees are the same
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // Both nodes are NULL
    if (p == NULL && q == NULL)
        return true;

    // One node is NULL
    if (p == NULL || q == NULL)
        return false;

    // Values differ
    if (p->val != q->val)
        return false;

    // Check left and right subtrees
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() {
    /*
        Tree 1:
             1
            / \
           2   3

        Tree 2:
             1
            / \
           2   3
    */

    struct TreeNode* p = createNode(1);
    p->left = createNode(2);
    p->right = createNode(3);

    struct TreeNode* q = createNode(1);
    q->left = createNode(2);
    q->right = createNode(3);

    if (isSameTree(p, q))
        printf("true\n");
    else
        printf("false\n");

    // Free memory
    free(p->left);
    free(p->right);
    free(p);

    free(q->left);
    free(q->right);
    free(q);

    return 0;
}
