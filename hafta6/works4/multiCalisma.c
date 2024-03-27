#include <stdio.h>
int main()
{
    int a[3][4] = { {1, 2, 3, 10}, {4, 5, 6, 11}, {7, 8, 9, 12}};    
   	    	
    for (int i = 0; i < 3; ++i) {
        for (int k = 0; k < 4; ++k)
            printf("%2d ", a[i][k]);
        printf("\n");
    }   	
    printf("\n%d", a[0][0]);
    printf("\n%d", a[0][1]);
    printf("\n%d", a[0][2]);
    printf("\n%d", a[0][3]);

    printf("\n%d", a[2][0]);
    printf("\n%d", a[1][3]);
    printf("\n%d", a[1][2]);
    printf("\n%d", a[2][3]);

     
    
}