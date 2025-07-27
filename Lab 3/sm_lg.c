#include <stdio.h>
#include<limits.h>

int main()
{
    int n;

    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min = INT_MAX;
    int max = INT_MIN;
    int maxpos = -1;
    int minpos = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxpos = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            minpos = i;
        }
    }

    printf("Min position: %d, Max position: %d\n", minpos, maxpos);
    return 0;
}



/*
#include <stdio.h>
#include <limits.h> // For INT_MAX and INT_MIN

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be positive.\n");
        return 1; // Exit if the size is not positive
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = INT_MAX; // Initialize min to the maximum possible integer
    int max = INT_MIN; // Initialize max to the minimum possible integer
    int maxpos = -1;   // Initialize positions to -1 (invalid)
    int minpos = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxpos = i; // Update max position
        }
        if (arr[i] < min)
        {
            min = arr[i];
            minpos = i; // Update min position
        }
    }

    printf("Min position: %d, Max position: %d\n", minpos, maxpos);
    return 0;
}
*/
