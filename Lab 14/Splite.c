#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};


struct Node* insertEnd(struct Node* first, int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;

    if (first == NULL) {
        first = newNode;
        newNode->link = first; // Point to itself for circularity
    } else {
        struct Node* temp = first;
        while (temp->link != first) {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = first;
    }
    return first;
}

void printList(struct Node* first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = first;
    do {
        printf("%d -> ", current->info);
        current = current->link;
    } while (current != first);
    printf("HEAD\n"); // Indicate circularity
}

void splitCircularList(struct Node* first, struct Node** f1, struct Node** f2) {
    struct Node* slow_ptr = first;
    struct Node* fast_ptr = first;

    if (first == NULL) {
        *f1 = NULL;
        *f2 = NULL;
        return;
    }

    // Find the middle of the list using slow and fast pointers
    while (fast_ptr->link != first && fast_ptr->link->link != first) {
        fast_ptr = fast_ptr->link->link;
        slow_ptr = slow_ptr->link;
    }

    // If there are an even number of nodes, fast_ptr will be at the last node
    if (fast_ptr->link->link == first) {
        fast_ptr = fast_ptr->link;
    }

    // Set head of first half
    *f1 = first;

    // Set head of second half
    *f2 = slow_ptr->link;

    // Make the first half circular
    slow_ptr->link = *f1;

    // Make the second half circular
    fast_ptr->link = *f2;
}

int main() {
    struct Node* first = NULL;
    struct Node* f1 = NULL;
    struct Node* f2 = NULL;
    int num, data;

    printf("Enter the number of nodes in the circular linked list: ");
    scanf("%d", &num);

    printf("Enter the data for each node:\n");
    for (int i = 0; i < num; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        first = insertEnd(first, data);
    }

    printf("\nOriginal Circular Linked List: ");
    printList(first);

    splitCircularList(first, &f1, &f2);

    printf("\nFirst Half of Circular Linked List: ");
    printList(f1);

    printf("Second Half of Circular Linked List: ");
    printList(f2);

    return 0;
}
