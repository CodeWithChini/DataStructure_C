#include<stdio.h>


int main() {
    int ar1[3][2], ar2[2][3], ans[3][3] = {0}; // Initialize ans to 0

    printf("Enter elements of matrix 1 (3x2):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &ar1[i][j]);
        }
    }

    printf("Enter elements of matrix 2 (2x3):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &ar2[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans[i][j] = 0; // Initialize the current element to 0
            for (int k = 0; k < 2; k++) {
                ans[i][j] += ar1[i][k] * ar2[k][j];
            }
        }
    }


    printf("Resultant matrix (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}

