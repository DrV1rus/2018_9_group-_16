#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//student
void CourseRegistration();
void RegisteredCourses();

typedef struct {
	char num_id[10];
	char name[20];
	char last_name[20];
	char date[10];
	char name_class[20];
	int year;
	char semester;
	char marital_status[10];
	char courses[100];
	char adress[100];
	char mail[100];
	char phone_number[11];
	int bill;
	char grades[10];
}Students;

typedef struct {
	char name_class[20];
	char Lecturers[500];
	char Practicing[500];
	char workers[500];
	char courses[500];
	char Students[500];
}Academic_departments;

int main() {
	int option; //the choice of the user
	do {
		printf("Please choose an option:\nMenu:\n1-Course registration\n2-Schedule\n3-Grades\n4-Exams Schedule\n5-Messages\n6-Account page\n7-Update details\n8-Reports\n9-Help\n10-Exit\n");
		scanf("%d", &option);
		switch (option) {
		case 1:
			CourseRegistration();
			break;
		case 2:
			printf("option 2\n");
			break;
		case 3:
			printf("option 3\n");
			break;
		case 4:
			printf("option 4\n");
			break;
		case 5:
			printf("option 5\n");
			break;
		case 6:
			printf("option 6\n");
			break;
		case 7:
			printf("option 7\n");
			break;
		case 8:
			printf("option 8\n");
			break;
		case 9:
			printf("option 9\n");
			break;
		case 10:
			printf("option 10\n");
			break;
		default:
			if (option < 1 || option>10)
				printf("Please choose another option\n");
		}
	} while (option != 10); //when you choose exit it will exit the program and loop

	return 0;
}


void CourseRegistration() {
	int option;
	do {
		printf("Please choose an option:\n1-Registered Courses\n2-Courses to register for them\n3-Back to main menu");
		scanf("%d", &option);
		switch (option) {
		case 1:
			RegisteredCourses();
			break;
		case 2:
			printf("2");
			break;
		case 3:
			break;
		}

	} while (option != 3);

}

void RegisteredCourses() {
	Students student1;
	Academic_departments course1;
	char id[10] = "32748594";
	char temp[500] = { '0' };
	char class[20];
	int year_study = 0;
	int line = 0;
	FILE *ofp;
	ofp = fopen("Students.txt", "r+");
	if (ofp == NULL) {
		printf("Can't open the file\n");
		exit(1);
	}
	//while (fscanf(ofp, "%s %s %s %s %s %d %s %s %s %s %s %d %s ", &student1.num_id, &student1.name, &student1.last_name, &student1.date, &student1.name_class, &student1.year, &student1.semester, &student1.marital_status, &student1.courses, &student1.adress, &student1.mail, &student1.phone_number, &student1.bill, &student1.grades) != EOF)
	//{
		/*if (strcmp(id, student1.num_id) == 0) {
			strcpy(class, student1.name_class);
			year_study = student1.year;
		}*/
	//}
	(fscanf(ofp, "%s %s %s %s %s %d %s %s %s %s %s %d %s ", &student1.num_id, &student1.name, &student1.last_name, &student1.date, &student1.name_class, &student1.year, &student1.semester, &student1.marital_status, &student1.courses, &student1.adress, &student1.mail, &student1.phone_number, &student1.bill, &student1.grades) != EOF);
	printf("year:%d\n", year_study);
	printf("class:%s\n", class);
	fclose(ofp);
	FILE *ofp2;
	ofp2 = fopen("Academic departments.txt", "r");
	if (ofp2 == NULL) {
		printf("Can't open the file\n");
		exit(1);
	}
	while (!feof(ofp2)) 
	{
		fgets(temp, 500, ofp2);
		line++;
		if (line == 1)
			strcpy(course1.name_class, temp);
		if (line == 2)
			strcpy(course1.Lecturers, temp);
		if (line == 3)
			strcpy(course1.Practicing, temp);
		if (line == 4)
			strcpy(course1.workers, temp);
		if (line == 5)
			strcpy(course1.courses, temp);
		if (line == 6)
			strcpy(course1.Students, temp);
	}
	printf("%s\n", course1.courses);
	fclose(ofp2);
	strcat(student1.courses, " ");
	strcat(student1.courses, course1.courses);
	printf("%s\n", student1.courses);
	FILE *wop;
	wop = fopen("Students.txt", "r+");
	if (wop == NULL) {
		printf("Can't open the file\n");
		exit(1);
	}
	int count = 0;
	fwrite(&student1, sizeof(Students), 1, wop);
	printf(" Student's ID: %s \n", student1.num_id);
	printf(" Student's name: %s \n", student1.name);
	printf(" Student's lastname: %s \n", student1.last_name);
	printf(" Student's date: %s \n", student1.date);
	printf(" Student's class: %s \n", student1.name_class);
	printf(" Student's year: %d \n", student1.year);
	printf(" Student's semester: %c \n", student1.semester);
	printf(" Student's marital status: %s \n", student1.marital_status);
	printf(" Student's courses: %s \n", student1.courses);
	printf(" Student's adress: %s \n", student1.adress);
	printf(" Student's mail: %s \n", student1.mail);
	printf(" Student's phone number: %s \n", student1.phone_number);
	printf(" Student's bill: %d \n", student1.bill);
	printf(" Student's grades: %s \n", student1.grades);
	fclose(wop);
	printf("DONE\n");

}
