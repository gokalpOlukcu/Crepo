#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Prototypes
void print_arr(int *arr, int n);
void print_histogram(int *arr, int n, int bins);
void print_menu();

int *rand_arr(int *arr, int n, int min_num, int max_num);
int *sort_arr_bubble(int *arr, int n);
int *sort_arr_insertion(int *arr, int n);

int mode(int *arr, int n);
int binary_search(int *arr, int n, int key);
int linear_search(int *arr, int n, int key);
int find_max(int *arr, int n);
int find_min(int *arr, int n);

float average(int *arr, int n);
float median(int *arr, int n);
float standard_deviation(int *arr, int n);

int main()
{
    int *arr = NULL;
    // Seed the random number generator
    srand(time(NULL));

    int choice = 1;
    while (choice != 0)
    {
        print_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            free(arr);
            exit(EXIT_SUCCESS);
        case 1:
            int size, min_num, max_num, sort_choice;
            printf("Enter the size of the array: ");
            scanf("%d", &size);
            printf("Enter the maximum number: ");
            scanf("%d", &max_num);
            printf("Enter the minimum number: ");
            scanf("%d", &min_num);
            printf("Choose the sorting algorithm: \n");
            printf("1. Bubble sort\n");
            printf("2. Insertion sort\n");
            printf("Enter your choice: ");
            scanf("%d", &sort_choice);

            arr = rand_arr(arr, size, min_num, max_num);
            if (sort_choice == 1)
            {
                arr = sort_arr_bubble(arr, size);
            }
            else if (sort_choice == 2)
            {
                arr = sort_arr_insertion(arr, size);
            }
            print_arr(arr, size);
            break;
        case 2:
            if (arr != NULL)
                print_arr(arr, size);
            else
                printf("Array is empty\n");
            break;
        case 3:
            if (arr != NULL)
            {
                printf("Min: %d\n", find_min(arr, size));
                printf("Max: %d\n", find_max(arr, size));
                printf("Average: %.2f\n", average(arr, size));
                printf("Median: %.2f\n", median(arr, size));
                printf("Standard deviation: %.2f\n", standard_deviation(arr, size));
                printf("Mode: %d\n", mode(arr, size));
            }
            else
                printf("Array is empty\n");
            break;
        case 4:
            if (arr != NULL) {
                int bins ;
                printf("Enter the number of bins: ");
                scanf("%d", &bins);
                print_histogram(arr, size, bins);
            }
            else
                printf("Array is empty\n");
            break;
        case 5:
            if (arr == NULL)
            {
                printf("Array is empty\n");
                break;
            }
            else
            {
                int search_choice, key;
                printf("Enter the number to search: ");
                scanf("%d", &key);
                printf("Choose the search algorithm: \n");
                printf("1. Linear search\n");
                printf("2. Binary search\n");
                scanf("%d", &search_choice);
                if (search_choice == 1)
                {
                    int index = linear_search(arr, size, key);
                    if (index != -1)
                    {
                        printf("Number found at index %d\n", index);
                    }
                    else
                    {
                        printf("Number not found\n");
                    }
                }
                else if (search_choice == 2)
                {
                    int index = binary_search(arr, size, key);
                    if (index != -1)
                    {
                        printf("Number found at index %d\n", index);
                    }
                    else
                    {
                        printf("Number not found\n");
                    }
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

void print_menu()
{
    printf("--------------------------------------------\n");
    printf("0. Exit\n");
    printf("1. Create an new random integer array and sort it\n");
    printf("2. Print the array\n");
    printf("3. Find the min, max, average, median, standard deviation and mode of the array\n");
    printf("4. Print a histogram of the array\n");
    printf("5. Search for a number in the array\n");
    printf("---------------------------------------------\n");
    printf("Enter your choice: ");
}

// Prints the array
void print_arr(int *arr, int n)
{
    printf("Array: [");
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("]\n");
}

// Generates random numbers and stores them in the array
int *rand_arr(int *arr, int size, int min_num, int max_num)
{

    // Allocate memory for the array
    if ((arr = (int *)malloc(size * sizeof(int))) == NULL)
    {
        perror("Error:");
        exit(EXIT_FAILURE);
    }

    // Generate random numbers and store them in the array
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (max_num - min_num + 1) + min_num;
    }

    return arr;
}

// Sorts the array in ascending order (Bubble sort algorithm)
int *sort_arr_bubble(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

// Sorts the array in ascending order (Insertion sort algorithm)
int *sort_arr_insertion(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

// Find average of the array
float average(int *arr, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

// Finds median of the array (for sorted arrays)
float median(int *arr, int n)
{
    if (n % 2 == 0)
    {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else
    {
        return arr[n / 2];
    }
}

// Find the standard deviation of the array
float standard_deviation(int *arr, int n)
{
    float avg = average(arr, n);
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (arr[i] - avg) * (arr[i] - avg);
    }
    return sqrt(sum / n);
}

// Find the maximum number (for sorted arrays)
int find_max(int *arr, int size)
{
    return arr[size - 1];
}

// Find the minimum number (for sorted arrays)
int find_min(int *arr, int size)
{
    return arr[0];
}

// Find the mode of the array (for the sorted array)
int mode(int *arr, int n)
{
    int mode = arr[0];
    int count = 1;
    int max_count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            if (count > max_count)
            {
                max_count = count;
                mode = arr[i - 1];
            }
            count = 1;
        }
    }

    return mode;
}

// Prints a histogram of the array (for the sorted arrays)
void print_histogram(int *arr, int n, int bins)
{
    int minValue = find_min(arr, n);
    int maxValue = find_max(arr, n);
    int range = maxValue - minValue + 1; // +1 to include maxValue in the range
    int binSize = range / bins;
    if (binSize == 0)
        binSize = 1; // Ensure binSize is at least 1

    int *hist = (int *)calloc(bins, sizeof(int));
    if (hist == NULL)
    {
        perror("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        int index = (arr[i] - minValue) / binSize;
        if (index >= bins)
            index = bins - 1; // Ensure the last bin includes maxValue
        hist[index]++;
    }

    printf("Histogram: \n");
    for (int i = 0; i < bins; i++)
    {
        printf("%d-%d: %d \n", i * binSize + minValue, (i + 1) * binSize + minValue - 1, hist[i]);
    }

    free(hist);
}

// find number in element. it returns the index of the number in the array (for the sorted array)
int binary_search(int *arr, int n, int num)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int linear_search(int *arr, int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}