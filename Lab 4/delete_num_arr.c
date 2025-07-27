#include<stdio.h>

int main()
{
    int n ,pos,num;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter delete num : ");
    scanf("%d", &num);
    printf("Enter position num : ");
    scanf("%d", &pos);

    if(pos < 0 || pos > n)
    {
        printf("Invalid position");
        return 1;
    }

    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}



