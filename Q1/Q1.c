#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100

// Insertion Sort
void insertion_sort(int arr[], int size)
{
    int i, j;
    int data[size];
    int temp;

    // Local Copy of Array so no changes occurs to orignal
    for (i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }

    for (i = 0; i < size; i++)
    {
        // Search for Insertion Point
        for (j = i; j > 0; j--)
        {
            if (data[j] < data[j - 1])
            {
                // Swap
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
    printf("\n\nInsertion Sort: ");
    printf("\nSorted Data: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}

// Exchange Sort
void exchange_sort(int arr[], int size)
{
    int i, j;
    int data[size];
    int temp;

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
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("\n\nExchange Sort: ");
    printf("\nSorted Data: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}

void selection_sort(int arr[], int size)
{
    int i, j, min_idx;
    int data[size];
    int temp;

    // Local Copy of Array so no changes occurs to orignal
    for (i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < size; j++)
            if (data[j] < data[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        temp = data[i];
        data[i] = data[min_idx];
        data[min_idx] = temp;
    }

    printf("\n\nSelection Sort: ");
    printf("\nSorted Data: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}

// Quick Sort

// Quick Sort partition (Problem with large dataset)
int quick_sort_partiton(int data[], long int low, long int high)
{
    long int i = 0, j = high + 1;
    long int temp;

    while (1)
    {
        // Find item on left to swap
        while (data[++i] < data[low])
        {
            if (i == high)
            {
                break;
            }
        }

        // Find item on right to swap
        while (data[low] < data[--j])
        {
            if (j == low)
            {
                break;
            }
        }

        // Check if pointer cross
        if (i >= j)
        {
            break;
        }

        // Swap
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    // Swap
    temp = data[low];
    data[low] = data[j];
    data[j] = temp;

    return j;
}

void quick_sort_sort(int data[], long int low, long int high)
{
    if (high <= low)
    {
        return;
    }

    // Initial Partition
    long int j = quick_sort_partiton(data, low, high);

    // Recursively Partitioning and sorting
    // Left Side
    quick_sort_sort(data, low, j - 1);
    // Right Side
    quick_sort_sort(data, j + 1, high);
}

void quick_sort(int arr[], int size)
{
    long int low = 0, high = size;
    int data[size];
    long int i, j;

    // Local Copy of Array so no changes occurs to orignal
    for (i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }

    // Random Shuffle

    // Sort
    quick_sort_sort(data, low, high - 1);

    printf("\n\nQuick Sort: ");
    printf("\nSorted Data: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}

// Shell Sort
void shell_sort(int arr[], int size)
{
    int i, j, h = 1;
    int data[size];
    int temp;

    // Local Copy of Array so no changes occurs to orignal
    for (i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }

    while (h < (size / 3))
    {
        h = (3 * h) + 1;
    }

    while (h >= 1)
    {

        for (i = h; i < size; i++)
        {
            for (j = i; j >= h; j = j - h)
            {
                if (data[j] < data[j - h])
                {
                    temp = data[j];
                    data[j] = data[j - h];
                    data[j - h] = temp;
                }
            }
        }
        h = h / 3;
    }

    printf("\n\nShell Sort: ");
    printf("\nSorted Data: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}

// Heap Sort
void heapify(int data[], int n, int i)
{
    int temp;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && data[l] > data[largest])
    {
        largest = l;
    }

    if (r < n && data[r] > data[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        temp = data[i];
        data[i] = data[largest];
        data[largest] = temp;

        heapify(data, n, largest);
    }
}

void heap_sort(int arr[], int size)
{
    int i, j;
    int data[size];
    int temp;

    // Local Copy of Array so no changes occurs to orignal
    for (i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(data, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        heapify(data, i, 0);
    }

    printf("\n\nHeap Sort: ");
    printf("\nSorted Data: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}

int main()
{
    FILE *fp;
    int *arr;
    char filename[MAX_FILE_NAME];
    char c;
    int num_record, num_content;

    // Open the file
    fp = fopen("s.txt", "r");
    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

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
            // Print the elements of the array
            printf("\n\nThe dataset is: ");
            for (int i = 0; i < num_content; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");

            // Insertion Sort
            insertion_sort(arr, num_content);

            // Exchange Sort
            exchange_sort(arr, num_content);

            // Selection Sort
            selection_sort(arr, num_content);

            // Quick Sort
            quick_sort(arr, num_content);

            // Shell Sort
            shell_sort(arr, num_content);

            // Heap Sort
            heap_sort(arr, num_content);

            // Free Memory
            fflush(stdin);
            free(arr);
        }
        num_record--;
    }

    // Close the file
    fclose(fp);
    printf("\n\n");

    return 0;
}
