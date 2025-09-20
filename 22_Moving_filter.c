#include<stdio.h>
#define FILTER_SIZE 3

float buffer[FILTER_SIZE] = {0};
int bindex = 0;
int count = 0;

float average_moving(float new_sample){
    buffer[bindex] = new_sample;
    bindex = (bindex+1) % FILTER_SIZE; //Repeat and limit the filter size
    if(count<FILTER_SIZE) count++;
    //compute the average
    float sum = 0; 
    for(int i=0; i<count; i++){
        sum += buffer[i];
    }
    return sum/count;
}

int main(){
     float samples[] = {1, 5, 6, 7, 3, 5, 2, 6, 8, 9, 4, 3};
     int n= sizeof(samples)/sizeof(samples[0]);
     for(int i=0; i<n; i++){
        float avg = average_moving(samples[i]);
        printf("Input: %.2f\tMoving ave: %.2f\n", samples[i], avg);
     }
     return 0; 
}