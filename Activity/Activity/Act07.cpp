#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
int main()
{
	FILE* fp;
	int i;
	struct player {
		char name[50];
		int level;
		int score;
	};
	player p[5];

	for (i = 0; i < 5; i++) {
		strcpy(p[i].name, "Anonymous");
		p[i].level = i;
		p[i].score = i * 100;
	}
	for (i = 0; i < 5; i++) {
		printf("name : %s\t", p[i].name);
		printf("level : %d\t", p[i].level);
		printf("score : %d\n", p[i].score);
	}

	fp = fopen("Activity07.txt", "w");

	for (i = 0; i < 5; i++) {
		fprintf(fp, "%s %d %d\n", p[i].name, p[i].level, p[i].score);
	}

	fclose(fp);
	return 0;
}