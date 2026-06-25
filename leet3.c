#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct TreeNode* buildBST(int* nums, int left, int right) {
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;

    struct TreeNode* root = createNode(nums[mid]);

    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildBST(nums, 0, numsSize - 1);
}

void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int n = sizeof(nums) / sizeof(nums[0]);

    struct TreeNode* root = sortedArrayToBST(nums, n);

    printf("Preorder Traversal of BST:\n");
    preorder(root);

    return 0;
}
