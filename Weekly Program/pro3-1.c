//find prime number among 10 numbers
#include<stdio.h>
int main() {
    int num[10], cnt;
    printf("Enter 10 numbers : ");
    
    do {
        scanf("%d", &num[cnt++]);
    } while (cnt<10);
    
    printf("Prime Number : ");
    for (cnt=0; cnt<10; cnt++) {
        int numCheck=0;
        int tempNum=num[cnt];
        while (num[cnt]>1) {
            for (int i=2; i<=num[cnt]; i++) {
                if (num[cnt]%i==0) {
                    numCheck+=1;
                    num[cnt]/=i;
                    i=1;
                }
            }
        }
        if (numCheck==1) {
            printf("%d ", tempNum);
        }
    }
    return 0;
}