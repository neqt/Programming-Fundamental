//factorial
#include<stdio.h>

int factorial(int n) {
    int fac=1;
    for (int cnt=n; cnt>=1; cnt--) {
        fac*=cnt;
    }
    return fac;
}

int main() {
    int n;
    printf("Enter a nember : ");
    scanf("%d", &n);
    if (n>=0) {
        printf("%d! = %d", n, factorial(n));
    }
    else {
        printf("Error");
    }
    return 0;
}