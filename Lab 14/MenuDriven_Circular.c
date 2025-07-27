#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

struct Node* insertAtFront(struct Node* first, int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;

    if (first == NULL) {
        newNode->link = newNode; // Point to itself
        return newNode; // New node is the only node
    }

    struct Node* temp = first;
    while (temp->link != first) {
        temp = temp->link; // Find the last node
    }
    temp->link = newNode; // Last node points to new node
    newNode->link = first; // New node points to the first node
    return newNode; // New node becomes the new head
}

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (!head) return NULL;

    struct Node *temp = head, *toDelete = NULL;

    if (position == 0) {
        while (temp->link != head) {
            temp = temp->link; // Find the last node
        }
        toDelete = head;
        if (head == head->link) {
            head = NULL; // Only one node in the list
        } else {
            head = head->link; // Move head to the next node
            temp->link = head; // Last node points to new head
        }
        free(toDelete);
        return head;
    }

    for (int i = 0; i < position - 1 && temp->link != head; i++) {
        temp = temp->link; // Traverse to the node before the one to delete
    }

    if (temp->link == head) return head; // Position is out of bounds
    toDelete = temp->link;
    temp->link = toDelete->link; // Bypass the node to delete
    free(toDelete);

    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;

    if (!head) {
        newNode->link = newNode; // Point to itself
        return newNode; // New node is the only node
    }

    struct Node* temp = head;
    while (temp->link != head) {
        temp = temp->link; // Find the last node
    }
    temp->link = newNode; // Last node points to new node
    newNode->link = head; // New node points to head
    return head;
}

void display(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->info);
        temp = temp->link;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Delete at position\n");
        printf("3. Insert at end\n");
        printf("4. Display all nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
