#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    if (left == -1)
        return -1;

    int right = height(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;

    return (left > right ? left : right) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return height(root) != -1;
}

int main() {
    
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    if (isBalanced(root))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
