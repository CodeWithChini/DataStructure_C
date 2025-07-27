#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* Rptr;
    struct Node* Lptr;
};

struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->Rptr = NULL;
    newNode->Lptr = NULL;
    return newNode;
}

void deleteAlternateNodes(struct Node** first) {
    struct Node* current = *first;
    struct Node* temp;
    int count = 0;

    while (current != NULL) {
        if (count % 2 == 1) {  // Delete every alternate node
            temp = current;
            if (current->Lptr != NULL) {
                current->Lptr->Rptr = current->Rptr; // Update left pointer of the previous node
            }
            if (current->Rptr != NULL) {
                current->Rptr->Lptr = current->Lptr; // Update right pointer of the next node
            }
            current = current->Rptr;
            free(temp);
        } else {
            current = current->Rptr;
        }
        count++;
    }
}

void displayList(struct Node* temp) {
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->Rptr;
    }
    printf("NULL\n");
}

struct Node* createListFromInput(int n) {
    if (n <= 0) return NULL;

    int value;
    struct Node* head = NULL;
    struct Node* last = NULL;

    for (int index = 0; index < n; index++) { 
        printf("Enter value for node %d: ", index + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode; // First node
            last = newNode;
        } else {
            last->Rptr = newNode; // Link new node to the end
            newNode->Lptr = last; // Link back to the previous node
            last = newNode; // Update last
        }
    }
    return head;
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node* temp = createListFromInput(n);

    printf("Original list:\n");
    displayList(temp);

    deleteAlternateNodes(&temp);

    printf("List after deleting alternate nodes:\n");
    displayList(temp);

    return 0;
}
