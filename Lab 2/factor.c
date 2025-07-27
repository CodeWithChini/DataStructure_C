#include<stdio.h>
void main()
{
    int factor = 1 , n , i = 1 ;
    printf("Enter an num : ");
    scanf("%d" , &n);

    while(i <= n)
    {
        if(n % i == 0)
        {
            printf("%d " , i);
            i++;
        }
        else
        {
            i++;
        }
    }
   // printf("%d", i);
}
