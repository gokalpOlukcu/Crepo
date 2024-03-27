#include <stdio.h>
#include <stdlib.h>

// Example 3: Updating/Appending a text file 


int main()
{
    FILE *fp = fopen("./data/test.txt", "a");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    // Write last line
    fputs("This is the last line\n", fp);

    fclose(fp);

    // append line ito the first line then write it do not overwrite
    fp = fopen("./data/test.txt", "r+");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    // Write in the first line
    fputs("This is the first line\n", fp);

    fclose(fp);

    
    exit(EXIT_SUCCESS);
}