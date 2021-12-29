//factorization
#include<stdio.h>
int main() {
    int num, i;
    printf("Enter number : ");
    scanf("%d", &num);
    printf("Factoring Result : ");
    if (num>1) {
        for (i=2; i<=num; i++) {
            if (num%i==0) {
                printf("%d", i);
                num/=i;
                i=1;
                if (num>1) {
                    printf(" x ");
                }
            }
        }
    }
    else {
        printf("%d", num);
    }
    return 0;
}