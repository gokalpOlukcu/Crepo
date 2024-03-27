#include <stdio.h>

int totalArray(int *A, int N) 
{   
    int total = 0;
    for (int i = 0; i < N; i++)
        total += A[i];
    return total;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    
    int sum = totalArray(array, size);
    
    printf("Total sum of array elements: %d\n", sum);
    
    return 0;
}