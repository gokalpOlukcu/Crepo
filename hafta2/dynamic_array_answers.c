#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bunlar öğrencilere verilecek
int getArraySize(int* array);
int getArrayCapacity(int* array);
int* getArrayElements(int* array);
int* initArray(int initCapacity);
void setArraySize(int* array, int size);
void setArrayCapacity(int* array, int capacity);
void setArrayElements(int* array, int* elements);
void resizeArray(int **arr, int newCapacity);

// Bunlar alıştırma olacak
void addElement(int **arr, int value);
void deleteLastElement(int **arr);
void printArray(int *arr);

// Bunlar sadece test için
void addNRandElements(int **arr, int n);
void deleteNLastElements(int **arr, int n);
void Test1();
void Test2();
void Test3();

// Main kısmı öğrencilere verilecek
int main() {
    srand(time(NULL));

    Test1();

    // Wait for user input
    printf("Press Enter to continue...");
    while (getchar() != '\n');
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
    int size = getArraySize(*arr);
    int capacity = getArrayCapacity(*arr);

    if (capacity == size && capacity == 0) {
        resizeArray(arr, capacity + 1);
    } else if (size == capacity) {
        resizeArray(arr, capacity * 2);
    } 

    int* elems = getArrayElements(*arr);
    elems[size] = value;
    setArraySize(*arr, size + 1);
}

void deleteLastElement(int **arr) {
    int oldSize = getArraySize(*arr); // Update size after deletion
    if (oldSize > 0) {
        // Zero out the last element
        int* elems = getArrayElements(*arr);
        elems[oldSize - 1] = 0;

        // Decrease the size as we're deleting an element
        setArraySize(*arr, oldSize - 1);
    }
    int newSize = getArraySize(*arr);

    int capacity = getArrayCapacity(*arr);

    // Check if we need to resize the array
    while (newSize > 0 && newSize <= capacity / 4) {
        capacity /= 2;
    }

    if (capacity != getArrayCapacity(*arr)) {
        resizeArray(arr, capacity);
    }
}

void printArray(int *arr) {
    int size = getArraySize(arr);
    int* elements = getArrayElements(arr);
    for (int i = 0; i < size; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");
}

void addNRandElements(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        addElement(arr, rand() % 100 + 1);
    }
}

void deleteNLastElements(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        deleteLastElement(arr);
    }
}

void Test1() {
    // Initialize the array with 4 dummy elements
    int* arr = initArray(0);

    // Create 3 elements
    addElement(&arr, 30);
    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    addElement(&arr, 40);
    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);
    
    addElement(&arr, 50);
    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    // Create 5 more elements
    addElement(&arr, 60);
    addElement(&arr, 70);
    addElement(&arr, 80);
    addElement(&arr, 90);
    addElement(&arr, 100);
    addElement(&arr, 110);

    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    // Delete 6 elements
    deleteLastElement(&arr);
    deleteLastElement(&arr);
    deleteLastElement(&arr);
    deleteLastElement(&arr);
    deleteLastElement(&arr);
    deleteLastElement(&arr);

    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    // Free the memory
    free(arr);
}

void Test2() {
    int* arr = initArray(100);

    // Create 2 elements
    addNRandElements(&arr, 30);

    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    // Delete 1 element
    deleteNLastElements(&arr, 20);

    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    addNRandElements(&arr, 110);

    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    free(arr);
}

void Test3() {
    int* arr = initArray(10); // Start with a small capacity to make it easy to reach the threshold

    // Fill the array to just over half capacity to ensure it will resize upon addition
    for (int i = 0; i < 15; i++) {
        addElement(&arr, i + 1);
    }

    printf("After adding elements:\n");
    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    // Now, delete elements one by one to trigger potential resizing bug
    for (int i = 0; i < 10; i++) {
        deleteLastElement(&arr);
    }

    printf("After deleting elements:\n");
    printf("Number of elements: %d\n", getArraySize(arr));
    printf("Memory Capacity: %d\n", getArrayCapacity(arr));
    printArray(arr);

    // Clean up
    free(arr);
}