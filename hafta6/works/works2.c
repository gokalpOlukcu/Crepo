int x = 8;
int *p = &x;

int main()
{
    printf("%p \n", p);
    printf("%p \n", &p);
    printf("%p \n", &x);
    printf("%d \n", *p);
    printf("%d \n", x);
}    
