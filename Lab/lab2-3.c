//hollow square
#include<stdio.h>
int main() {
    int num, i, j, k;
    printf("Enter number : ");
    scanf("%d", &num);
    for (i=1; i<=num; i++) {
        for (j=1; j<=num; j++) {
            if (i==1 || j==1 || i==num || j==num) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}