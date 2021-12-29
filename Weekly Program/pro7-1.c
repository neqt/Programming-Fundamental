//convert seconds to hours
#include<stdio.h>
int main() {
    int num, sec, min, hrs;
    scanf("%d", &num);
    sec = num%60;
    min = (num%3600)/60;
    hrs = num/3600;
    printf("%d:%02d:%02d", hrs, min, sec);
    return 0;
}