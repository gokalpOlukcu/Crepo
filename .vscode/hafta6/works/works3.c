#include <stdlib.h>
#include <stdio.h>

short sayilar[10];
short *p;

int main() {
    sayilar[3] = 123;
    p = sayilar; // No need for &
    printf("p = %d\n", *p); // Print the value pointed to by p
    printf("4. element = %d\n", *(p + 3)); // Print the 4th element of sayilar array
    printf ("4. element = %d\n", *(p+3)); // ?
    return 0;
}