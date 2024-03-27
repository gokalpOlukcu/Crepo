// Example 6: Updating binary file

#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen("./data/data.dat", "rb+");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    // multiply each element by 2

    int data[20];

    fread(data, sizeof(int), 20, fp);

    for (int i = 0; i < 20; i++)
    {
        data[i] *= 2; // 0, 2, 4, ..., 38
    }

    fseek(fp, 0, SEEK_SET);
    fwrite(data, sizeof(int), 20, fp);

    fclose(fp);

    // append 30 more elements

    fp = fopen("./data/data.bin", "ab");
    if (fp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    int data_part2[30];

    for (int i = 0; i < 30; i++)
    {
        data_part2[i] = i; // 20, 21, 22, ..., 49
    }

    fwrite(data_part2, sizeof(int), 30, fp);

    fclose(fp);

    exit(EXIT_SUCCESS);
}

