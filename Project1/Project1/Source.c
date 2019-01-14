#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <math.h>

#define MAX_USER_LENGTH 10
#define user_amount 85
#define correction 3  // First (-2) is for going for correct amount of users( as of now 83), the second (-2) is for loop correction, therefore -4.
#define SIZE 20

//-------------------------------------------------
struct username
{
	char user[10];
	int password;
	int type;
};
typedef struct username username;
//-------------------------------------------------
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
//-------------------------------------------------
struct Grade {
	char student_id[10];
	char course_id[6];
	char first_exam[4];
	char second_exam[4];
	char special_exam[4];
};
typedef struct Grade grades;
//-------------------------------------------------
struct adEm
{
	char ID_administration_employee[10];
	char first_name_ad[35];
	char last_name_ad[35];
	char Date_of_birth_ad[35];
	char Address_ad[35];
	int phone_ad[35];
	char Email_ad[35];
	char role_ad[35];
	char reception_hours_ad[35];
};
typedef struct adEm adEm;

struct spacialExam {
	char num_id[10];

	char course_num[6];
	char data_exam[10];
};
typedef struct spacialExam spacialExam;

void tests();
int login();
int backup();
void create_backup(FILE*, FILE*);
int data_manager_menu();
int password_restore();
int set_permissions();
int choose_block_unblock();
int block_student();
int revoke_block_student();
int reports();

int StudentMessages();
int CoursesToRegister();


int main()
{
	tests();
	
}

void tests()
{
	int login_test, backup_test, d_menu_test, pass_res_test, set_perm_test;
	int block_student_test, rem_block_stu_test, reports_test;
	int student_messages, choice_pick, course_reg_test, del_course_reg_test;
	printf(" A demo test will be conducted. if there are no errors, a message will pop, otherwise error will be displayed.\n");
	printf("Test for login function. It will success if whether the login was successful AND has access. It will fail if user has NO access or wrong details upon login.\n");
	printf("It will also fail in case if login.txt file was not opened.\n");
	login_test = login();
	if (login_test == 1)
		printf("Test for login function was successful.\n\n");
	else
		printf("Test failed due to bad login or login.txt file was not found.\n\n");

	printf("Test for backup function:\n It will success if it creates a backup successfully, otherwise it will fail.\n");
	backup_test = backup();
	if (backup_test == 1)
		printf("Test for backup function was successful.\n\n");
	else
		printf("Test failed.\n\n");

	printf("Test for data manager menu function:\n It will success if one of the cases works, otherwise fails\n");
	d_menu_test = data_manager_menu();
	if (d_menu_test == 1)
		printf("Test for data manager menu was successful.\n\n");
	else
		printf("Test failed.\n\n");

	printf("Test for password restorization function:\n Returns 1 if it managed to open and change passwords, returns 0 if failed.\n");
	pass_res_test = password_restore();
	if (pass_res_test == 1)
		printf("Test for password restorization was successful.\n\n");
	else
		printf("Test failed due to failing to open file or user was not found in database.\n\n");

	printf("Test for permissions function:\n Returns 1 if it managed to open and change permissions, returns 0 if failed.\n");
	set_perm_test = set_permissions();
	if (set_perm_test == 1)
		printf("Test for permission setting was successful.\n\n");
	else
		printf("Test failed.\n\n");

	printf("Test for blocking student function:\n Returns 1 if it managed to open and block student, returns 0 if failed.\n");
	block_student_test = block_student();
	if (block_student_test == 1)
		printf("Test for blocking access to a student was successful.\n\n");
	else
		printf("Test failed due to opening one of the files.\n\n");

	printf("Test for blocking student function:\n Returns 1 if it managed to open and unblock student, returns 0 if failed.\n");
	rem_block_stu_test = revoke_block_student();
	if (rem_block_stu_test == 1)
		printf("Test for blocking access to a student was successful.\n\n");
	else
		printf("Test failed due to opening one of the files.\n\n");

	printf("Test for blocking student function:\n Returns 1 if it managed to open the file report, returns 0 if failed.\n");
	reports_test = reports();
	if (reports_test == 1)
		printf("Test for accessing to the reports was successful.\n\n");
	else
		printf("Test failed due to opening one of the files.\n\n");

	printf("Test for student_messages function:\n Returns 1 if it manages to add, returns 0 if failed.\n");
	student_messages = StudentMessages();
	if (student_messages == 1)
		printf("Test for accessing and printing student messages was successful.\n\n");
	else
		printf("Test failed due to opening one of the files.\n\n");

	printf("Test for choice pick function:\n Returns 1 if it picked correctly, returns 0 if not.\n");
	choice_pick = choose_block_unblock();
	if (choice_pick == 1)
		printf("Test for choosing a function was successful..\n\n");
	else
		printf("Test failed due wrong pick.\n\n"); 

	printf("Test for course_reg function:\n Returns 1 if registered correctly, 2 if already registered, returns 0 if not.\n");
	course_reg_test = CoursesToRegister();
	if (course_reg_test == 1 || course_reg_test == 2)
		printf("Test for course registration was successful..\n\n");
	else
		printf("Test failed due wrong pick.\n\n"); 

}
int login()
{
	username u1[user_amount];
	char inp_user[10] = { "dat_admin" };
	int inp_pass = 123456, flag = 0, i = 0;
	while (strlen(inp_user) > 9 || strlen(inp_user) < 1)
	{
		printf(" You have entered the username incorrectly.:\n");
		printf(" Enter your username and password:\n");
		scanf("%s", &inp_user);
		scanf("%d", &inp_pass);
	}
	FILE* file;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		return 0;
	}
	while (fscanf(file, "%d%s%d", &(u1[i].type), &(u1[i].user), &(u1[i].password)) != EOF)
	{
		if (strcmp(u1[i].user, inp_user) == 0 && u1[i].password == inp_pass && u1[i].type == 1)
		{
			flag = 1;
			break;
		}
		else if (strcmp(u1[i].user, inp_user) == 0 && u1[i].password == inp_pass && u1[i].type == 2)
		{
			flag = 2;
			break;
		}
		else if (strcmp(u1[i].user, inp_user) == 0 && u1[i].password == inp_pass && u1[i].type == 3)
		{
			flag = 3;
			break;
		}
		else if (strcmp(u1[i].user, inp_user) == 0 && u1[i].password == inp_pass && u1[i].type == 0)
		{
			flag = 4;
			break;
		}
		i++;
	}

	if (flag == 1)
	{
	//	printf(" Login for student was successful.\n");
		fclose(file);
		return 1;
	}
	else if (flag == 2)
	{
	//	printf(" Login for coordinator was successful.\n");
		fclose(file);
		return 1;
	}
	else if (flag == 3)
	{
	//	printf(" Login for data manager was successful.\n");
		fclose(file);
		return 1;
	}
	else if (flag == 4)
	{
	//	printf(" This login account has no permissions. Please contact data manager for permission access.\n");
		fclose(file);
		return 0;
	}
	else
	{
	//	printf(" User name was not found or password is incorrect. Login failed.\n");
		fclose(file);
		return 0;
	}
}
//*************Data manager functions************
int backup()
{
	FILE* OP, *BU;
	OP = fopen("login.txt", "r");
	BU = fopen("mock_backup_login.txt", "w");
	create_backup(OP, BU);
	return 1;
}
void create_backup(FILE* OP, FILE* BU)
{
	char c;
	if (OP == NULL || BU == NULL)
	{
		printf("Cant open the file.\n");
		return 0;
	}
	while ((c = fgetc(OP)) != EOF)
		fputc(c, BU);
	fclose(OP); fclose(BU);
}

int data_manager_menu()
{
	int user_choice = 1;
	do {
		switch (user_choice)
		{
		case 1:
			return 1;
			break;

		case 0:
			printf("You're logging out .\n");
			return 1;
			break;
		}
	} while (user_choice != 0);
	return 0;
}

int password_restore()
{
	// Read from file
	username logins[user_amount];

	int i = 0, new_pass = 12345, flag = 0, choice = 1;
	FILE* file;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		return 0;
	}
	while (fscanf(file, "%d\n%s\n%d\n", &(logins[i].type), &(logins[i].user), &(logins[i].password)) != EOF)
		i++;

	char user_inp[10] = "316317750";
	for (int j = 0; j < user_amount - correction; j++)
	{
		if (strcmp(logins[j].user, user_inp) == 0)
		{
			flag = 1;
			if (choice == 1)
			{
				logins[j].password = new_pass;
			}
			else
			{
				fclose(file);
			}
			break;
		}
	}
	if (flag == 0)
	{
		//printf("The user was not found in the login database.\n");
		fclose(file);
	}

	if (flag == 1)
	{
		file = fopen("login.txt", "w");
		if (file == NULL) {
			printf("Cant open the file.\n");
			exit(1);
		}
		i = 0;
		while (fprintf(file, "%d\n%s\n%d\n", (logins[i].type), (logins[i].user), (logins[i].password)) != EOF && i < user_amount - correction) // for some reason it takes 2
			i++;
	//	printf("The password was successfully updated.\n");
		fclose(file);
		return 1;
	}
	return 0;
}

int set_permissions()
{
	username users[user_amount];
	int i = 0, j = 0, perm_choice = 1;
	char insert_user[10] = { "316317750" };
	FILE* file;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		return 0;
	}
	while (fscanf(file, "%d\n%s\n%d\n", &(users[i].type), &(users[i].user), &(users[i].password)) != EOF)
		i++;
	fclose(file);
	for (int k = 0; k < user_amount - correction; k++)
		if (strcmp(users[k].user, insert_user) == 0)
		{
		//	printf("Which permission would you like to set:\n 1 - Student.\t 2 - Manager. \t 3 - Teaching Staff. \n");
		//	scanf("%d", &perm_choice);
			if (perm_choice == 1)
			{
				users[k].type = 1;
			//	printf("The permission as a student was successfully given to the user.\n");
			}
			else if (perm_choice == 2)
			{
				users[k].type = 2;
			//	printf("The permission as a manager was successfully given to the user.\n");
			}
			else if (perm_choice == 3)
			{
				users[k].type = 4;
			//	printf("The permission as a teaching staff was successfully given to the user.\n");
			}
		}
	file = fopen("login.txt", "w");
	if (file == NULL) {
		printf("Cant open the file.\n");
		return 0;
	}
	i = 0;
	while (fprintf(file, "%d\n%s\n%d\n", (users[i].type), (users[i].user), (users[i].password)) != EOF && i < user_amount - correction) // for some reason it takes 2
		i++;
	fclose(file);
	return 1;
}

int block_student()
{
	char student_dep = 'a';
	char semester = 'a';
	char inp_desired_block_id[10] = "316317750";
	int i = 0, j = 0, k = 0, index = 0;
	char temp_arr[2500];
	//bill student_payments[19];
	FILE* ofp = NULL;
	username Users[user_amount];
	FILE* file;
	if (student_dep == 'a')
	{
		if (semester == 'a')
		{
			ofp = fopen("bills-software a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else
		{
			ofp = fopen("bills-software b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
	}
	else
	{
		if (semester == 'a') {
			ofp = fopen("students electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else
		{
			ofp = fopen("students electrical-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
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
	bill students_bills[20];
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

	/*for (int j = 0; j < 19; j++)
	{
		if (atoi(students_bills[j].payed) < 4500)
		{
			printf("----------------------------------------------------|  \n");
			printf("User ID|  %s\n", students_bills[j].student_id);
			printf("----------------------------------------------------|  \n");
			printf("Tuition fees|  %s\n", students_bills[j].total_payment);
			printf("----------------------------------------------------|  \n");
			printf("Payed       |  %s\n", students_bills[j].payed);
			printf("----------------------------------------------------|  \n");
			printf("Left to pay |  %s\n", students_bills[j].left_to_pay);
			printf("----------------------------------------------------|  \n");
		}
	}*/


	int z = 0;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		return 0;
	}
	while (fscanf(file, "%d\n%s\n%d\n", &(Users[z].type), &(Users[z].user), &(Users[z].password)) != EOF)
		z++;
	fclose(file);
	z = 0;
	for (z = 0; z < user_amount - correction; z++)
	{
		if (strcmp(Users[z].user, inp_desired_block_id) == 0)
		{
			Users[z].type = 0;
			break;
		}
	}
	file = fopen("login.txt", "w");
	if (file == NULL) {
		printf("Cant open the file.\n");
		return 0;
	}
	z = 0;
	while (fprintf(file, "%d\n%s\n%d\n", (Users[z].type), (Users[z].user), (Users[z].password)) != EOF && z < user_amount - correction) // for some reason it takes 2
		z++;
	fclose(file);
//	printf("The requested user's access was successfully revoked.\n");
	return 1;
}

int revoke_block_student()
{
	char student_dep = 'a';
	char semester = 'a';
	char inp_desired_block_id[10] = "316317763";
	int i = 0, j = 0, k = 0, index = 0;
	char temp_arr[2500];
	//bill student_payments[19];
	FILE* ofp = NULL;
	username Users[user_amount];
	FILE* file;
	if (student_dep == 'a')
	{
		if (semester == 'a')
		{
			ofp = fopen("bills-software a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else
		{
			ofp = fopen("bills-software b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
	}
	else
	{
		if (semester == 'a') {
			ofp = fopen("students electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else
		{
			ofp = fopen("students electrical-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
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
	bill students_bills[20];
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

	/*for (int j = 0; j < 19; j++)
	{
		if (atoi(students_bills[j].payed) > 4500)
		{
			printf("----------------------------------------------------|  \n");
			printf("User ID|  %s\n", students_bills[j].student_id);
			printf("----------------------------------------------------|  \n");
			printf("Tuition fees|  %s\n", students_bills[j].total_payment);
			printf("----------------------------------------------------|  \n");
			printf("Payed       |  %s\n", students_bills[j].payed);
			printf("----------------------------------------------------|  \n");
			printf("Left to pay |  %s\n", students_bills[j].left_to_pay);
			printf("----------------------------------------------------|  \n");
		}
	}
	printf("Enter the desired ID you wish to unblock access:\n");*/

	int z = 0;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		return 0;
	}
	while (fscanf(file, "%d\n%s\n%d\n", &(Users[z].type), &(Users[z].user), &(Users[z].password)) != EOF)
		z++;
	fclose(file);
	z = 0;
	for (z = 0; z < user_amount - correction; z++)
	{
		if (strcmp(Users[z].user, inp_desired_block_id) == 0 && Users[z].type == 0)
		{
			Users[z].type = 1;
			break;
		}
	}
	file = fopen("login.txt", "w");
	if (file == NULL) {
		printf("Cant open the file.\n");
		return 0;
	}
	z = 0;
	while (fprintf(file, "%d\n%s\n%d\n", (Users[z].type), (Users[z].user), (Users[z].password)) != EOF && z < user_amount - correction) // for some reason it takes 2
		z++;
	fclose(file);
	//printf("The requested user's access was successfully revoked.\n");
	return 1;
}

int choose_block_unblock()
{
	int choice = 2;
	if (choice == 1)
		return 1;
	else if (choice == 2)
		return 1;
	else
	{
		return 0;
	}
}

int reports()
{
	char ch;
	FILE* fl, *fp, *fw;
	int choice = 1;;
	if (choice == 1) // lecturers report
	{
		fl = fopen("report-lecturers-electrical.txt", "r");
		if (fl == NULL)
		{
			printf("Cant open the file.\n");
			return 0;
		}
	//	while ((ch = fgetc(fl)) != EOF)
	//		printf("%c", ch);
		fclose(fl);

		fl = fopen("report-lecturers-software.txt", "r");
		if (fl == NULL)
		{
			printf("Cant open the file.\n");
			return 0;
		}
	//	while ((ch = fgetc(fl)) != EOF)
	//		printf("%c", ch);
		fclose(fl);

	}
	else if (choice == 2) // practitioners report
	{
		fp = fopen("report-practitioners-electrical.txt", "r");
		if (fp == NULL)
		{
			printf("Cant open the file.\n");
			return 0;
		}
		while ((ch = fgetc(fp)) != EOF)
			printf("%c", ch);
		fclose(fp);

		fp = fopen("report-practitioners-software.txt", "r");
		if (fp == NULL)
		{
			printf("Cant open the file.\n");
			return 0;
		}
		while ((ch = fgetc(fp)) != EOF)
			printf("%c", ch);
		fclose(fp);
	}
	else if (choice == 3) // Workers report.
	{
		fw = fopen("report-workers.txt", "r");
		if (fw == NULL)
		{
			printf("Cant open the file.\n");
			return 0;
		}
		while ((ch = fgetc(fw)) != EOF)
			printf("%c", ch);
		fclose(fw);
	}
	else
	{
		printf("Wrong choice, try again.\n");
		reports();
	}
	return 1;
}

int StudentMessages() {
	char student_dep = 'a';
	char semester = 'a';

	char temp_arr[300];
	int index = 0, i = 0, k = 0, j = 0;
	FILE *ofp = NULL;//for opening message file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("messages for students-software a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else if (semester == 'b') {
			ofp = fopen("messages for students-software b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
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
				return 0;
			}
		}
		else if (semester == 'b') {
			ofp = fopen("messages for students-electrical b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else {
			printf("No such semester,going back to main menu\n");
			return 0;
		}
	}
	else {
		printf("No such department,going back to main menu\n");
		return 0;
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
	return 1;
}


int CoursesToRegister() {
	char ID[10] = { "316317763" };
	char student_dep = 'a';
	char semester = 'a';

	courses courses_reg[20];
	int num_courses = 0;
	char course_num[7] = { "0001" };
	char answer = 1;
	int i = 0, j = 0, k = 0, index = 0;
	char temp_arr[2500];//move all the file to this temp array
	FILE *ofp = NULL;//for opening courses file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp = fopen("courses software-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else if (semester == 'b') {
			ofp = fopen("courses software-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
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
				return 0;
			}
		}
		else if (semester == 'b') {
			ofp = fopen("courses electrical-b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				return 0;
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

	if (answer == '1') {
		printf("Checking your listed courses\n");
	}
	else if (answer == '0') {
		return 0;
	}


	//***********************************updating the list of courses in student******************
	students student1[25];
	FILE *ofp2 = NULL;//for opening students file
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp2 = fopen("students software-a.txt", "r");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else if (semester == 'b') {
			ofp2 = fopen("students software-b.txt", "r");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp2 = fopen("students electrical-a.txt", "r");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else {
			ofp2 = fopen("students electrical-b.txt", "r");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				return 0;
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
		if (strcmp(ID, student1[l].num_id) == 0) {
			if (course_num[0] == student1[l].listed_courses[z] && course_num[1] == student1[l].listed_courses[z + 1] && course_num[2] == student1[l].listed_courses[z + 2] && course_num[3] == student1[l].listed_courses[z + 3] && course_num[4] == student1[l].listed_courses[z + 4]) {
				printf("Choose another course, you already registered:\n");
				return 2;
			}
		}
	}
	//
	char add_between[2] = { ',' };
	strcat(course_num, add_between);
	//add course
	for (int d = 0; d < num_students; d++) {
		if (strcmp(ID, student1[d].num_id) == 0) {
			if (student1[d].listed_courses[0] == 'n')
				strcpy(student1[d].listed_courses, course_num);
			else
				strcat(student1[d].listed_courses, course_num);
			//changing the list of courses
		}
	}
	//printf("You have successfully signed for Course\n");
	//----------------------writing to file-----------------------------
	if (student_dep == 'a') { //************check the other departments********
		if (semester == 'a') {
			ofp2 = fopen("students software-a.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else {
			ofp2 = fopen("students software-b.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
	}
	else if (student_dep == 'b') {//electrical
		if (semester == 'a') {
			ofp2 = fopen("students electrical-a.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else if (semester == 'b') {
			ofp2 = fopen("students electrical-b.txt", "w");
			if (ofp2 == NULL) {
				printf("Can't open the file\n");
				return 0;
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
				return 0;
			}
		}
		else {
			ofp1 = fopen("courses software-b.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
	}
	else {//electrical
		if (semester == 'a') {
			ofp1 = fopen("courses electrical-a.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				return 0;
			}
		}
		else {
			ofp1 = fopen("courses electrical-b.txt", "w");
			if (ofp1 == NULL) {
				printf("Can't open the file\n");
				return 0;
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
	return 1;
}


