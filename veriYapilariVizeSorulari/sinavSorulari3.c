#include <stdio.h> 
int main() 
{ 
 int bliss, t, i, j; 
 int arr[][3]={20,30,10,27,4,25,8,1,6}; 
 for(t=1; t<9; t++) 
 { 
 for(i=0; i<3; i++) 
 { 
 for(j=0; j<2; j++) 
 { 
 if (arr[i][j]>arr[i][j+1]) 
 { 
 bliss=arr[i][j]; 
 arr[i][j]=arr[i][j+1]; 
 arr[i][j+1]=bliss; 
 } 
 } 
 } 
 for(i=0; i<2; i++) 
 { 
 if (arr[i][2]>arr[i+1][0]) 
 { 
 bliss=arr[i][2]; 
 arr[i][2]=arr[i+1][0]; 
 arr[i+1][0]=bliss; 
 } 
 } 
 } 
 return 0; 
} 