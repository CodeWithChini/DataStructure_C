#include<stdio.h>
#include<stdlib.h>
#define n 100

int arr[n], front = -1, rear = -1;

void insertAtFront()
{
    if(front == 0) // Changed condition - only prevent insertion if front is at index 0
    {
        printf("Deque Overflow at front end\n");
        return;
    }

    int x;
    printf("Enter value to be inserted at front: ");
    scanf("%d", &x);

    if(front == -1) // Deque is empty
    {
        front = rear = 0;
    }
    else
    {
        front--; // Move front backwards
    }
    arr[front] = x;
    return;
}

void insertAtRear()
{
    if(rear >= n-1)
    {
        printf("Deque Overflow at rear end\n");
        return;
    }

    int x;
    printf("Enter value to be inserted at rear: ");
    scanf("%d", &x);

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = x;
    return;
}

int deleteFromFront()
{
    if(front == -1)
    {
        printf("Deque Underflow at front end\n");
        return -1;
    }

    int val = arr[front];

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return val;
}

int deleteFromRear()
{
    if(front == -1)
    {
        printf("Deque Underflow at rear end\n");
        return -1;
    }

    int val = arr[rear];

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
    return val;
}

void displayDeque()
{
    if(front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice, val;
    while(1)
    {
        printf("\nDouble Ended Queue Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertAtFront();
                break;
            case 2:
                insertAtRear();
                break;
            case 3:
                val = deleteFromFront();
                if(val != -1)
                    printf("Deleted from front: %d\n", val);
                break;
            case 4:
                val = deleteFromRear();
                if(val != -1)
                    printf("Deleted from rear: %d\n", val);
                break;
            case 5:
                displayDeque();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
