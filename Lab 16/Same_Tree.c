#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int info)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int info)
{
    if (root == NULL)
        return createNode(info);
    if (info < root->info)
        root->left = insertNode(root->left, info);
    else
        root->right = insertNode(root->right, info);
    return root;
}

int sameTree(struct Node* root1, struct Node* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
         return 1;
    }
    if (root1 == NULL || root2 == NULL)
    {
          return 0;
    }

    if(root1->info != root2->info)
    {
        return 0;
    }

    return sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);

}


int main()
{
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;
    int choice, data;
        printf("Enter data for first tree: ");
        scanf("%d", &data);
        root1 = insertNode(root1, data);
        printf("Enter data for second tree: ");
        scanf("%d", &data);
        root2 = insertNode(root2, data);
    while (1) {
        printf("\n\n--- Same Tree Menu ---\n");
        printf("1. Insert Node in First Tree\n");
        printf("2. Insert Node in Second Tree\n");
        printf("3. Check if both trees are same\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert in first tree: ");
                scanf("%d", &data);
                root1 = insertNode(root1, data);
                printf("Node Inserted in first tree.\n");
                break;

            case 2:
                printf("Enter data to insert in second tree: ");
                scanf("%d", &data);
                root2 = insertNode(root2, data);
                printf("Node Inserted in second tree.\n");
                break;

            case 3:
                if (sameTree(root1, root2)) {
                    printf("Both trees are same.\n");
                } else {
                    printf("Trees are not same.\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
}
}
