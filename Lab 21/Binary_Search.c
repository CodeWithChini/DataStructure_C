#include<stdio.h>

int Binary_Search(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2; // to avoid overflow

        if(arr[mid] == target)
        {
            return mid; // if target found ,it return index
        }
        else if(arr[mid] < target)
        {
            left = mid + 1; // search in right half
        }
        else
        {
            right = mid - 1; // search in left half
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

    printf("Note : Array should be in sorted order\n");
    for(int i = 0; i < n; i++)
    {
        printf("Enetr a element [%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter a element you want to find in array : ");
   scanf("%d", &target);

    int ans = Binary_Search(arr, n, target);
   printf("Your element at index %d", ans);
}
