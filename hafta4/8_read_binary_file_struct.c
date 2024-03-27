// Example 8: Reading a binary file with struct

#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int student_id;
    char name[50];
    float marks;
} Student;

int main()
{
    FILE *fp = fopen("./data/students.dat", "rb");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    Student students[10];

    fread(students, sizeof(Student), 10, fp);

    for (int i = 0; i < 10; i++)
    {
        printf("Student ID: %d\n", students[i].student_id);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    
    fclose(fp);
    
    exit(EXIT_SUCCESS);
}