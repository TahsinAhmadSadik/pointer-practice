#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void fillPlane(int ***a, int N, int s, int sqr)
{
    //random seed
    srand(time(NULL) + s);
    for(int i=0; i<N; i++)
    {
        //create R*C Matrix
        //if square base then all matrix should be 1*N
        //else a matrix will be i*i
        int R,C;
        R = (sqr == 1) ? 1 : i+1;
        C = (sqr == 1) ? N : i+1;

        int **m = malloc(R*sizeof(int *));
        *(a+i) = m;
        for(int j=0; j<R; j++)
        {
            int *r = malloc(C*sizeof(int));
            *(m+j) = r;
            //fill elements
            for(int k=0; k<C; k++)
            {
                *(r+k) = rand()%10;
                //if(sqr==1) printf("%d ", *(r+k));
            }
        }
    }
}

void printPlane(int ***a, int N, int sqr)
{
    for(int i=0; i<N; i++)
    {
        //inside matrix


        //print  R*C Matrix
        //if square base then all matrix should be 1*N
        //else a matrix will be i*i
        int R,C;
        R = (sqr == 1) ? 1 : i+1;
        C = (sqr == 1) ? N : i+1;

        for(int j=0; j<R; j++)
        {
            //inside row
            //fill space
            if(sqr == 0) for(int q=0; q < N-R; q++) printf(" ");
            //print element
            for(int k=0; k<C; k++)
            {
                //inside cell
                printf("%d ", *(*(*(a+i)+j)+k));
            }
            //fill space
            if(sqr == 0) for(int q=0; q < N-R; q++) printf(" ");
            printf("\n");
        }
    }
}

int main()
{
    //input N
    int N;
    printf("Input N: ");
    scanf("%d", &N);

    //Create Surfaces (a,b,c,d are triangular and e is square)
    int ***a = malloc(N*sizeof(int **));
    int ***b = malloc(N*sizeof(int **));
    int ***c = malloc(N*sizeof(int **));
    int ***d = malloc(N*sizeof(int **));
    int ***e = malloc(N*sizeof(int **));

    //Fill the Plane
    fillPlane(a, N, 0, 0);
    fillPlane(b, N, 1, 0);
    fillPlane(c, N, 2, 0);
    fillPlane(d, N, 3, 0);
    fillPlane(e, N, 4, 1);

    //Print the Plane
    int n;
    printf("Enter plane index (1-5): ");
    scanf("%d", &n);
    while(n)
    {
        if(n == 1) printPlane(a,N, 0);
        else if(n == 2) printPlane(b,N, 0);
        else if(n == 3) printPlane(c,N, 0);
        else if(n == 4) printPlane(d,N, 0);
        else if(n == 5) printPlane(e,N, 1);
        else printf("Plane does not exist.\n");
        printf("Enter plane index (1-5): ");
        scanf("%d", &n);
    }

    printf("Exiting program.");
}

