// 79. Write a program to construct a binary tree from given Postorder and Preorder
// traversal sequence.

#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode { 
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to search for an element in an array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive function to construct binary tree from preorder and postorder traversals
struct TreeNode* buildTreeFromPrePost(int pre[], int post[], int* preIndex,
                                     int postStart, int postEnd, int size) {
    // Base case
    if (*preIndex >= size || postStart > postEnd) {
        return NULL;
    }

    // The first element in preorder is the root
    struct TreeNode* root = createNode(pre[*preIndex]);
    (*preIndex)++;

    // If there are no more elements to process
    if (postStart == postEnd) {
        return root;
    }

    // Find the next element of pre[] in post[]
    int nextInPost = search(post, postStart, postEnd, pre[*preIndex]);

    if (nextInPost != -1) {
        // Construct left subtree
        root->left = buildTreeFromPrePost(pre, post, preIndex, postStart, nextInPost, size);

        // Construct right subtree
        root->right = buildTreeFromPrePost(pre, post, preIndex, nextInPost + 1, postEnd - 1, size);
    }

    return root;
}

// Wrapper function to build tree
struct TreeNode* buildTree(int pre[], int post[], int size) {
    int preIndex = 0;
    return buildTreeFromPrePost(pre, post, &preIndex, 0, size - 1, size);
}

// Utility function for inorder traversal (for verification)
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Utility function for preorder traversal
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Utility function for postorder traversal
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to free the memory allocated for the tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Example test case
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    printf("Given Preorder: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", preorder[i]);
    }
    printf("\n");

    printf("Given Postorder: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", postorder[i]);
    }
    printf("\n");

    // Build the tree
    struct TreeNode* root = buildTree(preorder, postorder, size);

    // Verify by printing traversals
    printf("\nConstructed Tree Traversals:\n");
    printf("Inorder: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder: ");
    postorderTraversal(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}
