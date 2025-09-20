#include<stdio.h>
#include<string.h>

int main(){
    char k[6] = "Korea";
    char c[6] = "China";
    char tmp[6];

    printf("Original ==> k = %s, c = %s\n", k, c);

    strcpy(tmp, k);
    strcpy(k, c);
    strcpy(c, tmp);

    printf("After ==> k = %s, c = %s\n", k, c);

    return 0; 
}