//write a string to a text file
#include <stdio.h>
#include <string.h>
int main() {
    FILE *fileAddress;
    fileAddress = fopen("data.txt", "w");
    char str[1000];
    int count = 0;
    do {
        scanf("%c", &str[count]);
        count++;
    } while (str[count - 1] != '.');

    if (fileAddress != NULL) {
        for (int i = 0; i < count; i++) {
            fputc(str[i], fileAddress);
        }
        fclose(fileAddress);
    }
    else {
        printf("\n Unable to Create or Open the data.txt File");
    }
    return 0;
}