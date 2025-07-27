#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter a size: ");
    scanf("%d",&n);

    int sum = 0;
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);
    }
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    printf("sum = %d",sum);
}