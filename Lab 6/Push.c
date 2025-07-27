#include <stdio.h>
#include <stdlib.h>
#define size 100

int stack[size];
int top = -1;

void stackPush(int x) {
    if (top >= size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = x;
}

int stackPop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int stackPeep(int pos) {
    if (top - pos + 1 < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top - pos + 1];
}

void stackChange(int x, int pos) {
    if (top - pos + 1 < 0) {
        printf("Stack Underflow\n");
        return;
    }
    stack[top - pos + 1] = x;
}

void display() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, item, index, newValue;

    while (1) {
        printf("\nMenu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                stackPush(item);
                break;
            case 2:
                item = stackPop();
                if (item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;
            case 3:
                printf("Enter the position to peep: ");
                scanf("%d", &index);
                item = stackPeep(index);
                if (item != -1) {
                    printf("Item at position %d: %d\n", index, item);
                }
                break;
            case 4:
                printf("Enter the index to change: ");
                scanf("%d", &index);
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                stackChange(newValue, index);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
