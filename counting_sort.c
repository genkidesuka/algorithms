#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h> // printf
void counting_sort(int input[], int output[], int size, int keys)
{
    int i;
    int occurences[keys];
    /* initialize occurences */
    for(i = 0; i < keys; i++)
        occurences[i] = 0;
    /* occurences contains the number of elements with key = i */
    for(i = 0; i < size; i++ )
    {
        //printf(" %d, ", input[i]);
        occurences[input[i]]++;
    }
    /* occurences contains the number of elements with key <= i */
    //printf(" %d, ", occurences[0]);
    for(i = 1; i < keys; i++)
    {
        occurences[i] += occurences[i-1];
        //printf(" %d, ", occurences[i]);
    }
    /* generate output */
    for(i = size-1; i >= 0; i--)
    {
        /* place input[i] in the sorted table */
        output[occurences[input[i]]-1] = input[i];
        /* update of next element's place */
        occurences[input[i]]--;
    }

}

/* usage: $ ./counting_sort <number> ... <number> <keys>
 * for example: input = [2 5 3 0 2 3 0 3] thus size = 8
 * (8 integers) and key = 6 (6 different integers)
 * -> $ ./counting_sort 2 5 3 0 2 3 0 3 6 
 */
int main(int argc, char **argv)
{
    int i;
    int input[argc-2];
    int output[argc-2];

    for(i = 0; i < argc-2; i++) 
        input[i] = atoi(*(argv+i+1));
    counting_sort(input, output, argc-2, atoi(*(argv+argc-1)));
    /* Display sorted array */
    for(i = 0; i < argc-2; printf(" %d,", output[i++]))
        ;
    printf("\n");
    return EXIT_SUCCESS;
}
