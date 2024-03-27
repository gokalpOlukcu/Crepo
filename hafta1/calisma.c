#include <stdlib.h>
#include <stdio.h>
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
    FILE* file = fopen("data.txt", "rb");
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
    printf("Description: %s\n",rec[i].description);
    printf("Release_year: %d\n",rec[i].release_year);
    printf("Rental_duration: %d\n",rec[i].rental_duration);
    printf("Rental_rate: %d\n",rec[i].rental_rate);
    printf("Lenght: %d\n",rec[i].lenght);
    printf("Replacement_cost: %d\n",rec[i].replacement_cost);
    printf("Rating: %d\n",rec[i].rating);
    printf("Last_update: %d\n",rec[i].last_update);
    }
    return 0;
}