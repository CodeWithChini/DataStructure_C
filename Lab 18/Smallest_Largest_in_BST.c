// 80. WAP to find the smallest and largest elements in the Binary Search Tree.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node* createNode(int info)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->lptr = newNode->rptr = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int info)
{
    if (root == NULL)
    {
        return createNode(info);
    }
    if (info < root->info)
    {
        root->lptr = insertNode(root->lptr, info);
    }
    else
    {
        root->rptr = insertNode(root->rptr, info);
    }
    return root;
}

struct Node* smallest_Node(struct Node* root)
{
    while(root && root->lptr != NULL)
    {
        root = root->lptr;
    }
    return root;
}


struct Node* largest_Node(struct Node* root)
{
    while(root && root->rptr != NULL)
    {
        root = root->rptr;
    }
    return root;
}

int main()
{
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n\n--- BST Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Find smallest node\n");
        printf("3. Find largest node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("Node Inserted.\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    struct Node* smallest = smallest_Node(root);
                    printf("Smallest Node: %d\n", smallest->info);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    struct Node* largest = largest_Node(root);
                    printf("Smallest Node: %d\n", largest->info);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
