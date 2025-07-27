#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};

struct Node *first = NULL;
struct Node *AVAIL = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->link = NULL;
    return newNode;
}

void initializeAVAIL(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        struct Node* newNode = createNode(0);
        newNode->link = AVAIL;
        AVAIL = newNode;
    }
}

struct Node* CopyLL() {
    if (first == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *newNode = NULL;
    if (AVAIL == NULL) {
        printf("Underflow\n");
        return NULL;
    } else {
        newNode = AVAIL;
        AVAIL = AVAIL->link;
        newNode->info = first->info;
    }

    struct Node *save = first;
    struct Node *pred = newNode;

    while (save->link != NULL) {
        if (AVAIL == NULL) {
            printf("Underflow\n");
            return NULL;
        } else {
            struct Node *temp = AVAIL;
            AVAIL = AVAIL->link;
            temp->info = save->link->info;
            pred->link = temp;
            pred = temp;
        }
        save = save->link;
    }
    pred->link = NULL;
    return newNode;
}

void printLL(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

void addNode(int value) {
    struct Node* newNode = createNode(value);
    if (first == NULL) {
        first = newNode;
    } else {
        struct Node* temp = first;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

int main() {
    int numNodes, value;
\
    printf("Enter the number of nodes for the AVAIL list: ");
    scanf("%d", &numNodes);
    initializeAVAIL(numNodes);

    printf("Enter the values for the linked list (enter -1 to stop):\n");
    while (1) {
        printf("Value: ");
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        addNode(value);
    }

    struct Node *copiedList = CopyLL();

    printf("Copied List: ");
    printLL(copiedList); 

    return 0;
}
