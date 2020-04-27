#include <stdio.h>
#include <stdlib.h>

// Driver program
int main(void)
{
    // This program will create same sequence of
    // random numbers on every program run
    FILE *fptr;

    // creating a file "random.txt" in "write" mode
    fptr = fopen("Source.txt", "w");
    long long i;
    if (fptr == NULL)
    {
        printf("ERROR");
        exit(1);
    }

    for (i = 0; i < 10000; i++)
    {

        // to generate number less than 100000
        int val = rand() % 1000000;

        // storing data to file
        fprintf(fptr, "%d ", val);
    }

    // closing the file
    fclose(fptr);
    printf("numbers generated successfully !! ");
    return 0;
}