// Example 7: Creating and writing a binary file with struct

#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int student_id;
    char name[50];
    float marks;
} Student;

int main()
{
    FILE *fp = fopen("./data/students.dat", "wb");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    Student students[5] = {
        {1, "Alice", 90.5},
        {2, "Bob", 85.5},
        {3, "Charlie", 80.5},
        {4, "David", 75.5},
        {5, "Eve", 70.5}
    };
    
    fwrite(students, sizeof(Student), 5, fp);
    
    fclose(fp);
    
    exit(EXIT_SUCCESS);
}