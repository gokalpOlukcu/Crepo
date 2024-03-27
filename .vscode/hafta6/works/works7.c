#include <stdio.h>
#include <stdlib.h>

float *nums;
int N;
int I;

int main()
{
printf("Read how many numbers:");
scanf("%d",&N);
nums = (float *)calloc(N, sizeof(float));
/* nums is now an array of floats of size N */
for (I = 0; I < N; I++) {
  printf("Please enter number %d: ",I+1);
  scanf("%f",&(nums[I]));
}
}
