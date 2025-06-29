#include <stdio.h>
#include <stdlib.h>

int main()
{
    //input main matrix
    int M,N,k;
    printf("Input M & N: ");
    scanf("%d %d", &M, &N);
    int **a = malloc(M*sizeof(int *));
    for(int i=0; i<M; i++)
    {
        printf("Input Row %d: ", i+1);
        int *row = malloc(N*sizeof(int));
        *(a+i) = row;
        for(int j=0; j<N; j++) scanf("%d", row+j);
    }
    //input kernel matrix
    printf("Input k: ");
    scanf("%d", &k);
    int **b = malloc(k*sizeof(int *));
    for(int i=0; i<k; i++)
    {
        printf("Input Row %d: ", i+1);
        int *row = malloc(k*sizeof(int));
        *(b+i) = row;
        for(int j=0; j<k; j++) scanf("%d", row+j);
    }
    //declare output matrix x*y
    int x = M-k+1;
    int y = N-k+1;
    int **c = malloc(x*sizeof(int *));
    for(int i=0; i<x; i++)
    {
        int *row = malloc(y*sizeof(int));
        *(c+i) = row;
        for(int j=0; j<y; j++)
        {
            //convolution
            int dot = 0;
            for(int l=0; l<k; l++)
            {
                for(int m=0; m<k; m++)
                {
                    dot += *(*(a+l+i)+m+j) * *(*(b+l)+m);
                }
            }
            *(row+j) = dot;
        }
    }
    //print output matrix x*y
    printf("Output:\n");
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++) printf("%d ", *(*(c+i)+j));
        printf("\n");
    }
    //free memory
    for(int i=0; i<M; i++) free(*(a+i));
    for(int i=0; i<k; i++) free(*(b+i));
    for(int i=0; i<x; i++) free(*(c+i));
    free(a);
    free(b);
    free(c);
}
