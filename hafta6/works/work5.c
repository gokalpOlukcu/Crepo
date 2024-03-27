int main()
{

int V = 101;
int *P = &V;	/* P points to int V */
int **Q = &P;	/* Q points to int pointer P */

printf("%d %d %d\n",V,*P,**Q); /* prints 101 3 times */

}