#include <stdlib.h> //EXIT_SUCCESS
#include <stdio.h> //fprint

int max_int(int a, int b)
{
    return (a > b) ? a : b;
}
int find_pic(int input[], int start, int end)
{
    int mid = (end - start)/2;
    //printf("start = %d, mid = %d, end = %d\n", start, mid, end);
    if(end - start == 0) return input[mid];
    if(end - start == 1) return max_int(input[start], input[end]);
    /* pic is in left part */
    if(input[mid] < input[mid-1])
        return find_pic(input, start, mid-1);
    /* pic is in right part */
    else if(input[mid] < input[mid+1])
        return find_pic(input, mid+1, end);
    else return input[mid];
}
int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
        printf("Usage:$ ./a.out <number> ... <number>\n");
        return EXIT_FAILURE;
    }
    int input[argc-1];
    /* init input */
    for(int i = 0; i < argc-1; i++)
    {
        input[i] = atoi(*(argv+i+1));
        printf(" %d,", input[i]);
    }
    printf("\n");
    printf("pic = %d\n", find_pic(input, 0, argc-2));
    return EXIT_SUCCESS;
}
