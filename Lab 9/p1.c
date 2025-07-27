#include<stdio.h>
#include<stdlib.h>
int main(){
    int *iptr = (int*)malloc(sizeof(int));
    char *cptr = (char*)malloc(sizeof(char));
    float *fptr = (float*)malloc(sizeof(float));

    if(iptr && cptr && fptr){
        *iptr = 22;
        *cptr = 'J';
        *fptr = 22.29;

        printf("%d\n",*iptr);
        printf("%c\n",*cptr);
        printf("%.2f\n",*fptr);

        free(iptr);
        free(cptr);
        free(fptr);
    }
    else{
        printf("Memory allocated invalid.");
    }
    return 0;
}