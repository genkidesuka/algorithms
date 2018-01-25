#include <stdlib.h> //EXIT_SUCCESS
#include <stdio.h> //fprint
#include <time.h> //time

#define SIZE 10

typedef struct coord_t
{
    int col, row;
}coord_t;

int find_max(int line[])
{
    int max = SIZE-1;
    for(int i = 0; i < SIZE; i++)
    {
        if(line[max] < line[i]) max = i;
    }
    return max;
}

coord_t* find_pic2D(int input[SIZE][SIZE], int start, int end)
{
    int mid = (end-start)/2;

    coord_t* max = malloc(sizeof coord_t);
    max->row = mid;
    max->col = find_max(input[mid]);

    if(end - start == 0) return find_max(input[mid]);
    else if(end - start == 1)
        if(input[end][
    /* Incomplete */
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int input[SIZE][SIZE];
    /* init input */
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            input[i][j] = rand()%SIZE;
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("max = %d\n", input[0][find_max(input[0])]);
    return EXIT_SUCCESS;
}
