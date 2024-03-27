// Example 5: Reading a binary file

#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen("./data/data.dat", "rb");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    int data[20];

    fread(data, sizeof(int), 20, fp);

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", data[i]); // prints 0 1 2 3 ... 19
    }

    fclose(fp);

    exit(EXIT_SUCCESS);
}

