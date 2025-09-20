#include<stdio.h>
#include<string.h>

struct Seoul{
    char d_name[10];
    int bus;
};
typedef struct Seoul Seoul; 

int main(){
    Seoul s[5] = {{"ac", 500}, {"bed", 350}, {"dff", 700}};
    Seoul tmp; 
    int i, j, n;
    n= sizeof(s)/sizeof(Seoul); // Size

    printf("sizeof(s): %d\n", (int)sizeof(s)); // considering padding: 4-byte boundary
    printf("sizeof(Seoul): %d\n", (int)sizeof(Seoul));
    // char d_name[10]: 10 bytes
    // int bus: 4 bytes, totla 14 bytes, adding padding 2 bytes
    // s[5]: 5 structs x 16 bytes each = 80 bytes

    puts("\n Original");
    for(i=0; i<n; i++){
        printf("[%d] %7s %5d \n", i+1, s[i].d_name, s[i].bus);
    }
    puts("-----------");

    // Sort
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(strcmp(s[i].d_name, s[j].d_name)>0){
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
    puts("\t -----------");
    for(i=0; i<n; i++){
        printf("\t [%d] %7s %5d\n", i+1, s[i].d_name, s[i].bus);
    }
    puts("\t-------------");

    return 0; 
}