//P(x) = 1+...+(x-1) = x
#include<stdio.h>
int main() {
    int x, i, sum;
    for (x=1; x<=10000; x++) {
        sum=0;
        for (i=1; i<x; i++) {
            if (x%i==0) {
                sum += i;
            }
        }
        if (sum==x) {
            printf("%d ", sum);
        }
    }
    return 0;
}