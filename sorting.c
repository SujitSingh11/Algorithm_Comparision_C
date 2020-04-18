#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100

// Count number of digits
int count_digit(unsigned long long int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10; // n = n/10
        ++count;
    }

    return count;
}

// Printing Algorithm Preformance to file
void algo_preformance_offset(unsigned long long int comp, unsigned long long int iter, unsigned long long int swaps, int offset)
{
    FILE *ofp;
    // Table elements
    char slash[] = "_";
    char dash[] = "|";
    char space[] = " ";
    char newline[] = "\n";
    ofp = fopen("Output_Sorting.txt", "a");
    char s_comp[1000], s_iter[1000], s_swaps[1000];
    sprintf(s_comp, "%llu", comp);
    sprintf(s_iter, "%llu", iter);
    sprintf(s_swaps, "%llu", swaps);

    int comp_count = count_digit(comp);
    int iter_count = count_digit(iter);
    int swaps_count = count_digit(swaps);
    if (offset == 0)
    {
        swaps_count = swaps_count + 1;
    }
    int tc = 0;

    fputs(s_iter, ofp);
    while (tc <= (14 - iter_count))
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs(s_comp, ofp);
    while (tc <= (14 - comp_count))
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs(s_swaps, ofp);
    while (tc <= (12 - swaps_count))
    {
        fputs(space, ofp);
        tc++;
    }
    fputs(dash, ofp);
    fclose(ofp);
}
void algo_preformance(unsigned long long int comp, unsigned long long int iter, unsigned long long int swaps)
{
    FILE *ofp;
    // Table elements
    char slash[] = "_";
    char dash[] = "|";
    char space[] = " ";
    char newline[] = "\n";
    ofp = fopen("Output_Sorting.txt", "a");

    char s_comp[1000], s_iter[1000], s_swaps[1000];

    sprintf(s_comp, "%llu", comp);
    sprintf(s_iter, "%llu", iter);
    sprintf(s_swaps, "%llu", swaps);

    int comp_count = count_digit(comp);
    int iter_count = count_digit(iter);
    int swaps_count = count_digit(swaps);

    int tc = 0;

    fputs(s_iter, ofp);
    while (tc <= (14 - iter_count))
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs(s_comp, ofp);
    while (tc <= (14 - comp_count))
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs(s_swaps, ofp);
    while (tc <= (12 - swaps_count))
    {
        fputs(space, ofp);
        tc++;
    }
    fputs(dash, ofp);
    fclose(ofp);
}

// Insertion Sort
void insertion_sort(int arr[], int size, int offset)
{
    int i, j;
    int data[size];
    int temp;
    unsigned long long int swaps = 0, iter = 0, comp = 0;

    // Local Copy of Array so no changes occurs to orignal
    for (i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }

    // Alternate Method
    // Insertion Sort
    // for (i = 1; i < size; i++)
    // {
    //     temp = data[i];                      // 2
    //     j = i - 1;                           //0
    //     while ((temp < data[j]) && (j >= 0)) // 1<2
    //     {
    //         data[j + 1] = data[j]; //
    //         swaps++;
    //         j = j - 1;
    //         comp++;
    //     }
    //     iter++;
    //     data[j + 1] = temp;
    // }

    for (i = 0; i < size; i++)
    {
        // Search for Insertion Point
        for (j = i; j > 0; j--)
        {
            comp++;
            if (data[j] < data[j - 1])
            {
                // Swap
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
                swaps++;
            }
            else
            {
                break;
            }
        }
        iter++;
    }
    printf("\n\nInsertion Sort: ");
    // printf("\nSorted Data: ");
    // for (i = 0; i < size; i++)
    // {
    //     printf("%d ", data[i]);
    // }
    printf("\nNumber of Comparisons: %lu", comp);
    printf("\nNumber of Iteration: %lu", iter);
    printf("\nNumber of Swap: %lu", swaps);
    algo_preformance_offset(comp, iter, swaps, offset);
}

// Bubble Sort
void bubble_sort(int arr[], int size, int offset)
{
    int i, j;
    int data[size];
    int temp, swapped;
    unsigned long long int swaps = 0, iter = 0, comp = 0;

    // Local Copy of Array so no changes occurs to orignal
    for (i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }

    // Bubble Sort with early exit
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            comp++;
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                swaps++;
            }
        }
        iter++;
    }

    printf("\nBubble Sort: ");
    // printf("\nSorted Data: ");
    // for (i = 0; i < size; i++)
    // {
    //     printf("%d ", data[i]);
    // }
    printf("\nNumber of Comparisons: %lu", comp);
    printf("\nNumber of Iteration: %lu", iter);
    printf("\nNumber of Swap: %lu", swaps);

    algo_preformance_offset(comp, iter, swaps, offset);
}

void bubble_sort_early_exit(int arr[], int size, int offset)
{
    int i, j;
    int data[size];
    int temp, swapped;
    unsigned long long int swaps = 0, iter = 0, comp = 0;

    // Local Copy of Array so no changes occurs to orignal
    for (i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }

    // Bubble Sort with early exit
    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            comp++;
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                swaps++;
                swapped = 1;
            }
        }
        iter++;
        if (swapped == 0)
            break;
    }

    printf("\nBubble Sort Early Exit: ");
    // printf("\nSorted Data: ");
    // for (i = 0; i < size; i++)
    // {
    //     printf("%d ", data[i]);
    // }
    printf("\nNumber of Comparisons: %lu", comp);
    printf("\nNumber of Iteration: %lu", iter);
    printf("\nNumber of Swap: %lu", swaps);
    algo_preformance_offset(comp, iter, swaps, offset);
}

// Quick Sort

// Quick Sort partition (Problem with large dataset)
int quick_sort_partiton(int data[], long int low, long int high, unsigned long long int **comp, unsigned long long int **iter, unsigned long long int **swaps)
{
    long int i = 0, j = high + 1;
    long int temp;

    while (1)
    {
        // Find item on left to swap
        while (data[++i] < data[low])
        {
            **comp = **comp + 1;
            if (i == high)
            {
                **comp = **comp + 1;
                break;
            }
        }

        // Find item on right to swap
        while (data[low] < data[--j])
        {
            **comp = **comp + 1;
            if (j == low)
            {
                **comp = **comp + 1;
                break;
            }
        }

        // Check if pointer cross
        if (i >= j)
        {
            **comp = **comp + 1;
            break;
        }

        // Swap
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        **swaps = **swaps + 1;
    }

    // Swap
    temp = data[low];
    data[low] = data[j];
    data[j] = temp;
    **swaps = **swaps + 1;

    return j;
}

void sort(int data[], long int low, long int high, unsigned long long int *comp, unsigned long long int *iter, unsigned long long int *swaps)
{
    if (high <= low)
    {
        *comp = *comp + 1;
        return;
    }

    // Initial Partition
    long int j = quick_sort_partiton(data, low, high, &comp, &iter, &swaps);

    *iter = *iter + 1;
    // Recursively Partitioning and sorting
    // Left Side
    sort(data, low, j - 1, comp, iter, swaps);
    // Right Side
    sort(data, j + 1, high, comp, iter, swaps);
}

void quick_sort(int arr[], int size)
{
    long int low = 0, high = size;
    int data[size];
    long int i, j;
    unsigned long long int comp = 0, iter = 0, swaps = 0;
    FILE *ofp;
    ofp = fopen("Output_Sorting.txt", "a");

    // Local Copy of Array so no changes occurs to orignal
    for (i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }

    // Random Shuffle

    // Sort
    sort(data, low, high - 1, &comp, &iter, &swaps);

    printf("\nQuick Sort: ");
    // printf("\nSorted Data: ");
    // for (i = 0; i < size; i++)
    // {
    //     printf("%d ", data[i]);
    // }
    printf("\nNumber of Comparisons: %lu", comp);
    printf("\nNumber of Iteration: %lu", iter);
    printf("\nNumber of Swap: %lu", swaps);

    algo_preformance(comp, iter, swaps);
}

// Print in File
void table_header()
{
    FILE *ofp;
    // Table elements
    char slash[] = "_";
    char dash[] = "|";
    char space[] = " ";
    char newline[] = "\n";

    int tc = 0;
    ofp = fopen("Output_Sorting.txt", "a");

    fputs(space, ofp);
    while (tc <= 98)
    {
        fputs(slash, ofp);
        tc++;
    }
    tc = 0;
    fputs(newline, ofp);
    fputs(dash, ofp);
    while (tc <= 98)
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs(dash, ofp);
    fputs(newline, ofp);

    fputs(dash, ofp);
    while (tc <= 5)
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs("Algorithm", ofp);
    while (tc <= 7)
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs("No. of Items", ofp);
    while (tc <= 6)
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs("Case", ofp);
    while (tc <= 9)
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs("Iteration", ofp);
    while (tc <= 5)
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs("Comparision", ofp);
    while (tc <= 5)
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs("Moves", ofp);
    while (tc <= 5)
    {
        fputs(space, ofp);
        tc++;
    }
    tc = 0;
    fputs(dash, ofp);

    fputs(newline, ofp);
    fputs(dash, ofp);
    while (tc <= 98)
    {
        fputs(slash, ofp);
        tc++;
    }
    tc = 0;
    fputs(dash, ofp);
    fputs(newline, ofp);

    fclose(ofp);
}

int main()
{
    FILE *fp;
    int *arr;
    char filename[MAX_FILE_NAME];
    char c;
    int num_record, num_content;

    FILE *ofp;
    // Table elements
    char slash[] = "_";
    char dash[] = "|";
    char space[] = " ";
    char newline[] = "\n";

    int tc = 0;
    ofp = fopen("Output_Sorting.txt", "a");
    int count_item_digits;
    int i = 0;
    char cases[3][10] = {"Sorted ", "Reverse", "Average"};
    char no_of_items[10];
    // printf("Enter file name: ");
    // scanf("%s", filename);

    // Open the file
    fp = fopen("s.txt", "r");
    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Table Header
    table_header();
    fclose(ofp);
    // Get first integer from
    fscanf(fp, "%d", &num_record);
    while (num_record != 0)
    {
        fscanf(fp, "%d", &num_content);
        arr = (int *)malloc(num_content * sizeof(int));
        if (arr == NULL)
        {
            printf("Memory not allocated.\n");
            exit(0);
        }
        else
        {
            printf("\n");
            // Get the elements of the array
            for (int i = 0; i < num_content; i++)
            {
                fscanf(fp, "%d", &arr[i]);
            }
            ofp = fopen("Output_Sorting.txt", "a");
            count_item_digits = count_digit(num_content);

            // Print the elements of the array
            // printf("The dataset is: ");
            // for (int i = 0; i < num_content; i++)
            // {
            //     printf("%d ", arr[i]);
            // }
            // printf("\n");

            // Insertion Sort
            fputs(dash, ofp);
            while (tc <= 98)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(dash, ofp);
            fputs(newline, ofp);

            fputs(dash, ofp);
            while (tc <= 5)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs("Insertion Sort", ofp);
            while (tc <= 5)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;

            sprintf(no_of_items, "%llu", num_content);
            fputs(no_of_items, ofp);
            while (tc <= (14 - count_item_digits))
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(cases[i], ofp);

            while (tc <= 7)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fclose(ofp);
            insertion_sort(arr, num_content, i);

            // Bubble Sort
            ofp = fopen("Output_Sorting.txt", "a");
            fputs(dash, ofp);
            while (tc <= 98)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(dash, ofp);
            fputs(newline, ofp);
            fputs(dash, ofp);
            while (tc <= 5)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs("Bubble Sort   ", ofp);
            while (tc <= 5)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(no_of_items, ofp);
            while (tc <= (14 - count_item_digits))
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(cases[i], ofp);
            while (tc <= 7)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fclose(ofp);
            bubble_sort(arr, num_content, i);

            // Bubble Sort early exit
            ofp = fopen("Output_Sorting.txt", "a");
            fputs(dash, ofp);
            while (tc <= 98)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(dash, ofp);
            fputs(newline, ofp);
            fputs(dash, ofp);
            while (tc <= 5)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs("Bubble Sort(E)", ofp);
            while (tc <= 5)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(no_of_items, ofp);
            while (tc <= (14 - count_item_digits))
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(cases[i], ofp);
            while (tc <= 7)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fclose(ofp);
            bubble_sort_early_exit(arr, num_content, i);

            // Quick Sort
            ofp = fopen("Output_Sorting.txt", "a");
            fputs(dash, ofp);
            while (tc <= 98)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(dash, ofp);
            fputs(newline, ofp);
            fputs(dash, ofp);
            while (tc <= 5)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs("Quick Sort    ", ofp);
            while (tc <= 5)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(no_of_items, ofp);
            while (tc <= (14 - count_item_digits))
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fputs(cases[i], ofp);
            while (tc <= 7)
            {
                fputs(space, ofp);
                tc++;
            }
            tc = 0;
            fclose(ofp);
            quick_sort(arr, num_content);

            // Heap Sort
            // Shell Sort
            //

            // Free Memory
            i++;
            if (i > 2)
                i = 0;
            fflush(stdin);
            free(arr);
        }
        num_record--;
    }
    ofp = fopen("Output_Sorting.txt", "a");
    fputs(newline, ofp);
    fputs(dash, ofp);
    while (tc <= 98)
    {
        fputs(slash, ofp);
        tc++;
    }
    tc = 0;
    fputs(dash, ofp);
    fputs(newline, ofp);
    // Close the file
    fclose(fp);
    printf("\n\n");

    return 0;
}
