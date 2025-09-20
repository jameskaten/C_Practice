#include<stdio.h>
#include<string.h>

int main(){
    char city[5][10];
    char tmp[10];
    int i, j, n;
    n = sizeof(city)/sizeof(char[10]);

    // Input
    printf("Where do you want to live? [%d] places\n", n);
    for(i=0; i<n; i++){
        printf("[%d]th city: ", i);
        fgets(city[i], sizeof(city[i]), stdin);
    }
    puts("\n Original");
    for(i=0; i<n; i++){
        printf("city[%d] ==> %s\n", i, city[i]);
    }

    //Arrange
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(strcmp(city[i], city[j])>0){
                strcpy(tmp, city[i]);
                strcpy(city[i], city[j]);
                strcpy(city[j], tmp);
            }
        }
    }
    //Print
    puts("\n Output");
    for(i=0; i<n; i++){
        printf("city[%d] ==> %s\n", i, city[i]);
    }
    return 0; 
}