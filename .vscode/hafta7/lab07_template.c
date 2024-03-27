#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define SIZE 100000

// Utility Functions
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int find_min(int a, int b) {
    return (a < b) ? a : b;
}


// Searching Algorithms

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        // If the element is present at the middle itself
        if (arr[mid] == x) return mid;
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
    // We reach here when element is not present in array
    return -1;
}

int jumpSearch(int arr[], int x, int n) {
    
}

// Returns the position of first occurrence of x in array
int exponentialSearch(int arr[], int n, int x) {
    
}

// Sorting Algorithms
void selectionSort(int arr[], int n) {
    
}

void merge(int arr[], int l, int m, int r) {
    
}

void mergeSort(int arr[], int l, int r) {
    
}

int partition (int arr[], int low, int high) {
    
}

void quickSort(int arr[], int low, int high) {
    
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Main Function
int main() {
    FILE *file;
    int array[SIZE];
    int copiedArray[SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Reading the binary file into array
    file = fopen("random_numbers.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    fread(array, sizeof(int), SIZE, file);
    fclose(file);


    // Merge Sort
    memcpy(copiedArray, array, sizeof(array));
    start = clock();
    mergeSort(copiedArray, 0, SIZE - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort took %f seconds\n", cpu_time_used);

    // Quick Sort
    memcpy(copiedArray, array, sizeof(array));
    start = clock();
    quickSort(copiedArray, 0, SIZE - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort took %f seconds\n", cpu_time_used);
    
    // Selection Sort
    memcpy(copiedArray, array, sizeof(array));
    start = clock();
    selectionSort(copiedArray, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds\n", cpu_time_used);

    // Bubble Sort
    memcpy(copiedArray, array, sizeof(array));
    start = clock();
    bubbleSort(copiedArray, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds\n", cpu_time_used);

    // Searching (Example with Jump Search)
    int searchElement = array[SIZE / 2]; // Just an example element to search
    start = clock();
    int searchResult = jumpSearch(copiedArray, searchElement, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Jump Search took %f seconds, found at index: %d\n", cpu_time_used, searchResult);

    // Searching (Example with Exponential Search)
    searchElement = array[SIZE / 2]; // Just an example element to search
    start = clock();
    searchResult = exponentialSearch(copiedArray, SIZE, searchElement);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Exponential Search took %f seconds, found at index: %d\n", cpu_time_used, searchResult);

    // Searching (Example with Binary Search)
    searchElement = array[SIZE / 2]; // Just an example element to search
    start = clock();
    searchResult = binarySearch(copiedArray, 0, SIZE - 1, searchElement);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search took %f seconds, found at index: %d\n", cpu_time_used, searchResult);

    return 0;
}
