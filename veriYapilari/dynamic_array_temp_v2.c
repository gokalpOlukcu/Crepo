#include <stdio.h>
#include <stdlib.h>

int* getArrayElements(int* array); // Get the elements of the array
int* initArray(int initCapacity); // Initialize the array with a dummy size and capacity

int getArrayCapacity(int* array); // Get the capacity of the array
int getArraySize(int* array); // Get the number of elements in the array

void setArraySize(int* array, int size); // Set the number of elements in the array
void setArrayCapacity(int* array, int capacity); // Set the capacity of the array
void resizeArray(int **arr, int newCapacity); // Reallocate the array to a new capacity



// FILL THE FOLLOWING FUNCTIONS
void addElement(int **arr, int value); // Add an element to the array last position and resize the array by 2x if it's full
void deleteLastElement(int **arr); // Delete the last element and resize the array by 1/2 if it's less than 1/4 or 1/4
void printArray(int *arr); // Print the array

/* 
Note: The array is represented as [num_elements, memory_capacity, 
                                   element_1, element_2, ..., element_{num_elements}, 
                                   empty_1, empty_2, ..., empty_{memory_capacity}]
*/

int main() {
    // Initialize the array with 4 dummy elements
    int* arr = initArray(4); // Output: [0, 4, empty, empty, empty, empty]

    // Create 3 elements
    addElement(&arr, 30); // Output: [1, 4, 30, empty, empty, empty]
    addElement(&arr, 40); // Output: [2, 4, 30, 40, empty, empty]
    addElement(&arr, 50); // Output: [3, 4, 30, 40, 50, empty]

    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    // Create 5 more elements
    addElement(&arr, 60); // Output: [4, 4, 30, 40, 50, 60]
    addElement(&arr, 70); // Output: [5, 8, 30, 40, 50, 60, 70, empty, empty, empty]
    addElement(&arr, 80); // Output: [6, 8, 30, 40, 50, 60, 70, 80, empty, empty]
    addElement(&arr, 90); // Output: [7, 8, 30, 40, 50, 60, 70, 80, 90, empty]
    addElement(&arr, 100); // Output: [8, 8, 30, 40, 50, 60, 70, 80, 90, 100]
    addElement(&arr, 110); // Output: [9, 16, 30, 40, 50, 60, 70, 80, 90, 100, 110, empty, empty, empty, empty, empty]

    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    // Delete 6 elements
    // Note: Just Zero is the last element
    deleteLastElement(&arr); // Output: [8, 16, 30, 40, 50, 60, 70, 80, 90, 100, 0, empty, empty, empty, empty, empty] 
    deleteLastElement(&arr); // Output: [7, 16, 30, 40, 50, 60, 70, 80, 90, 0, 0, empty, empty, empty, empty, empty]
    deleteLastElement(&arr); // Output: [6, 16, 30, 40, 50, 60, 70, 80, 0, 0, 0, empty, empty, empty, empty, empty]
    deleteLastElement(&arr); // Output: [5, 16, 30, 40, 50, 60, 70, 0, 0, 0, 0, empty, empty, empty, empty, empty]
    // 1/4 of 16 is 4 so resize 16 to 8
    deleteLastElement(&arr); // Output: [4, 8, 30, 40, 50, 60, 0, 0, 0, 0] 
    deleteLastElement(&arr); // Output: [3, 8, 30, 40, 50, 0, 0, 0, 0]

    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    // Free the memory
    free(arr);

    return 0;
}


int* getArrayElements(int* array) {
    return array + 2;
}

int getArrayCapacity(int* array) {
    return *(array + 1);
}

int getArraySize(int* array) {
    return *array;
}

void setArrayCapacity(int* array, int capacity) {
    *(array + 1) = capacity;
}

void setArraySize(int* array, int size) {
    *array = size;
}

int* initArray(int initCapacity) {
    int* array = (int*)malloc(sizeof(int) * (initCapacity + 2));
    setArraySize(array, 0);
    setArrayCapacity(array, initCapacity);
    return array;
}

// Reallocate the array to a new capacity
void resizeArray(int **arr, int newCapacity) {
    int* temp = (int*)realloc(*arr, sizeof(int) * (newCapacity + 2));
    if (temp != NULL) {
        *arr = temp; // Update the pointer
        setArrayCapacity(temp, newCapacity);
    }
}

// Add an element to the array last position
void addElement(int **arr, int value) {
    /* Fill this part */
}

void deleteLastElement(int **arr) {
    /* Fill this part */
}

void printArray(int *arr) {
    /* Fill this part */
}