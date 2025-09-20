#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char* name;
}Person;

int main(){
    Person original;
    original.name = (char*)malloc(50* sizeof(char));
    if(original.name == NULL){
        perror("Memory allocation failed");
    }
    strcpy(original.name, "Allice");

    //Shallow copy
    Person shallowCopy;
    shallowCopy.name = original.name;

    // Deep copy
    Person deepCopy;
    deepCopy.name = (char*)malloc(50*sizeof(char));
    if(deepCopy.name == NULL){
        perror("Memory allocation failed");
        free(original.name);
        return 1;
    }

    printf("Original name: %s\n", original.name);
    printf("Shallow copy name: %s\n", shallowCopy.name);
    printf("Deep copy name: %s\n", deepCopy.name);

    //Modify original name
    strcpy(original.name, "Bob");
    
    // Show result
    printf("\n After Modification\n");
    printf("Original name: %s\n", original.name);
    printf("Shallow copy name: %s\n", shallowCopy.name);
    printf("Deep copy name: %s\n", deepCopy.name);

    free(original.name);
    free(deepCopy.name);

    return 0; 
}