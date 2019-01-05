#define _CRT_SECURE_NO_WARNINGS
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

void login();
void backup();
void create_backup(FILE*, FILE*);
void data_manager_menu();
void password_restore();
void set_permissions();
void choose_block_unblock();
void block_student();
void revoke_block_student();
void reports();

int main()
{
	login();
}
void login()
{
	username u1[user_amount];
	char inp_user[10];
	int inp_pass, flag = 0, i = 0;
	printf(" Enter your username (Max 9 chars!) and password:\n");
	scanf("%s", &inp_user);
	scanf("%d", &inp_pass);
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
		exit(1);
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
		printf(" Login for student was successful.\n");
		fclose(file);
	}
	else if (flag == 2)
	{
		printf(" Login for coordinator was successful.\n");
		fclose(file);
	}
	else if (flag == 3)
	{
		printf(" Login for data manager was successful.\n");
		fclose(file);
		data_manager_menu();
	}
	else if (flag == 4)
	{
		printf(" This login account has no permissions. Please contact data manager for permission access.\n");
		fclose(file);
	}
	else
	{
		printf(" User name was not found or password is incorrect. Login failed.\n");
		fclose(file);
	}
}
//*************Data manager functions************
void backup()
{
	FILE* OP, *BU;
	OP = fopen("login.txt", "r");
	BU = fopen("backup_login.txt", "w");
	create_backup(OP, BU);
	OP = fopen("bills-electrical a.txt", "r");
	BU = fopen("backup_bills-electrical a.txt", "w");
	create_backup(OP, BU);
	OP = fopen("bills-electrical b.txt", "r");
	BU = fopen("backup_bills-electrical b.txt", "w");
	create_backup(OP, BU);
	OP = fopen("bills-software a.txt", "r");
	BU = fopen("backup_bills-software a.txt.txt", "w");
	create_backup(OP, BU);
	OP = fopen("bills-software b.txt", "r");
	BU = fopen("backup_bills-software b.txt.txt", "w");
	create_backup(OP, BU);
	OP = fopen("choice_courses.txt", "r");
	BU = fopen("backup_choice_courses.txt", "w");
	create_backup(OP, BU);
	OP = fopen("courses electrical-a.txt", "r");
	BU = fopen("backup_courses electrical-a.txt", "w");
	create_backup(OP, BU);
	OP = fopen("courses electrical-b.txt", "r");
	BU = fopen("backup_courses electrical-b.txt", "w");
	create_backup(OP, BU);
	OP = fopen("courses software-a.txt", "r");
	BU = fopen("backup_courses software-a.txt", "w");
	create_backup(OP, BU);
	OP = fopen("courses software-b.txt", "r");
	BU = fopen("backup_courses software-b.txt", "w");
	create_backup(OP, BU);
	OP = fopen("electrical department.txt", "r");
	BU = fopen("backup_electrical department.txt", "w");
	create_backup(OP, BU);
	OP = fopen("flowchart_electrical.txt", "r");
	BU = fopen("backup_flowchart_electrical.txt", "w");
	create_backup(OP, BU);
	OP = fopen("flowchart_software.txt", "r");
	BU = fopen("backup_flowchart_software.txt", "w");
	create_backup(OP, BU);
	OP = fopen("grades electrical-a.txt", "r");
	BU = fopen("backup_grades electrical-a.txt", "w");
	create_backup(OP, BU);
	OP = fopen("grades electrical-b.txt", "r");
	BU = fopen("backup_grades electrical-b.txt", "w");
	create_backup(OP, BU);
	OP = fopen("grades software-a.txt", "r");
	BU = fopen("backup_grades software-a.txt", "w");
	create_backup(OP, BU);
	OP = fopen("grades software-b.txt", "r");
	BU = fopen("backup_grades software-b.txt", "w");
	create_backup(OP, BU);
	OP = fopen("messages for students-electrical a.txt", "r");
	BU = fopen("backup_messages for students-electrical a.txt", "w");
	create_backup(OP, BU);
	OP = fopen("messages for students-electrical b.txt", "r");
	BU = fopen("backup_messages for students-electrical b.txt", "w");
	create_backup(OP, BU);
	OP = fopen("messages for students-software a.txt", "r");
	BU = fopen("backup_messages for students-software a.txt", "w");
	create_backup(OP, BU);
	OP = fopen("messages for students-software b.txt", "r");
	BU = fopen("backup_messages for students-software b.txt", "w");
	create_backup(OP, BU);
	OP = fopen("report-lecturers-electrical.txt", "r");
	BU = fopen("backup_report-lecturers-electrical.txt", "w");
	create_backup(OP, BU);
	OP = fopen("report-lecturers-software.txt", "r");
	BU = fopen("backup_report-lecturers-software.txt", "w");
	create_backup(OP, BU);
	OP = fopen("report-practitioners-electrical.txt", "r");
	BU = fopen("backup_report-practitioners-electrical.txt", "w");
	create_backup(OP, BU);
	OP = fopen("report-practitioners-software.txt", "r");
	BU = fopen("backup_report-practitioners-software.txt", "w");
	create_backup(OP, BU);
	OP = fopen("report-workers.txt", "r");
	BU = fopen("backup_report-workers.txt", "w");
	create_backup(OP, BU);
	OP = fopen("software department.txt", "r");
	BU = fopen("backup_software department.txt", "w");
	create_backup(OP, BU);
	OP = fopen("students electrical-a.txt", "r");
	BU = fopen("backup_students electrical-a.txt", "w");
	create_backup(OP, BU);
	OP = fopen("students electrical-b.txt", "r");
	BU = fopen("backup_students electrical-b.txt", "w");
	create_backup(OP, BU);
	OP = fopen("students software-a.txt", "r");
	BU = fopen("backup_students software-a.txt", "w");
	create_backup(OP, BU);
	OP = fopen("students software-b.txt", "r");
	BU = fopen("backup_students software-b.txt", "w");
	create_backup(OP, BU);
	OP = fopen("amount student report.txt", "r");
	BU = fopen("backup_amount student report.txt", "w");
	create_backup(OP, BU);
	OP = fopen("administrative_Employee.txt", "r");
	BU = fopen("backup_administrative_Employee.txt", "w");
	create_backup(OP, BU);

	printf("Backup was successful!\n");
	data_manager_menu();
}
void create_backup(FILE* OP, FILE* BU)
{
	char c;
	if (OP == NULL || BU == NULL)
	{
		printf("Cant open the file.\n");
		exit(1);
	}
	while ((c = fgetc(OP)) != EOF)
		fputc(c, BU);
	fclose(OP); fclose(BU);
}

void data_manager_menu()
{
	int user_choice;
	printf("\n Data Manager Menu:\n");
	printf(" 1 - Create a backup.\n 2 - Restore a password. \n 3 - Data management. \n 4 - User authority. \n 5 - Payments - block or unblock user.\n 6 - Delete user.\n 7 - Reports.\n 0 - Log out. \n");
	printf("Enter your choice:\n");
	scanf("%d", &user_choice);
	do {
		switch (user_choice)
		{
		case 1:
			backup();
			break;
		case 2:
			password_restore();
			break;
		case 3:
			// data management
			break;
		case 4:
			set_permissions();// User Authority.
			break;
		case 5:
			choose_block_unblock();// Payments - block student or unblock student.
			break;
		case 6:
			// Delete user.
			break;
		case 7:
			reports();// Reports.
			break;

		case 0:
			printf("You're logging out .\n");
			break;
		}
	} while (user_choice != 0);
}

void password_restore()
{
	// Read from file
	username logins[user_amount];

	int i = 0, new_pass = 0, flag = 0, choice = 0;
	FILE* file;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		exit(1);
	}
	while (fscanf(file, "%d\n%s\n%d\n", &(logins[i].type), &(logins[i].user), &(logins[i].password)) != EOF)
		i++;

	char user_inp[10];
	printf("Enter the user ID whose password you wish to change.\n");
	scanf("%s", &user_inp);
	for (int j = 0; j < 4; j++)
	{
		if (strcmp(logins[j].user, user_inp) == 0)
		{
			flag = 1;
			printf("The user exists.\n Do you wish to restore or change the password? 1 - Yes. 2 - No. \n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				printf("Enter new user password:\n");
				scanf("%d", &new_pass);
				logins[j].password = new_pass;
			}
			else
			{
				fclose(file);
				data_manager_menu();
			}
			break;
		}
	}
	if (flag == 0)
	{
		printf("The user was not found in the login database.\n");
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
		printf("The password was successfully updated.\n");
		fclose(file);
	}
	data_manager_menu();
}

void set_permissions()
{
	username users[user_amount];
	int i = 0, j = 0, perm_choice = 0;
	char insert_user[10];
	FILE* file;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		exit(1);
	}
	while (fscanf(file, "%d\n%s\n%d\n", &(users[i].type), &(users[i].user), &(users[i].password)) != EOF)
		i++;
	fclose(file);
	printf("The following users has no permissions (if any):\n");
	for (j = 0; j < 4; j++)
	{
		if (users[j].type == 0)
			printf("%s\n", &(users[j].user));
	}
	printf("Enter the user ID whose permission you wish to set:\n");
	scanf("%s", &insert_user);
	for (int k = 0; k < user_amount - correction; k++)
		if (strcmp(users[k].user, insert_user) == 0)
		{
			printf("Which permission would you like to set:\n 1 - Student.\t 2 - Manager. \t 3 - Teaching Staff. \n");
			scanf("%d", &perm_choice);
			if (perm_choice == 1)
			{
				users[k].type = 1;
				printf("The permission as a student was successfully given to the user.\n");
			}
			else if (perm_choice == 2)
			{
				users[k].type = 2;
				printf("The permission as a manager was successfully given to the user.\n");
			}
			else if (perm_choice == 3)
			{
				users[k].type = 4;
				printf("The permission as a teaching staff was successfully given to the user.\n");
			}
		}
	file = fopen("login.txt", "w");
	if (file == NULL) {
		printf("Cant open the file.\n");
		exit(1);
	}
	i = 0;
	while (fprintf(file, "%d\n%s\n%d\n", (users[i].type), (users[i].user), (users[i].password)) != EOF && i < user_amount - correction) // for some reason it takes 2
		i++;
	fclose(file);
	data_manager_menu();
}

void block_student()
{
	char student_dep;
	char semester;
	char inp_desired_block_id[10];
	printf("Please choose your department:a-software, b-electrical for viewing bills\n");
	getchar();
	printf("Your choice:\n");
	scanf("%c", &student_dep);
	printf("Please enter your semester: a or b\n");
	getchar();
	scanf("%c", &semester);
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
				exit(1);
			}
		}
		else
		{
			ofp = fopen("bills-software b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else
	{
		if (semester == 'a') {
			ofp = fopen("students electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else
		{
			ofp = fopen("students electrical-b.txt", "r");
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

	for (int j = 0; j < 19; j++)
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
	}
	printf("Enter the desired ID you wish to block access:\n");
	scanf("%s", &inp_desired_block_id);

	int z = 0;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		exit(1);
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
		exit(1);
	}
	z = 0;
	while (fprintf(file, "%d\n%s\n%d\n", (Users[z].type), (Users[z].user), (Users[z].password)) != EOF && z < user_amount - correction) // for some reason it takes 2
		z++;
	fclose(file);
	printf("The requested user's access was successfully revoked.\n");
	data_manager_menu();
}

void revoke_block_student()
{
	char student_dep;
	char semester;
	char inp_desired_block_id[10];
	printf("Please choose your department:a-software, b-electrical for viewing bills\n");
	getchar();
	printf("Your choice:\n");
	scanf("%c", &student_dep);
	printf("Please enter your semester: a or b\n");
	getchar();
	scanf("%c", &semester);
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
				exit(1);
			}
		}
		else
		{
			ofp = fopen("bills-software b.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
	}
	else
	{
		if (semester == 'a') {
			ofp = fopen("students electrical-a.txt", "r");
			if (ofp == NULL) {
				printf("Can't open the file\n");
				exit(1);
			}
		}
		else
		{
			ofp = fopen("students electrical-b.txt", "r");
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

	for (int j = 0; j < 19; j++)
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
	printf("Enter the desired ID you wish to block access:\n");
	scanf("%s", &inp_desired_block_id);

	int z = 0;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		exit(1);
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
		exit(1);
	}
	z = 0;
	while (fprintf(file, "%d\n%s\n%d\n", (Users[z].type), (Users[z].user), (Users[z].password)) != EOF && z < user_amount - correction) // for some reason it takes 2
		z++;
	fclose(file);
	printf("The requested user's access was successfully revoked.\n");
	data_manager_menu();
}

void choose_block_unblock()
{
	int choice = 0;
	printf("Choose if you wish to block or unblock a student. 1 - to block, 2 - to unblock.\n");
	scanf("%d", &choice);
	if (choice == 1)
		block_student();
	else if (choice == 2)
		revoke_block_student();
	else
	{
		printf("You've picked a wrong choice. You will now return to main menu.\n");
		data_manager_menu();
	}
}

void reports()
{
	char ch;
	FILE* fl, *fp, *fw;
	int choice = 0;
	printf("Choose a report that you want to display:\n 1 - Lecturers report. \n 2 - Practitioners report. \n 3 - Workers report.\n");
	scanf("%d", &choice);
	if (choice == 1) // lecturers report
	{
		fl = fopen("report-lecturers-electrical.txt", "r");
		if (fl == NULL)
		{
			printf("Cant open the file.\n");
			exit(1);
		}
		while ((ch = fgetc(fl)) != EOF)
			printf("%c", ch);
		fclose(fl);

		fl = fopen("report-lecturers-software.txt", "r");
		if (fl == NULL)
		{
			printf("Cant open the file.\n");
			exit(1);
		}
		while ((ch = fgetc(fl)) != EOF)
			printf("%c", ch);
		fclose(fl);

	}
	else if (choice == 2) // practitioners report
	{
		fp = fopen("report-practitioners-electrical.txt", "r");
		if (fp == NULL)
		{
			printf("Cant open the file.\n");
			exit(1);
		}
		while ((ch = fgetc(fp)) != EOF)
			printf("%c", ch);
		fclose(fp);

		fp = fopen("report-practitioners-software.txt", "r");
		if (fp == NULL)
		{
			printf("Cant open the file.\n");
			exit(1);
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
			exit(1);
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
	data_manager_menu();
}
