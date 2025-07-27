#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int unique[n];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;

        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            unique[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n");

    return 0;
}
