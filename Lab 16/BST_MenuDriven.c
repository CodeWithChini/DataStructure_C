#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

//search a node in tree
int Search_in_BST(struct Node * root, int x)
{
    if(root == NULL)
    {
        // printf("Tree is Empty");
        return 0;
    }

    if(x > root->data)
    {
        return Search_in_BST(root->right, x);
    }
    else if(x < root->data)
    {
        return Search_in_BST(root->left, x);
    }
    return 1;
}

//delete a node in tree
struct Node * delete(struct Node * root, int x)
{
     if(root == NULL)
    {
        printf("Tree is Empty");
        return 0;
    }

    if(x > root->data)
    {
        return delete(root->right, x);
    }
    else if(x < root->data)
    {
        return delete(root->left, x);
    }
    else if(root->left==NULL)
        {
            struct Node * temp = root->right;
             free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct Node * temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
        return root;
    }
    struct Node* temp = root->left;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    temp->right = root->right;
    free(root);
    return temp;

};


// Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n\n--- Binary Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search a Node\n");
        printf("6. delete a Node\n");
        printf("7. Exit\n");
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
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
               printf("Search a Node in BST:\n ");
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (Search_in_BST(root, data)) {
                    printf("Node %d found in the BST.\n", data);
                } else {
                    printf("Node %d not found in the BST.\n", data);
                }
                printf("Search completed.\n");
                break;

            case 6:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("Node Deleted.\n");
                printf("\n");
                break;

                case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}
