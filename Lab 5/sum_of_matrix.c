#include<stdio.h>

int main()
{
    int mat1[2][2];
    int mat2[2][2];
    int sum[2][2];


    printf("matrix 1 :");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter a element of mat[%d][%d] :\n", i, j);
            scanf("%d\n" ,&mat1[i][j]);
        }
    }


    printf("matrix 2 :");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter a element of mat[%d][%d] :\n", i, j);
            scanf("%d\n" ,&mat2[i][j]);
        }
}
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d", sum[i][j]);
        }
        printf("\n");
    }
}
