#include <stdio.h>

void selectionSort(int input[], int n)
{
	for(int i = 0; i < n-1; i++ )
    {
	// Find min element in the array
	int min = input[i], minIndex = i;

	for(int j = i+1; j < n; j++)
    {
		if(input[j] < min)
        {
			min = input[j];
			minIndex = j;
		}
	}
    
	// Swap
	int temp = input[i];
	input[i] = input[minIndex];
	input[minIndex] = temp;
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
    selectionSort(arr, n);
    printf("Sorted array is : ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
