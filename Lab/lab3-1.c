//sum of digits until single digit
#include<stdio.h>
int main() {    
    int num, sum;
    printf("Enter a number : ");
    scanf("%d", &num);   
    printf("%d", num);
    while(num>9) {
        sum = 0;
        while(num>0) { 
            sum += num%10;
            num /= 10;
        }
        printf(" -> %d", sum);
        num = sum;
    }
    return 0;
}