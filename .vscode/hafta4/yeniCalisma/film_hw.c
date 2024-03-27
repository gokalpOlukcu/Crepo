#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000 //Do not edit this macro.

int aranansayi;
int aranandeger;
int aranandeger2;
int updatenumber;
int i;

typedef struct{
    int film_id;
    char title[255];
    char description[1023];
    unsigned int release_year;
    char rental_duration;
    float rental_rate;
    unsigned char length;
    float replacement_cost;
    char rating[10];
    char last_update[30];
} RECORD_t;  

void list(RECORD_t* rec);
void update(RECORD_t* rec);
void print(RECORD_t* rec);

int main() {
    RECORD_t rec[MAX]; 
    print(rec);
    }


void update(RECORD_t* rec) 
    {
    char descr[1023]; // descr dizi olarak tanımlanmalı
    unsigned int ryear;

    printf("Lutfen bir sayi giriniz. Guncelleme yapmak icin 1, Degerleri gostermek iCin 0 : ");
    scanf("%d", &aranandeger);
    if (aranandeger == 1) {
        printf("Dizide aradiginiz sayi nedir :");
        scanf("%d", &aranansayi);
        for (i = 0; i < MAX; i++) {
            printf("Guncellenen FILM ID: %d\n", rec[i].film_id);
            if (aranansayi == rec[i].film_id) { // Noktalı virgülü kaldırın
                printf("\nDizide guncellemek istediginiz description nedir: ");
                scanf("%s", descr); // & operatörü kaldırıldı
                strcpy(rec[i].description, descr); // strcpy'nin argümanları düzeltildi
                printf("\nGuncellenen description degeri : %s",rec[i].description);
                printf("\n Dizide guncellemek istediginiz release_year nedir: ");
                scanf("%u", &ryear); // Doğru format belirteci kullanıldı
                rec[i].release_year = ryear; // release_year değiştirildi
                printf("Guncellenen release_year degeri %d",rec[i].release_year);
                
            printf("\nLutfen bir sayi giriniz. Degerleri gostermek iCin 1: ");
            scanf("%d", &aranandeger2);
            if (aranandeger2 == 1) {
            for (i = 0; i < MAX; i++) {
            printf("Film_id: %d\n", rec[i].film_id);
            if (aranandeger2 == rec[i].film_id) {
                printf("Film_id: %d\n", rec[i].film_id);
                printf("Title: %s\n", rec[i].title);
                printf("Description: %s\n", rec[i].description);
                printf("Release_year: %u\n", rec[i].release_year); // Doğru format belirteci kullanıldı
                printf("Rental_duration: %d\n", rec[i].rental_duration);
                printf("Rental_rate: %.2f\n", rec[i].rental_rate); // %d yerine %f kullanıldı
                printf("Length: %d\n", rec[i].length); // Yazım hatası düzeltildi
                printf("Replacement_cost: %.2f\n", rec[i].replacement_cost); // %d yerine %f kullanıldı
                printf("Rating: %s\n", rec[i].rating); // %d yerine %s kullanıldı
                printf("Last_update: %s\n", rec[i].last_update); // %d yerine %s kullanıldı
            }
        }
        
            }
        }
         }
}
                     
}

void print(RECORD_t* rec) {
    int i;
    printf("\nTum kayitlar:\n");
    for (int i = 0; i < MAX; i++) {
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

void list(RECORD_t* rec) 
{
    
    rec = (RECORD_t *)malloc(sizeof(RECORD_t) * MAX);
    FILE *file = fopen("data.txt", "rb");
    if (file == NULL) {
        perror("Error Opening file");
        fflush(stdout);
        exit(0);
    }
    fread(rec, sizeof(RECORD_t) * MAX, 1, file);
    fclose(file);
}
