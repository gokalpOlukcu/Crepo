#include <stdlib.h>
#include <stdio.h>
#include <string.h>  

#define MAX 1000

typedef struct {
    int film_id;
    char title[255];
    char description[1023];
    unsigned int release_year;
    int rental_duration;
    float rental_rate;
    unsigned char length;
    float replacement_cost;
    char rating[10];
    char last_update[30];
} RECORD_t;

int i;
int s;
int searchedNumber;
int updatenumber;
char descr[1023]; 
unsigned int ryear;


void checkfolder(RECORD_t *rec) {
    
    FILE *file = fopen("data.txt", "rb+");
    if (file == NULL) {
        perror("Error Opening file");
        fflush(stdout);
        exit(1);
    }
    fread(rec, sizeof(RECORD_t), MAX, file);
    fclose(file);
    }

void createBinaryFile(RECORD_t *rec)
{
    FILE *hedefdosya;
    FILE *fp = fopen("./batDosyasi/batDosyasi.bat", "rb+");
    if (fp == NULL)
    {
        if (hedefdosya == NULL) {
        perror("Error Opening file");
        fflush(stdout);
        exit(1);         
    }
    else
    {
                hedefdosya = fopen("./batDosyasi/batDosyasi.bat", "w+");
    }}
    
    for(s = 0; s < MAX; s++);
    {
                fprintf(hedefdosya,"Film_id: %d\n", rec[s].film_id);
                fprintf(hedefdosya,"Title: %s\n", rec[s].title);
                fprintf(hedefdosya,"Description: %s\n", rec[s].description);
                fprintf(hedefdosya,"Release_year: %u\n", rec[s].release_year);
                fprintf(hedefdosya,"Rental_duration: %d\n", rec[s].rental_duration);
                fprintf(hedefdosya,"Rental_rate: %.2f\n", rec[s].rental_rate);
                fprintf(hedefdosya,"Length: %d\n", rec[s].length);
                fprintf(hedefdosya,"Replacement_cost: %.2f\n", rec[s].replacement_cost);
                fprintf(hedefdosya,"Rating: %s\n", rec[s].rating);
                fprintf(hedefdosya,"Last_update: %s\n", rec[s].last_update);
                s++;
    }
    fread(rec, sizeof(RECORD_t), MAX, hedefdosya);
    fclose(hedefdosya);
    exit(EXIT_SUCCESS);
}

//We can print the values we want with a all search
void allprint(RECORD_t *rec)
{
    for(int i = 0; i < MAX; i++)
    {
                printf("Film_id: %d\n", rec[i].film_id);
                printf("Title: %s\n", rec[i].title);
                printf("Description: %s\n", rec[i].description);
                printf("Release_year: %u\n", rec[i].release_year);
                printf("Rental_duration: %d\n", rec[i].rental_duration);
                printf("Rental_rate: %.2f\n", rec[i].rental_rate); 
                printf("Length: %d\n", rec[i].length);
                printf("Replacement_cost: %.2f\n", rec[i].replacement_cost); 
                printf("Rating: %s\n", rec[i].rating); 
                printf("Last_update: %s\n", rec[i].last_update);
    }}

// We can print the values we want with a special search.
void specialprint(RECORD_t *rec)
{
    for (i = 0; i < MAX; i++) {
            if (searchedNumber == rec[i].film_id) {
                printf("Film_id: %d\n", rec[i].film_id);
                printf("Title: %s\n", rec[i].title);
                printf("Description: %s\n", rec[i].description);
                printf("Release_year: %u\n", rec[i].release_year);
                printf("Rental_duration: %d\n", rec[i].rental_duration);
                printf("Rental_rate: %.2f\n", rec[i].rental_rate); 
                printf("Length: %d\n", rec[i].length); 
                printf("Replacement_cost: %.2f\n", rec[i].replacement_cost); 
                printf("Rating: %s\n", rec[i].rating); 
                printf("Last_update: %s\n", rec[i].last_update); 
            }
        }
}

void update(RECORD_t *rec)
{
for (i = 0; i < MAX; i++) {
            printf("\nUpdated FILM ID : %d\n", rec[i].film_id);
            if (searchedNumber == rec[i].film_id) {  
                printf("\nWhat is the description you want to update in the series ? : ");
                scanf("%s", descr);  
                strcpy(rec[i].description, descr);  
                printf("\nUpdated description value : %s",rec[i].description);
                printf("\nWhat is the release_year you want to update in the series? : ");
                scanf("%u", &ryear);  
                rec[i].release_year = ryear;  
                printf("nUpdated release_year value : %d",rec[i].release_year);
            printf("\nAll desired emoticons updated : ");   
            for (i = 0; i < MAX; i++) 
            {
            if (searchedNumber == rec[i].film_id) {
                printf("Film_id: %d\n", rec[i].film_id);
                printf("Title: %s\n", rec[i].title);
                printf("Description: %s\n", rec[i].description);
                printf("Release_year: %u\n", rec[i].release_year);
                printf("Rental_duration: %d\n", rec[i].rental_duration);
                printf("Rental_rate: %.2f\n", rec[i].rental_rate);
                printf("Length: %d\n", rec[i].length);
                printf("Replacement_cost: %.2f\n", rec[i].replacement_cost);
                printf("Rating: %s\n", rec[i].rating);
                printf("Last_update: %s\n", rec[i].last_update);
            }
            }
        }
        }
}
int main() 
{
 
    
    RECORD_t *rec = (RECORD_t *)malloc(sizeof(RECORD_t) * MAX);
    checkfolder(rec);
    int i;

    printf("Select the action you want to perform? 1 for updating, 0 for creating bat file ? : ");
    scanf("%d", &searchedNumber);
    if(searchedNumber==1)
    {
        printf("\nPlease enter a number. 1 to update, 0 to show these values. : ");
    scanf("%d", &searchedNumber);
    if (searchedNumber == 1) 
    {
        printf("\nWhat is the number you are looking for in the series? :");
        scanf("%d", &searchedNumber);
        update(rec);
        
    } 
    else 
    {
    printf("\nPlease enter a number. 1 for the desired value, 0 for all values:");
    scanf("%d", &searchedNumber);
    if(searchedNumber==1)
    {
        printf("What is the number you are looking for in the series ? :");
        scanf("%d", &searchedNumber);
        specialprint(rec);
    }
    else
    {
        allprint(rec);
    }    
    }
    }
    else
    {
    createBinaryFile(rec);
    }  
}
