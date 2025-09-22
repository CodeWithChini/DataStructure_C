#include <stdio.h>
#include <stdlib.h>

// Define colors
enum Color { RED, BLACK };

// Red-Black Tree node structure
struct Node {
    int data;
    enum Color color;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
};

// Global root of the tree
struct Node *root = NULL;

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always red initially
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Left rotation
void leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Right rotation
void rightRotate(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

// Function to fix violations after insertion
void fixInsert(struct Node* k) {
    struct Node* u; // uncle node
    while (k != root && k->parent->color == RED) {
        if (k->parent == k->parent->parent->left) { // Parent is left child of grandparent
            u = k->parent->parent->right; // Uncle is right child
            if (u != NULL && u->color == RED) { // Case 1: Uncle is red
                k->parent->color = BLACK;
                u->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else { // Case 2 & 3: Uncle is black or NULL
                if (k == k->parent->right) { // Case 2: K is right child
                    k = k->parent;
                    leftRotate(k);
                }
                // Case 3: K is left child
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        } else { // Parent is right child of grandparent (symmetric cases)
            u = k->parent->parent->left; // Uncle is left child
            if (u != NULL && u->color == RED) { // Case 1: Uncle is red
                k->parent->color = BLACK;
                u->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else { // Case 2 & 3: Uncle is black or NULL
                if (k == k->parent->left) { // Case 2: K is left child
                    k = k->parent;
                    rightRotate(k);
                }
                // Case 3: K is right child
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        }
    }
    root->color = BLACK; // Root must always be black
}

// Insertion function
void insert(int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (newNode->data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (parent == NULL) {
        root = newNode;
    } else if (newNode->data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    fixInsert(newNode);
}

// Inorder traversal to print the tree
void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d (%s) ", node->data, (node->color == RED ? "RED" : "BLACK"));
        inorderTraversal(node->right);
    }
}

// Main function for testing
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);
    insert(5);

    printf("Inorder traversal of Red-Black Tree: \n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
