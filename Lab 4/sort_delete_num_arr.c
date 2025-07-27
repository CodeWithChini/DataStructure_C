#include <stdio.h>

int main() {
    int n, num, pos = -1;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d sorted elements in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to delete: ");
    scanf("%d", &num);

    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Number %d not found in the array.\n", num);
        return 0;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;


    printf("Array after deleting %d:\n", num);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
