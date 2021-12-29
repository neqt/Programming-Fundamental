//greatest common divisor
#include<stdio.h>
int main() {
    int firstNum, secondNum, i, gcd;
    printf("Enter first number : ");
    scanf("%d", &firstNum);   
    printf("Enter second number : ");
    scanf("%d", &secondNum);
    for (i=1; i<=firstNum && i<=secondNum; i++) {
        if (firstNum%i==0 && secondNum%i==0) {
            gcd=i;
        }
    }
    printf("Greatest common divisor = %d", gcd);
    return 0;
}