#include <stdio.h>
#include <stdlib.h>

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

// Recursive inorder traversal
void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;

    inorder(root->left, result, index);
    result[(*index)++] = root->val;
    inorder(root->right, result, index);
}

// Function to return inorder traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // Max nodes = 100
    *returnSize = 0;

    inorder(root, result, returnSize);

    return result;
}

int main() {
    /*
           1
            \
             2
            /
           3

       Inorder: 1 3 2
    */

    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    int returnSize;
    int* result = inorderTraversal(root, &returnSize);

    printf("Inorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
