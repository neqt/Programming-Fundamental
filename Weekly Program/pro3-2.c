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
        int j=0;
        for (int i=1; i<=num[cnt]; i++) {
            if(num[cnt]%i==0) {
                j+=1;
            }
        }
        if (j==2) {
            printf("%d ", num[cnt]);
        }   
    }
    return 0;
}