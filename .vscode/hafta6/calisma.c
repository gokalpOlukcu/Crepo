#include <stdio.h> 
#include <string.h> 
typedef struct xyz { 
 char name[30]; 
 short relY; 
} album; 
int main() 
{ 
 album x, *tmp; 
 tmp = &x; 
 strcpy(tmp->name, "Rust in Peace"); 
 x.relY = 1990; 
 printf("%s\n", x.name); 
 printf("%d\n", tmp->relY); 
 return 0; 
} 