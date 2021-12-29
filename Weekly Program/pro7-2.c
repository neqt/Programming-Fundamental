//convert seconds to hours
#include<stdio.h>
int main() {
    int num, sec=0, min=0, hrs=0;
    scanf("%d", &num);
    if (num>59) {
        sec = num%60;
        num /= 60;
        if (num>59) {
            min = num%60;
            hrs = num/60;
        }
        else {
            min = num;
        }
    }
    else {
        sec = num;
    }
    printf("%d:%02d:%02d", hrs, min, sec);
    return 0;
}