#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h> // printf
#include <math.h> //log, pow

/* return the digit at position position in number */
int get_digit(int number, int position, int base)
{
    int tmp = pow(base, position);
    return (number/tmp)%base;
}

void counting_sort(int input[], int output[], int size, int keys, int position)
{
    int i, tmp, base = keys;
    int occurences[keys];
    /* initialize occurences */
    for(i = 0; i < keys; i++)
        occurences[i] = 0;
    /* occurences contains the number of elements with key = i */
    for(i = 0; i < size; i++ )
    {
        tmp = get_digit(input[i], position, base);
        //printf(" %d, ", input[i]);
        occurences[tmp]++;
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
        tmp = get_digit(input[i], position, base);
        /* place input[i] in the sorted table */
        output[occurences[tmp]-1] = input[i];
        /* update of next element's place */
        occurences[tmp]--;
    }
}

void radix_sort(int input[], int output[], int size, int keys, int base)
{
    int i;
    int digits = (int)log(keys)/log(base)+1;
    //printf(" digits = %d\n", digits);
    for(i = 0; i < digits; i++)
    {
        //printf(" i = %d\n", i);
        counting_sort(input, output, size, base, i);
        /* copy the output into input */
        for(int j = 0; j < size; printf(" %d,", output[j++]))
            input[j] = output[j];
        printf("\n");
    }
}

/* usage: $ ./radix_sort <number> ... <numbers> <keys>
 * example: $ ./radix_sort 42 25 3 80 62 30 33 30 5 3 100
 * sort into [3, 3, 5, 25, 30, 30, 33, 42, 62, 80]
 */
int main(int argc, char **argv)
{
    int i, base = 10;
    int input[argc-2];
    int output[argc-2];

    for(i = 0; i < argc-2; i++) 
        input[i] = atoi(*(argv+i+1));
    radix_sort(input, output, argc-2, atoi(*(argv+argc-1)), base);
    /* Display sorted array */
    for(i = 0; i < argc-2; printf(" %d,", output[i++]))
        ;
    printf("\n");
    return EXIT_SUCCESS;
}
