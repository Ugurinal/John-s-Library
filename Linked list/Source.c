#include <stdio.h>
#include <stdlib.h>

struct STUDENT {
	STUDENT* next;
	int id;
	char info[50];
	int rank;
};

int main() {

	STUDENT* list = NULL;
	STUDENT* temp;
	STUDENT* head;
	int id, count, choice;
	while (1) {

		printf("1-Add\n2-List\n3-Delete\n4-Exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			temp = (STUDENT*)malloc(sizeof(STUDENT));
			printf("Enter the id-message-rank\n");
			scanf("%d %s %d", &temp->id, &temp->info, &temp->rank);
			if (list == NULL) {
				list = temp;
			}
			else {
				head = list;
				while (head->next != NULL) {
					head = head->next;
				}
				head->next = temp;
			}
			temp->next = NULL;
			break;

		case 2:
			head = list;
			while (head != NULL) {
				printf("%d - %s - %d\n", head->id, head->info, head->rank);
				head = head->next;
			}
			break;
		case 3:
			printf("Enter id to delete\n");
			scanf("%d", &id);
			head = list;
			temp = list->next;
			if (list->id == id) {
				list = list->next;
			}
			else {
				while (temp != NULL) {
					if (temp->id == id) {
						head->next = temp->next;
					}
					temp = temp->next;
					head = head->next;
				}
			}
			break;
		case 4:exit(0);
		}

	}
	
	system("pause");
	return 0;
}