/* Online C Compiler and Editor */
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct
{
    int film_id;
    char title [255];
    char description[1023];
    unsigned int release_year;
    int rental_duration;
    float rental_rate;
    unsigned char lenght;
    float replacement_cost;
    char rating[10];
    char last_update[30];

}RECORD_t;

int main()
{
    RECORD_t* rec = (RECORD_t*)malloc(sizeof(RECORD_t) * MAX);
    FILE *file;
    file = fopen("C:\\Users\\GÖKALP\\Desktop\\veriYapilari\\data.txt", "rb");
    if (file == NULL)
    {
        perror("Error Opening file");
        fflush(stdout);
        exit(0);
    }
    fread(rec, sizeof(RECORD_t) * MAX, 1, file);
    fclose(file);

    for(int i = 0; i < MAX; i++)
    {
        printf("Film_id: %d\n",rec[i].film_id);
        printf("Title: %s\n",rec[i].title);

    }


    return 0;
}
 