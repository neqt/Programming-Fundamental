//find max-min among three numbers
#include<stdio.h>
int main() {
    int firstNum, secondNum, thirdNum, max, min;
    printf("Enter three numbers : ");
    scanf("%d %d %d", &firstNum, &secondNum, &thirdNum);
    
    if (firstNum>=secondNum && firstNum>=thirdNum) {
        max=firstNum;
        if (secondNum<=thirdNum) {
            min=secondNum;
        }
        else {
            min=thirdNum;
        }
    }
    else if (secondNum>=thirdNum && secondNum>=firstNum) {
        max=secondNum;
        if (thirdNum<=firstNum) {
            min=thirdNum;
        }
        else {
            min=firstNum;
        }
    }
    else if (thirdNum>=firstNum && thirdNum>=secondNum) {
        max=thirdNum;
        if (firstNum<=secondNum) {
            min=firstNum;
        }
        else {
            min=secondNum;
        }
    }
    printf("Maximum + Minimum = %d", max+min);
    return 0;
}