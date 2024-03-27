#include <stdlib.h>
#include <stdio.h>



int main()
{

    char array[5];
    printf("%p\n Deneme 1 :", array);
    printf("%p\n Deneme 2 :", &array[ 0 ]);
    printf("%p\n Deneme 3 :", &array);
    return 0;

}