#include<stdio.h>

float lpf(float input, float alpha){
    static float prev_output = 0.0f;
    float output = alpha * input + (1.0f - alpha) * prev_output; 
    prev_output = output; 
    return output; 
}

int main(){
    float alpha = 0.3f;
    float noisy_data[] = {3, 5, 6, 3, 7, 4, 5, 2, 4, 5, 6, 7};
    int len = sizeof(noisy_data)/sizeof(noisy_data[0]);
    for(int i=0; i<len; i++){
        float filtered = lpf(noisy_data[i], alpha);
        printf("Input: %.2f -> Filtered: %.2f\n", noisy_data[i], filtered);
    }
    return 0; 
}