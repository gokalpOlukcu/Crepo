// Example 9: Updating binary file with struct

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int student_id;
    char name[50];
    float marks;
} Student;

int main()
{
    FILE *fp = fopen("./data/students.bin", "rb+");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    // student_id 3 and update the marks

    Student student;
    int position_of_student = 2;

    // Go and read the 3rd student
    fseek(fp, position_of_student * sizeof(Student), SEEK_SET);
    fread(&student, sizeof(Student), 1, fp);

    // Change students name and marks
    strcpy(student.name, "Mehmet");
    student.marks = 85.5;

    // Seek back to the 3rd student and update it. 
    fseek(fp, position_of_student * sizeof(Student), SEEK_SET);
    fwrite(&student, sizeof(Student), 1, fp);
    
    fclose(fp);

    // Append 5 more new students to the binary file

    fp = fopen("./data/students.dat", "ab");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    Student new_students[5] = {
        {6, "Fatma", 95.5},
        {7, "Gizem", 90.5},
        {8, "Hakan", 85.5},
        {9, "Ismail", 80.5},
        {10, "Jale", 75.5}
    };

    fwrite(new_students, sizeof(Student), 5, fp);

    fclose(fp);
    
    exit(EXIT_SUCCESS);
}