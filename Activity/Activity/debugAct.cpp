#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main2()
{
    int n, reversedInteger = 1, remainder, originalInteger;
    printf("Enter an integer: ");
    scanf_s("%d", &n);

    originalInteger = n;
    // reversed integer is stored in variable (#1)
    while (n != 0)
    {
        remainder = n % 10;
        reversedInteger = reversedInteger * 10 + remainder; //bug here
        n /= 10;  //(#2)
    }

    // palindrome if orignalInteger and reversedInteger are equal (#3)
    if (originalInteger == reversedInteger)
    {
        printf("%d is a palindrome.", originalInteger);
    }
    else
    {
        printf("%d is not a palindrome.", originalInteger);
    }
    return 0;
}