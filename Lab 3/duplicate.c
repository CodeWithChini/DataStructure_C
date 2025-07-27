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

    int hasDuplicate = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                hasDuplicate = 1;
                break;
            }
        }
        if (hasDuplicate) {
            break;
        }
    }

    if (hasDuplicate) {
        printf("The array contains duplicate numbers.\n");
    } else {
        printf("The array does not contain duplicate numbers.\n");
    }

    return 0;
}
