#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void save(char **author, char **title, int *year, int count) {
	int len;
	printf("Enter the size of author \n");
	scanf("%d", &len);
	author[count] = (char*)calloc(len + 1, sizeof(char));
	printf("Enter the size of title\n");
	scanf("%d", &len);
	title[count] = (char*)calloc(len + 1, sizeof(char));
	printf("Enter the author and title\n");
	scanf("%s %s", author[count], title[count]);
	printf("Enter the year\n");
	scanf("%d", year);
	printf("\n");
}

void list(char **author, char **title, int *year, int count) {
	for (int i = 0; i < count; i++) {
		printf("%s -- %s -- %d\n", author[i], title[i], year[i]);
	}
}

int main() {

	char **author;
	char **title;
	int *year;
	int count = 0, i;
	int choice;

	author = (char**)malloc(sizeof(char*));
	title = (char**)malloc(sizeof(char*));
	year = (int*)malloc(sizeof(int));

	while (1) {
		printf("1-Add\n2-List\n3-Exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:save(author, title, (year + count), count);
			count++;
			author =(char**)realloc(author, (count + 1) * sizeof(char*));
			title = (char**)realloc(title, (count + 1) * sizeof(char*));
			year = (int*)realloc(year, (count + 1) * sizeof(int));
			break;
		case 2:list(author, title, year, count);
			break;
		case 3:	for (i = 0; i < count; i++) {
			free(author[i]);
			free(title[i]);
		}
				free(year);
				free(title);
				free(author); exit(0); break;
		}
		
	}
	
	return 0;
}
