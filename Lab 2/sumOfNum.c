#include <stdio.h>

int main() {
    int n, totalSum = 0;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    for (int k = 1; k <= n; k++) {
        totalSum += (k * (k + 1)) / 2; 
    }

    printf("The sum of the series is: %d\n", totalSum);

    return 0;
}
