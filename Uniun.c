#include <stdio.h>
#include <stdlib.h>

struct book {
	char name[20];
	char author[20];
	int year;
	char isbn[13];

};

struct magazine {
	char name[20];
	int month;
	int year;

};

struct data {
	char type;
	union {
		book book;
		magazine magazine;
	}un;
	data *next;
};

data *veri = NULL;

int main() {

	data *temp;
	data *head;
	int choice;

	while (1) {
		temp = (data*)malloc(sizeof(data));
		printf("1-Add\n2-List\n3-Delete\n4-Exit\n");
		scanf("%d", &choice);
		while (getchar() != '\n');
		switch (choice) {
		case 1:
			printf("For book : b \n For magazine : m\n");
			temp->type = getchar();
			while (getchar() != '\n');
			switch (temp->type) {
			case 'b':
				printf("Enter name , author , year and isbn : \n");
				scanf("%20s %20s %d %13s", &temp->un.book.name, &temp->un.book.author, &temp->un.book.year, &temp->un.book.isbn);

				break;
			case 'm':
				printf("Enter name , month and year : \n");
				scanf("%20s %d %d", &temp->un.magazine.name, &temp->un.magazine.month, &temp->un.magazine.year);
				while (getchar() != '\n');

			}
			if (veri == NULL) {
				veri = temp;
				
			}
			else {
				head = veri;
				while (head->next != NULL) {
					head = head->next;
				}
				head->next = temp;
			}
			temp->next = NULL; break;
			break;
		case 2:
			head = veri;
			printf("Enter m for magazine b for book\n");
			scanf("%d", &temp->type);
			while (getchar() != '\n');
			switch (temp->type) {
			case 'b':
				while (head != NULL) {
					printf("%s-%s-%d-%s\n", head->un.book.name, head->un.book.author, head->un.book.year, head->un.book.isbn);
					head = head->next;
				}break;
			case 'm':
				while (head != NULL) {
					printf("%s-%d-%d\n", head->un.magazine.name, head->un.magazine.month, head->un.magazine.year);
					head = head->next;
				}break;
			}
			break;
		case 3:; // Delete ekle
		case 4:; // Exit;

		}

	}


	system("pause");
	return 0;
}
