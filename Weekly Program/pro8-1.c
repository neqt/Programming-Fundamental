//write a string to a text file
#include<stdio.h>
int main() {
    FILE *fp;
    char str[1000];
    int count = 0;
    do {
        scanf("%c", &str[count]);
        count++;  
    } while (str[count-1] != '.');

    fp = fopen("data.txt", "w");
    for (int i = 0; i < count; i++) {        
        fprintf(fp, "%c", str[i]);
    }   
    fclose(fp);
    return 0;
}