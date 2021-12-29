//fibonacci
#include<stdio.h>
int main() {
    int f[1000], n, seq;
    printf("Enter a number : ");
    scanf("%d", &n);

    if (n>=0) {
        f[0]=0;
        f[1]=1;
        for (seq=2; seq<=n; seq++) {
            f[seq]=f[seq-1]+f[seq-2];
        }
        printf("F(%d) : %d", n, f[n]);
    }
    else {
        printf("Invalid number");
    }
    return 0;
}