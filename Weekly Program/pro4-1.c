//find standard deviation among 10 numbers
#include<stdio.h>
int main() {
    float num[10]; 
    int typeData, cnt=0;
    printf("Please select the type of calculation\n");
    printf("1. Sample\n2. Population\n");
    printf("It is a : ");
    scanf("%d", &typeData);
    printf("Enter data set : ");
    do {
        scanf("%f", &num[cnt++]);
    } while (cnt<10);
    
    printf("Standard deviation : ");
    float sum=0;
    for (cnt=0; cnt<10; cnt++) {
        sum += num[cnt];
    }
    float mean=sum/10, squares=0;
    for (cnt=0; cnt<10; cnt++) {
        squares += (num[cnt]-mean)*(num[cnt]-mean);
    }
    float variance=0;
    if (typeData==1) {
        variance = squares/9;
        float sqrt = variance/2;
        float temp = 0;     
        while (sqrt!=temp) {
            temp = sqrt;
            sqrt = (variance/temp+temp)/2;
        }
        printf("%f", sqrt);
    }
    else if (typeData==2) {
        variance=squares/10;
        float sqrt = variance/2;
        float temp = 0;
        while (sqrt!=temp) {
            temp = sqrt;
            sqrt = (variance/temp+temp)/2;
        }
        printf("%f", sqrt);
    }
    else {
        printf("Invalid type");
    }
    return 0;
}