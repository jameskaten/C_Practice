#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char* p = (char*)malloc(strlen("sam")+1);
    if(p==NULL){
        puts("Fail");
    }
    strcpy(p, "sam");
    printf("p = %d, &p = %d\n", p, &p);
    printf("p = %p, &p = %p\n", (void*)p, (void*)&p);
    printf("*p = %d, p = %d, &p = %d\n", *p, p, &p);
    printf("*p = %d, p = %p, &p = %p\n", *p, (void*)p, (void*)&p);

    free(p);
    return 0; 
}