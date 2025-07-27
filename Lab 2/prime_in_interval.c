#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    int lower, upper;
    printf("Enter lower bound: ");
    scanf("%d", &lower);
    printf("Enter upper bound: ");
    scanf("%d", &upper);
    printf("Prime numbers between %d and %d are:\n", lower, upper);
    for (int num = lower; num <= upper; num++)
    {
        if (isPrime(num))
        {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}

