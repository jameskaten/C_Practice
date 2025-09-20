#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i; 
    int * p; 
    printf("Total numbers: ");
    scanf("%d", &n);
    p = (int*)malloc(sizeof(int)*n);
    if(p==NULL){
        printf("Fail");
        return 1;
    }
    printf("[%d] number of int: \n", n);
    for(i=0; i<n; i++){
        printf("[%d] integer: ", i);
        scanf("%d", p+i);
    }
    printf("\n [%d] integer prin\n", n);
    for(i=0; i<n; i++){
        printf("[%d] ==> %d\n", i, *(p+i));
    }
    free(p);
    return 0; 
}