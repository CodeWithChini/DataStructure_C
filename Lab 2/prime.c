#include<stdio.h>

int main(){
    int n, i = 2, isprime = 1;
    scanf("%d", &n);

    if(n <= 1){
        isprime = 0;
    }
    else
    {
        while (i<= n/2)
        {
            if(n % i == 0){
                isprime = 0;
                break;
            }
            i++;
        }
    }

    if(isprime == 1)
    {
        printf("Prime");
    }
    else
    {
        printf("Not Prime");
    }
}
