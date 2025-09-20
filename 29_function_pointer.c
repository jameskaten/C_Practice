#include<stdio.h>

void plus(int x, int y);
void minus(int x, int y);

int main(){
    int num1, num2;
    char op;
    void (*fnptr)(int, int); // declaration 

    printf("First integer: ");
    scanf("%d", &num1);

    printf("+, -: ");
    getchar();  // Consume leftover newline from previous input
    scanf("%c", &op); // Read a single character safely

    printf("Second integer: ");
    scanf("%d", &num2);

    switch(op){
        case '+': fnptr = plus; break;
        case '-': fnptr = minus; break;
        default: puts("Wrong operator! "); return 1; 
    }

    fnptr(num1, num2); // call functions

    return 0;
}

void plus(int x, int y){
    printf("%d + %d = %d\n", x, y, x+y);
}

void minus(int x, int y){
    printf("%d - %d = %d\n", x, y, x-y);
}