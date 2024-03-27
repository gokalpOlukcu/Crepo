#include <stdio.h> 
int electricEye(int *arr) 
{ 
 int i, j; 
 for (i=0; i<2; i++) 
 { 
 for (j=0; j<2; j++) 
 { 
 printf("%d ", arr[i]); 
 arr++; 
 } 
 printf("\n"); 
 } 
} 
int main() 
{ 
 int arr[2][3]= {10, 34, 21, 78, 5, 25}; 
 electricEye(*arr); 
 return 0; 
} 