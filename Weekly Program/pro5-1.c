//fibonacci
#include<stdio.h>
int main() {
    int f, n, numA=0, numB=1;
    printf("Enter a number : ");
    scanf("%d", &n);

    if (n==0) {
        printf("F(0) : %d", numA);
    }
    else if (n==1) {
        printf("F(1) : %d", numB);
    }
    else if (n>1) {
        for (int seq=2; seq<=n; seq++) {
            f = numA + numB;
            numA = numB;
            numB = f;
        }
        printf("F(%d) : %d", n, f);
    }
    else {
        printf("Invalid number");
    }
    return 0;
}