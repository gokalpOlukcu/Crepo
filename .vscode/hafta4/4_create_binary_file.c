// Example 4: Creating and writing a binary file

#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen("./data/data.dat", "wb");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    int data[20];

    for (int i = 0; i < 20; i++)
    {
        data[i] = i; // 0, 1, 2, ..., 19
    }

    fwrite(data, sizeof(int), 20, fp);
    
    fclose(fp);
    
    exit(EXIT_SUCCESS);
}

