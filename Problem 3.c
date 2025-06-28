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

    //Sort Column by Selection Sort
    for(int i=0; i<c; i++)
    {
        //sort this column
        for(int j=0; j<r; j++)
        {
            int min_idx = j;
            for(int k=j+1; k<r; k++)
            {
                int x = *(*(a+min_idx)+i);
                int y = *(*(a+k)+i);
                if(y < x) min_idx = k;
            }
            //swap
            int t = *(*(a+min_idx)+i);
            *(*(a+min_idx)+i) = *(*(a+j)+i);
            *(*(a+j)+i) = t;
        }
    }

    //Printing Transpose Matrix
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++) printf("%d ",*(*(a+i)+j));
        printf("\n");
    }

    //Free Memory
    for(int i=0; i<r; i++) free(*(a+i));
    free(a);
}
