//find max-min among three numbers
#include<stdio.h>
int main() {
    int n[10], i, max=0, min=0;
    printf("Enter three numbers : ");
    do {
        scanf("%d", &n[i++]);
    } while (i<3);

    for (i=1; i<3; i++) {
        if (n[i]>n[max]) {
            max=i;
        }
        if (n[i]<n[min]) {
            min=i;
        }
    }
    printf("Maximum + Minimum = %d", n[max]+n[min]);
    return 0;
}