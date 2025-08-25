#include<stdio.h>
#include<stdlib.h>
#define n 100

int arr[n], front = -1, rear = -1;

void enqueue()
{
    if(rear >= n-1)
    {
        printf("Queue Overflow\n");
        return;
    }

    int x;
    printf("Enter value to be inserted: ");
    scanf("%d", &x);

    if(front == -1)
    {
        front = 0;
    }

    rear++;
    arr[rear] = x;
}

int dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
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

void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
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
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                val = dequeue();
                if(val != -1)
                {
                    printf("Dequeued: %d\n", val);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
