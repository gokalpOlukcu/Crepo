#include <stdio.h>
#include <stdlib.h>

// Example 2: Reading a text file


int main()
{
    FILE *fp = fopen("./data/test.txt", "r");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    // Read the test.txt
    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }

    // set the file pointer to the beginning of the file
    rewind(fp);

    // Read by buffer 
    char buffer[255];
    while (fgets(buffer, 255, fp) != NULL)
    {
        printf("%s", buffer);
    }


    fclose(fp);
    
    exit(EXIT_SUCCESS);
}