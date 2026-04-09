#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student {
	char name[10];
	int class;
	int grade;
};

int main() {

	int n;
	printf("N : ");
	scanf("%d", &n);

	char name_list[100][50];
	int  name_cnt = 0;

	FILE* fp;
	fp = fopen("name_list.txt", "r");
	if (fp == NULL) {
		printf("Fail to open\n");
		return 0;
	}

	char file_buff[50];

	while (fgets(file_buff, sizeof(file_buff), fp) != NULL) {

		file_buff[strcspn(file_buff, "\r\n")] = '\0';
		if (file_buff[0] != '\0') {
			strcpy(name_list[name_cnt], file_buff);
			name_cnt++;
		}

		memset(file_buff, 0, sizeof(file_buff));
	}

	fclose(fp);

	srand((unsigned)time(NULL));

	struct student* s = (struct student*)malloc(sizeof(struct student) * n);
	if (s == NULL) {
		printf("메모리 할당 실패\n");
		return 0;
	}

	for (int i = 0; i < n; i++) {
		strcpy(s[i].name, name_list[rand() % name_cnt]);
		s[i].class = i + 1;
		s[i].grade = rand() % 100 + 1;
	}

	struct student max;
	struct student min;  

	max = s[0];
	min = s[0]; 
	for (int i = 1; i < n; i++) {            
		if (s[i].grade > max.grade) max = s[i];
		if (s[i].grade < min.grade) min = s[i]; 
	}

	int total = 0;
	for (int i = 0; i < n; i++) total += s[i].grade;
	double avg = (double)total / n;

	printf("\n최고점  학번: %d  이름 : %s 성적 %d\n", max.class, max.name, max.grade);
	printf("최저점  학번: %d  이름 : %s 성적 %d\n", min.class, min.name, min.grade); 
	printf("평균    %.2f점\n", avg);  

	free(s); 

	return 0;
}