// Example 1: Creating and writing a text File

#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen("./data/test.txt", "w");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    
    fprintf(fp, "Hello World\n");

    // put 4 '_' characters in the file
    for (int i = 0; i < 4; i++)
    {
        fputc('_', fp);
    }
    // put a new line character in the file
    fputc('\n', fp);

    // put 'Hello' string in the file 10 times
    for (int i = 0; i < 10; i++) {
        fputs("Hello\n", fp);
    }
    
    fclose(fp);
    
    exit(EXIT_SUCCESS);
}

