#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20
#define INDEX 7
//student
void CourseRegistration(char*);
void CoursesToRegister(char*);
void DeleteCourses(char*);
void Schedule(char*);
void AccountPage(char*);
void StudentGrades(char*);
void ExamsSchedule(char*);
void StudentMessages();
void StudentReports(char*);
void StudentHelp();

struct Students {
	char num_id[10];
	char name[7];
	char last_name[7];
	char listed_courses[100];
	char exames[200];
	char bill[10];
	char birthday[9];
	char mail[20];
	char adress[25];
	char telephone[11];
};
typedef struct Students students;
//-------------------------------------------------
struct Academic_departments {
	char Lecturers[10];
	char Trainers[10];
	char workers[10];
	char students[10];
	char courses[5];
};
typedef struct Academic_departments department;
//--------------------------------------------------

struct Courses {
	char course_num[6];
	char course_name[35];
	char department[35];
	char points[4];
	char lecturer_name[35];
	char trainer_name[35];
	char lecture_time[35];
	char practice_time[35];
	char name_previous_courses[35];
	char home_work[10];
	char exames_date[35];
	char test_date[35];
	char places[3];
};
typedef struct Courses courses;
//------------------------------------------------

struct Bill {
	char student_id[10];
	char total_payment[10];
	char payed[10];
	char left_to_pay[10];
};
typedef struct Bill bill;

struct Grade {
	char student_id[10];
	char course_id[6];
	char first_exam[4];
	char second_exam[4];
	char special_exam[4];
};
typedef struct Grade grades;

int main() {
	int option;//the choice of the user
	char* id = "316317763";//example
	do {
		printf("\nMenu\n1-Course registration\n2-Schedule\n3-Grades\n4-Exams Schedule\n5-Messages\n6-Account page\n7-Update details\n8-Reports\n9-Help\n10-Exit\nPlease choose an option:\n");
		scanf("%d", &option);
		switch (option) {
		case 1:
			CourseRegistration(id);
			break;
		case 2:
			Schedule(id);
			break;
		case 3:
			StudentGrades(id);
			break;
		case 4:
			ExamsSchedule(id);
			break;
		case 5:
			StudentMessages();
			break;
		case 6:
			AccountPage(id);
			break;
		case 7:
			printf("option 7\n");
			break;
		case 8:
			StudentReports(id);
			break;
		case 9:
			StudentHelp();
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

void CourseRegistration(char* id) {
	int option;
	do {
		printf("\nPlease choose an option:\n1-Courses to register for them\n2-Delete registered Courses\n3-Back to main menu\n");
		scanf("%d", &option);
		switch (option) {
		case 1:
			CoursesToRegister(id);
			break;
		case 2:
			DeleteCourses(id);
			break;
		case 3:
			break;
		}

	} while (option != 3);

}

void CoursesToRegister(char* id) {
	char student_dep;
	char semester;
	printf("\nPlease choose your department:a-software, b-electrical\n");
	getchar();
	printf("Your choice:");
	scanf("%c", &student_dep);
	while (!(student_dep >= 'a' && student_dep <= 'z')) {
		printf("\nPlease choose again your department:a-software, b-electrical\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &student_dep);
	}
	printf("Please enter your semester:");
	getchar();
	scanf("%c", &semester);
	while (!(semester >= 'a' && semester <= 'z')) {
		printf("Please choose again your semester:\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &semester);
	}

	courses courses_reg[20];
	int num_courses = 0;
	char course_num[7];
	char answer;
	int i = 0, j = 0, k = 0, index = 0;
	char temp_arr[2500];//move all the file to this temp array
	FILE *ofp = NULL;//for opening courses file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("courses software-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("courses software-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp = fopen("courses electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("courses electrical-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else {
		printf("No such department,going back to main menu\n");
		return;
	}

	while (!feof(ofp)) {//reading for the courses file to get the name of courses
		temp_arr[index] = fgetc(ofp);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp);
	//stop reading from a file
	while (temp_arr[i] != '\0') { //move info to struct courses
		while (temp_arr[i] != '-') {
			courses_reg[k].course_num[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].course_num[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].course_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].course_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].department[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].department[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].points[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].points[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].lecturer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].lecturer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].trainer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].trainer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].lecture_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].lecture_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].practice_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].practice_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].name_previous_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].name_previous_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].home_work[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].home_work[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].exames_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].exames_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[k].test_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].test_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			courses_reg[k].places[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[k].places[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		k++;
	}
	num_courses = k;
	printf("\nPlease choose a course to register:\n");
	for (int i = 0; i < num_courses; i++)
		printf("%s %s\n", courses_reg[i].course_num, courses_reg[i].course_name);

	printf("Enter the number of course you want to register:\n");
	scanf("%s", &course_num);
	char places_left[3];
	for (int i = 0; i < num_courses; i++) {
		if (strcmp(course_num, courses_reg[i].course_num) == 0) {
			printf("Course number: %s\n", courses_reg[i].course_num);
			printf("Course name: %s\n", courses_reg[i].course_name);
			printf("Lecturer name: %s\n", courses_reg[i].lecturer_name);
			printf("Lecture time: %s\n", courses_reg[i].lecture_time);
			printf("Trainer name: %s\n", courses_reg[i].trainer_name);
			printf("Practice time: %s\n", courses_reg[i].practice_time);
			printf("How much places left in course: %s\n", courses_reg[i].places);
			strcpy(places_left, courses_reg[i].places);
		}
	}

	printf("\nDo you want to register?\n0-No, 1-Yes\n");
	printf("Your choice:");
	getchar();
	scanf("%c", &answer);
	while (answer != '1' && answer != '0') {
		printf("Choose again-0 for no, 1 for yes\n");
		printf("Your choice:");
		getchar();
		scanf("%c", &answer);
	}
	if (answer == '1') {
		printf("Checking your listed courses\n");
	}
	else if (answer == '0') {
		return;
	}


	//***********************************updating the list of courses in student******************
	students student1[25];
	FILE *ofp2 = NULL;//for opening students file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp2 = fopen("students software-a.txt", "r");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp2 = fopen("students software-b.txt", "r");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp2 = fopen("students electrical-a.txt", "r");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp2 = fopen("students electrical-b.txt", "r");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	i = 0, j = 0, k = 0, index = 0;
	while (!feof(ofp2)) {//reading for the info on students
		temp_arr[index] = fgetc(ofp2);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp2);

	while (temp_arr[i] != '\0') { //move info to struct
		while (temp_arr[i] != '-') {
			student1[k].num_id[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].num_id[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].last_name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].last_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].listed_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].listed_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].exames[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].exames[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].bill[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].bill[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].birthday[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].birthday[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].mail[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].mail[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].adress[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].adress[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			student1[k].telephone[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].telephone[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		k++;
	}
	int num_students = k;

	//check if the course already exists
	int z = 0;
	for (int l = 0; l < num_students; l++) {
		if (strcmp(id, student1[l].num_id) == 0) {
			if (course_num[0] == student1[l].listed_courses[z] && course_num[1] == student1[l].listed_courses[z + 1] && course_num[2] == student1[l].listed_courses[z + 2] && course_num[3] == student1[l].listed_courses[z + 3] && course_num[4] == student1[l].listed_courses[z + 4]) {
				printf("Choose another course, you already registered:\n");
				scanf("%s", &course_num);
			}
		}
	}
	//
	char add_between[2] = { ',' };
	strcat(course_num, add_between);
	//add course
	for (int d = 0; d < num_students; d++) {
		if (strcmp(id, student1[d].num_id) == 0) {
			if (student1[d].listed_courses[0] == 'n')
				strcpy(student1[d].listed_courses, course_num);
			else
				strcat(student1[d].listed_courses, course_num);
			//changing the list of courses
		}
	}
	printf("You have successfully signed for Course\n");
	//----------------------writing to file-----------------------------
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp2 = fopen("students software-a.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp2 = fopen("students software-b.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp2 = fopen("students electrical-a.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp2 = fopen("students electrical-b.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}

	int a = 0, b = 0;
	while (b < num_students)
	{
		for (a = 0; student1[b].num_id[a] != '\0'; a++)
			fputc(student1[b].num_id[a], ofp2);
		if (student1[b].num_id[a] == '\0')
		{
			fputc('-', ofp2);
		}
		//**************************************************************
		for (a = 0; student1[b].name[a] != '\0'; a++)
			fputc(student1[b].name[a], ofp2);
		if (student1[b].name[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].last_name[a] != '\0'; a++)
			fputc(student1[b].last_name[a], ofp2);
		if (student1[b].last_name[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].listed_courses[a] != '\0'; a++)
			fputc(student1[b].listed_courses[a], ofp2);
		if (student1[b].listed_courses[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].exames[a] != '\0'; a++)
			fputc(student1[b].exames[a], ofp2);
		if (student1[b].exames[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].bill[a] != '\0'; a++)
			fputc(student1[b].bill[a], ofp2);
		if (student1[b].bill[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].birthday[a] != '\0'; a++)
			fputc(student1[b].birthday[a], ofp2);
		if (student1[b].birthday[a] == '\0')
		{
			fputc('-', ofp2);
		}
		//**************************************************************
		for (a = 0; student1[b].mail[a] != '\0'; a++)
			fputc(student1[b].mail[a], ofp2);
		if (student1[b].mail[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].adress[a] != '\0'; a++)
			fputc(student1[b].adress[a], ofp2);
		if (student1[b].adress[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].telephone[a] != '\0'; a++)
			fputc(student1[b].telephone[a], ofp2);
		if (student1[b].telephone[a] == '\0')
		{
			fputc('$', ofp2);
			fputc('\n', ofp2);
		}
		b++;
	}
	fclose(ofp2);
	//*********************************end of updating student************************
	//**************************Updating info to database Courses-number of students**********************
	int number = 0;
	char first, second;
	first = places_left[0];
	second = places_left[1];
	number = (first - '0') * 10 + (second - '0');
	number = number - 1;// one student register,left places-1
	places_left[0] = (number / 10) + '0';
	places_left[1] = (number % 10) + '0';
	places_left[2] = '\0';
	for (int i = 0; i < num_courses; i++) {
		if (strcmp(course_num, courses_reg[i].course_num) == 0)
			strcpy(courses_reg[i].places, places_left);
	}
	FILE *ofp1 = NULL;
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp1 = fopen("courses software-a.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses software-b.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else {//electrical
		if (semester == 'a') {
			ofp1 = fopen("courses electrical-a.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses electrical-b.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	a = 0, b = 0;
	while (b < num_courses)
	{
		for (a = 0; courses_reg[b].course_num[a] != '\0'; a++)
			fputc(courses_reg[b].course_num[a], ofp1);
		if (courses_reg[b].course_num[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].course_name[a] != '\0'; a++)
			fputc(courses_reg[b].course_name[a], ofp1);
		if (courses_reg[b].course_name[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].department[a] != '\0'; a++)
			fputc(courses_reg[b].department[a], ofp1);
		if (courses_reg[b].department[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].points[a] != '\0'; a++)
			fputc(courses_reg[b].points[a], ofp1);
		if (courses_reg[b].points[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].lecturer_name[a] != '\0'; a++)
			fputc(courses_reg[b].lecturer_name[a], ofp1);
		if (courses_reg[b].lecturer_name[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].trainer_name[a] != '\0'; a++)
			fputc(courses_reg[b].trainer_name[a], ofp1);


		if (courses_reg[b].trainer_name[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].lecture_time[a] != '\0'; a++)
			fputc(courses_reg[b].lecture_time[a], ofp1);


		if (courses_reg[b].lecture_time[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].practice_time[a] != '\0'; a++)
			fputc(courses_reg[b].practice_time[a], ofp1);


		if (courses_reg[b].practice_time[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].name_previous_courses[a] != '\0'; a++)
			fputc(courses_reg[b].name_previous_courses[a], ofp1);


		if (courses_reg[b].name_previous_courses[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].home_work[a] != '\0'; a++)
			fputc(courses_reg[b].home_work[a], ofp1);


		if (courses_reg[b].home_work[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].exames_date[a] != '\0'; a++)
			fputc(courses_reg[b].exames_date[a], ofp1);


		if (courses_reg[b].exames_date[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].test_date[a] != '\0'; a++)
			fputc(courses_reg[b].test_date[a], ofp1);


		if (courses_reg[b].test_date[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].places[a] != '\0'; a++)
			fputc(courses_reg[b].places[a], ofp1);


		if (courses_reg[b].places[a] == '\0')
		{
			fputc('$', ofp1);
			fputc('\n', ofp1);
		}
		b++;


	}
	fclose(ofp1);

	//***********************************end of updating number of places*************************
}

void DeleteCourses(char* id) {
	char student_dep;
	char semester;
	printf("\nPlease choose your department:a-software, b-electrical\n");
	getchar();
	printf("Your choice:");
	scanf("%c", &student_dep);
	while (!(student_dep >= 'a' && student_dep <= 'z')) {
		printf("\nPlease choose again your department:a-software, b-electrical\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &student_dep);
	}
	printf("Please enter your semester:");
	getchar();
	scanf("%c", &semester);
	while (!(semester >= 'a' && semester <= 'z')) {
		printf("Please choose again your semester:\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &semester);
	}
	courses courses_reg[20];
	char courses_to_show[100];
	char course_num[6];
	int i = 0, j = 0, k = 0, index = 0;
	students student1[25];
	char temp_arr[2500];
	FILE *ofp = NULL;//for opening students file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("students software-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students software-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp = fopen("students electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students electrical-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else {
		printf("No such department,going back to main menu\n");
		return;
	}

	i = 0, j = 0, k = 0, index = 0;
	while (!feof(ofp)) {//reading for the info on students
		temp_arr[index] = fgetc(ofp);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp);

	while (temp_arr[i] != '\0') { //move info to struct students
		while (temp_arr[i] != '-') {
			student1[k].num_id[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].num_id[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].last_name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].last_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].listed_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].listed_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].exames[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].exames[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].bill[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].bill[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].birthday[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].birthday[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].mail[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].mail[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].adress[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].adress[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			student1[k].telephone[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].telephone[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		k++;
	}
	//************************end of moving to struct*******************
	int num_students = k;
	int index_in_student_list = 0;
	for (int t = 0; t < num_students; t++) {
		if (strcmp(id, student1[t].num_id) == 0) {
			strcpy(courses_to_show, student1[t].listed_courses);
			index_in_student_list = t;
		}
	}

	FILE *ofp1 = NULL;//for opening courses file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp1 = fopen("courses software-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses software-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else {//electrical
		if (semester == 'a') {
			ofp1 = fopen("courses electrical-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses electrical-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}

	}
	index = 0;
	while (!feof(ofp1)) {//reading for the courses file to get the name of courses
		temp_arr[index] = fgetc(ofp1);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp1);
	//stop reading from a file courses
	i = 0, j = 0;
	int g = 0, d = 0;
	while (temp_arr[i] != '\0') { //move info to struct courses
		while (temp_arr[i] != '-') {
			courses_reg[g].course_num[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].course_num[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].course_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].course_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].department[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].department[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].points[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].points[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].lecturer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].lecturer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].trainer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].trainer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].lecture_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].lecture_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].practice_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].practice_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].name_previous_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].name_previous_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].home_work[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].home_work[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].exames_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].exames_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].test_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].test_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			courses_reg[g].places[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].places[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		g++;
	}
	//char courses_in_semester[100];
	int array_index[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int num_courses = g;
	int f = 0, h = 0, s = 0, a = 0, flag = 0;
	while (courses_to_show[h] != '\0') {
		for (f = 0; f < num_courses; f++) {
			if (courses_to_show[h] == courses_reg[f].course_num[0] && courses_to_show[h + 1] == courses_reg[f].course_num[1] && courses_to_show[h + 2] == courses_reg[f].course_num[2] && courses_to_show[h + 3] == courses_reg[f].course_num[3] && courses_to_show[h + 4] == courses_reg[f].course_num[4]) {
				array_index[a] = f;
				a++;
				h += 6;
			}
		}
	}

	printf("\nYour registered courses:\n");
	for (d = 0; d < SIZE; d++) {
		if (array_index[d] != -1) {
			printf("Course number: %s, ", courses_reg[array_index[d]].course_num);
			printf("Course name: %s\n", courses_reg[array_index[d]].course_name);

		}
	}
	printf("Please enter the course number you want to delete:\n");
	printf("Course number:");
	scanf("%s", &course_num);
	printf("\n");
	printf("Info on course:\n");
	int course_index = 0;
	char places_left[3];
	for (int i = 0; i < num_courses; i++) {
		if (strcmp(course_num, courses_reg[i].course_num) == 0) {
			printf("Course number:%s\n", courses_reg[i].course_num);
			printf("Course name:%s\n", courses_reg[i].course_name);
			printf("Lecturer name:%s\n", courses_reg[i].lecturer_name);
			printf("Lecture time:%s\n", courses_reg[i].lecture_time);
			printf("Trainer name:%s\n", courses_reg[i].trainer_name);
			printf("Practice time:%s\n", courses_reg[i].practice_time);
			course_index = i;
			strcpy(places_left, courses_reg[i].places);
		}
	}
	printf("\n");
	printf("You successfully deleted the course\n");
	//***********************************************************************************
	//****************************Deleting from student**********************************
	a = 0, f = 0, j = 0;
	int index_start = 0;
	while (j < 100) {//finding the index of the course
		if (student1[index_in_student_list].listed_courses[j] == course_num[0] && student1[index_in_student_list].listed_courses[j + 1] == course_num[1] && student1[index_in_student_list].listed_courses[j + 2] == course_num[2] && student1[index_in_student_list].listed_courses[j + 3] == course_num[3] && student1[index_in_student_list].listed_courses[j + 4] == course_num[4]) {
			index_start = j;
			break;
		}
		j += 6;
	}
	char temp[100];
	int index_end = index_start + 5;
	int p = 0;
	for (int w = 0; courses_to_show[w] != '\0'; w++) {
		if (!(w >= index_start && w <= index_end)) {
			temp[p] = courses_to_show[w];
			p++;
		}
	}
	temp[p] = '\0';
	if (temp[0] == '\0') {
		strcpy(temp, "none");
	}
	strcpy(student1[index_in_student_list].listed_courses, temp);
	//*********************Updating Student*****************************
	FILE *ofp2 = NULL;//for opening students file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp2 = fopen("students software-a.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp2 = fopen("students software-b.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp2 = fopen("students electrical-a.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp2 = fopen("students electrical-b.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}

	a = 0;
	int b = 0;
	while (b < num_students)
	{
		for (a = 0; student1[b].num_id[a] != '\0'; a++)
			fputc(student1[b].num_id[a], ofp2);
		if (student1[b].num_id[a] == '\0')
		{
			fputc('-', ofp2);
		}
		//**************************************************************
		for (a = 0; student1[b].name[a] != '\0'; a++)
			fputc(student1[b].name[a], ofp2);
		if (student1[b].name[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].last_name[a] != '\0'; a++)
			fputc(student1[b].last_name[a], ofp2);
		if (student1[b].last_name[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].listed_courses[a] != '\0'; a++)
			fputc(student1[b].listed_courses[a], ofp2);
		if (student1[b].listed_courses[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].exames[a] != '\0'; a++)
			fputc(student1[b].exames[a], ofp2);
		if (student1[b].exames[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].bill[a] != '\0'; a++)
			fputc(student1[b].bill[a], ofp2);
		if (student1[b].bill[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].birthday[a] != '\0'; a++)
			fputc(student1[b].birthday[a], ofp2);
		if (student1[b].birthday[a] == '\0')
		{
			fputc('-', ofp2);
		}
		//**************************************************************
		for (a = 0; student1[b].mail[a] != '\0'; a++)
			fputc(student1[b].mail[a], ofp2);
		if (student1[b].mail[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].adress[a] != '\0'; a++)
			fputc(student1[b].adress[a], ofp2);
		if (student1[b].adress[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].telephone[a] != '\0'; a++)
			fputc(student1[b].telephone[a], ofp2);
		if (student1[b].telephone[a] == '\0')
		{
			fputc('$', ofp2);
			fputc('\n', ofp2);
		}
		b++;
	}
	fclose(ofp2);
	//*********************************end of updating student************************


	//***************************Deleting from courses-update places***********************************
	int number = 0;
	char first, second;
	first = places_left[0];
	second = places_left[1];
	number = (first - '0') * 10 + (second - '0');
	number = number + 1;// one student left places+1
	places_left[0] = (number / 10) + '0';
	places_left[1] = (number % 10) + '0';
	places_left[2] = '\0';
	strcpy(courses_reg[course_index].places, places_left);
	//******************************************************************************************
	//************************moving updated info********************
	ofp1 = NULL;
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp1 = fopen("courses software-a.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses software-b.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else {//electrical
		if (semester == 'a') {
			ofp1 = fopen("courses electrical-a.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses electrical-b.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	a = 0;
	b = 0;
	while (b < num_courses)
	{
		for (a = 0; courses_reg[b].course_num[a] != '\0'; a++)
			fputc(courses_reg[b].course_num[a], ofp1);
		if (courses_reg[b].course_num[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].course_name[a] != '\0'; a++)
			fputc(courses_reg[b].course_name[a], ofp1);
		if (courses_reg[b].course_name[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].department[a] != '\0'; a++)
			fputc(courses_reg[b].department[a], ofp1);
		if (courses_reg[b].department[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].points[a] != '\0'; a++)
			fputc(courses_reg[b].points[a], ofp1);
		if (courses_reg[b].points[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].lecturer_name[a] != '\0'; a++)
			fputc(courses_reg[b].lecturer_name[a], ofp1);
		if (courses_reg[b].lecturer_name[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].trainer_name[a] != '\0'; a++)
			fputc(courses_reg[b].trainer_name[a], ofp1);


		if (courses_reg[b].trainer_name[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].lecture_time[a] != '\0'; a++)
			fputc(courses_reg[b].lecture_time[a], ofp1);


		if (courses_reg[b].lecture_time[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].practice_time[a] != '\0'; a++)
			fputc(courses_reg[b].practice_time[a], ofp1);


		if (courses_reg[b].practice_time[a] == '\0')
		{
			fputc('-', ofp1);
		}

		//**************************************************************
		for (a = 0; courses_reg[b].name_previous_courses[a] != '\0'; a++)
			fputc(courses_reg[b].name_previous_courses[a], ofp1);


		if (courses_reg[b].name_previous_courses[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].home_work[a] != '\0'; a++)
			fputc(courses_reg[b].home_work[a], ofp1);


		if (courses_reg[b].home_work[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].exames_date[a] != '\0'; a++)
			fputc(courses_reg[b].exames_date[a], ofp1);


		if (courses_reg[b].exames_date[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].test_date[a] != '\0'; a++)
			fputc(courses_reg[b].test_date[a], ofp1);


		if (courses_reg[b].test_date[a] == '\0')
		{
			fputc('-', ofp1);
		}
		//**************************************************************
		for (a = 0; courses_reg[b].places[a] != '\0'; a++)
			fputc(courses_reg[b].places[a], ofp1);


		if (courses_reg[b].places[a] == '\0')
		{
			fputc('$', ofp1);
			fputc('\n', ofp1);
		}
		b++;


	}
	fclose(ofp1);
	//*********************End of updating courses***********************************************
}

void Schedule(char* id) {
	char student_dep;
	char semester;
	printf("\nPlease choose your department:a-software, b-electrical\n");
	getchar();
	printf("Your choice:");
	scanf("%c", &student_dep);
	while (!(student_dep >= 'a' && student_dep <= 'z')) {
		printf("\nPlease choose again your department:a-software, b-electrical\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &student_dep);
	}
	printf("Please enter your semester:");
	getchar();
	scanf("%c", &semester);
	while (!(semester >= 'a' && semester <= 'z')) {
		printf("Please choose again your semester:\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &semester);
	}

	courses courses_reg[20];
	char courses_to_show[100];
	char course_num[6];
	int i = 0, j = 0, k = 0, index = 0;
	students student1[25];
	char temp_arr[2500];

	FILE *ofp = NULL;//for opening students file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("students software-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students software-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp = fopen("students electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students electrical-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else {
		printf("No such department,going back to main menu\n");
		return;
	}

	i = 0, j = 0, k = 0, index = 0;
	while (!feof(ofp)) {//reading for the info on students
		temp_arr[index] = fgetc(ofp);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp);

	while (temp_arr[i] != '\0') { //move info to struct students
		while (temp_arr[i] != '-') {
			student1[k].num_id[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].num_id[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].last_name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].last_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].listed_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].listed_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].exames[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].exames[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].bill[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].bill[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].birthday[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].birthday[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].mail[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].mail[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].adress[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].adress[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			student1[k].telephone[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].telephone[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		k++;
	}
	//************************end of moving to struct*******************
	int num_students = k;
	int index_in_student_list = 0;
	for (int t = 0; t < num_students; t++) {
		if (strcmp(id, student1[t].num_id) == 0) {
			strcpy(courses_to_show, student1[t].listed_courses);
			index_in_student_list = t;
		}
	}
	//******************************************************************
	FILE *ofp1 = NULL;//for opening courses file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp1 = fopen("courses software-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses software-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else {//electrical
		if (semester == 'a') {
			ofp1 = fopen("courses electrical-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses electrical-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}

	}
	index = 0;
	while (!feof(ofp1)) {//reading for the courses file to get the name of courses
		temp_arr[index] = fgetc(ofp1);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp1);
	//stop reading from a file courses
	i = 0, j = 0;
	int g = 0, d = 0;
	while (temp_arr[i] != '\0') { //move info to struct courses
		while (temp_arr[i] != '-') {
			courses_reg[g].course_num[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].course_num[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].course_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].course_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].department[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].department[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].points[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].points[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].lecturer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].lecturer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].trainer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].trainer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].lecture_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].lecture_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].practice_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].practice_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].name_previous_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].name_previous_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].home_work[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].home_work[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].exames_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].exames_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].test_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].test_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			courses_reg[g].places[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].places[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		g++;
	}
	int array_index[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int num_courses = g;
	int f = 0, h = 0, s = 0, a = 0, flag = 0;
	while (courses_to_show[h] != '\0') {
		for (f = 0; f < num_courses; f++) {
			if (courses_to_show[h] == courses_reg[f].course_num[0] && courses_to_show[h + 1] == courses_reg[f].course_num[1] && courses_to_show[h + 2] == courses_reg[f].course_num[2] && courses_to_show[h + 3] == courses_reg[f].course_num[3] && courses_to_show[h + 4] == courses_reg[f].course_num[4]) {
				array_index[a] = f;
				a++;
				h += 6;
			}
		}
	}
	char sunday_lec[50] = { "No lectures today" };
	char monday_lec[50] = { "No lectures today" };
	char tuesday_lec[50] = { "No lectures today" };
	char wednesday_lec[50] = { "No lectures today" };
	char thursday_lec[50] = { "No lectures today" };
	char day[10];
	int q = 0, w = 0, l = 0;
	char temp[50];
	d = 0;
	while (array_index[d] != -1) {//getting info on lectures
		q = 0;
		for (int f = 8; courses_reg[array_index[d]].lecture_time[f] != ','; f++)
			day[q++] = courses_reg[array_index[d]].lecture_time[f];
		day[q] = '\0';
		if (strcmp(day, "sunday") == 0) {
			for (w = 9 + strlen(day); courses_reg[array_index[d]].lecture_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].lecture_time[w];
			temp[l] = '\0';
			strcpy(sunday_lec, courses_reg[array_index[d]].course_name);
			strcat(sunday_lec, " -Lecture:");
			strcat(sunday_lec, temp);
			//strcat(sunday, courses_reg[array_index[d]].practice_time);
		}
		if (strcmp(day, "monday") == 0) {
			l = 0;
			for (w = 9 + strlen(day); courses_reg[array_index[d]].lecture_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].lecture_time[w];
			temp[l] = '\0';
			strcpy(monday_lec, courses_reg[array_index[d]].course_name);
			strcat(monday_lec, " -Lecture:");
			strcat(monday_lec, temp);
			//strcat(monday, courses_reg[array_index[d]].practice_time);
		}
		if (strcmp(day, "tuesday") == 0) {
			l = 0;
			for (w = 9 + strlen(day); courses_reg[array_index[d]].lecture_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].lecture_time[w];
			temp[l] = '\0';
			strcpy(tuesday_lec, courses_reg[array_index[d]].course_name);
			strcat(tuesday_lec, " -Lecture:");
			strcat(tuesday_lec, temp);
			//strcpy(tuesday, temp);
			//strcat(tuesday, courses_reg[array_index[d]].practice_time);
		}
		if (strcmp(day, "wednesday") == 0) {
			l = 0;
			for (w = 9 + strlen(day); courses_reg[array_index[d]].lecture_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].lecture_time[w];
			temp[l] = '\0';
			strcpy(wednesday_lec, courses_reg[array_index[d]].course_name);
			strcat(wednesday_lec, " -Lecture:");
			strcat(wednesday_lec, temp);
			//strcpy(wednesday, temp);
			//strcat(wednesday, courses_reg[array_index[d]].practice_time);
		}
		if (strcmp(day, "thursday") == 0) {
			l = 0;
			for (w = 9 + strlen(day); courses_reg[array_index[d]].lecture_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].lecture_time[w];
			temp[l] = '\0';
			strcpy(thursday_lec, courses_reg[array_index[d]].course_name);
			strcat(thursday_lec, " -Lecture:");
			strcat(thursday_lec, temp);
			//strcpy(thursday,temp);
			//strcat(thursday, courses_reg[array_index[d]].practice_time);
		}
		d++;
	}
	char sunday_pr[50] = { "No practices today" };
	char monday_pr[50] = { "No practices today" };
	char tuesday_pr[50] = { "No practices today" };
	char wednesday_pr[50] = { "No practices today" };
	char thursday_pr[50] = { "No practices today" };
	//char day[10];
	q = 0, w = 0, l = 0;
	strcpy(temp, " ");
	d = 0;
	while (array_index[d] != -1) {//getting info on practices
		q = 0;
		for (int f = 9; courses_reg[array_index[d]].practice_time[f] != ','; f++)
			day[q++] = courses_reg[array_index[d]].practice_time[f];
		day[q] = '\0';
		if (strcmp(day, "sunday") == 0) {
			for (w = 10 + strlen(day); courses_reg[array_index[d]].practice_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].practice_time[w];
			temp[l] = '\0';
			strcpy(sunday_pr, "Practice:");
			strcat(sunday_pr, temp);
		}
		if (strcmp(day, "monday") == 0) {
			l = 0;
			for (w = 10 + strlen(day); courses_reg[array_index[d]].practice_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].practice_time[w];
			temp[l] = '\0';
			strcpy(monday_pr, "Practice:");
			strcat(monday_pr, temp);
		}
		if (strcmp(day, "tuesday") == 0) {
			l = 0;
			for (w = 10 + strlen(day); courses_reg[array_index[d]].practice_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].practice_time[w];
			temp[l] = '\0';
			strcpy(tuesday_pr, "Practice:");
			strcat(tuesday_pr, temp);
		}
		if (strcmp(day, "wednesday") == 0) {
			l = 0;
			for (w = 10 + strlen(day); courses_reg[array_index[d]].practice_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].practice_time[w];
			temp[l] = '\0';
			strcpy(wednesday_pr, "Practice:");
			strcat(wednesday_pr, temp);
		}
		if (strcmp(day, "thursday") == 0) {
			l = 0;
			for (w = 10 + strlen(day); courses_reg[array_index[d]].practice_time[w] != '\0'; w++)
				temp[l++] = courses_reg[array_index[d]].practice_time[w];
			temp[l] = '\0';
			strcpy(thursday_pr, "Practice:");
			strcat(thursday_pr, temp);
		}
		d++;
	}
	//*****************printing the schedule********
	printf("Your Schedule:\n");
	printf("----------------------------------------------------|\n");
	printf("Sunday   | %s\n", sunday_lec);
	printf("         | %s\n", sunday_pr);
	printf("----------------------------------------------------|\n");
	printf("Monday   | %s\n", monday_lec);
	printf("         | %s\n", monday_pr);
	printf("----------------------------------------------------|\n");
	printf("Tuesday  | %s\n", tuesday_lec);
	printf("         | %s\n", tuesday_pr);
	printf("----------------------------------------------------|\n");
	printf("Wednesday| %s\n", wednesday_lec);
	printf("         | %s\n", wednesday_pr);
	printf("----------------------------------------------------|\n");
	printf("Thursday | %s\n", thursday_lec);
	printf("         | %s\n", thursday_pr);
	printf("----------------------------------------------------|\n");
	printf("\n");
	//***************************end of printing*****************************
	printf("Your courses are:\n");
	for (d = 0; d < SIZE; d++) {
		if (array_index[d] != -1) {
			printf("%s ", courses_reg[array_index[d]].course_num);
			printf("%s\n", courses_reg[array_index[d]].course_name);

		}
	}
	printf("Information about the course:\n");
	printf("If you want to see the details about the course choose: 1, else 0\n");
	int option;
	scanf("%d", &option);
	while (option == 1) {
		printf("Enter the course number:\n");
		printf("Course number:");
		scanf("%s", &course_num);
		printf("\n");
		printf("Info on course:\n");
		//int course_index = 0;
		for (int i = 0; i < num_courses; i++) {
			if (strcmp(course_num, courses_reg[i].course_num) == 0) {
				printf("----------------------------------------------------|\n");
				printf("Course number: %s\n", courses_reg[i].course_num);
				printf("----------------------------------------------------|\n");
				printf("Course name: %s\n", courses_reg[i].course_name);
				printf("----------------------------------------------------|\n");
				printf("Lecturer name: %s\n", courses_reg[i].lecturer_name);
				printf("----------------------------------------------------|\n");
				printf("Lecture time: %s\n", courses_reg[i].lecture_time);
				printf("----------------------------------------------------|\n");
				printf("Trainer name: %s\n", courses_reg[i].trainer_name);
				printf("----------------------------------------------------|\n");
				printf("Practice time: %s\n", courses_reg[i].practice_time);
				printf("----------------------------------------------------|\n");
				printf("Name of previous courses: %s\n", courses_reg[i].name_previous_courses);
				printf("----------------------------------------------------|\n");
				printf("Homework in course: %s\n", courses_reg[i].home_work);
				printf("----------------------------------------------------|\n");
				printf("Exames date: %s\n", courses_reg[i].exames_date);
				printf("----------------------------------------------------|\n");
				printf("Test date: %s\n", courses_reg[i].test_date);
				printf("----------------------------------------------------|\n");
			}
		}
		printf("\n");
		printf("Choose again:1 for another course, 0 for exit from course details\n");
		scanf("%d", &option);
	}

}

void AccountPage(char* id) {
	char student_dep;
	char semester;
	printf("\nPlease choose your department:a-software, b-electrical\n");
	getchar();
	printf("Your choice:");
	scanf("%c", &student_dep);
	while (!(student_dep >= 'a' && student_dep <= 'z')) {
		printf("\nPlease choose again your department:a-software, b-electrical\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &student_dep);
	}
	printf("Please enter your semester:");
	getchar();
	scanf("%c", &semester);
	while (!(semester >= 'a' && semester <= 'z')) {
		printf("Please choose again your semester:\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &semester);
	}

	char courses_to_show[100];
	int num_courses = 0;
	int i = 0, j = 0, k = 0, index = 0;
	students student1[25];
	char temp_arr[2500];
	FILE *ofp = NULL;//for opening students file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("students software-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students software-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp = fopen("students electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students electrical-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else {
		printf("No such department,going back to main menu\n");
		return;
	}

	i = 0, j = 0, k = 0, index = 0;
	while (!feof(ofp)) {//reading for the info on students
		temp_arr[index] = fgetc(ofp);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp);

	while (temp_arr[i] != '\0') { //move info to struct students
		while (temp_arr[i] != '-') {
			student1[k].num_id[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].num_id[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].last_name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].last_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].listed_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].listed_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].exames[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].exames[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].bill[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].bill[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].birthday[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].birthday[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].mail[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].mail[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].adress[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].adress[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			student1[k].telephone[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].telephone[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		k++;
	}
	//************************end of moving to struct*******************
	int num_students = k;
	int index_in_student_list = 0;
	for (int t = 0; t < num_students; t++) {
		if (strcmp(id, student1[t].num_id) == 0) {
			strcpy(courses_to_show, student1[t].listed_courses);
			index_in_student_list = t;
		}
	}
	//******************************************************************
	//************************reading from bills files******************
	ofp = NULL;
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("bills-software a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp = fopen("bills-software b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	index = 0;
	while (!feof(ofp)) {//reading for the info on bills
		temp_arr[index] = fgetc(ofp);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp);
	bill students_bills[25];
	i = 0, j = 0, k = 0;
	while (temp_arr[i] != '\0') { //move info to struct bills
		while (temp_arr[i] != '-') {
			students_bills[k].student_id[j] = temp_arr[i];
			j++;
			i++;
		}
		students_bills[k].student_id[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			students_bills[k].total_payment[j] = temp_arr[i];
			j++;
			i++;
		}
		students_bills[k].total_payment[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			students_bills[k].payed[j] = temp_arr[i];
			j++;
			i++;
		}
		students_bills[k].payed[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			students_bills[k].left_to_pay[j] = temp_arr[i];
			j++;
			i++;
		}
		students_bills[k].left_to_pay[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		k++;
	}
	//*************************printing**********************************
	printf("Account page:\n");
	printf("----------------------------------------------------|  \n");
	printf("Tuition fees|  %s\n", students_bills[index_in_student_list].total_payment);
	printf("----------------------------------------------------|  \n");
	printf("Payed       |  %s\n", students_bills[index_in_student_list].payed);
	printf("----------------------------------------------------|  \n");
	printf("Left to pay |  %s\n", students_bills[index_in_student_list].left_to_pay);
	printf("----------------------------------------------------|  \n");
	//******************************************************************
	//*********************update student*******************************
	strcpy(student1[index_in_student_list].bill, students_bills[index_in_student_list].left_to_pay);
	//*********************update the file of student*******************
	FILE* ofp2 = NULL;
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp2 = fopen("students software-a.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp2 = fopen("students software-b.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else {
		if (semester == 'a') {
			ofp2 = fopen("students electrical-a.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp2 = fopen("students electrical-b.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}

	int a = 0, b = 0;
	while (b < num_students)
	{
		for (a = 0; student1[b].num_id[a] != '\0'; a++)
			fputc(student1[b].num_id[a], ofp2);
		if (student1[b].num_id[a] == '\0')
		{
			fputc('-', ofp2);
		}
		//**************************************************************
		for (a = 0; student1[b].name[a] != '\0'; a++)
			fputc(student1[b].name[a], ofp2);
		if (student1[b].name[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].last_name[a] != '\0'; a++)
			fputc(student1[b].last_name[a], ofp2);
		if (student1[b].last_name[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].listed_courses[a] != '\0'; a++)
			fputc(student1[b].listed_courses[a], ofp2);
		if (student1[b].listed_courses[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].exames[a] != '\0'; a++)
			fputc(student1[b].exames[a], ofp2);
		if (student1[b].exames[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].bill[a] != '\0'; a++)
			fputc(student1[b].bill[a], ofp2);
		if (student1[b].bill[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].birthday[a] != '\0'; a++)
			fputc(student1[b].birthday[a], ofp2);
		if (student1[b].birthday[a] == '\0')
		{
			fputc('-', ofp2);
		}
		//**************************************************************
		for (a = 0; student1[b].mail[a] != '\0'; a++)
			fputc(student1[b].mail[a], ofp2);
		if (student1[b].mail[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].adress[a] != '\0'; a++)
			fputc(student1[b].adress[a], ofp2);
		if (student1[b].adress[a] == '\0')
		{
			fputc('-', ofp2);
		}

		//**************************************************************
		for (a = 0; student1[b].telephone[a] != '\0'; a++)
			fputc(student1[b].telephone[a], ofp2);
		if (student1[b].telephone[a] == '\0')
		{
			fputc('$', ofp2);
			fputc('\n', ofp2);
		}
		b++;
	}
	fclose(ofp2);
}

void StudentGrades(char* id) {
	char student_dep;
	char semester;
	printf("\nPlease choose your department:a-software, b-electrical\n");
	getchar();
	printf("Your choice:");
	scanf("%c", &student_dep);
	while (!(student_dep >= 'a' && student_dep <= 'z')) {
		printf("\nPlease choose again your department:a-software, b-electrical\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &student_dep);
	}
	printf("Please enter your semester:");
	getchar();
	scanf("%c", &semester);
	while (!(semester >= 'a' && semester <= 'z')) {
		printf("Please choose again your semester:\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &semester);
	}
	courses courses_reg[20];
	char courses_to_show[100];
	char course_num[6];
	int i = 0, j = 0, k = 0, index = 0;
	students student1[25];
	char temp_arr[2500];
	FILE *ofp = NULL;//for opening students file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("students software-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students software-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp = fopen("students electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students electrical-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else {
		printf("No such department,going back to main menu\n");
		return;
	}

	i = 0, j = 0, k = 0, index = 0;
	while (!feof(ofp)) {//reading for the info on students
		temp_arr[index] = fgetc(ofp);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp);

	while (temp_arr[i] != '\0') { //move info to struct students
		while (temp_arr[i] != '-') {
			student1[k].num_id[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].num_id[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].last_name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].last_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].listed_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].listed_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].exames[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].exames[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].bill[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].bill[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].birthday[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].birthday[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].mail[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].mail[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].adress[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].adress[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			student1[k].telephone[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].telephone[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		k++;
	}
	//************************end of moving to struct*******************
	int num_students = k;
	int index_in_student_list = 0;
	for (int t = 0; t < num_students; t++) {
		if (strcmp(id, student1[t].num_id) == 0) {
			strcpy(courses_to_show, student1[t].listed_courses);
			index_in_student_list = t;
		}
	}

	FILE *ofp1 = NULL;//for opening courses file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp1 = fopen("courses software-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses software-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else {//electrical
		if (semester == 'a') {
			ofp1 = fopen("courses electrical-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses electrical-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}

	}
	index = 0;
	while (!feof(ofp1)) {//reading for the courses file to get the name of courses
		temp_arr[index] = fgetc(ofp1);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp1);
	//stop reading from a file courses
	i = 0, j = 0;
	int g = 0, d = 0;
	while (temp_arr[i] != '\0') { //move info to struct courses
		while (temp_arr[i] != '-') {
			courses_reg[g].course_num[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].course_num[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].course_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].course_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].department[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].department[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].points[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].points[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].lecturer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].lecturer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].trainer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].trainer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].lecture_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].lecture_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].practice_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].practice_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].name_previous_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].name_previous_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].home_work[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].home_work[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].exames_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].exames_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].test_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].test_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			courses_reg[g].places[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].places[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		g++;
	}
	//char courses_in_semester[100];
	int array_index[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };//array of indexs-courses
	int num_courses = g;
	int f = 0, h = 0, s = 0, a = 0, flag = 0;
	while (courses_to_show[h] != '\0') {
		for (f = 0; f < num_courses; f++) {
			if (courses_to_show[h] == courses_reg[f].course_num[0] && courses_to_show[h + 1] == courses_reg[f].course_num[1] && courses_to_show[h + 2] == courses_reg[f].course_num[2] && courses_to_show[h + 3] == courses_reg[f].course_num[3] && courses_to_show[h + 4] == courses_reg[f].course_num[4]) {
				array_index[a] = f;
				a++;
				h += 6;
			}
		}
	}
	printf("Grades\n");
	printf("Your courses for this semester:\n");
	for (d = 0; d < SIZE; d++) {
		if (array_index[d] != -1) {
			printf("----------------------------------------------------|  \n");
			printf("Course number: %s, ", courses_reg[array_index[d]].course_num);
			printf("Course name: %s\n", courses_reg[array_index[d]].course_name);

		}
	}

	grades course_grades[105];
	ofp1 = NULL;
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp1 = fopen("grades software-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("grades software-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else {//electrical
		if (semester == 'a') {
			ofp1 = fopen("grades electrical-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("grades electrical-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}

	}
	//**************************reading from grades file******************
	index = 0;
	while (!feof(ofp1)) {//reading for the grades file
		temp_arr[index] = fgetc(ofp1);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp1);
	//stop reading from a file
	i = 0, j = 0, k = 0;
	while (temp_arr[i] != '\0') { //move info to struct grades
		while (temp_arr[i] != '-') {
			course_grades[k].student_id[j] = temp_arr[i];
			j++;
			i++;
		}
		course_grades[k].student_id[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			course_grades[k].course_id[j] = temp_arr[i];
			j++;
			i++;
		}
		course_grades[k].course_id[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			course_grades[k].first_exam[j] = temp_arr[i];
			j++;
			i++;
		}
		course_grades[k].first_exam[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			course_grades[k].second_exam[j] = temp_arr[i];
			j++;
			i++;
		}
		course_grades[k].second_exam[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			course_grades[k].special_exam[j] = temp_arr[i];
			j++;
			i++;
		}
		course_grades[k].special_exam[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		k++;
	}
	//*****************************showing the grades************
	int num_of_rows = k;//num of rows(grades) in the file
	int option;
	printf("For watching the course grade please enter 1,else 0\n");
	scanf("%d", &option);
	while (option != 0) {
		printf("Please enter the course number for watching the garding:\n");
		printf("Course number:");
		scanf("%s", &course_num);
		printf("\n");
		printf("-----------------------------------|  \n");

		for (int i = 0; i < num_of_rows; i++) {
			if (strcmp(id, course_grades[i].student_id) == 0) {
				if (strcmp(course_num, course_grades[i].course_id) == 0) {
					printf("First exam:%s\n", course_grades[i].first_exam);
					if ((strcmp(course_grades[i].first_exam, "56") < 0) && !(strcmp(course_grades[i].first_exam, "0") == 0))
						printf("You must access an additional exam to increase the grade\n");
					else
						printf("You can register for an additional date, please send a request to the student department coordinator of your department by email\n");
					printf("-----------------------------------|  \n");
					printf("Second exam:%s\n", course_grades[i].second_exam);
					if ((strcmp(course_grades[i].second_exam, "56") < 0) && !(strcmp(course_grades[i].second_exam, "0") == 0))
						printf("You must access an additional exam to increase the grade\n");
					else
						printf("You can register for an additional date, please send a request to the student department coordinator of your department by email\n");
					printf("-----------------------------------|  \n");
					printf("Special exam:%s\n", course_grades[i].special_exam);
					printf("-----------------------------------|  \n");
					if ((strcmp(course_grades[i].first_exam, course_grades[i].second_exam) > 0) && (strcmp(course_grades[i].special_exam, "0") == 0))
						printf("Final grade:%s\n", course_grades[i].first_exam);
					else if ((strcmp(course_grades[i].first_exam, course_grades[i].second_exam) < 0) && (strcmp(course_grades[i].special_exam, "0") == 0))
						printf("Final grade:%s\n", course_grades[i].second_exam);
					else
						printf("Final grade:%s\n", course_grades[i].special_exam);
					printf("-----------------------------------|  \n");

				}
			}
		}
		printf("For watching the course grade please enter 1,else 0\n");
		scanf("%d", &option);
	}
	//*******************Calculating the average grade***********************************
	int grade = 0, num_grades_for_student = 0, sum_grades = 0;
	for (int i = 0; i < num_of_rows; i++) {
		if (strcmp(id, course_grades[i].student_id) == 0) {
			if ((strcmp(course_grades[i].first_exam, course_grades[i].second_exam) > 0) && (strcmp(course_grades[i].special_exam, "0") == 0))
				grade = atoi(course_grades[i].first_exam);
			else if ((strcmp(course_grades[i].first_exam, course_grades[i].second_exam) < 0) && (strcmp(course_grades[i].special_exam, "0") == 0))
				grade = atoi(course_grades[i].second_exam);
			else
				grade = atoi(course_grades[i].special_exam);
			sum_grades += grade;
			num_grades_for_student++;
		}
	}
	float average = 0;
	average = sum_grades / num_grades_for_student;
	printf("\n");
	printf("----------------------------------------------------|  \n");
	printf("Average grade:%.2f\n", average);
	printf("----------------------------------------------------|  \n");
	printf("Average grade of the year:%.2f\n", average);
	printf("----------------------------------------------------|  \n");
	//*************************how much points********************************************
	int point = 0, sum_points = 0;
	while (array_index[s] >= 0) {
		point = atoi(courses_reg[array_index[s]].points);
		sum_points += point;
		s++;
	}
	printf("Total points:%d\n", sum_points);
	printf("----------------------------------------------------|  \n");
	//*************************************************************************
}

void ExamsSchedule(char* id) {
	char student_dep;
	char semester;
	printf("\nPlease choose your department:a-software, b-electrical\n");
	getchar();
	printf("Your choice:");
	scanf("%c", &student_dep);
	while (!(student_dep >= 'a' && student_dep <= 'z')) {
		printf("\nPlease choose again your department:a-software, b-electrical\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &student_dep);
	}
	printf("Please enter your semester:");
	getchar();
	scanf("%c", &semester);
	while (!(semester >= 'a' && semester <= 'z')) {
		printf("Please choose again your semester:\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &semester);
	}
	courses courses_reg[20];
	char courses_to_show[100];
	int i = 0, j = 0, k = 0, index = 0;
	students student1[25];
	char temp_arr[2500];
	FILE *ofp = NULL;//for opening students file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("students software-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students software-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp = fopen("students electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("students electrical-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else {
		printf("No such department,going back to main menu\n");
		return;
	}

	i = 0, j = 0, k = 0, index = 0;
	while (!feof(ofp)) {//reading for the info on students
		temp_arr[index] = fgetc(ofp);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp);

	while (temp_arr[i] != '\0') { //move info to struct students
		while (temp_arr[i] != '-') {
			student1[k].num_id[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].num_id[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].last_name[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].last_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].listed_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].listed_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].exames[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].exames[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].bill[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].bill[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].birthday[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].birthday[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].mail[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].mail[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			student1[k].adress[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].adress[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			student1[k].telephone[j] = temp_arr[i];
			j++;
			i++;
		}
		student1[k].telephone[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		k++;
	}
	//************************end of moving to struct*******************
	int num_students = k;
	int index_in_student_list = 0;
	for (int t = 0; t < num_students; t++) {
		if (strcmp(id, student1[t].num_id) == 0) {
			strcpy(courses_to_show, student1[t].listed_courses);
			index_in_student_list = t;
		}
	}

	FILE *ofp1 = NULL;//for opening courses file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp1 = fopen("courses software-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses software-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else {//electrical
		if (semester == 'a') {
			ofp1 = fopen("courses electrical-a.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			ofp1 = fopen("courses electrical-b.txt", "r");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}

	}
	index = 0;
	while (!feof(ofp1)) {//reading for the courses file to get the name of courses
		temp_arr[index] = fgetc(ofp1);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp1);
	//stop reading from a file courses
	i = 0, j = 0;
	int g = 0, d = 0;
	while (temp_arr[i] != '\0') { //move info to struct courses
		while (temp_arr[i] != '-') {
			courses_reg[g].course_num[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].course_num[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].course_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].course_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].department[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].department[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].points[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].points[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].lecturer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].lecturer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].trainer_name[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].trainer_name[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].lecture_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].lecture_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].practice_time[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].practice_time[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].name_previous_courses[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].name_previous_courses[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].home_work[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].home_work[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].exames_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].exames_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '-') {
			courses_reg[g].test_date[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].test_date[j] = '\0';
		i++;
		j = 0;
		while (temp_arr[i] != '$') {
			courses_reg[g].places[j] = temp_arr[i];
			j++;
			i++;
		}
		courses_reg[g].places[j] = '\0';
		i++;
		if (temp_arr[i] != '\0')
			i++;
		j = 0;
		g++;
	}
	//char courses_in_semester[100];
	int array_index[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };//array of indexs-courses
	int num_courses = g;
	int f = 0, h = 0, s = 0, a = 0, flag = 0;
	while (courses_to_show[h] != '\0') {
		for (f = 0; f < num_courses; f++) {
			if (courses_to_show[h] == courses_reg[f].course_num[0] && courses_to_show[h + 1] == courses_reg[f].course_num[1] && courses_to_show[h + 2] == courses_reg[f].course_num[2] && courses_to_show[h + 3] == courses_reg[f].course_num[3] && courses_to_show[h + 4] == courses_reg[f].course_num[4]) {
				array_index[a] = f;
				a++;
				h += 6;
			}
		}
	}
	printf("Your exams and tasks for this semester:\n");
	printf("----------------------------------------------------|  \n");
	printf("Semester:%c\n", semester);
	char temp_date1[9], temp_date2[9];
	for (d = 0; d < SIZE; d++) {
		if (array_index[d] >= 0) {
			printf("----------------------------------------------------|  \n");
			printf("Course name:%s\n", courses_reg[array_index[d]].course_name);
			printf("Lecturer name:%s\n", courses_reg[array_index[d]].lecturer_name);
			printf("Homework:%s\n", courses_reg[array_index[d]].home_work);
			printf("Homework date:%s\n", courses_reg[array_index[d]].test_date);
			s = 0, h = 0, j = 0;
			for (int i = 0; i < strlen(courses_reg[array_index[d]].exames_date); i++) {
				if (s < INDEX) {
					temp_date1[s] = courses_reg[array_index[d]].exames_date[i];
					s++;
				}
				else if (courses_reg[array_index[d]].exames_date[i] == ',')
					j = i;
				else if (i > j) {
					temp_date2[h] = courses_reg[array_index[d]].exames_date[i];
					h++;
				}
			}
			temp_date1[s] = '\0';
			temp_date2[h] = '\0';
			printf("First exam date:%s\n", temp_date1);
			printf("Second exam date:%s\n", temp_date2);
			printf("----------------------------------------------------|  \n");
		}
	}
}

void StudentMessages() {
	char student_dep;
	char semester;
	printf("\nPlease choose your department:a-software, b-electrical\n");
	getchar();
	printf("Your choice:");
	scanf("%c", &student_dep);
	while (!(student_dep >= 'a' && student_dep <= 'z')) {
		printf("\nPlease choose again your department:a-software, b-electrical\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &student_dep);
	}
	printf("Please enter your semester:");
	getchar();
	scanf("%c", &semester);
	while (!(semester >= 'a' && semester <= 'z')) {
		printf("Please choose again your semester:\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &semester);
	}
	char temp_arr[300];
	int index = 0, i = 0, k = 0, j = 0;
	FILE *ofp = NULL;//for opening message file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("messages for students-software a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("messages for students-software b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp = fopen("messages for students-electrical a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else if (semester == 'b') {
			ofp = fopen("messages for students-electrical b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return;
		}
	}
	else {
		printf("No such department,going back to main menu\n");
		return;
	}
	while (!feof(ofp)) {
		temp_arr[index] = fgetc(ofp);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp);
	printf("---------------------------------------------------------------------------|  \n");
	printf("Date     | Body of the message                                             |\n");
	printf("---------------------------------------------------------------------------|  \n");
	while (temp_arr[i] != '\0') {//printing the file
		while (temp_arr[i] != '$') {
			printf("%c", temp_arr[i]);
			i++;
		}
		i++;
	}
	printf("\n");
	printf("---------------------------------------------------------------------------|  \n");

}

void StudentReports(char* id) {
	int option;
	printf("Please enter an option for the report:\n");
	scanf("%d", &option);
	char student_dep;
	char semester;
	printf("\nPlease choose your department:a-software, b-electrical\n");
	getchar();
	printf("Your choice:");
	scanf("%c", &student_dep);
	while (!(student_dep >= 'a' && student_dep <= 'z')) {
		printf("\nPlease choose again your department:a-software, b-electrical\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &student_dep);
	}
	printf("Please enter your semester:");
	getchar();
	scanf("%c", &semester);
	while (!(semester >= 'a' && semester <= 'z')) {
		printf("Please choose again your semester:\n");
		getchar();
		printf("Your choice:");
		scanf("%c", &semester);
	}
	if (option == 1) {
		courses courses_reg[20];
		char courses_to_show[100];
		//int num_courses = 0;
		//char course_num[6];
		int i = 0, j = 0, k = 0, index = 0;
		students student1[25];
		char temp_arr[2500];
		FILE *ofp = NULL;//for opening students file
		if (student_dep == 'a') { //************check the other departments********
			if (semester == 'a') {
				ofp = fopen("students software-a.txt", "r");
				if (ofp == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}
			else {
				ofp = fopen("students software-b.txt", "r");
				if (ofp == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}
		}
		else {//electrical
			if (semester == 'a') {
				ofp = fopen("students electrical-a.txt", "r");
				if (ofp == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}
			else {
				ofp = fopen("students electrical-b.txt", "r");
				if (ofp == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}


		}
		i = 0, j = 0, k = 0, index = 0;
		while (!feof(ofp)) {//reading for the info on students
			temp_arr[index] = fgetc(ofp);
			index++;
		}
		temp_arr[index - 1] = '\0';
		fclose(ofp);

		while (temp_arr[i] != '\0') { //move info to struct students
			while (temp_arr[i] != '-') {
				student1[k].num_id[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].num_id[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				student1[k].name[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].name[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				student1[k].last_name[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].last_name[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				student1[k].listed_courses[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].listed_courses[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				student1[k].exames[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].exames[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				student1[k].bill[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].bill[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				student1[k].birthday[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].birthday[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				student1[k].mail[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].mail[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				student1[k].adress[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].adress[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '$') {
				student1[k].telephone[j] = temp_arr[i];
				j++;
				i++;
			}
			student1[k].telephone[j] = '\0';
			i++;
			if (temp_arr[i] != '\0')
				i++;
			j = 0;
			k++;
		}
		//************************end of moving to struct*******************
		int num_students = k;
		int index_in_student_list = 0;
		for (int t = 0; t < num_students; t++) {
			if (strcmp(id, student1[t].num_id) == 0) {
				strcpy(courses_to_show, student1[t].listed_courses);
				index_in_student_list = t;
			}
		}

		FILE *ofp1 = NULL;//for opening courses file
		if (student_dep == 'a') { //************check the other departments********
			if (semester == 'a') {
				ofp1 = fopen("courses software-a.txt", "r");
				if (ofp1 == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}
			else {
				ofp1 = fopen("courses software-b.txt", "r");
				if (ofp1 == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}
		}
		else {//electrical
			if (semester == 'a') {
				ofp1 = fopen("courses electrical-a.txt", "r");
				if (ofp1 == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}
			else {
				ofp1 = fopen("courses electrical-b.txt", "r");
				if (ofp1 == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}

		}
		index = 0;
		while (!feof(ofp1)) {//reading for the courses file to get the name of courses
			temp_arr[index] = fgetc(ofp1);
			index++;
		}
		temp_arr[index - 1] = '\0';
		fclose(ofp1);
		//stop reading from a file courses
		i = 0, j = 0;
		int g = 0, d = 0;
		while (temp_arr[i] != '\0') { //move info to struct courses
			while (temp_arr[i] != '-') {
				courses_reg[g].course_num[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].course_num[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].course_name[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].course_name[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].department[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].department[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].points[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].points[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].lecturer_name[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].lecturer_name[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].trainer_name[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].trainer_name[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].lecture_time[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].lecture_time[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].practice_time[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].practice_time[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].name_previous_courses[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].name_previous_courses[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].home_work[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].home_work[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].exames_date[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].exames_date[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				courses_reg[g].test_date[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].test_date[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '$') {
				courses_reg[g].places[j] = temp_arr[i];
				j++;
				i++;
			}
			courses_reg[g].places[j] = '\0';
			i++;
			if (temp_arr[i] != '\0')
				i++;
			j = 0;
			g++;
		}
		//char courses_in_semester[100];
		int array_index[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };//array of indexs-courses
		int num_courses = g;
		int f = 0, h = 0, s = 0, a = 0, flag = 0;
		while (courses_to_show[h] != '\0') {
			for (f = 0; f < num_courses; f++) {
				if (courses_to_show[h] == courses_reg[f].course_num[0] && courses_to_show[h + 1] == courses_reg[f].course_num[1] && courses_to_show[h + 2] == courses_reg[f].course_num[2] && courses_to_show[h + 3] == courses_reg[f].course_num[3] && courses_to_show[h + 4] == courses_reg[f].course_num[4]) {
					array_index[a] = f;
					a++;
					h += 6;
				}
			}
		}
		printf("Grades\n");
		printf("Your courses for this semester:\n");
		for (d = 0; d < SIZE; d++) {
			if (array_index[d] != -1) {
				printf("----------------------------------------------------|  \n");
				printf("%s ", courses_reg[array_index[d]].course_num);
				printf("%s\n", courses_reg[array_index[d]].course_name);

			}
		}
		printf("----------------------------------------------------|  \n");
		grades course_grades[105];
		ofp1 = NULL;
		if (student_dep == 'a') { //************check the other departments********
			if (semester == 'a') {
				ofp1 = fopen("grades software-a.txt", "r");
				if (ofp1 == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}
			else {
				ofp1 = fopen("grades software-b.txt", "r");
				if (ofp1 == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}
		}
		else {//electrical
			if (semester == 'a') {
				ofp1 = fopen("grades electrical-a.txt", "r");
				if (ofp1 == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}
			else {
				ofp1 = fopen("grades electrical-b.txt", "r");
				if (ofp1 == NULL) {
					printf("Can't open the file\n");
					exit(1);
				}
			}

		}
		//**************************reading from grades file******************
		index = 0;
		while (!feof(ofp1)) {//reading for the grades file
			temp_arr[index] = fgetc(ofp1);
			index++;
		}
		temp_arr[index - 1] = '\0';
		fclose(ofp1);
		//stop reading from a file
		i = 0, j = 0, k = 0;
		while (temp_arr[i] != '\0') { //move info to struct grades
			while (temp_arr[i] != '-') {
				course_grades[k].student_id[j] = temp_arr[i];
				j++;
				i++;
			}
			course_grades[k].student_id[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				course_grades[k].course_id[j] = temp_arr[i];
				j++;
				i++;
			}
			course_grades[k].course_id[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				course_grades[k].first_exam[j] = temp_arr[i];
				j++;
				i++;
			}
			course_grades[k].first_exam[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '-') {
				course_grades[k].second_exam[j] = temp_arr[i];
				j++;
				i++;
			}
			course_grades[k].second_exam[j] = '\0';
			i++;
			j = 0;
			while (temp_arr[i] != '$') {
				course_grades[k].special_exam[j] = temp_arr[i];
				j++;
				i++;
			}
			course_grades[k].special_exam[j] = '\0';
			i++;
			if (temp_arr[i] != '\0')
				i++;
			j = 0;
			k++;
		}
		//*****************************showing the grades************
		int num_of_rows = k;//num of rows(grades) in the file
		printf("Failed exams:\n");
		for (int i = 0; i < num_of_rows; i++) {
			if (strcmp(id, course_grades[i].student_id) == 0) {
				for (int q = 0; q < SIZE && array_index[q] != -1; q++) {
					if (strcmp(courses_reg[array_index[q]].course_num, course_grades[i].course_id) == 0) {
						if ((strcmp(course_grades[i].first_exam, "56") < 0) && !(strcmp(course_grades[i].first_exam, "0") == 0)) {
							printf("Course number:%s, ", course_grades[i].course_id);
							printf("Grade:%s\n", course_grades[i].first_exam);
						}
						if ((strcmp(course_grades[i].second_exam, "56") < 0) && !(strcmp(course_grades[i].second_exam, "0") == 0)) {
							printf("Course number:%s, ", course_grades[i].course_id);
							printf("Grade:%s\n", course_grades[i].second_exam);
						}
						if ((strcmp(course_grades[i].special_exam, "56") < 0) && !(strcmp(course_grades[i].special_exam, "0") == 0)) {
							printf("Course number:%s, ", course_grades[i].course_id);
							printf("Grade:%s\n", course_grades[i].special_exam);
						}
					}
				}
			}
		}
		printf("\n");
	}
}

void StudentHelp() {
	FILE* ofp = NULL;
	ofp = fopen("manual.txt", "r");
	if (ofp == NULL) {
		printf("Can't open the file\n");
		exit(1);
	}
	char temp_arr[1100];
	int index = 0, i = 0;
	while (!feof(ofp)) {
		temp_arr[index] = fgetc(ofp);
		index++;
	}
	temp_arr[index - 1] = '\0';
	fclose(ofp);
	while (temp_arr[i] != '\0') {//printing the file
		while (temp_arr[i] != '$') {
			printf("%c", temp_arr[i]);
			i++;
		}
		i++;
	}
	printf("\n");
	printf("\n");
}