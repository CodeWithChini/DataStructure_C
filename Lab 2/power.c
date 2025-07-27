#include<stdio.h>
void main()
{
    int exeponent , base , n = 1 , ans = 1;
    printf("Enter base : ");
    scanf("%d", &base);
    printf("Enter exeponant : ");
    scanf("%d" , &exeponent);

    while(n <= exeponent)
    {
        ans = base * ans;
        n++;
    }
    printf("%d", ans);
}
