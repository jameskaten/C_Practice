#include<stdio.h>
#include<stdlib.h>

struct Seoul{
    char dong[10];
    int bus;
};
typedef struct Seoul Seoul; 

int main(){
    Seoul s = {"Bang", 500};
    Seoul* p = (Seoul*)malloc(sizeof(Seoul));
    if(p==NULL){
        puts("Fail");
        return 1;
    }
    *p = s; // insert
    printf("s ==> %s, %d\n", s.dong, s.bus);
    printf("*p ==> %s, %d\n", p->dong, p->bus);

    free(p);
    return 0; 
}