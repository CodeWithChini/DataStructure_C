#include<stdio.h>

int main()
{
    int n ,pos,num;
    scanf("%d", &n);
    int arr[n + 1];

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter insert num : ");
    scanf("%d", &num);
    printf("Enter position num : ");
    scanf("%d", &pos);


    if(pos < 0 || pos > n){
        printf("Invalid position");
        return 1;
    }

    for (int i = n; i > pos ;i--){
        arr[i] = arr[i - 1];
    }

    arr[pos] = num;

    for (int i = 0; i < n+1; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
