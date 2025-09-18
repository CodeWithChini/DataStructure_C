#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int isBalanced(struct Node* root) {
    if (root == NULL) {
        return 1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return 1;
    }

    return 0;
}

int main() {
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    if (isBalanced(root1)) {
        printf("Tree 1 is height-balanced.\n");
    } else {
        printf("Tree 1 is not height-balanced.\n");
    }

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->left->left = newNode(3);
    root2->left->left->left = newNode(4);

    if (isBalanced(root2)) {
        printf("Tree 2 is height-balanced.\n");
    } else {
        printf("Tree 2 is not height-balanced.\n");
    }

    return 0;
}
