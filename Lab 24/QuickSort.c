#include<stdio.h>

void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for(int j = low; j < high; j++)
        {
            if(arr[j] < pivot)
            {
                i++;                    int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
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
    QuickSort(arr, 0, n - 1);
    printf("Sorted array is : ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
