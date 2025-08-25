#include<stdio.h>
#include<stdlib.h>
#define n 100

int arr[n], front = -1, rear = -1;

void insert_Circular_Queue()
{
  if(front == n)
  {
    rear = 0;
  }
  else
  {
    rear++;
  }

  if(front == rear)
  {
    printf("Circular Queue Overflow\n");
    return;
  }

  int x;
  printf("Enter value to be inserted: ");
    scanf("%d", &x);

    arr[rear] = x;
    if(front == -1)
    {
        front = 0;
    }
    return;
}

int delete_Circular_Queue()
{
    if(front == -1)
    {
        printf("Circular Queue Underflow\n");
        return -1;
    }

    int val = arr[front];

    if(front == rear)
    {
        front = rear = -1;
    }

    if(front == n-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return val;
}

void display_Circular_Queue()
{
    if(front == -1)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");
    if(rear >= front)
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        for(int i = front; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        for(int i = 0; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice, val;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert into Circular Queue\n");
        printf("2. Delete from Circular Queue\n");
        printf("3. Display Circular Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_Circular_Queue();
                break;
            case 2:
                val = delete_Circular_Queue();
                if(val != -1)
                {
                    printf("Deleted value: %d\n", val);
                }
                break;
            case 3:
                display_Circular_Queue();
                break;
            case 0:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}
