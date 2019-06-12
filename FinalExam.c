#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <string>


typedef struct
{
	char type;			// type (tur)

	char name[100];   //name surname (ad soyad)

	int id;			//id(Numara)


	char courses[7][100];	// 7 course name/ title of  thesis
	char thesis[1000];

}STD;



int main()
{

	STD grad[3];
	char ch;
	int count = 0, j = 0;
	while (1) {


		printf("Enter type, name surname, id and the courses:");
		scanf("%c", &grad[0].type);
		while (getchar() != '\n');
		scanf("%s", &grad[0].name);
		scanf("%d", &grad[0].id);

		if (grad[0].type = 'P') {
			scanf("%s", &grad[0].thesis);
		}
		else {
			for (int i = 0; i < 7; i++) {
				scanf("%s", grad[0].courses[i][100]);
			}
		}

		system("pause");

	}
	system("pause");
	return 0;
}
