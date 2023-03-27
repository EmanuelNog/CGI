#include <stdio.h>

void test(float array[]){

    //int size = sizeof array / sizeof array[0];
    float size = sizeof array[0] / sizeof(float);
    printf("alo %f",size);
    
}
void main(){

    float array[3]={1,2,3};

    test(array);

    
}
