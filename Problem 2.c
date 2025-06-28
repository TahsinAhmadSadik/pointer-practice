#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Input Row-Column
    int r,c;
    printf("Input row and column: ");
    scanf("%d %d", &r, &c);

    //Declare Matrix Array
    int **a = malloc(r*sizeof(int *));

    //Input Matrix Element
    for(int i=0; i<r; i++)
    {
        int *row = malloc(c*sizeof(int));
        *(a+i) = row;
        printf("Input Row %d: ", i);
        for(int j=0; j<c; j++) scanf("%d", row+j);
    }

    //Declare Transpose Matrix Array
    int **b = malloc(r*sizeof(int *));

    //Calculate Transpose Matrix
    for(int i=0; i<c; i++)
    {
        //row of original matrix is column of transpose matrix
        int *row = malloc(r*sizeof(int));
        *(b+i) = row;
        for(int j=0; j<r; j++) *(*(b+i)+j) = *(*(a+j)+i);
    }

    //Printing Transpose Matrix
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<r; j++) printf("%d ",*(*(b+i)+j));
        printf("\n");
    }

    //Free Memory
    for(int i=0; i<r; i++) free(*(a+i));
    for(int i=0; i<c; i++) free(*(b+i));
    free(a);
    free(b);
}
