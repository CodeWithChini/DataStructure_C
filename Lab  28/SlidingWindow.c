#include<stdio.h>

int main()
{
    int arr[] = {1,2,1,0,1,1,0};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);

    if(n < k)
    {
        printf("Array size is not valid");
        return 0;
    }

    int currSum = 0;
    for(int i = 0; i < k ; i++)
    {
        currSum += arr[i];
    }
    int maxSum = currSum;

    for(int i = k ; i < n ; i++)
    {
        currSum += arr[i] - arr[i - k];
        if(currSum > maxSum)
        {
            maxSum = currSum;
        }
    }
    printf("%d", maxSum);

    return 0;
}
