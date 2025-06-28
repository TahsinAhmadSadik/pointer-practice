#include <stdio.h>
#include <stdlib.h>

void findMinMax(int **a, int r, int c)
{
    int min = **a;
    int max = **a;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(*(*(a+i)+j) > max) max = *(*(a+i)+j);
            if(*(*(a+i)+j) < min) min = *(*(a+i)+j);
        }
    }

    printf("Max: %d, Min: %d", max, min);
}

void printMatrix(int **a, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++) printf("%d ", *(*(a+i)+j));
        printf("\n");
    }

}

void swapRow(int **a, int r, int c)
{
    int x,y;
    printf("Enter Two Row Numbers to Swap (from 0): ");
    scanf("%d %d", &x, &y);
    int *temp = *(a+x);
    *(a+x) = *(a+y);
    *(a+y) = temp;

    printMatrix(a,r,c);
}

void swapCol(int **a, int r, int c)
{
    int x,y;
    printf("Enter Two Column Numbers to Swap (from 0): ");
    scanf("%d %d", &x, &y);
    for(int i=0; i<r; i++)
    {
        int t = *(*(a+i)+x);
        *(*(a+i)+x) = *(*(a+i)+y);
        *(*(a+i)+y) = t;
    }

    printMatrix(a,r,c);
}

int main()
{
    //Row-Column Input
    int r,c;
    printf("Input row and column: ");
    scanf("%d %d", &r, &c);

    //Setting up matrix array
    int **a = malloc(r*sizeof(int *));

    //Matrix element input
    for(int i=0; i<r; i++)
    {
        printf("Input Row %d: ", i);
        int *row = malloc(c*sizeof(int));
        *(a+i) = row;
        for(int j=0; j<c; j++) scanf("%d", row+j);
    }

    //Task Handling (Comment Out One for Better Response)
    findMinMax(a, r, c);
    //swapRow(a, r, c);
    //swapCol(a, r, c);

    //Free Memory
    for(int i=0; i<r; i++) free(*(a+i));
    free(a);
}
