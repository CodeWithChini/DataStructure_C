#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int x)
{
    if (root == NULL)
    {
        return createNode(x);
    }
    if(root->left == NULL)
    {
        root->left = createNode(x);
    }
     else if (root->right == NULL)
     {
        root->right = createNode(x);
    }
     else
     {
        root->left = insertNode(root->left, x);
    }
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {

    struct Node* root = NULL;
    int data;
    printf("Enter root node data: ");
    scanf("%d", &data);
    root = createNode(data);

    int choice, x;
    do {
        
    }


    // // root->left = createNode(2);
    // // root->right = createNode(3);
    // // root->left->left = createNode(4);
    // // root->left->right = createNode(5);

    // printf("Inorder Traversal: ");
    // inorder(root);

    // printf("\nPreorder Traversal: ");
    // preorder(root);

    // printf("\nPostorder Traversal: ");
    // postorder(root);

    // return 0;
}
