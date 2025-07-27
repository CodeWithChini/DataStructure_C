#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter a size:");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int));
    for(int i=0; i<n ;i++){
        scanf("%d",arr+i);
    }
    
    int max = arr[0];
    for(int i=0; i<n ;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("largest num = %d",max);
}