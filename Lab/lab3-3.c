//make your own butterfly Ƹ̵̡Ӝ̵̨̄Ʒ
#include<stdio.h>
int main() {
    int num, x, y, size;
    printf("Enter the size of butterfly : ");
    scanf("%d", &num);
    size = (num*2)-1;
    for (y=1; y<=size; y++) {
        for (x=1; x<=size; x++) {
            if (x<=y && x+y<=size+1 || x>=y && x+y>=size+1) {
                printf("*  ");
            }
            else {
                printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
}