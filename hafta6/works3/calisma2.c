#include <stdlib.h>
#include <stdio.h>

#define MAX 5

int main()
{

int a = 20;
int *b;

b = &a;
printf("Deger: %d\n",*b);
printf("Deger: %p\n",b);



int v=10;
int *p = &v;

int seri[MAX]={1,2,3,4,5};
int *c = seri;

float type[5];

printf("Degerin pointer adresi :%p \n", v);
printf("Degerin pointer adresi :%p \n", p);
printf("Deger :%d \n", *p);

printf("1. Serinin uzunlugu :%1d \n", sizeof(type));
printf("1. Serinin adresi :%p \n", seri);
printf("1. Serinin pointer adresi :%p \n", c);
printf("1. Serinin pointer adresi :%d \n", *(c+1));

    int x = 8;
    int *k = &x;

    printf("%p \n", k);
    printf("%p \n", &k);
    printf("%p \n", &x);
    printf("%d \n", *k);
    printf("%d \n", x);

}