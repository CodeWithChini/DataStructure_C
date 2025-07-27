#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int num1, num2;

    printf("Enter the first number to replace: ");
    scanf("%d", &num1);
    printf("Enter the second number to replace with: ");
    scanf("%d", &num2);

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num1) {
            arr[i] = num2;
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Replaced %d with %d at index %d.\n", num1, num2, index);
    } else {
        printf("%d not found in the array.\n", num1);
    }

    printf("Final array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
