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

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}