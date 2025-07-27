#include <stdio.h>
#include <math.h>

int main() {
    int num, originalNum, remainder, result, digits;

    printf("Armstrong numbers between 1 and 1000 are:\n");

    for (num = 1; num <= 1000; num++) {
        originalNum = num;
        result = 0;
        digits = 0;

        while (originalNum != 0) {
            originalNum /= 10;
            digits++;
        }

        originalNum = num;

        while (originalNum != 0) {
            remainder = originalNum % 10;
            result += pow(remainder, digits);
            originalNum /= 10;
        }

        if (result == num) {
            printf("%d\n", num);
        }
    }

    return 0;
}
