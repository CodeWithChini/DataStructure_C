#include<stdio.h>


void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++) //n-i-1 because last i elements are already sorted
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        printf("Enter a element [%d] : ", i);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array is : ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
