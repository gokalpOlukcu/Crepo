#include <stdio.h>
#include <string.h>
#define		ARRAY_SIZE	20
#define		MAX_NAME_LEN	16
void swap_str(char *p1, char *p2)
{
    char temp[ARRAY_SIZE];
    strcpy(temp, p1);
    strcpy(p1, p2);
    strcpy(p2, temp);
}
void sort_names(char ptr[][MAX_NAME_LEN], size_t size)
{
    for (size_t i = 0; i < size - 1; ++i) {
	for (size_t k = 0; k < size - 1 - i; ++k) {
            if (strcmp(ptr[k], ptr[k + 1]) > 0)
		swap_str(ptr[k], ptr[k + 1]);
	}
    }
}
void display_names(const char ptr[][MAX_NAME_LEN], size_t size)
{
    for (size_t i = 0; i < size; ++i)
	printf("%s ", ptr[i]);
    printf("\n");
}
int main()
{
    char names[ARRAY_SIZE][MAX_NAME_LEN] = { 
    "Ali", "Veli", "Hasan", "Necati", "Deniz",
    "Kaan", "Selami", "Salah", "Irmak", "Macit",
    "Derya", "Funda", "Kemal", "Burak", "Bayram",
    "Ozlem", "Nuri", "Metin", "Ferhan", "Korhan" };
    display_names(names, ARRAY_SIZE);
    sort_names(names, ARRAY_SIZE);
    printf("***********************************\n");
    display_names(names, ARRAY_SIZE);
}