#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
	char name[15];
	
	int year;
	book* next;
};


int main() {

	book* list = NULL;
	book* temp;
	book* head;
	int i = 0;
	int choice, len;
	while (i < 3) {

		temp = (book*)malloc(sizeof(book));

		scanf("%d %s", &temp->year, &temp->name);
		if (list == NULL)
			list = temp;
		else {
			head = list;
			while (head->next != NULL) {
				head = head->next;
			}
			head->next = temp;
		}
		temp->next = NULL;
		i++;
	}
	
	temp = (book*)malloc(sizeof(book));

	temp->year = 15;
	temp->next = list->next;
	list->next = temp;


	
	while (list != NULL) {
		printf("%d", list->year);
		list = list->next;
	}


	system("pause");
	return 0;
}