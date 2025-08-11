#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int info) {
    if (root == NULL)
        return createNode(info);
    if (info < root->info)
        root->left = insertNode(root->left, info);
    else
        root->right = insertNode(root->right, info);
    return root;
}

int sameTree(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    if (root1->info != root2->info) {
        return 0;
    }

    return sameTree(root1->left, root2->right) && sameTree(root1->right, root2->left);
}

int symmetricTree(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    return sameTree(root->left, root->right);
}

int main() {
    struct Node* root = createNode(8);
    root->left = createNode(5);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(6);
    root->right->left = createNode(6);
    root->right->right = createNode(3);

    if (symmetricTree(root)) {
        printf("The tree is symmetric.\n");
    } else {
        printf("The tree is not symmetric.\n");
    }

    return 0;
}
