#include<stdio.h>

int main(){
    int a, b, res;
    char op;

    printf("The first number: ");
    scanf("%d", &a);

    printf("+, -");
    fflush(stdin);
    op = getchar();

    printf("The second number: ");
    scanf("%d", &b);

    switch(op)
    {
    case '+': res = a + b; break;
    case '-': res = a - b; break;
    default:
        printf("%d no calculator \n", op);
    }
    printf("%d %c %d = %d\n", a, op, b, res);

    return 0; 
}
