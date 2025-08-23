#include<stdio.h>


int Linear_Search(int arr[], int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            return i;  // if target found ,it return index
        }
    }
    return -1; // if target not found
}

int main()
{
    int n, target;
    printf("Enter Size of array : ");
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enetr a element [%d]", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter a element you want to find in array : ");
   scanf("%d", &target);

   int ans = Linear_Search(arr, n, target);
   printf("%d", ans);
}
