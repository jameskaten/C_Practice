#include<stdio.h>

int main(){
    int dan, i; 
    while(1){
        do
        {
            /* code */
            printf("What number? ");
            scanf("%d", &dan);
            if(dan==1){
                return 1; 
            }
        } while (dan<2||dan>9);
        printf("** %d dan **\n", dan);
        for(i=1; i<=9; i++){
            printf("%d * %d = %d\n", dan, i, dan * i);
        }        
    }
    getchar();
    return 0; 

}