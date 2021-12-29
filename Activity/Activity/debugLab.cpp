#include<stdio.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
    double a, b, c, s=0, area=0;
    printf("Enter each side of triangle : ");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    if (a+b>c && b+c>a && c+a>b && a>0 && b>0 && c>0) {
        s = a+b+c/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        printf("%.2lf", area);
    }
    else {
        printf("0");
    }
    return 0;
}