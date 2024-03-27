#include <stdio.h>
#include <stdlib.h>

#define DEG 4

int main()
{
int myNumbers[4] = {25, 50, 75, 100};
int *ptr = myNumbers;
int i;

for (i = 0; i < 4; i++) {
  printf("Array pointer : %d\n", *(ptr + i));
  printf("Array adress :  %p\n", *(ptr + i));
}
}