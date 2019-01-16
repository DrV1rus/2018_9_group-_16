#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <math.h>

//-------------------------------------------------
#define MAX_USER_LENGTH 10
#define user_amount 85
#define correction 3  // First (-2) is for going for correct amount of users( as of now 83), the second (-2) is for loop correction, therefore -4.
#define SIZE 20
#define SIZE4 35
#define INDEX 7
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

struct user
{
	char ID[10];
	char Username[11];
	int type;

};
typedef struct user user;

//***********Student **********
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
void StudentMenu(char*);

void UpdateDetails();
//****************************************

//***********Registration manager **********
void main_page();
void Courses();
void delete_course();
void update_course();
void main_information();
void software_flowchart();
void electrical_flowchart();
void students_update();
void full_course();
void amount_student_report();
void update_exam_date();

void addGrade();
void updateAddPost();
void addExamDate();
//****************************************

//*************Data manager************
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
void addEmployeManager();
void deleteEmployeManager();
void initData(char* temp);
int stringSearch(char userTemp[2000], char temp[2000]);
void addStudent();
void deleteStudent();
void database();
void pick_delete();
//****************************************

int main()
{
	login();
	return 0;
}

// LOGIN Function: 0 - No permissions. 1 - Student permission. 2 - Manager Permission. 3 - Data Manager Permission.
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
		StudentMenu(inp_user);
		fclose(file);
	}
	else if (flag == 2)
	{
		printf(" Login for coordinator was successful.\n");
		main_page();
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
		printf("Contact details: 054-7362741 or email: helplogin@hit.ac.il.\n");
		fclose(file);
	}
	else
	{
		printf(" User name was not found or password is incorrect. Login failed.\n");
		printf("Contact details: 054-7362741 or email: helplogin@hit.ac.il.\n");
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
void database()
{
	int u_choice = 0;
	printf("Which file to add :1 for students,2 for administrative staff.\n");
	scanf("%d", &u_choice);
	switch (u_choice)
	{
	case 1:
		addStudent();
		break;
	case 2:
		addEmployeManager();
		break;
	}
}
void pick_delete()
{
	int u_choice = 0;
	printf("Which file to delete :1 for students.\n 2 for administrative staff.\n");
	scanf("%d", &u_choice);
	switch (u_choice)
	{
	case 1:
		deleteStudent();
		break;
	case 2:
		deleteEmployeManager();
		break;
	}
}

void data_manager_menu()
{
	int user_choice;
	printf("\n Data Manager Menu:\n");
	printf(" 1 - Create a backup.\n 2 - Restore a password. \n 3 - Data management. \n 4 - User authority. \n 5 - Payments - block or unblock user.\n 6 - Delete user.\n 7 - Reports.\n 0 - Log out. \n");
	printf("Enter your choice:\n");
	scanf("%d", &user_choice);
	switch (user_choice)
	{
	case 1:
		backup();
		break;
	case 2:
		password_restore();
		break;
	case 3:
		printf("Database\n");// data management
		database();
		break;
	case 4:
		set_permissions();// User Authority.
		break;
	case 5:
		choose_block_unblock();// Payments - block student or unblock student.
		break;
	case 6:
		pick_delete();// Delete user.
		break;
	case 7:
		reports();// Reports.
		break;

	case 0:
		printf("You're logging out .\n");
		exit(1);
		break;
	}
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
	for (int j = 0; j < user_amount - correction; j++)
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
	for (j = 0; j < user_amount - correction; j++)
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
	printf("Enter the desired ID you wish to unblock access:\n");
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
	printf("The requested user's access was successfully restored.\n");
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

void addEmployeManager()
{

	char ID_user[10], Username_user[11], temp[2000];
	FILE* fp;
	fp = NULL;
	int i = 0;
	printf("Enter the user ID and password:\n");
	printf("Enter ID:\n");
	scanf("%s", &ID_user);
	do {
		for (i = 0; i < (int)strlen(ID_user); i++)
		{
			if (ID_user[i] < '0' || ID_user[i]>'9' || strlen(ID_user) < 9)
			{
				printf("Please enter again ID:\n");
				scanf("%s", &ID_user);
			}
		}
	} while ((ID_user[i] >= '0' && ID_user[i] <= '9') && strlen(ID_user) == 9);

	printf("Enter Username:\n");
	scanf("%s", &Username_user);

	initData(temp);
	int  choice;
	printf("Which database will you add:1 for students,2 for administrative staff, 3 for staff member\n");
	scanf("%d", &choice);

	if (choice == 2)
	{
		fp = fopen("administrative_Employee.txt", "r");
		if (fp == NULL)
		{
			printf(" unable to open file \n");
			exit(1);
		}

		fclose(fp);
		fp = fopen("administrative_Employee.txt", "a");
		if (fp == NULL)
		{
			printf(" unable to open file \n");
			exit(1);
		}
		fprintf(fp, "%s\n", temp);
		fclose(fp);
	}
}

void deleteEmployeManager()
{

	char temp[2000], addEmpTemp[2000];
	struct adEm am;
	int  i = 0, k, index = 0;
	FILE* fp;
	fp = NULL;
	char Username[10], password[11];
	printf("Enter user name:\n");
	scanf("%s", &Username);
	do {
		for (i = 0; i < (int)strlen(Username); i++)
		{
			if (Username[i] < '0' || Username[i]>'9' || strlen(Username) < 9)
			{
				printf("Please enter again  user name:\n");
				scanf("%s", &Username);
			}
		}
	} while ((Username[i] >= '0' && Username[i] <= '9') && strlen(Username) == 9);

	printf("Enter password:\n");
	scanf("%s", &password);


	initData(temp);
	fp = fopen("administrative_Employee.txt", "r");
	if (fp == NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}
	fseek(fp, 0, SEEK_SET);

	// Copy text file contents into an array//
	for (i = 0; !feof(fp); i++)
	{
		addEmpTemp[i] = fgetc(fp);
	}
	addEmpTemp[i - 1] = '\0';
	//printf("us=%s\n", addEmpTemp);

	index = stringSearch(addEmpTemp, temp);
	//printf("index=%d\n", index);

	if (index != -1) // stdTemp contine temp, Delete the user's details from the array//
	{
		for (k = 0; temp[k] != '\0'; k++);
		{
			for (i = index; addEmpTemp[i] != '\0'; i++)
			{
				addEmpTemp[i] = addEmpTemp[i + k + 1];
			}
		}
		addEmpTemp[i] = '\0';
		fclose(fp);


		//Enter the details of the new data into the file//
		fp = fopen("administrative_Employee.txt", "w+");
		if (fp == NULL)
		{
			printf(" unable to open file \n");
			exit(1);
		}
		fprintf(fp, "%s", addEmpTemp);
		printf("Deletion confirmed, user deleted from database\n");
		fclose(fp);
	}
	else
	{
		fclose(fp);
	}

} //A function that deletes employee employee information//

void initData(char* temp)
{
	int i = 0, len = 0;
	struct	adEm ad;

	printf("Enter Id:\n");
	scanf("%s", &ad.ID_administration_employee);
	getchar();
	do {
		for (i = 0; i < (int)strlen(ad.ID_administration_employee); i++)
		{
			if (ad.ID_administration_employee[i] < '0' || ad.ID_administration_employee[i]>'9' || strlen(ad.ID_administration_employee) < 8)
			{
				printf("Please enter again ID:\n");
				scanf("%s", &ad.ID_administration_employee);
				getchar();
			}
		}
	} while ((ad.ID_administration_employee[i] >= '0' && ad.ID_administration_employee[i] <= '9') && strlen(ad.ID_administration_employee) == 8);

	/**********************************/
	printf("Enter first name:\n");
	fgets(ad.first_name_ad, 35, stdin);
	i = 0;
	while (ad.first_name_ad[i] != '\n')
		i++;
	if (ad.first_name_ad[i] == '\n')
		ad.first_name_ad[i] = '\0';
	/**********************************/
	printf("Enter last name:\n");
	fgets(ad.last_name_ad, 35, stdin);
	i = 0;
	while (ad.last_name_ad[i] != '\n')
		i++;
	if (ad.last_name_ad[i] == '\n')
		ad.last_name_ad[i] = '\0';
	/**********************************/
	printf("Enter  Date of birth:\n");
	fgets(ad.Date_of_birth_ad, 35, stdin);
	i = 0;
	while (ad.Date_of_birth_ad[i] != '\n')
		i++;
	if (ad.Date_of_birth_ad[i] == '\n')
		ad.Date_of_birth_ad[i] = '\0';
	/**********************************/
	printf("Enter phone:\n");
	scanf("%s", &ad.phone_ad);
	getchar();
	/**********************************/
	printf("Enter Address:\n");
	fgets(ad.Address_ad, 35, stdin);
	i = 0;
	while (ad.Address_ad[i] != '\n')
		i++;
	if (ad.Address_ad[i] == '\n')
		ad.Address_ad[i] = '\0';
	/**********************************/
	printf("Enter Email:\n");
	scanf("%s", &ad.Email_ad);
	getchar();
	/**********************************/

	printf("Enter role: Coordinator or resDatabase\n");
	fgets(ad.role_ad, 35, stdin);
	i = 0;
	while (ad.role_ad[i] != '\n')
		i++;
	if (ad.role_ad[i] == '\n')
		ad.role_ad[i] = '\0';

	/**********************************/
	printf("Enter  reception hours:\n");
	scanf("%s", &ad.reception_hours_ad);

	//Inserting a user's personal data into an array//
	strcpy(temp, ad.ID_administration_employee);
	strcat(temp, "-");
	strcat(temp, ad.first_name_ad);
	strcat(temp, "-");
	strcat(temp, ad.last_name_ad);
	strcat(temp, "-");
	strcat(temp, ad.Date_of_birth_ad);
	strcat(temp, "-");
	strcat(temp, ad.Address_ad);
	strcat(temp, "-");
	strcat(temp, ad.phone_ad);
	strcat(temp, "-");
	strcat(temp, ad.Email_ad);
	strcat(temp, "-");
	strcat(temp, ad.role_ad);
	strcat(temp, "-");
	strcat(temp, ad.reception_hours_ad);
	//printf("%s\n", temp);
} //Function that takes employee data managers//

int stringSearch(char userTemp[2000], char temp[2000])
{
	int k, i, j;
	for (k = 0; temp[k] != '\0'; k++);
	{
		for (i = 0, j = 0; userTemp[i] != '\0' && temp[j] != '\0'; i++)
		{
			if (userTemp[i] == temp[j])
			{
				j++;
			}
			else
			{
				j = 0;
			}
		}
	}
	if (j == k)
	{
		return (i - j); //returns an index for a string that needs to be deleted//
	}
	else
	{
		return -1;
	}
}

void addStudent()
{

	char  temp[2000];
	FILE* fp;
	fp = NULL;
	int len = 0, i = 0;
	char number_semester_std[35];
	char department_std[35];
	struct Students std;

	char Username[10], password[11];
	printf("Enter user name:\n");
	scanf("%s", &Username);
	do {
		for (i = 0; i < (int)strlen(Username); i++)
		{
			if (Username[i] < '0' || Username[i]>'9' || strlen(Username) < 9)
			{
				printf("Please enter again  user name:\n");
				scanf("%s", &Username);
			}
		}
	} while ((Username[i] >= '0' && Username[i] <= '9') && strlen(Username) == 9);

	printf("Enter password:\n");
	scanf("%s", &password);


	/*************************************************************/
	printf("Enter Id:\n");
	scanf("%s", &std.num_id);
	getchar();

	do {
		for (i = 0; i < (int)strlen(std.num_id); i++)
		{
			if (std.num_id[i] < '0' || std.num_id[i]>'9' || strlen(std.num_id) < 9)
			{
				printf("Please enter again ID:\n");
				scanf("%s", &std.num_id);
				getchar();
			}
		}
	} while ((std.num_id[i] >= '0' && std.num_id[i] <= '9') && strlen(std.num_id) == 9);
	/**********************************/
	printf("Enter first name:\n");
	fgets(std.name, 7, stdin);
	i = 0;
	while (std.name[i] != '\n')
		i++;
	if (std.name[i] == '\n')
		std.name[i] = '\0';
	/**********************************/
	printf("Enter last name:\n");
	fgets(std.last_name, 7, stdin);
	i = 0;
	while (std.last_name[i] != '\n')
		i++;
	if (std.last_name[i] == '\n')
		std.last_name[i] = '\0';
	/**********************************/
	printf("Enter  Date of birth:\n");
	fgets(std.birthday, 9, stdin);
	i = 0;
	while (std.birthday[i] != '\n')
		i++;
	if (std.birthday[i] == '\n')
		std.birthday[i] = '\0';
	/**********************************/
	printf("Enter phone:\n");
	scanf("%s", &std.telephone);
	getchar();
	/**********************************/
	printf("Enter address:\n");
	fgets(std.adress, 25, stdin);
	i = 0;
	while (std.adress[i] != '\n')
		i++;
	if (std.adress[i] == '\n')
		std.adress[i] = '\0';
	/**********************************/
	printf("Enter mail:\n");
	scanf("%s", &std.mail);
	getchar();
	/**********************************/

	printf("Enter exames:\n");
	fgets(std.exames, 200, stdin);
	i = 0;
	while (std.exames[i] != '\n')
		i++;
	if (std.exames[i] == '\n')
		std.exames[i] = '\0';

	/**********************************/

	printf("Enter listed courses:\n");
	fgets(std.listed_courses, 100, stdin);
	i = 0;
	while (std.listed_courses[i] != '\n')
		i++;
	if (std.listed_courses[i] == '\n')
		std.listed_courses[i] = '\0';

	/**********************************/
	printf("Enter boill:\n");
	fgets(std.bill, 10, stdin);
	i = 0;
	while (std.bill[i] != '\n')
		i++;
	if (std.bill[i] == '\n')
		std.bill[i] = '\0';
	/**********************************/

	printf("Enter number semester:\n");
	fgets(number_semester_std, 35, stdin);
	i = 0;
	while (number_semester_std[i] != '\n')
		i++;
	if (number_semester_std[i] == '\n')
		number_semester_std[i] = '\0';
	/**********************************/
	printf("Enter department:\n");
	fgets(department_std, 35, stdin);
	i = 0;
	while (department_std[i] != '\n')
		i++;
	if (department_std[i] == '\n')
		department_std[i] = '\0';
	/**********************************/

	//Inserting a user's personal data into an array//
	strcpy(temp, std.num_id);
	strcat(temp, "-");
	strcat(temp, std.name);
	strcat(temp, "-");
	strcat(temp, std.last_name);
	strcat(temp, "-");
	strcat(temp, std.listed_courses);
	strcat(temp, "-");
	strcat(temp, std.exames);
	strcat(temp, "-");
	strcat(temp, std.bill);
	strcat(temp, "-");
	strcat(temp, std.birthday);
	strcat(temp, "-");
	strcat(temp, std.mail);
	strcat(temp, "-");
	strcat(temp, std.adress);
	strcat(temp, "-");
	strcat(temp, std.telephone);
	strcat(temp, "$");


	int  choice;
	printf("Which database will you add:1 for students,2 for administrative staff, 3 for staff member\n");
	scanf("%d", &choice);

	if ((strcmp(department_std, "students software") == 0) && (strcmp(number_semester_std, "a") == 0) && choice == 1)
	{
		fp = fopen("students software-a.txt", "r");
	}
	else if (strcmp(department_std, "students software") == 0 && strcmp(number_semester_std, "b") == 0 && choice == 1)
	{
		fp = fopen("students software-b.txt", "r");
	}
	else if ((strcmp(department_std, "students electrical") == 0) && (strcmp(number_semester_std, "a") == 0) && choice == 1)
	{
		fp = fopen("students electrical-a.txt", "r");
	}
	else if (strcmp(department_std, "students electrical") == 0 && strcmp(number_semester_std, "b") == 0 && choice == 1)
	{
		fp = fopen("students electrical-b.txt", "r");
	}
	if (fp == NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}
	fclose(fp);
	if ((strcmp(department_std, "students software") == 0) && (strcmp(number_semester_std, "a") == 0) && choice == 1)
	{
		fp = fopen("students software-a.txt", "a");
	}
	else if (strcmp(department_std, "students software") == 0 && strcmp(number_semester_std, "b") == 0 && choice == 1)
	{
		fp = fopen("students software-b.txt", "a");
	}
	else if ((strcmp(department_std, "students electrical") == 0) && (strcmp(number_semester_std, "a") == 0) && choice == 1)
	{
		fp = fopen("students electrical-a.txt", "a");
	}
	else if (strcmp(department_std, "students electrical") == 0 && strcmp(number_semester_std, "b") == 0 && choice == 1)
	{
		fp = fopen("students electrical-b.txt", "a");
	}

	if (fp == NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	fprintf(fp, "%s\n", temp);
	fclose(fp);


} //A function that adds student information to the appropriate database//

void deleteStudent()
{
	char temp[2000], stdTemp[2000];
	int  i = 0, k, index = 0;
	FILE* fp;
	fp = NULL;
	char number_semester_std[35];
	char department_std[35];
	char Username[10], password[11];
	struct Students std;

	printf("Enter user name:\n");
	scanf("%s", &Username);
	do {
		for (i = 0; i < (int)strlen(Username); i++)
		{
			if (Username[i] < '0' || Username[i]>'9' || strlen(Username) < 9)
			{
				printf("Please enter again  user name:\n");
				scanf("%s", &Username);
			}
		}
	} while ((Username[i] >= '0' && Username[i] <= '9') && strlen(Username) == 9);

	printf("Enter password:\n");
	scanf("%s", &password);

	printf("Enter Id:\n");
	scanf("%s", &std.num_id);
	getchar();

	do {
		for (i = 0; i < (int)strlen(std.num_id); i++)
		{
			if (std.num_id[i] < '0' || std.num_id[i]>'9' || strlen(std.num_id) < 9)
			{
				printf("Please enter again ID:\n");
				scanf("%s", &std.num_id);
				getchar();
			}
		}
	} while ((std.num_id[i] >= '0' && std.num_id[i] <= '9') && strlen(std.num_id) == 9);
	/**********************************/
	printf("Enter first name:\n");
	fgets(std.name, 7, stdin);
	i = 0;
	while (std.name[i] != '\n')
		i++;
	if (std.name[i] == '\n')
		std.name[i] = '\0';
	/**********************************/
	printf("Enter last name:\n");
	fgets(std.last_name, 7, stdin);
	i = 0;
	while (std.last_name[i] != '\n')
		i++;
	if (std.last_name[i] == '\n')
		std.last_name[i] = '\0';
	/**********************************/
	printf("Enter  Date of birth:\n");
	fgets(std.birthday, 9, stdin);
	i = 0;
	while (std.birthday[i] != '\n')
		i++;
	if (std.birthday[i] == '\n')
		std.birthday[i] = '\0';
	/**********************************/
	printf("Enter phone:\n");
	scanf("%s", &std.telephone);
	getchar();
	/**********************************/
	printf("Enter address:\n");
	fgets(std.adress, 25, stdin);
	i = 0;
	while (std.adress[i] != '\n')
		i++;
	if (std.adress[i] == '\n')
		std.adress[i] = '\0';
	/**********************************/
	printf("Enter mail:\n");
	scanf("%s", &std.mail);
	getchar();
	/**********************************/

	printf("Enter exames:\n");
	fgets(std.exames, 200, stdin);
	i = 0;
	while (std.exames[i] != '\n')
		i++;
	if (std.exames[i] == '\n')
		std.exames[i] = '\0';

	/**********************************/

	printf("Enter listed courses:\n");
	fgets(std.listed_courses, 100, stdin);
	i = 0;
	while (std.listed_courses[i] != '\n')
		i++;
	if (std.listed_courses[i] == '\n')
		std.listed_courses[i] = '\0';

	/**********************************/
	printf("Enter boill:\n");
	fgets(std.bill, 10, stdin);
	i = 0;
	while (std.bill[i] != '\n')
		i++;
	if (std.bill[i] == '\n')
		std.bill[i] = '\0';
	/**********************************/

	printf("Enter number semester:\n");
	fgets(number_semester_std, 35, stdin);
	i = 0;
	while (number_semester_std[i] != '\n')
		i++;
	if (number_semester_std[i] == '\n')
		number_semester_std[i] = '\0';
	/**********************************/
	printf("Enter department:\n");
	fgets(department_std, 35, stdin);
	i = 0;
	while (department_std[i] != '\n')
		i++;
	if (department_std[i] == '\n')
		department_std[i] = '\0';
	/**********************************/

	//Inserting a user's personal data into an array//
	strcpy(temp, std.num_id);
	strcat(temp, "-");
	strcat(temp, std.name);
	strcat(temp, "-");
	strcat(temp, std.last_name);
	strcat(temp, "-");
	strcat(temp, std.listed_courses);
	strcat(temp, "-");
	strcat(temp, std.exames);
	strcat(temp, "-");
	strcat(temp, std.bill);
	strcat(temp, "-");
	strcat(temp, std.birthday);
	strcat(temp, "-");
	strcat(temp, std.mail);
	strcat(temp, "-");
	strcat(temp, std.adress);
	strcat(temp, "-");
	strcat(temp, std.telephone);
	strcat(temp, "$");

	//printf("%s\n", temp);
	if (strcmp(department_std, "students software") == 0 && strcmp(number_semester_std, "a") == 0)
	{
		fp = fopen("students software-a.txt", "r");
		if (fp == NULL)
		{
			printf(" unable to open file \n");
			exit(1);
		}
		fseek(fp, 0, SEEK_SET);
	}
	else if (strcmp(department_std, "students software") == 0 && strcmp(number_semester_std, "b") == 0)
	{
		fp = fopen("students software-b.txt", "r");
		if (fp == NULL)
		{
			printf(" unable to open file \n");
			exit(1);
		}
		fseek(fp, 0, SEEK_SET);
	}
	else if ((strcmp(department_std, "students electrical") == 0) && (strcmp(number_semester_std, "a") == 0))
	{
		fp = fopen("students electrical-a.txt", "r");
		if (fp == NULL)
		{
			printf(" unable to open file \n");
			exit(1);
		}
		fseek(fp, 0, SEEK_SET);
	}
	else if ((strcmp(department_std, "students electrical") == 0) && (strcmp(number_semester_std, "b") == 0))
	{
		fp = fopen("students electrical-b.txt", "r");
		if (fp == NULL)
		{
			printf(" unable to open file \n");
			exit(1);
		}
		fseek(fp, 0, SEEK_SET);
	}


	// Copy text file contents into an array//
	for (i = 0; !feof(fp); i++)
	{
		stdTemp[i] = fgetc(fp);
	}
	stdTemp[i - 1] = '\0';

	index = stringSearch(stdTemp, temp);

	if (index != -1) // stdTemp contine temp, Delete the user's details from the array//
	{
		for (k = 0; temp[k] != '\0'; k++);
		{
			for (i = index; stdTemp[i] != '\0'; i++)
			{
				stdTemp[i] = stdTemp[i + k + 1];
			}
		}
		stdTemp[i] = '\0';
		fclose(fp);
		if (strcmp(department_std, "students software") == 0 && strcmp(number_semester_std, "a") == 0)
		{
			//Enter the details of the new data into the file//
			fp = fopen("students software-a.txt", "w+");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}
			fprintf(fp, "%s", stdTemp);
			printf("Deletion confirmed, user deleted from database\n");
			fclose(fp);
		}
		else if (strcmp(department_std, "students software") == 0 && strcmp(number_semester_std, "b") == 0)
		{
			//Enter the details of the new data into the file//
			fp = fopen("students software-b.txt", "w+");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}
			fprintf(fp, "%s", stdTemp);
			printf("Deletion confirmed, user deleted from database\n");
			fclose(fp);
		}
		else if ((strcmp(department_std, "students electrical") == 0) && (strcmp(number_semester_std, "a") == 0))
		{
			//Enter the details of the new data into the file//
			fp = fopen("students electrical-a.txt", "w+");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}
			fprintf(fp, "%s", stdTemp);
			printf("Deletion confirmed, user deleted from database\n");
			fclose(fp);
		}
		else if ((strcmp(department_std, "students electrical") == 0) && (strcmp(number_semester_std, "b") == 0))
		{
			//Enter the details of the new data into the file//
			fp = fopen("students electrical-b.txt", "w+");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}
			fprintf(fp, "%s", stdTemp);
			printf("Deletion confirmed, user deleted from database\n");
			fclose(fp);
		}
	}
	else
	{
		fclose(fp);
	}
} //A function that deletes student information from the appropriate database//

//*************Data manager functions end************

//***********Student functions **********************
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
	int z = 0, flag=0;
	for (int l = 0; l < num_students; l++) {
		if (strcmp(id, student1[l].num_id) == 0) {
			flag = 1;
			if (course_num[0] == student1[l].listed_courses[z] && course_num[1] == student1[l].listed_courses[z + 1] && course_num[2] == student1[l].listed_courses[z + 2] && course_num[3] == student1[l].listed_courses[z + 3] && course_num[4] == student1[l].listed_courses[z + 4]) {
				printf("Choose another course, you already registered:\n");
				scanf("%s", &course_num);
			}
		}
	}
	if (flag == 0)
	{
		printf("You are not in this semester por department, please check again.\n");
		return;
	}
	else
		printf("You have successfully signed for Course.\n");
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
	int flag1 = 0, e = 0;
	for (e = 0; e < SIZE; e++) 
	{
		if (array_index[e] != -1)
		{
			if (strcmp(course_num, courses_reg[array_index[d]].course_num) == 0)
				flag1 = 1;
		}
	}
	if (flag1 == 0)
	{
		printf("You don't have such registered couse. Try again.\n");
		return;
	}
	else
		printf("You successfully deleted the course.\n");

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
			for (int i = 0; i < (int)strlen(courses_reg[array_index[d]].exames_date); i++) {
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
	printf("Please enter an option for the report:1-Failed courses\n");
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
// Student menu
void StudentMenu(char* id)
{
	int option = 0; //the choice of the user
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
			UpdateDetails();
			break;
		case 8:
			StudentReports(id);
			break;
		case 9:
			StudentHelp();
			break;
		default:
			if (option < 1 || option>10)
				printf("Please choose another option\n");
		}
	} while (option != 10); //when you choose exit it will exit the program and loop
}

void UpdateDetails()
{
	int choice, i = 0, j = 0, k = 0, len = 0, numbStd = 0, stdExist = 0, index = 0;
	struct Students Student[1000];
	char  stdTemp[2000], number_semester[35], department[35], ID_std[10];
	FILE* fp;
	fp = NULL;
	char ID_std_[10];
	char first_name_std_[7];
	char last_name_std_[7];
	char Date_of_birth_std_[9];
	char Address_std_[25];
	int phone_std_[11];
	char Email_std_[20];
	char exames_std_[200];
	char courses_std_[100];
	char bill_std_[10];

	printf("\nEnter number semester:\n");
	scanf("%s", &number_semester);
	getchar();
	printf("Enter department:\n");
	fgets(department, 35, stdin);
	i = 0;
	while (department[i] != '\n')
		i++;
	if (department[i] == '\n')
		department[i] = '\0';

	/**********************************/

	//Open a file to read//
	if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
		fp = fopen("students software-b.txt", "r");

	else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
		fp = fopen("students software-a.txt", "r");

	else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
		fp = fopen("students electrical-a.txt", "r");

	else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
		fp = fopen("students electrical-b.txt", "r");
	if (fp == NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	// Copy text file contents into an array//
	for (i = 0; !feof(fp); i++)
	{
		stdTemp[i] = fgetc(fp);
	}
	stdTemp[i - 1] = '\0';

	printf("Enter Id:\n");
	scanf("%s", &ID_std);
	getchar();
	do {
		for (i = 0; i < (int)strlen(ID_std); i++)
		{
			if (ID_std[i] < '0' || ID_std[i]>'9' || strlen(ID_std) < 9)
			{
				printf("Please enter again ID:\n");
				scanf("%s", &ID_std);
				getchar();
			}
		}
	} while ((ID_std[i] >= '0' && ID_std[i] <= '9') && strlen(ID_std) == 9);

	//Separation of fields by using an array//
	i = 0;
	j = 0;
	k = 0;
	while (stdTemp[i] != '\0')
	{
		while (stdTemp[i] != '-')
		{
			Student[j].num_id[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].num_id[k] = '\0';
		i++;
		k = 0;
		while (stdTemp[i] != '-')
		{
			Student[j].name[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].name[k] = '\0';
		i++;
		k = 0;
		while (stdTemp[i] != '-')
		{
			Student[j].last_name[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].last_name[k] = '\0';
		i++;
		k = 0;
		while (stdTemp[i] != '-')
		{
			Student[j].listed_courses[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].listed_courses[k] = '\0';
		i++;
		k = 0;
		while (stdTemp[i] != '-')
		{
			Student[j].exames[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].exames[k] = '\0';

		i++;
		k = 0;
		while (stdTemp[i] != '-')
		{
			Student[j].bill[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].bill[k] = '\0';
		i++;
		k = 0;
		while (stdTemp[i] != '-')
		{
			Student[j].birthday[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].birthday[k] = '\0';
		i++;
		k = 0;
		while (stdTemp[i] != '-')
		{
			Student[j].mail[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].mail[k] = '\0';
		i++;
		k = 0;
		while (stdTemp[i] != '-')
		{
			Student[j].adress[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].adress[k] = '\0';
		i++;
		k = 0;
		while (stdTemp[i] != '$')
		{
			Student[j].telephone[k] = stdTemp[i];
			k++;
			i++;
		}
		Student[j].telephone[k] = '\0';

		i++;
		if (stdTemp[i] != '\0')
			i++;

		k = 0;
		j++;
		numbStd++;
	}
	printf("\n");

	i = 0;
	while (i < numbStd)
	{	//Finding an index using an ID number//
		if (strcmp(Student[i].num_id, ID_std) == 0)
		{
			stdExist = 1;
			index = i;
		}
		i++;
	}
	if (stdExist == 0)
		printf("\nThe student is not exist!!!\n");
	else
	{
		stdExist = 0;
		printf("What information you want to change? 1 for first name, 2 for last name, 3 for Date of birth,4 for phone, 5 for Address, 6 for Email\n");
		scanf("%d", &choice);
		//Select a field of structure to change//
		switch (choice)
		{
		case 1:
		{
			printf("change first name:\n");
			getchar();
			fgets(first_name_std_, SIZE4, stdin);
			i = 0;
			while (first_name_std_[i] != '\n')
				i++;
			if (first_name_std_[i] == '\n')
				first_name_std_[i] = '\0';
			break;
		}
		case 2:
		{
			printf("change last name:\n");
			getchar();
			fgets(last_name_std_, SIZE4, stdin);
			i = 0;
			while (last_name_std_[i] != '\n')
				i++;
			if (last_name_std_[i] == '\n')
				last_name_std_[i] = '\0';
			break;
		}
		case 3:
		{
			printf("change  Date of birth:\n");
			getchar();
			fgets(Date_of_birth_std_, SIZE4, stdin);
			i = 0;
			while (Date_of_birth_std_[i] != '\n')
				i++;
			if (Date_of_birth_std_[i] == '\n')
				Date_of_birth_std_[i] = '\0';
			break;
		}
		case 4:
		{
			printf("change phone:\n");
			scanf("%s", &phone_std_);
			getchar();
			break;
		}
		case 5:
		{
			printf("change Address:\n");
			getchar();
			fgets(Address_std_, SIZE4, stdin);
			i = 0;
			while (Address_std_[i] != '\n')
				i++;
			if (Address_std_[i] == '\n')
				Address_std_[i] = '\0';
			break;
		}
		case 6:
		{
			printf("change Email:\n");
			scanf("%s", &Email_std_);
			getchar();
			break;
		}
		default:
		{
			if (choice < 1 || choice > 6)
				printf("Invalid choice.\n");
			break;
		}

		}

		/***********************************************/
			//Update the new value in the field of the structure//
		i = 0;
		j = 0;
		if (choice == 1)
		{
			while (first_name_std_[i] != '\0')
			{
				Student[index].name[j] = first_name_std_[i];
				i++;
				j++;
			}
			Student[index].name[j] = first_name_std_[i];
		}
		/***********************************************/
		i = 0;
		j = 0;
		if (choice == 2)
		{
			while (last_name_std_[i] != '\0')
			{
				Student[index].last_name[j] = last_name_std_[i];
				i++;
				j++;
			}
			Student[index].last_name[j] = last_name_std_[i];
		}
		/***********************************************/
		i = 0;
		j = 0;
		if (choice == 3)
		{
			while (Date_of_birth_std_[i] != '\0')
			{
				Student[index].birthday[j] = Date_of_birth_std_[i];
				i++;
				j++;
			}
			Student[index].birthday[j] = Date_of_birth_std_[i];
		}
		/***********************************************/
		i = 0;
		j = 0;
		if (choice == 4)
		{
			while (phone_std_[i] != '\0')
			{
				Student[index].telephone[j] = phone_std_[i];
				i++;
				j++;
			}
			Student[index].telephone[j] = phone_std_[i];
		}
		/***********************************************/
		i = 0;
		j = 0;
		if (choice == 5)
		{
			while (Address_std_[i] != '\0')
			{
				Student[index].adress[j] = Address_std_[i];
				i++;
				j++;
			}
			Student[index].adress[j] = Address_std_[i];
		}
		/***********************************************/
		i = 0;
		j = 0;
		if (choice == 6)
		{
			while (Email_std_[i] != '\0')
			{
				Student[index].mail[j] = Email_std_[i];
				i++;
				j++;
			}
			Student[index].mail[j] = Email_std_[i];
		}
		i = 0;
		j = 0;

		//Open a file to write//
		if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
			fp = fopen("students software-b.txt", "w+");

		else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
			fp = fopen("students software-a.txt", "w+");

		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
			fp = fopen("students electrical-a.txt", "w+");

		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
			fp = fopen("students electrical-b.txt", "w+");

		/*******************************************************************************/
		//Enter the new values ​​from the structure to a text file//
		while (j < numbStd)
		{
			for (k = 0; Student[j].num_id[k] != '\0'; k++)
				fputc(Student[j].num_id[k], fp);

			if (Student[j].num_id[k] == '\0')
			{
				fputc('-', fp);
			}
			/****************************************************/
			for (k = 0; Student[j].name[k] != '\0'; k++)
				fputc(Student[j].name[k], fp);

			if (Student[j].name[k] == '\0')
			{
				fputc('-', fp);
			}
			/*****************************************************/
			for (k = 0; Student[j].last_name[k] != '\0'; k++)
				fputc(Student[j].last_name[k], fp);

			if (Student[j].last_name[k] == '\0')
			{
				fputc('-', fp);
			}
			/*****************************************************/
			for (k = 0; Student[j].listed_courses[k] != '\0'; k++)
				fputc(Student[j].listed_courses[k], fp);

			if (Student[j].listed_courses[k] == '\0')
			{
				fputc('-', fp);
			}
			/*****************************************************/
			for (k = 0; Student[j].exames[k] != '\0'; k++)
				fputc(Student[j].exames[k], fp);

			if (Student[j].exames[k] == '\0')
			{
				fputc('-', fp);
			}
			/*****************************************************/
			for (k = 0; Student[j].bill[k] != '\0'; k++)
				fputc(Student[j].bill[k], fp);

			if (Student[j].bill[k] == '\0')
			{
				fputc('-', fp);
			}
			/*****************************************************/
			for (k = 0; Student[j].birthday[k] != '\0'; k++)
				fputc(Student[j].birthday[k], fp);

			if (Student[j].birthday[k] == '\0')
			{
				fputc('-', fp);
			}
			/*****************************************************/
			for (k = 0; Student[j].mail[k] != '\0'; k++)
				fputc(Student[j].mail[k], fp);

			if (Student[j].mail[k] == '\0')
			{
				fputc('-', fp);
			}
			/*****************************************************/
			for (k = 0; Student[j].adress[k] != '\0'; k++)
				fputc(Student[j].adress[k], fp);

			if (Student[j].adress[k] == '\0')
			{
				fputc('-', fp);
			}
			/*****************************************************/
			for (k = 0; Student[j].telephone[k] != '\0'; k++)
				fputc(Student[j].telephone[k], fp);

			if (Student[j].telephone[k] == '\0')
			{
				fputc('$', fp);
				fputc('\n', fp);
			}
			j++;
		}
	}

	fclose(fp);
}
//***********Student functions end*******************

//*************Registration manager(coordinator) functions************
void update_exam_date()
{
	FILE *fptr1 = NULL;
	struct Courses courses[100];
	char temp_arr[2000];
	char department[35];
	char semester;
	char _course_num[6];
	int i = 0, j = 0, k = 0;
	int num_courses = 0;
	int course_exist = 0;
	int index;
	int choice;
	char new_date[10];
	char moed_A[10];
	char moed_B[10];
	//char moed_test[10];
	int user_choice1 = 0;

	printf("\nFor department courses press 1\nFor main courses press 2 \n");
	scanf("%d", &user_choice1);

	while (user_choice1 != 1 && user_choice1 != 2)
	{
		printf("\nInvalid choice!!!\nFor department courses press 1\nFor main courses press 2 \n");
		scanf("%d", &user_choice1);
	}
	//**************************************************************
	printf("Enter department :");
	scanf("%s", &department);


	//**************************************************************
	printf("Enter semester :");
	getchar();
	scanf("%c", &semester);

	//**************************************************************
	if (user_choice1 == 1)
	{
		if (strcmp(department, "software") == 0 && semester == 'a')
			fptr1 = fopen("courses software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr1 = fopen("courses software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr1 = fopen("courses electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr1 = fopen("courses electrical-a.txt", "r");
	}
	else if (user_choice1 == 2)
		fptr1 = fopen("choice_courses.txt", "r");

	//**************************************************************
	if (fptr1 == NULL)
	{
		printf("ERROR\n");
		exit(1);

	}
	//**************************************************************
	printf("Enter course number :");
	scanf("%s", &_course_num);
	//**************************************************************
	i = 0;
	while (!feof(fptr1))
	{
		temp_arr[i] = fgetc(fptr1);
		i++;
	}
	temp_arr[i - 1] = '\0';
	fclose(fptr1);
	//**************************************************************

	i = 0;
	j = 0;
	k = 0;
	while (temp_arr[i] != '\0')
	{
		while (temp_arr[i] != '-')
		{
			courses[j].course_num[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_num[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].course_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].department[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].department[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].points[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].points[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecturer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecturer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].trainer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].trainer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecture_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecture_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].practice_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].practice_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].name_previous_courses[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].name_previous_courses[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].home_work[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].home_work[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].exames_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].exames_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].test_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].test_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '$')
		{
			courses[j].places[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].places[k] = '\0';
		//**************************************************************
		i++;
		if (temp_arr[i] != '\0')
			i++;

		k = 0;
		j++;
		num_courses++;

	}
	printf("\n");

	i = 0;
	while (i < num_courses)
	{
		if (strcmp(courses[i].course_num, _course_num) == 0)
		{
			course_exist = 1;
			index = i;
		}
		i++;
	}
	if (course_exist == 0)
		printf("\nThe course dont exist!!!\n");

	else
	{
		i = 0;
		k = 0;
		while (courses[index].exames_date[i] != ',')
		{
			moed_A[k] = courses[index].exames_date[i];
			i++;
			k++;
		}
		moed_A[k] = '\0';
		i++;
		k = 0;
		while (courses[index].exames_date[i] != '\0')
		{
			moed_B[k] = courses[index].exames_date[i];
			i++;
			k++;
		}
		moed_B[k] = '\0';

		printf("Enter new date :");
		scanf("%s", &new_date);
		printf("\nTo change exam moed A date press 1\nTo change exam moed B date press 2\nTo change test date press 3\n ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			i = 0;
			k = 0;
			while (new_date[i] != '\0')
			{
				courses[index].exames_date[k] = new_date[i];
				i++;
				k++;
			}
			courses[index].exames_date[k] = ',';
			i = 0;
			k++;
			while (moed_B[i] != '\0')
			{
				courses[index].exames_date[k] = moed_B[i];
				i++;
				k++;
			}
			courses[index].exames_date[k] = '\0';
		}

		if (choice == 2)
		{
			i = 0;
			k = 0;
			while (moed_A[i] != '\0')
			{
				courses[index].exames_date[k] = moed_A[i];
				i++;
				k++;
			}
			courses[index].exames_date[k] = ',';
			i = 0;
			k++;
			while (new_date[i] != '\0')
			{
				courses[index].exames_date[k] = new_date[i];
				i++;
				k++;
			}
			courses[index].exames_date[k] = '\0';
		}

		if (choice == 3)
		{
			i = 0;
			k = 0;
			while (new_date[i] != '\0')
			{
				courses[index].test_date[k] = new_date[i];
				i++;
				k++;
			}
			courses[index].test_date[k] = '\0';
		}

		fclose(fptr1);
		if (user_choice1 == 1)
		{
			if (strcmp(department, "software") == 0 && semester == 'a')
				fptr1 = fopen("courses software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr1 = fopen("courses software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr1 = fopen("courses electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr1 = fopen("courses electrical-a.txt", "w+");
		}
		if (user_choice1 == 2)
			fptr1 = fopen("choice_courses.txt", "w+");

		j = 0;
		while (j < num_courses)
		{
			for (k = 0; courses[j].course_num[k] != '\0'; k++)
				fputc(courses[j].course_num[k], fptr1);

			if (courses[j].course_num[k] == '\0')
			{
				fputc('-', fptr1);
			}


			//**************************************************************
			for (k = 0; courses[j].course_name[k] != '\0'; k++)
				fputc(courses[j].course_name[k], fptr1);


			if (courses[j].course_name[k] == '\0')
			{
				fputc('-', fptr1);
			}

			//**************************************************************
			for (k = 0; courses[j].department[k] != '\0'; k++)
				fputc(courses[j].department[k], fptr1);


			if (courses[j].department[k] == '\0')
			{
				fputc('-', fptr1);
			}

			//**************************************************************
			for (k = 0; courses[j].points[k] != '\0'; k++)
				fputc(courses[j].points[k], fptr1);


			if (courses[j].points[k] == '\0')
			{
				fputc('-', fptr1);
			}

			//**************************************************************
			for (k = 0; courses[j].lecturer_name[k] != '\0'; k++)
				fputc(courses[j].lecturer_name[k], fptr1);


			if (courses[j].lecturer_name[k] == '\0')
			{
				fputc('-', fptr1);
			}

			//**************************************************************
			for (k = 0; courses[j].trainer_name[k] != '\0'; k++)
				fputc(courses[j].trainer_name[k], fptr1);


			if (courses[j].trainer_name[k] == '\0')
			{
				fputc('-', fptr1);
			}

			//**************************************************************
			for (k = 0; courses[j].lecture_time[k] != '\0'; k++)
				fputc(courses[j].lecture_time[k], fptr1);


			if (courses[j].lecture_time[k] == '\0')
			{
				fputc('-', fptr1);
			}
			//**************************************************************
			for (k = 0; courses[j].practice_time[k] != '\0'; k++)
				fputc(courses[j].practice_time[k], fptr1);


			if (courses[j].practice_time[k] == '\0')
			{
				fputc('-', fptr1);
			}

			//**************************************************************
			for (k = 0; courses[j].name_previous_courses[k] != '\0'; k++)
				fputc(courses[j].name_previous_courses[k], fptr1);


			if (courses[j].name_previous_courses[k] == '\0')
			{
				fputc('-', fptr1);
			}
			//**************************************************************
			for (k = 0; courses[j].home_work[k] != '\0'; k++)
				fputc(courses[j].home_work[k], fptr1);


			if (courses[j].home_work[k] == '\0')
			{
				fputc('-', fptr1);
			}
			//**************************************************************
			for (k = 0; courses[j].exames_date[k] != '\0'; k++)
				fputc(courses[j].exames_date[k], fptr1);


			if (courses[j].exames_date[k] == '\0')
			{
				fputc('-', fptr1);
			}
			//**************************************************************
			for (k = 0; courses[j].test_date[k] != '\0'; k++)
				fputc(courses[j].test_date[k], fptr1);


			if (courses[j].test_date[k] == '\0')
			{
				fputc('-', fptr1);
			}
			//**************************************************************
			for (k = 0; courses[j].places[k] != '\0'; k++)
				fputc(courses[j].places[k], fptr1);


			if (courses[j].places[k] == '\0')
			{
				fputc('$', fptr1);
				fputc('\n', fptr1);
			}


			j++;
		}
		fclose(fptr1);
	}


};

void amount_student_report()
{
	FILE *fptr1 = NULL;
	FILE *fptr2 = NULL;
	FILE *fptr3 = NULL;
	struct Students students[500];
	struct Courses courses[100];
	char temp_arr[2000];
	char temp_arr1[10000];
	char department[35];
	char semester;
	//char course_num[6];
	char course_name[35];
	int i = 0, j = 0, k = 0;
	int num_courses = 0;
	int course_exist = 0;
	int index;
	int student_num = 0;
	int user_choice;
	char _places[20] = "Amount of students:";
	char _students[20] = "Students:";
	char _course_name[20] = "Course name:";
	char _lecturer_name[20] = "Lecturer name:";
	char _num_id[20] = "Id:";
	char _name[20] = "First name:";
	char _last_name[20] = "Last name:";
	char _listed_courses[20] = "Listed courses:";
	char _exames[20] = "Exames:";
	char _bill[20] = "Bill:";
	char _birthday[20] = "Birthday:";
	char _mail[20] = "Mail:";
	char _adress[20] = "Address:";
	char _telephone[20] = "telephone:";
	char _line[65] = "__________________________________________________________\n";
	int user_choice1 = 0;

	printf("\nFor department courses press 1\nFor main courses press 2 \n");
	scanf("%d", &user_choice1);

	while (user_choice1 != 1 && user_choice1 != 2)
	{
		printf("\nInvalid choice!!!\nFor department courses press 1\nFor main courses press 2 \n");
		scanf("%d", &user_choice1);
	}
	//**************************************************************
	printf("Enter department :");
	scanf("%s", &department);
	getchar();

	//**************************************************************
	printf("Enter semester :");
	scanf("%c", &semester);
	//**************************************************************
	if (user_choice1 == 1)
	{
		if (strcmp(department, "software") == 0 && semester == 'a')
			fptr1 = fopen("courses software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr1 = fopen("courses software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr1 = fopen("courses electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr1 = fopen("courses electrical-a.txt", "r");
	}
	if (user_choice1 == 2)
		fptr1 = fopen("choice_courses.txt", "r");
	//**************************************************************
	if (fptr1 == NULL)
	{
		fptr1 = fopen("choice_courses.txt", "r");
		if (fptr1 == NULL)
		{
			printf("ERROR\n");
			exit(1);
		}
	}
	//**************************************************************
	getchar();
	printf("Enter course name :");
	fgets(course_name, 35, stdin);
	i = 0;
	while (course_name[i] != '\n')
		i++;
	if (course_name[i] == '\n')
		course_name[i] = '\0';



	//**************************************************************
	i = 0;
	while (!feof(fptr1))
	{
		temp_arr[i] = fgetc(fptr1);
		i++;
	}
	temp_arr[i - 1] = '\0';
	fclose(fptr1);
	//**************************************************************
	i = 0;
	j = 0;
	k = 0;
	while (temp_arr[i] != '\0')
	{
		while (temp_arr[i] != '-')
		{
			courses[j].course_num[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_num[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].course_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].department[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].department[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].points[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].points[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecturer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecturer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].trainer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].trainer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecture_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecture_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].practice_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].practice_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].name_previous_courses[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].name_previous_courses[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].home_work[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].home_work[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].exames_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].exames_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].test_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].test_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '$')
		{
			courses[j].places[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].places[k] = '\0';
		//**************************************************************
		i++;
		if (temp_arr[i] != '\0')
			i++;

		k = 0;
		j++;
		num_courses++;

	}
	printf("\n");

	i = 0;
	while (i < num_courses)
	{
		if (strcmp(courses[i].course_name, course_name) == 0)
		{
			course_exist = 1;
			index = i;
		}
		i++;
	}
	if (course_exist == 0)
		printf("\nThe course dont exist!!!\n");


	else
	{
		k = 0;
		printf("Course Name:");
		while (courses[index].course_name[k] != '\0')
		{
			printf("%c", courses[index].course_name[k]);
			k++;
		}
		k = 0;
		printf("\nLecturer Name:");
		while (courses[index].lecturer_name[k] != '\0')
		{
			printf("%c", courses[index].lecturer_name[k]);
			k++;
		}
		k = 0;
		printf("\nAmount of students in the course:");
		while (courses[index].places[k] != '\0')
		{
			printf("%c", courses[index].places[k]);
			k++;
		}


		//**************************************************************
		if (strcmp(department, "software") == 0 && semester == 'a')
			fptr2 = fopen("students software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr2 = fopen("students software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr2 = fopen("students electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr2 = fopen("students electrical-a.txt", "r");
		//**************************************************************
		if (fptr2 == NULL)
		{
			printf("ERROR\n");
			exit(1);
		}
		//**************************************************************
		i = 0;
		while (!feof(fptr2))
		{
			temp_arr1[i] = fgetc(fptr2);
			i++;
		}
		temp_arr1[i - 1] = '\0';
		fclose(fptr2);


		//**************************************************************
		i = 0;
		j = 0;
		k = 0;
		while (temp_arr1[i] != '\0')
		{
			while (temp_arr1[i] != '-')
			{
				students[j].num_id[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].num_id[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				students[j].name[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].name[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				students[j].last_name[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].last_name[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				students[j].listed_courses[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].listed_courses[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				students[j].exames[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].exames[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				students[j].bill[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].bill[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				students[j].birthday[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].birthday[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				students[j].mail[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].mail[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				students[j].adress[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].adress[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '$')
			{
				students[j].telephone[k] = temp_arr1[i];
				k++;
				i++;
			}
			students[j].telephone[k] = '\0';
			//**************************************************************
			i++;
			if (temp_arr1[i] != '\0')
				i++;

			k = 0;
			j++;
			student_num++;
		}

		//**************************************************************

		printf("\nStudents:\n");
		i = 0;
		while (i < student_num)
		{
			printf("\n%d)", i + 1);
			//**************************************************************
			printf("\nId:");
			k = 0;
			while (students[i].num_id[k] != '\0')
			{
				printf("%c", students[i].num_id[k]);
				k++;
			}
			//**************************************************************
			printf("\nFirst name:");
			k = 0;
			while (students[i].name[k] != '\0')
			{
				printf("%c", students[i].name[k]);
				k++;
			}
			//**************************************************************
			printf("\nLast name:");
			k = 0;
			while (students[i].last_name[k] != '\0')
			{
				printf("%c", students[i].last_name[k]);
				k++;
			}
			//**************************************************************
			printf("\nListed courses:");
			k = 0;
			while (students[i].listed_courses[k] != '\0')
			{
				printf("%c", students[i].listed_courses[k]);
				k++;
			}
			//**************************************************************
			printf("\nExames:");
			k = 0;
			while (students[i].exames[k] != '\0')
			{
				printf("%c", students[i].exames[k]);
				k++;
			}
			//**************************************************************
			printf("\nBill:");
			k = 0;
			while (students[i].bill[k] != '\0')
			{
				printf("%c", students[i].bill[k]);
				k++;
			}
			//**************************************************************
			printf("\nBirthday:");
			k = 0;
			while (students[i].birthday[k] != '\0')
			{
				printf("%c", students[i].birthday[k]);
				k++;
			}
			//**************************************************************
			printf("\nMail:");
			k = 0;
			while (students[i].mail[k] != '\0')
			{
				printf("%c", students[i].mail[k]);
				k++;
			}
			//**************************************************************
			printf("\nAdress:");
			k = 0;
			while (students[i].adress[k] != '\0')
			{
				printf("%c", students[i].adress[k]);
				k++;
			}
			//**************************************************************
			printf("\nTelephone:");
			k = 0;
			while (students[i].telephone[k] != '\0')
			{
				printf("%c", students[i].telephone[k]);
				k++;
			}
			printf("\n---------------------------------------------------\n");
			i++;
		}

		printf("\nDo you wanna save this information in file?\nIf yes press 1:\n");
		scanf("%d", &user_choice);
		if (user_choice == 1)
		{
			fptr3 = fopen("amount student report.txt", "w+");
			if (fptr3 == NULL)
			{
				printf("ERROR\n");
				exit(1);
			}
			//**************************************************************
			for (k = 0; _course_name[k] != '\0'; k++)
				fputc(_course_name[k], fptr3);
			for (k = 0; courses[index].course_name[k] != '\0'; k++)
				fputc(courses[index].course_name[k], fptr3);
			if (courses[index].course_name[k] == '\0')
				fputc('\n', fptr3);
			//**************************************************************	
			for (k = 0; _lecturer_name[k] != '\0'; k++)
				fputc(_lecturer_name[k], fptr3);
			for (k = 0; courses[index].lecturer_name[k] != '\0'; k++)
				fputc(courses[index].lecturer_name[k], fptr3);
			if (courses[index].lecturer_name[k] == '\0')
				fputc('\n', fptr3);
			//**************************************************************
			for (k = 0; _places[k] != '\0'; k++)
				fputc(_places[k], fptr3);
			for (k = 0; courses[index].places[k] != '\0'; k++)
				fputc(courses[index].places[k], fptr3);
			if (courses[index].places[k] == '\0')
				fputc('\n', fptr3);
			//**************************************************************
			for (k = 0; _line[k] != '\0'; k++)
				fputc(_line[k], fptr3);
			for (k = 0; _students[k] != '\0'; k++)
				fputc(_students[k], fptr3);
			fputc('\n', fptr3);

			j = 0;
			while (j < student_num)
			{
				for (k = 0; _num_id[k] != '\0'; k++)
					fputc(_num_id[k], fptr3);
				for (k = 0; students[j].num_id[k] != '\0'; k++)
					fputc(students[j].num_id[k], fptr3);
				if (students[j].num_id[k] == '\0')
					fputc('\n', fptr3);
				//**************************************************************
				for (k = 0; _name[k] != '\0'; k++)
					fputc(_name[k], fptr3);
				for (k = 0; students[j].name[k] != '\0'; k++)
					fputc(students[j].name[k], fptr3);
				if (students[j].name[k] == '\0')
					fputc('\n', fptr3);

				//**************************************************************
				for (k = 0; _last_name[k] != '\0'; k++)
					fputc(_last_name[k], fptr3);
				for (k = 0; students[j].last_name[k] != '\0'; k++)
					fputc(students[j].last_name[k], fptr3);
				if (students[j].last_name[k] == '\0')
					fputc('\n', fptr3);

				//**************************************************************
				for (k = 0; _listed_courses[k] != '\0'; k++)
					fputc(_listed_courses[k], fptr3);
				for (k = 0; students[j].listed_courses[k] != '\0'; k++)
					fputc(students[j].listed_courses[k], fptr3);
				if (students[j].listed_courses[k] == '\0')
					fputc('\n', fptr3);

				//**************************************************************
				for (k = 0; _exames[k] != '\0'; k++)
					fputc(_exames[k], fptr3);
				for (k = 0; students[j].exames[k] != '\0'; k++)
					fputc(students[j].exames[k], fptr3);
				if (students[j].exames[k] == '\0')
					fputc('\n', fptr3);

				//**************************************************************
				for (k = 0; _bill[k] != '\0'; k++)
					fputc(_bill[k], fptr3);
				for (k = 0; students[j].bill[k] != '\0'; k++)
					fputc(students[j].bill[k], fptr3);
				if (students[j].bill[k] == '\0')
					fputc('\n', fptr3);

				//**************************************************************
				for (k = 0; _birthday[k] != '\0'; k++)
					fputc(_birthday[k], fptr3);
				for (k = 0; students[j].birthday[k] != '\0'; k++)
					fputc(students[j].birthday[k], fptr3);
				if (students[j].birthday[k] == '\0')
					fputc('\n', fptr3);
				//**************************************************************
				for (k = 0; _mail[k] != '\0'; k++)
					fputc(_mail[k], fptr3);
				for (k = 0; students[j].mail[k] != '\0'; k++)
					fputc(students[j].mail[k], fptr3);
				if (students[j].mail[k] == '\0')
					fputc('\n', fptr3);

				//**************************************************************
				for (k = 0; _adress[k] != '\0'; k++)
					fputc(_adress[k], fptr3);
				for (k = 0; students[j].adress[k] != '\0'; k++)
					fputc(students[j].adress[k], fptr3);
				if (students[j].adress[k] == '\0')
					fputc('\n', fptr3);
				//**************************************************************
				for (k = 0; _telephone[k] != '\0'; k++)
					fputc(_telephone[k], fptr3);
				for (k = 0; students[j].telephone[k] != '\0'; k++)
					fputc(students[j].telephone[k], fptr3);
				if (students[j].telephone[k] == '\0')
					fputc('\n', fptr3);

				for (k = 0; _line[k] != '\0'; k++)
					fputc(_line[k], fptr3);

				j++;
			}
			fclose(fptr3);
		}

	}



};

void full_course() {

	FILE *fptr1 = NULL;
	FILE *fptr2 = NULL;
	struct Students students[500];
	struct Courses courses[100];
	char temp_arr[10000];
	char temp_arr1[2000];
	char _num_id[10];
	char department[35];
	char semester;
	int i = 0, j = 0, k = 0;
	int student_num = 0;
	int student_exist = 0;
	int index;
	char course_num[6];
	int num_courses = 0;
	int course_exist = 0;
	int _index;
	char num_places[3];
	char zero[2] = "0";



	//**************************************************************
	printf("Enter student id :");
	scanf("%s", &_num_id);
	getchar();
	//**************************************************************
	printf("Enter department :");
	scanf("%s", &department);
	getchar();
	//**************************************************************
	printf("Enter semester :");
	scanf("%c", &semester);
	//**************************************************************
	if (strcmp(department, "software") == 0 && semester == 'a')
		fptr1 = fopen("students software-a.txt", "r");
	if (strcmp(department, "software") == 0 && semester == 'b')
		fptr1 = fopen("students software-b.txt", "r");
	if (strcmp(department, "electrical") == 0 && semester == 'b')
		fptr1 = fopen("students electrical-b.txt", "r");
	if (strcmp(department, "electrical") == 0 && semester == 'a')
		fptr1 = fopen("students electrical-a.txt", "r");
	//**************************************************************
	if (fptr1 == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	//**************************************************************
	i = 0;
	while (!feof(fptr1))
	{
		temp_arr[i] = fgetc(fptr1);
		i++;
	}
	temp_arr[i - 1] = '\0';
	//**************************************************************
	i = 0;
	j = 0;
	k = 0;
	while (temp_arr[i] != '\0')
	{
		while (temp_arr[i] != '-')
		{
			students[j].num_id[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].num_id[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].name[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].last_name[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].last_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].listed_courses[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].listed_courses[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].exames[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].exames[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].bill[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].bill[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].birthday[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].birthday[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].mail[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].mail[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].adress[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].adress[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '$')
		{
			students[j].telephone[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].telephone[k] = '\0';
		//**************************************************************
		i++;
		if (temp_arr[i] != '\0')
			i++;

		k = 0;
		j++;
		student_num++;
	}
	printf("\n");
	//**************************************************************
	i = 0;
	while (i < student_num)
	{
		if (strcmp(students[i].num_id, _num_id) == 0)
		{
			student_exist = 1;
			index = i;
		}
		i++;
	}
	//**************************************************************
	if (student_exist == 0)
		printf("\nThe student %s is not exist!!!\n", _num_id);
	//**************************************************************
	else
	{
		printf("The student information:\n");
		printf("Id:");
		k = 0;
		while (students[index].num_id[k] != '\0')
		{
			printf("%c", students[index].num_id[k]);
			k++;
		}
		//**************************************************************
		printf("\nFirst name:");
		k = 0;
		while (students[index].name[k] != '\0')
		{
			printf("%c", students[index].name[k]);
			k++;
		}
		//**************************************************************
		printf("\nLast name:");
		k = 0;
		while (students[index].last_name[k] != '\0')
		{
			printf("%c", students[index].last_name[k]);
			k++;
		}
		//**************************************************************
		printf("\nListed courses:");
		k = 0;
		while (students[index].listed_courses[k] != '\0')
		{
			printf("%c", students[index].listed_courses[k]);
			k++;
		}
		//**************************************************************
		printf("\nExames:");
		k = 0;
		while (students[index].exames[k] != '\0')
		{
			printf("%c", students[index].exames[k]);
			k++;
		}
		//**************************************************************
		printf("\nBill:");
		k = 0;
		while (students[index].bill[k] != '\0')
		{
			printf("%c", students[index].bill[k]);
			k++;
		}
		//**************************************************************
		printf("\nBirthday:");
		k = 0;
		while (students[index].birthday[k] != '\0')
		{
			printf("%c", students[index].birthday[k]);
			k++;
		}
		//**************************************************************
		printf("\nMail:");
		k = 0;
		while (students[index].mail[k] != '\0')
		{
			printf("%c", students[index].mail[k]);
			k++;
		}
		//**************************************************************
		printf("\nAdress:");
		k = 0;
		while (students[index].adress[k] != '\0')
		{
			printf("%c", students[index].adress[k]);
			k++;
		}
		//**************************************************************
		printf("\nTelephone:");
		k = 0;
		while (students[index].telephone[k] != '\0')
		{
			printf("%c", students[index].telephone[k]);
			k++;
		}
		printf("\n");
		//**************************************************************
		printf("Enter course number (5 digits) :");
		scanf("%s", &course_num);
		getchar();
		//**************************************************************

		if (strcmp(department, "software") == 0 && semester == 'a')
			fptr2 = fopen("courses software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr2 = fopen("courses software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr2 = fopen("courses electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr2 = fopen("courses electrical-a.txt", "r");

		//**************************************************************
		if (fptr2 == NULL)
		{
			printf("ERROR\n");
			exit(1);
		}
		//**************************************************************	
		i = 0;
		while (!feof(fptr2))
		{
			temp_arr1[i] = fgetc(fptr2);
			i++;
		}
		temp_arr1[i - 1] = '\0';
		//**************************************************************	
		i = 0;
		j = 0;
		k = 0;
		while (temp_arr1[i] != '\0')
		{
			while (temp_arr1[i] != '-')
			{
				courses[j].course_num[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].course_num[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].course_name[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].course_name[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].department[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].department[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].points[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].points[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].lecturer_name[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].lecturer_name[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].trainer_name[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].trainer_name[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].lecture_time[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].lecture_time[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].practice_time[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].practice_time[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].name_previous_courses[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].name_previous_courses[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].home_work[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].home_work[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].exames_date[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].exames_date[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].test_date[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].test_date[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '$')
			{
				courses[j].places[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].places[k] = '\0';
			//**************************************************************
			i++;
			if (temp_arr1[i] != '\0')
				i++;

			k = 0;
			j++;
			num_courses++;
		}
		printf("\n");
		//**************************************************************
		i = 0;
		while (i < num_courses)
		{
			if (strcmp(courses[i].course_num, course_num) == 0)
			{
				course_exist = 1;
				_index = i;
			}
			i++;
		}
		//**************************************************************
		if (course_exist == 0)
			printf("\nThe course %s  is not exist!!!\n", course_num);
		//**************************************************************
		else
		{

			if (strcmp(courses[_index].places, zero) == 0)
			{
				printf("The course is full!!!\n");
				fclose(fptr1);
				fclose(fptr2);
				exit(1);
			}


			j = 0;
			printf("\nNumber of places in course:\n");
			while (courses[_index].places[j] != '\0')
			{
				printf("%c", courses[_index].places[j]);
				j++;
			}
			printf("\nEnter new number of places in course:\n");
			scanf("%s", &num_places);
			getchar();
			i = 0;
			j = 0;
			while (num_places[i] != '\0')
			{
				courses[_index].places[j] = num_places[i];
				i++;
				j++;
			}
			courses[_index].places[j] = num_places[i];
			fclose(fptr2);
			//**************************************************************

			if (strcmp(department, "software") == 0 && semester == 'a')
				fptr1 = fopen("courses software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr1 = fopen("courses software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr1 = fopen("courses electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr1 = fopen("courses electrical-a.txt", "w+");

			//**************************************************************
			j = 0;
			while (j < num_courses)
			{
				for (k = 0; courses[j].course_num[k] != '\0'; k++)
					fputc(courses[j].course_num[k], fptr2);

				if (courses[j].course_num[k] == '\0')
				{
					fputc('-', fptr2);
				}


				//**************************************************************
				for (k = 0; courses[j].course_name[k] != '\0'; k++)
					fputc(courses[j].course_name[k], fptr2);


				if (courses[j].course_name[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].department[k] != '\0'; k++)
					fputc(courses[j].department[k], fptr2);


				if (courses[j].department[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].points[k] != '\0'; k++)
					fputc(courses[j].points[k], fptr2);


				if (courses[j].points[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].lecturer_name[k] != '\0'; k++)
					fputc(courses[j].lecturer_name[k], fptr2);


				if (courses[j].lecturer_name[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].trainer_name[k] != '\0'; k++)
					fputc(courses[j].trainer_name[k], fptr2);


				if (courses[j].trainer_name[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].lecture_time[k] != '\0'; k++)
					fputc(courses[j].lecture_time[k], fptr2);


				if (courses[j].lecture_time[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].practice_time[k] != '\0'; k++)
					fputc(courses[j].practice_time[k], fptr2);


				if (courses[j].practice_time[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].name_previous_courses[k] != '\0'; k++)
					fputc(courses[j].name_previous_courses[k], fptr2);


				if (courses[j].name_previous_courses[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].home_work[k] != '\0'; k++)
					fputc(courses[j].home_work[k], fptr2);


				if (courses[j].home_work[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].exames_date[k] != '\0'; k++)
					fputc(courses[j].exames_date[k], fptr2);


				if (courses[j].exames_date[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].test_date[k] != '\0'; k++)
					fputc(courses[j].test_date[k], fptr2);


				if (courses[j].test_date[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].places[k] != '\0'; k++)
					fputc(courses[j].places[k], fptr2);


				if (courses[j].places[k] == '\0')
				{
					fputc('$', fptr2);
					fputc('\n', fptr2);
				}


				j++;
			}
			fclose(fptr2);
			//**************************************************************
			i = 0;
			j = 0;
			k = 0;

			while (students[index].listed_courses[k] != '\0')
				k++;
			while (course_num[i] != '\0')
			{
				students[index].listed_courses[k] = course_num[i];
				i++;
				k++;
			}
			students[index].listed_courses[k] = ',';
			k++;
			students[index].listed_courses[k] = '\0';

			fclose(fptr1);
			//**************************************************************
			if (strcmp(department, "software") == 0 && semester == 'a')
				fptr1 = fopen("students software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr1 = fopen("students software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr1 = fopen("students electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr1 = fopen("students electrical-a.txt", "w+");
			//**************************************************************
			i = 0;
			j = 0;
			k = 0;


			while (j < student_num)
			{

				for (k = 0; students[j].num_id[k] != '\0'; k++)
					fputc(students[j].num_id[k], fptr1);

				if (students[j].num_id[k] == '\0')
				{
					fputc('-', fptr1);
				}



				//**************************************************************
				for (k = 0; students[j].name[k] != '\0'; k++)
					fputc(students[j].name[k], fptr1);


				if (students[j].name[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].last_name[k] != '\0'; k++)
					fputc(students[j].last_name[k], fptr1);


				if (students[j].last_name[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].listed_courses[k] != '\0'; k++)
					fputc(students[j].listed_courses[k], fptr1);


				if (students[j].listed_courses[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].exames[k] != '\0'; k++)
					fputc(students[j].exames[k], fptr1);


				if (students[j].exames[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].bill[k] != '\0'; k++)
					fputc(students[j].bill[k], fptr1);


				if (students[j].bill[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].birthday[k] != '\0'; k++)
					fputc(students[j].birthday[k], fptr1);


				if (students[j].birthday[k] == '\0')
				{
					fputc('-', fptr1);
				}
				//**************************************************************
				for (k = 0; students[j].mail[k] != '\0'; k++)
					fputc(students[j].mail[k], fptr1);


				if (students[j].mail[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].adress[k] != '\0'; k++)
					fputc(students[j].adress[k], fptr1);


				if (students[j].adress[k] == '\0')
				{
					fputc('-', fptr1);
				}
				//**************************************************************
				for (k = 0; students[j].telephone[k] != '\0'; k++)
					fputc(students[j].telephone[k], fptr1);


				if (students[j].telephone[k] == '\0')
				{
					fputc('$', fptr1);
					fputc('\n', fptr1);
				}
				j++;
			}
			fclose(fptr1);

		}
	}
};

void delete_course()
{
	FILE *fptr = NULL;
	struct Courses courses[100];
	char department[15];
	char semester;
	char temp_arr[2000];
	char course_name[35];
	char course_num[6];
	int i, j, k;
	int num_courses = 0;
	int course_exist = 0;
	int index;
	int flag = 0;
	int user_choice1 = 0;

	printf("\nFor department courses press 1\nFor main courses press 2 \n");
	scanf("%d", &user_choice1);

	while (user_choice1 != 1 && user_choice1 != 2)
	{
		printf("\nInvalid choice!!!\nFor department courses press 1\nFor main courses press 2 \n");
		scanf("%d", &user_choice1);
	}
	//**************************************************************
	printf("Enter department :");
	scanf("%s", &department);
	getchar();
	//**************************************************************
	printf("Enter semester :");
	scanf("%c", &semester);
	//**************************************************************
	printf("Enter course number :");
	scanf("%s", &course_num);
	//**************************************************************
	getchar();
	printf("Enter course name :");
	fgets(course_name, 35, stdin);
	i = 0;
	while (course_name[i] != '\n')
		i++;
	if (course_name[i] == '\n')
		course_name[i] = '\0';
	//**************************************************************
	if (user_choice1 == 1)
	{
		if (strcmp(department, "software") == 0 && semester == 'a')
			fptr = fopen("courses software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr = fopen("courses software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr = fopen("courses electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr = fopen("courses electrical-a.txt", "r");
	}
	if (user_choice1 == 2)
		fptr = fopen("choice_courses.txt", "r");
	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	//**************************************************************
	i = 0;
	while (!feof(fptr))
	{
		temp_arr[i] = fgetc(fptr);
		i++;
	}
	temp_arr[i - 1] = '\0';
	//**************************************************************
	i = 0;
	j = 0;
	k = 0;
	while (temp_arr[i] != '\0')
	{
		while (temp_arr[i] != '-')
		{
			courses[j].course_num[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_num[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].course_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].department[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].department[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].points[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].points[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecturer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecturer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].trainer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].trainer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecture_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecture_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].practice_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].practice_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].name_previous_courses[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].name_previous_courses[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].home_work[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].home_work[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].exames_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].exames_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].test_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].test_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '$')
		{
			courses[j].places[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].places[k] = '\0';
		//**************************************************************
		i++;
		if (temp_arr[i] != '\0')
			i++;

		k = 0;
		j++;
		num_courses++;

	}
	printf("\n");
	i = 0;
	while (i < num_courses)
	{
		if (strcmp(courses[i].course_name, course_name) == 0 && strcmp(courses[i].course_num, course_num) == 0)
		{
			course_exist = 1;
			index = i;
		}
		i++;
	}
	if (course_exist == 0)
		printf("\nThe course %s , %s dont exist!!!\n", course_name, course_num);
	else
	{
		fclose(fptr);
		if (user_choice1 == 1)
		{
			if (strcmp(department, "software") == 0 && semester == 'a')
				fptr = fopen("courses software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr = fopen("courses software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr = fopen("courses electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr = fopen("courses electrical-a.txt", "w+");
		}
		if (user_choice1 == 2)
			fptr = fopen("choice_courses.txt", "w+");

		j = 0;
		if (j == index)
			j++;
		while (j < num_courses)
		{

			for (k = 0; courses[j].course_num[k] != '\0'; k++)
				fputc(courses[j].course_num[k], fptr);

			if (courses[j].course_num[k] == '\0')
			{
				fputc('-', fptr);
			}


			//**************************************************************
			for (k = 0; courses[j].course_name[k] != '\0'; k++)
				fputc(courses[j].course_name[k], fptr);


			if (courses[j].course_name[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].department[k] != '\0'; k++)
				fputc(courses[j].department[k], fptr);


			if (courses[j].department[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].points[k] != '\0'; k++)
				fputc(courses[j].points[k], fptr);


			if (courses[j].points[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].lecturer_name[k] != '\0'; k++)
				fputc(courses[j].lecturer_name[k], fptr);


			if (courses[j].lecturer_name[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].trainer_name[k] != '\0'; k++)
				fputc(courses[j].trainer_name[k], fptr);


			if (courses[j].trainer_name[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].lecture_time[k] != '\0'; k++)
				fputc(courses[j].lecture_time[k], fptr);


			if (courses[j].lecture_time[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].practice_time[k] != '\0'; k++)
				fputc(courses[j].practice_time[k], fptr);


			if (courses[j].practice_time[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].name_previous_courses[k] != '\0'; k++)
				fputc(courses[j].name_previous_courses[k], fptr);


			if (courses[j].name_previous_courses[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].home_work[k] != '\0'; k++)
				fputc(courses[j].home_work[k], fptr);


			if (courses[j].home_work[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].exames_date[k] != '\0'; k++)
				fputc(courses[j].exames_date[k], fptr);


			if (courses[j].exames_date[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].test_date[k] != '\0'; k++)
				fputc(courses[j].test_date[k], fptr);


			if (courses[j].test_date[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].places[k] != '\0'; k++)
				fputc(courses[j].places[k], fptr);


			if (courses[j].places[k] == '\0')
			{
				fputc('$', fptr);
				fputc('\n', fptr);
			}


			//j++;


			j++;
			if (j == index)
				j++;



		}



	}



	fclose(fptr);
}

void add_new_course()
{
	FILE *fptr = NULL;
	struct Courses courses[100];
	char department[35];
	char semester;
	char temp_arr[1000];
	char course_name[35];
	char course_num[6];;
	char num_points[4];
	char lecturer_name[35];
	char trainer_name[35];
	char lecture_time[35];
	char practice_time[35];
	char name_previous_courses[35];
	char home_work[35];
	char exames_date[35];
	char test_date[35];
	char num_places[3];
	int i, j, k;
	int num_courses = 0;
	int course_exist = 0;
	int index;
	int flag = 0;
	int user_choice1 = 0;

	printf("\nFor department courses press 1\nFor main courses press 2 \n");
	scanf("%d", &user_choice1);

	while (user_choice1 != 1 && user_choice1 != 2)
	{
		printf("\nInvalid choice!!!\nFor department courses press 1\nFor main courses press 2 \n");
		scanf("%d", &user_choice1);
	}
	//**************************************************************
	printf("Enter department :");

	scanf("%s", &department);
	getchar();
	//**************************************************************
	printf("Enter semester :");
	scanf("%c", &semester);
	//**************************************************************
	if (user_choice1 == 1)
	{
		if (strcmp(department, "software") == 0 && semester == 'a')
			fptr = fopen("courses software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr = fopen("courses software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr = fopen("courses electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr = fopen("courses electrical-a.txt", "r");
	}
	if (user_choice1 == 2)
		fptr = fopen("choice_courses.txt", "r");


	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	//**************************************************************
	printf("Enter course number (5 digit number) :");
	scanf("%s", &course_num);
	getchar();
	//**************************************************************
	printf("Enter course name :");
	fgets(course_name, 35, stdin);
	i = 0;
	while (course_name[i] != '\n')
		i++;
	if (course_name[i] == '\n')
		course_name[i] = '\0';
	//**************************************************************
	//department
	//**************************************************************
	printf("Enter number points :");
	scanf("%s", &num_points);
	getchar();
	//**************************************************************
	printf("Enter lecturer name :");
	fgets(lecturer_name, 35, stdin);
	i = 0;
	while (lecturer_name[i] != '\n')
		i++;
	if (lecturer_name[i] == '\n')
		lecturer_name[i] = '\0';
	//**************************************************************
	printf("Enter trainer name :");
	fgets(trainer_name, 35, stdin);
	i = 0;
	while (trainer_name[i] != '\n')
		i++;
	if (trainer_name[i] == '\n')
		trainer_name[i] = '\0';
	//**************************************************************
	printf("Enter course time  :");
	fgets(lecture_time, 35, stdin);
	i = 0;
	while (lecture_time[i] != '\n')
		i++;
	if (lecture_time[i] == '\n')
		lecture_time[i] = '\0';
	//**************************************************************
	printf("Enter practice time  :");
	fgets(practice_time, 35, stdin);
	i = 0;
	while (practice_time[i] != '\n')
		i++;
	if (practice_time[i] == '\n')
		practice_time[i] = '\0';
	//**************************************************************
	printf("Enter name of previous courses  :");
	fgets(name_previous_courses, 35, stdin);
	i = 0;
	while (name_previous_courses[i] != '\n')
		i++;
	if (name_previous_courses[i] == '\n')
		name_previous_courses[i] = '\0';
	//**************************************************************
	printf("Enter tasks  :");
	fgets(home_work, 35, stdin);
	i = 0;
	while (home_work[i] != '\n')
		i++;
	if (home_work[i] == '\n')
		home_work[i] = '\0';
	//**************************************************************
	printf("Enter exams date  :");
	fgets(exames_date, 35, stdin);
	i = 0;
	while (exames_date[i] != '\n')
		i++;
	if (exames_date[i] == '\n')
		exames_date[i] = '\0';
	//**************************************************************
	printf("Enter tests date  :");
	fgets(test_date, 35, stdin);
	i = 0;
	while (test_date[i] != '\n')
		i++;
	if (test_date[i] == '\n')
		test_date[i] = '\0';
	//**************************************************************
	printf("Enter number of places :");
	scanf("%s", &num_places);
	getchar();
	//**************************************************************
	i = 0;
	while (!feof(fptr))
	{
		temp_arr[i] = fgetc(fptr);
		i++;
	}
	temp_arr[i - 1] = '\0';
	//**************************************************************	
	i = 0;
	j = 0;
	k = 0;
	while (temp_arr[i] != '\0')
	{
		while (temp_arr[i] != '-')
		{
			courses[j].course_num[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_num[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].course_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].department[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].department[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].points[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].points[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecturer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecturer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].trainer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].trainer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecture_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecture_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].practice_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].practice_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].name_previous_courses[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].name_previous_courses[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].home_work[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].home_work[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].exames_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].exames_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].test_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].test_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '$')
		{
			courses[j].places[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].places[k] = '\0';
		//**************************************************************
		i++;
		if (temp_arr[i] != '\0')
			i++;

		k = 0;
		j++;
		num_courses++;
	}
	printf("\n");
	//**************************************************************
	i = 0;
	while (i < num_courses)
	{
		if (strcmp(courses[i].course_name, course_name) == 0 && strcmp(courses[i].course_num, course_num) == 0)
		{
			course_exist = 1;
			index = i;
		}
		i++;
	}
	//**************************************************************
	if (course_exist == 1)
		printf("\nThe course %s , %s is exist!!!\n", course_name, course_num);
	//**************************************************************
	else
	{
		i = 0;
		j = 0;
		while (course_num[i] != '\0')
		{
			courses[num_courses].course_num[j] = course_num[i];
			i++;
			j++;
		}
		courses[num_courses].course_num[j] = course_num[i];

		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (course_name[i] != '\0')
		{
			courses[num_courses].course_name[j] = course_name[i];
			i++;
			j++;
		}
		courses[num_courses].course_name[j] = course_name[i];

		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (department[i] != '\0')
		{
			courses[num_courses].department[j] = department[i];
			i++;
			j++;
		}
		courses[num_courses].department[j] = department[i];

		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (num_points[i] != '\0')
		{
			courses[num_courses].points[j] = num_points[i];
			i++;
			j++;
		}
		courses[num_courses].points[j] = num_points[i];
		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (lecturer_name[i] != '\0')
		{
			courses[num_courses].lecturer_name[j] = lecturer_name[i];
			i++;
			j++;
		}
		courses[num_courses].lecturer_name[j] = lecturer_name[i];
		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (trainer_name[i] != '\0')
		{
			courses[num_courses].trainer_name[j] = trainer_name[i];
			i++;
			j++;
		}
		courses[num_courses].trainer_name[j] = trainer_name[i];
		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (lecture_time[i] != '\0')
		{
			courses[num_courses].lecture_time[j] = lecture_time[i];
			i++;
			j++;
		}
		courses[num_courses].lecture_time[j] = lecture_time[i];
		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (practice_time[i] != '\0')
		{
			courses[num_courses].practice_time[j] = practice_time[i];
			i++;
			j++;
		}
		courses[num_courses].practice_time[j] = practice_time[i];
		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (name_previous_courses[i] != '\0')
		{
			courses[num_courses].name_previous_courses[j] = name_previous_courses[i];
			i++;
			j++;
		}
		courses[num_courses].name_previous_courses[j] = name_previous_courses[i];
		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (home_work[i] != '\0')
		{
			courses[num_courses].home_work[j] = home_work[i];
			i++;
			j++;
		}
		courses[num_courses].home_work[j] = home_work[i];
		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (exames_date[i] != '\0')
		{
			courses[num_courses].exames_date[j] = exames_date[i];
			i++;
			j++;
		}
		courses[num_courses].exames_date[j] = exames_date[i];
		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (test_date[i] != '\0')
		{
			courses[num_courses].test_date[j] = test_date[i];
			i++;
			j++;
		}
		courses[num_courses].test_date[j] = test_date[i];
		i++;
		j++;
		//**************************************************************
		i = 0;
		j = 0;

		while (num_places[i] != '\0')
		{
			courses[num_courses].places[j] = num_places[i];
			i++;
			j++;
		}
		courses[num_courses].places[j] = num_places[i];

		//**************************************************************
		i = 0;
		j = 0;

		num_courses++;

		fclose(fptr);
		//**************************************************************
		if (user_choice1 == 1)
		{
			if (strcmp(department, "software") == 0 && semester == 'a')
				fptr = fopen("courses software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr = fopen("courses software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr = fopen("courses electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr = fopen("courses electrical-a.txt", "w+");
		}
		if (user_choice1 == 2)
			fptr = fopen("choice_courses.txt", "w+");


		j = 0;

		//**************************************************************
		while (j < num_courses)
		{
			for (k = 0; courses[j].course_num[k] != '\0'; k++)
				fputc(courses[j].course_num[k], fptr);

			if (courses[j].course_num[k] == '\0')
			{
				fputc('-', fptr);
			}


			//**************************************************************
			for (k = 0; courses[j].course_name[k] != '\0'; k++)
				fputc(courses[j].course_name[k], fptr);


			if (courses[j].course_name[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].department[k] != '\0'; k++)
				fputc(courses[j].department[k], fptr);


			if (courses[j].department[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].points[k] != '\0'; k++)
				fputc(courses[j].points[k], fptr);


			if (courses[j].points[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].lecturer_name[k] != '\0'; k++)
				fputc(courses[j].lecturer_name[k], fptr);


			if (courses[j].lecturer_name[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].trainer_name[k] != '\0'; k++)
				fputc(courses[j].trainer_name[k], fptr);


			if (courses[j].trainer_name[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].lecture_time[k] != '\0'; k++)
				fputc(courses[j].lecture_time[k], fptr);


			if (courses[j].lecture_time[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].practice_time[k] != '\0'; k++)
				fputc(courses[j].practice_time[k], fptr);


			if (courses[j].practice_time[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].name_previous_courses[k] != '\0'; k++)
				fputc(courses[j].name_previous_courses[k], fptr);


			if (courses[j].name_previous_courses[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].home_work[k] != '\0'; k++)
				fputc(courses[j].home_work[k], fptr);


			if (courses[j].home_work[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].exames_date[k] != '\0'; k++)
				fputc(courses[j].exames_date[k], fptr);


			if (courses[j].exames_date[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].test_date[k] != '\0'; k++)
				fputc(courses[j].test_date[k], fptr);


			if (courses[j].test_date[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].places[k] != '\0'; k++)
				fputc(courses[j].places[k], fptr);


			if (courses[j].places[k] == '\0')
			{
				fputc('$', fptr);
				fputc('\n', fptr);
			}


			j++;

		}



	}



	fclose(fptr);

}

void update_course()
{
	FILE *fptr = NULL;
	struct Courses courses[100];
	char department[15];
	char semester;
	char temp_arr[2000];
	char course_num[6];
	int i = 0, j = 0, k = 0;
	int num_courses = 0;
	int course_exist = 0;
	int index;
	int user_choice_ = 0;
	int user_choice1 = 0;

	char course_num_[6];
	char course_name_[35];
	char department_[35];
	char points_[4];
	char lecturer_name_[35];
	char trainer_name_[35];
	char lecture_time_[35];
	char practice_time_[35];
	char name_previous_courses_[35];
	char home_work_[35];
	char exames_date_[35];
	char test_date_[35];
	char places_[3];


	printf("\nFor department courses press 1\nFor main courses press 2 \n");
	scanf("%d", &user_choice1);

	while (user_choice1 != 1 && user_choice1 != 2)
	{
		printf("\nInvalid choice!!!\nFor department courses press 1\nFor main courses press 2 \n");
		scanf("%d", &user_choice1);
	}
	//**************************************************************
	printf("Enter department :");
	scanf("%s", &department);
	getchar();
	//**************************************************************
	printf("Enter semester :");
	scanf("%c", &semester);
	//**************************************************************
	if (user_choice1 == 1)
	{
		if (strcmp(department, "software") == 0 && semester == 'a')
			fptr = fopen("courses software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr = fopen("courses software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr = fopen("courses electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr = fopen("courses electrical-a.txt", "r");
	}
	if (user_choice1 == 2)
		fptr = fopen("choice_courses.txt", "r");
	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	//**************************************************************
	printf("Enter course number :");
	scanf("%s", &course_num);
	//**************************************************************
	i = 0;
	while (!feof(fptr))
	{
		temp_arr[i] = fgetc(fptr);
		i++;
	}
	temp_arr[i - 1] = '\0';
	//**************************************************************
	i = 0;
	j = 0;
	k = 0;
	while (temp_arr[i] != '\0')
	{
		while (temp_arr[i] != '-')
		{
			courses[j].course_num[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_num[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].course_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].department[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].department[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].points[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].points[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecturer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecturer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].trainer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].trainer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecture_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecture_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].practice_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].practice_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].name_previous_courses[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].name_previous_courses[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].home_work[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].home_work[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].exames_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].exames_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].test_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].test_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '$')
		{
			courses[j].places[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].places[k] = '\0';
		//**************************************************************
		i++;
		if (temp_arr[i] != '\0')
			i++;

		k = 0;
		j++;
		num_courses++;
	}

	printf("\n");
	//**************************************************************
	i = 0;
	while (i < num_courses)
	{
		if (strcmp(courses[i].course_num, course_num) == 0)
		{
			course_exist = 1;
			index = i;
		}
		i++;
	}
	//**************************************************************
	if (course_exist == 0)
		printf("\nThe course %s is not exist!!!\n", course_num);
	//**************************************************************
	else
	{
		course_exist = 0;
		printf("To change:\n course number press 1\n course name press 2\n course department press 3 \n course number of points press 4\n course lecturer name press 5\n course trainer name press 6\n course lecture time press 7\n course trainer time press 8\n course previous courses press 9\n course homework press 10\n course exames date press 11\n course tests date press 12\n course number places press 13\n");
		scanf("%d", &user_choice_);

		switch (user_choice_) {
		case 1:
			printf("change course number:\n");
			printf("Enter new course number (5 digit number) :");
			scanf("%s", &course_num_);
			getchar();
			i = 0;
			while (i < num_courses)
			{
				if (strcmp(courses[i].course_num, course_num_) == 0)
				{
					course_exist = 1;
					index = i;
				}
				i++;
			}
			while (course_exist == 1)
			{
				printf("\nThe course number %s is exist!!!\nEnter another course number!\n", course_num_);
				scanf("%s", &course_num_);
				getchar();
				course_exist = 0;
				i = 0;
				while (i < num_courses)
				{
					if (strcmp(courses[i].course_num, course_num_) == 0)
					{
						course_exist = 1;
						index = i;
					}
					i++;
				}
			}
			break;

		case 2:
			printf("change course name:\n");
			printf("Enter new course name :");
			getchar();
			fgets(course_name_, 35, stdin);
			i = 0;
			while (course_name_[i] != '\n')
				i++;
			if (course_name_[i] == '\n')
				course_name_[i] = '\0';
			break;

		case 3:
			printf("change course department:\n");
			printf("Enter new department :");
			scanf("%s", &department_);
			getchar();
			break;

		case 4:
			printf("change course number of points:\n");
			printf("Enter new number points :");
			scanf("%s", &points_);
			getchar();

			break;

		case 5:
			printf("change course lecturer name:\n");
			printf("Enter new lecturer name :");
			getchar();
			fgets(lecturer_name_, 35, stdin);
			i = 0;
			while (lecturer_name_[i] != '\n')
				i++;
			if (lecturer_name_[i] == '\n')
				lecturer_name_[i] = '\0';

			break;

		case 6:
			printf("change course trainer name:\n");
			printf("Enter new trainer name :");
			getchar();
			fgets(trainer_name_, 35, stdin);
			i = 0;
			while (trainer_name_[i] != '\n')
				i++;
			if (trainer_name_[i] == '\n')
				trainer_name_[i] = '\0';

			break;


		case 7:
			printf("change course lecture time:\n");
			printf("Enter new lecture time  :");
			getchar();
			fgets(lecture_time_, 35, stdin);
			i = 0;
			while (lecture_time_[i] != '\n')
				i++;
			if (lecture_time_[i] == '\n')
				lecture_time_[i] = '\0';

			break;


		case 8:
			printf("change course trainer time:\n");
			printf("Enter new practice time  :");
			getchar();
			fgets(practice_time_, 35, stdin);
			i = 0;
			while (practice_time_[i] != '\n')
				i++;
			if (practice_time_[i] == '\n')
				practice_time_[i] = '\0';

			break;


		case 9:
			printf("change previous courses:\n");
			printf("Enter new name of previous courses  :");
			getchar();
			fgets(name_previous_courses_, 35, stdin);
			i = 0;
			while (name_previous_courses_[i] != '\n')
				i++;
			if (name_previous_courses_[i] == '\n')
				name_previous_courses_[i] = '\0';

			break;

		case 10:
			printf("change course homework:\n");
			printf("Enter new tasks  :");
			getchar();
			fgets(home_work_, 35, stdin);
			i = 0;
			while (home_work_[i] != '\n')
				i++;
			if (home_work_[i] == '\n')
				home_work_[i] = '\0';

			break;

		case 11:
			printf("change course exames date:\n");
			printf("Enter new exams date  :");
			getchar();
			fgets(exames_date_, 35, stdin);
			i = 0;
			while (exames_date_[i] != '\n')
				i++;
			if (exames_date_[i] == '\n')
				exames_date_[i] = '\0';
			break;

		case 12:
			printf("change course tests date:\n");
			printf("Enter new tests date  :");
			getchar();
			fgets(test_date_, 35, stdin);
			i = 0;
			while (test_date_[i] != '\n')
				i++;
			if (test_date_[i] == '\n')
				test_date_[i] = '\0';

			break;

		case 13:
			printf("change course number places:\n");
			printf("Enter new number of places :");
			scanf("%s", &places_);
			getchar();

			break;
		default:
			if (user_choice_ < 1 || user_choice_ > 13)
				printf("Invalid choice.\n");
		}
		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 1)
		{
			while (course_num_[i] != '\0')
			{
				courses[index].course_num[j] = course_num_[i];
				i++;
				j++;
			}
			courses[index].course_num[j] = course_num_[i];
		}

		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 2)
		{
			while (course_name_[i] != '\0')
			{
				courses[index].course_name[j] = course_name_[i];
				i++;
				j++;
			}
			courses[index].course_name[j] = course_name_[i];
		}

		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 3)
		{
			while (department_[i] != '\0')
			{
				courses[index].department[j] = department_[i];
				i++;
				j++;
			}
			courses[index].department[j] = department_[i];
		}

		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 4)
		{
			while (points_[i] != '\0')
			{
				courses[index].points[j] = points_[i];
				i++;
				j++;
			}
			courses[index].points[j] = points_[i];
		}

		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 5)
		{
			while (lecturer_name_[i] != '\0')
			{
				courses[index].lecturer_name[j] = lecturer_name_[i];
				i++;
				j++;
			}
			courses[index].lecturer_name[j] = lecturer_name_[i];
		}

		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 6)
		{
			while (trainer_name_[i] != '\0')
			{
				courses[index].trainer_name[j] = trainer_name_[i];
				i++;
				j++;
			}
			courses[index].trainer_name[j] = trainer_name_[i];
		}

		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 7)
		{
			while (lecture_time_[i] != '\0')
			{
				courses[index].lecture_time[j] = lecture_time_[i];
				i++;
				j++;
			}
			courses[index].lecture_time[j] = lecture_time_[i];
		}
		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 8)
		{
			while (practice_time_[i] != '\0')
			{
				courses[index].practice_time[j] = practice_time_[i];
				i++;
				j++;
			}
			courses[index].practice_time[j] = practice_time_[i];
		}
		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 9)
		{
			while (name_previous_courses_[i] != '\0')
			{
				courses[index].name_previous_courses[j] = name_previous_courses_[i];
				i++;
				j++;
			}
			courses[index].name_previous_courses[j] = name_previous_courses_[i];
		}
		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 10)
		{
			while (home_work_[i] != '\0')
			{
				courses[index].home_work[j] = home_work_[i];
				i++;
				j++;
			}
			courses[index].home_work[j] = home_work_[i];
		}
		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 11)
		{
			while (exames_date_[i] != '\0')
			{
				courses[index].exames_date[j] = exames_date_[i];
				i++;
				j++;
			}
			courses[index].exames_date[j] = exames_date_[i];
		}
		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 12)
		{
			while (test_date_[i] != '\0')
			{
				courses[index].test_date[j] = test_date_[i];
				i++;
				j++;
			}
			courses[index].test_date[j] = test_date_[i];
		}
		//**************************************************************
		i = 0;
		j = 0;
		if (user_choice_ == 13)
		{
			while (places_[i] != '\0')
			{
				courses[index].places[j] = places_[i];
				i++;
				j++;
			}
			courses[index].places[j] = places_[i];
		}

		//**************************************************************
		i = 0;
		j = 0;

		fclose(fptr);
		//**************************************************************
		if (user_choice1 == 1)
		{
			if (strcmp(department, "software") == 0 && semester == 'a')
				fptr = fopen("courses software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr = fopen("courses software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr = fopen("courses electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr = fopen("courses electrical-a.txt", "w+");
		}
		if (user_choice1 == 2)
			fptr = fopen("choice_courses.txt", "w+");

		//**************************************************************
		while (j < num_courses)
		{
			for (k = 0; courses[j].course_num[k] != '\0'; k++)
				fputc(courses[j].course_num[k], fptr);

			if (courses[j].course_num[k] == '\0')
			{
				fputc('-', fptr);
			}


			//**************************************************************
			for (k = 0; courses[j].course_name[k] != '\0'; k++)
				fputc(courses[j].course_name[k], fptr);


			if (courses[j].course_name[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].department[k] != '\0'; k++)
				fputc(courses[j].department[k], fptr);


			if (courses[j].department[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].points[k] != '\0'; k++)
				fputc(courses[j].points[k], fptr);


			if (courses[j].points[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].lecturer_name[k] != '\0'; k++)
				fputc(courses[j].lecturer_name[k], fptr);


			if (courses[j].lecturer_name[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].trainer_name[k] != '\0'; k++)
				fputc(courses[j].trainer_name[k], fptr);


			if (courses[j].trainer_name[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].lecture_time[k] != '\0'; k++)
				fputc(courses[j].lecture_time[k], fptr);


			if (courses[j].lecture_time[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].practice_time[k] != '\0'; k++)
				fputc(courses[j].practice_time[k], fptr);


			if (courses[j].practice_time[k] == '\0')
			{
				fputc('-', fptr);
			}

			//**************************************************************
			for (k = 0; courses[j].name_previous_courses[k] != '\0'; k++)
				fputc(courses[j].name_previous_courses[k], fptr);


			if (courses[j].name_previous_courses[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].home_work[k] != '\0'; k++)
				fputc(courses[j].home_work[k], fptr);


			if (courses[j].home_work[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].exames_date[k] != '\0'; k++)
				fputc(courses[j].exames_date[k], fptr);


			if (courses[j].exames_date[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].test_date[k] != '\0'; k++)
				fputc(courses[j].test_date[k], fptr);


			if (courses[j].test_date[k] == '\0')
			{
				fputc('-', fptr);
			}
			//**************************************************************
			for (k = 0; courses[j].places[k] != '\0'; k++)
				fputc(courses[j].places[k], fptr);


			if (courses[j].places[k] == '\0')
			{
				fputc('$', fptr);
				fputc('\n', fptr);
			}
			j++;
		}
	}
	fclose(fptr);








}

void main_information()
{
	FILE *fptr = NULL;
	struct Courses courses[100];
	char department[15];
	char semester;
	char temp_arr[2000];
	char course_name[35];
	char course_num[6];
	int i = 0, j = 0, k = 0;
	int num_courses = 0;
	int course_exist = 0;
	int index;
	int user_choice = 0;
	int num = 0;
	int user_choice1 = 0;

	printf("\nFor department courses press 1\nFor main courses press 2 \n");
	scanf("%d", &user_choice1);

	while (user_choice1 != 1 && user_choice1 != 2)
	{
		printf("\nInvalid choice!!!\nFor department courses press 1\nFor main courses press 2 \n");
		scanf("%d", &user_choice1);
	}
	//**************************************************************
	printf("Enter department :");
	scanf("%s", &department);
	getchar();
	//**************************************************************
	printf("Enter semester :");
	scanf("%c", &semester);
	//**************************************************************
	printf("Enter course number :");
	scanf("%s", &course_num);
	//**************************************************************
	getchar();
	printf("Enter course name :");
	fgets(course_name, 35, stdin);
	i = 0;
	while (course_name[i] != '\n')
		i++;
	if (course_name[i] == '\n')
		course_name[i] = '\0';
	//**************************************************************
	if (user_choice1 == 1)
	{
		if (strcmp(department, "software") == 0 && semester == 'a')
			fptr = fopen("courses software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr = fopen("courses software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr = fopen("courses electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr = fopen("courses electrical-a.txt", "r");
	}
	if (user_choice1 == 2)
		fptr = fopen("choice_courses.txt", "r");
	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	//**************************************************************
	i = 0;
	while (!feof(fptr))
	{
		temp_arr[i] = fgetc(fptr);
		i++;
	}
	temp_arr[i - 1] = '\0';
	//**************************************************************
	i = 0;
	j = 0;
	k = 0;
	while (temp_arr[i] != '\0')
	{

		while (temp_arr[i] != '-')
		{
			courses[j].course_num[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_num[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].course_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].course_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].department[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].department[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].points[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].points[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecturer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecturer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].trainer_name[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].trainer_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].lecture_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].lecture_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].practice_time[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].practice_time[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].name_previous_courses[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].name_previous_courses[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].home_work[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].home_work[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].exames_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].exames_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			courses[j].test_date[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].test_date[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '$')
		{
			courses[j].places[k] = temp_arr[i];
			k++;
			i++;
		}
		courses[j].places[k] = '\0';
		//**************************************************************
		i++;
		if (temp_arr[i] != '\0')
			i++;

		k = 0;
		j++;
		num_courses++;
	}
	printf("\n");
	i = 0;

	while (i < num_courses)
	{
		if (strcmp(courses[i].course_name, course_name) == 0 && strcmp(courses[i].course_num, course_num) == 0)
		{
			course_exist = 1;
			index = i;
		}
		i++;
	}


	if (course_exist == 0)
		printf("\nThe course %s , %s dont exist!!!\n", course_name, course_num);


	else
	{
		printf("To get information only about this course ( %s , %s ) press: 0\nTo get information about all the courses in this department press: 1\n", course_name, course_num);
		scanf("%d", &user_choice);
		printf("\n");
		i = 0;
		if (user_choice == 0)
		{
			printf("Course number: ");
			while (courses[index].course_num[i] != '\0')
			{
				printf("%c", courses[index].course_num[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nCourse name: ");
			while (courses[index].course_name[i] != '\0')
			{
				printf("%c", courses[index].course_name[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nDepartment: ");
			while (courses[index].department[i] != '\0')
			{
				printf("%c", courses[index].department[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nNumber of points: ");
			while (courses[index].points[i] != '\0')
			{
				printf("%c", courses[index].points[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nLecturer name: ");
			while (courses[index].lecturer_name[i] != '\0')
			{
				printf("%c", courses[index].lecturer_name[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nTrainer name: ");
			while (courses[index].trainer_name[i] != '\0')
			{
				printf("%c", courses[index].trainer_name[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nLectur time: ");
			while (courses[index].lecture_time[i] != '\0')
			{
				printf("%c", courses[index].lecture_time[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nPractice time: ");
			while (courses[index].practice_time[i] != '\0')
			{
				printf("%c", courses[index].practice_time[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nName previous courses: ");
			while (courses[index].name_previous_courses[i] != '\0')
			{
				printf("%c", courses[index].name_previous_courses[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nHomework: ");
			while (courses[index].home_work[i] != '\0')
			{
				printf("%c", courses[index].home_work[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nExames date: ");
			while (courses[index].exames_date[i] != '\0')
			{
				printf("%c", courses[index].exames_date[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nTest date: ");
			while (courses[index].test_date[i] != '\0')
			{
				printf("%c", courses[index].test_date[i]);
				i++;
			}
			//**************************************************************
			i = 0;
			printf("\nNumber of places: ");
			while (courses[index].places[i] != '\0')
			{
				printf("%c", courses[index].places[i]);
				i++;
			}
			printf("\n\n\n");
		}
		printf("\n");


		j = 0;
		if (user_choice == 1)
		{
			while (j < num_courses)
			{
				i = 0;
				num = j + 1;
				printf("%d)\n", num);
				printf("\nCourse number: ");
				while (courses[j].course_num[i] != '\0')
				{
					printf("%c", courses[j].course_num[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nCourse name: ");
				while (courses[j].course_name[i] != '\0')
				{
					printf("%c", courses[j].course_name[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nDepartment: ");
				while (courses[j].department[i] != '\0')
				{
					printf("%c", courses[j].department[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nNumber of points: ");
				while (courses[j].points[i] != '\0')
				{
					printf("%c", courses[j].points[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nLecturer name: ");
				while (courses[j].lecturer_name[i] != '\0')
				{
					printf("%c", courses[j].lecturer_name[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nTrainer name: ");
				while (courses[j].trainer_name[i] != '\0')
				{
					printf("%c", courses[j].trainer_name[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nLectur time: ");
				while (courses[j].lecture_time[i] != '\0')
				{
					printf("%c", courses[j].lecture_time[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nPractice time: ");
				while (courses[j].practice_time[i] != '\0')
				{
					printf("%c", courses[j].practice_time[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nName previous courses: ");
				while (courses[j].name_previous_courses[i] != '\0')
				{
					printf("%c", courses[j].name_previous_courses[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nHomework: ");
				while (courses[j].home_work[i] != '\0')
				{
					printf("%c", courses[j].home_work[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nExames date: ");
				while (courses[j].exames_date[i] != '\0')
				{
					printf("%c", courses[j].exames_date[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nTest date: ");
				while (courses[j].test_date[i] != '\0')
				{
					printf("%c", courses[j].test_date[i]);
					i++;
				}
				//**************************************************************
				i = 0;
				printf("\nNumber of places: ");
				while (courses[j].places[i] != '\0')
				{
					printf("%c", courses[j].places[i]);
					i++;
				}
				printf("\n\n\n");
				j++;
			}
		}
	}
	fclose(fptr);
}

void Courses() {
	int user_choice;

	do {
		printf("Press: \n1 to add new course\n2 to delete course\n3 to update course\n4 to main information\n5 back to main page\n6 for exit\n");
		scanf("%d", &user_choice);

		switch (user_choice) {
		case 1:
			printf("add new course:\n");
			add_new_course();
			break;

		case 2:
			printf("delete course:\n");
			delete_course();
			break;

		case 3:
			printf("update course:\n");
			update_course();

			break;

		case 4:
			printf("main information:\n");
			main_information();
			break;

		case 5:
			printf("back to main page:\n");
			main_page();
			break;

		case 6:
			printf("exit\n");
			exit(1);
			break;

		default:
			if (user_choice < 1 || user_choice > 7)
				printf("Invalid choice.\nPlease select another option.\n");
		}

	} while (user_choice != 5);

}

void software_flowchart()
{
	FILE *fptr = NULL;
	char temp_arr[2000];
	int i = 0;

	fptr = fopen("flowchart_software.txt", "r");
	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	//**************************************************************
	i = 0;
	while (!feof(fptr))
	{
		temp_arr[i] = fgetc(fptr);
		i++;
	}
	temp_arr[i - 1] = '\0';
	//**************************************************************
	i = 0;
	printf("\nSoftware flowchart:\n");
	while (temp_arr[i] != '\0')
	{
		printf("%c", temp_arr[i]);
		i++;
	}
	printf("\n\n\n");
	fclose(fptr);
}

void electrical_flowchart()
{
	FILE *fptr = NULL;
	char temp_arr[2000];
	int i = 0;

	fptr = fopen("flowchart_electrical.txt", "r");
	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	//**************************************************************
	i = 0;
	while (!feof(fptr))
	{
		temp_arr[i] = fgetc(fptr);
		i++;
	}
	temp_arr[i - 1] = '\0';
	//**************************************************************
	i = 0;
	printf("\nElectrical flowchart:\n");
	while (temp_arr[i] != '\0')
	{
		printf("%c", temp_arr[i]);
		i++;
	}
	printf("\n\n\n");
	fclose(fptr);

}

void student_main()
{
	int user_choice;

	do {
		printf("Press: \n1 to update new course to student\n2 to register student to full course\n 3 to update student's grade.\n4 back to main page\n5 for exit\n");
		scanf("%d", &user_choice);

		switch (user_choice) {
		case 1:
			printf("Update new course to student:\n");
			students_update();
			break;

		case 2:
			printf("Register student to full course:\n");
			full_course();
			break;

		case 3:
			printf("Update student's grade:\n");
			addGrade();
			break;

		case 4:
			printf("back to main page:\n");
			main_page();
			break;

		case 5:
			printf("exit\n");
			exit(1);
			break;

		default:
			if (user_choice < 1 || user_choice > 5)
				printf("Invalid choice.\nPlease select another option.\n");
		}

	} while (user_choice != 3);


};

void students_update()
{
	FILE *fptr1 = NULL;
	FILE *fptr2 = NULL;
	struct Students students[500];
	struct Courses courses[100];
	char temp_arr[10000];
	char temp_arr1[2000];
	char _num_id[10];
	char department[35];
	char semester;
	int i = 0, j = 0, k = 0;
	int student_num = 0;
	int student_exist = 0;
	int index;
	char course_num[6];
	int num_courses = 0;
	int course_exist = 0;
	int _index;
	char num_places[3];
	int counter = 0;

	//**************************************************************
	printf("Enter student id :");
	scanf("%s", &_num_id);
	getchar();
	//**************************************************************
	printf("Enter department :");
	scanf("%s", &department);
	getchar();
	//**************************************************************
	printf("Enter semester :");
	scanf("%c", &semester);
	//**************************************************************
	if (strcmp(department, "software") == 0 && semester == 'a')
		fptr1 = fopen("students software-a.txt", "r");
	if (strcmp(department, "software") == 0 && semester == 'b')
		fptr1 = fopen("students software-b.txt", "r");
	if (strcmp(department, "electrical") == 0 && semester == 'b')
		fptr1 = fopen("students electrical-b.txt", "r");
	if (strcmp(department, "electrical") == 0 && semester == 'a')
		fptr1 = fopen("students electrical-a.txt", "r");
	//**************************************************************
	if (fptr1 == NULL)
	{
		printf("ERROR\n");
		exit(1);
	}
	//**************************************************************
	i = 0;
	while (!feof(fptr1))
	{
		temp_arr[i] = fgetc(fptr1);
		i++;
	}
	temp_arr[i - 1] = '\0';
	//**************************************************************
	i = 0;
	j = 0;
	k = 0;
	while (temp_arr[i] != '\0')
	{
		while (temp_arr[i] != '-')
		{
			students[j].num_id[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].num_id[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].name[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].last_name[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].last_name[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].listed_courses[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].listed_courses[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].exames[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].exames[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].bill[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].bill[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].birthday[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].birthday[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].mail[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].mail[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '-')
		{
			students[j].adress[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].adress[k] = '\0';
		//**************************************************************
		i++;
		k = 0;
		while (temp_arr[i] != '$')
		{
			students[j].telephone[k] = temp_arr[i];
			k++;
			i++;
		}
		students[j].telephone[k] = '\0';
		//**************************************************************
		i++;
		if (temp_arr[i] != '\0')
			i++;

		k = 0;
		j++;
		student_num++;
	}
	printf("\n");
	//**************************************************************
	i = 0;
	while (i < student_num)
	{
		if (strcmp(students[i].num_id, _num_id) == 0)
		{
			student_exist = 1;
			index = i;
		}
		i++;
	}
	//**************************************************************
	if (student_exist == 0)
		printf("\nThe student %s is not exist!!!\n", _num_id);
	//**************************************************************
	else
	{
		printf("The student information:\n");
		printf("Id:");
		k = 0;
		while (students[index].num_id[k] != '\0')
		{
			printf("%c", students[index].num_id[k]);
			k++;
		}
		//**************************************************************
		printf("\nFirst name:");
		k = 0;
		while (students[index].name[k] != '\0')
		{
			printf("%c", students[index].name[k]);
			k++;
		}
		//**************************************************************
		printf("\nLast name:");
		k = 0;
		while (students[index].last_name[k] != '\0')
		{
			printf("%c", students[index].last_name[k]);
			k++;
		}
		//**************************************************************
		printf("\nListed courses:");
		k = 0;
		while (students[index].listed_courses[k] != '\0')
		{
			printf("%c", students[index].listed_courses[k]);
			k++;
		}
		//**************************************************************
		printf("\nExames:");
		k = 0;
		while (students[index].exames[k] != '\0')
		{
			printf("%c", students[index].exames[k]);
			k++;
		}
		//**************************************************************
		printf("\nBill:");
		k = 0;
		while (students[index].bill[k] != '\0')
		{
			printf("%c", students[index].bill[k]);
			k++;
		}
		//**************************************************************
		printf("\nBirthday:");
		k = 0;
		while (students[index].birthday[k] != '\0')
		{
			printf("%c", students[index].birthday[k]);
			k++;
		}
		//**************************************************************
		printf("\nMail:");
		k = 0;
		while (students[index].mail[k] != '\0')
		{
			printf("%c", students[index].mail[k]);
			k++;
		}
		//**************************************************************
		printf("\nAdress:");
		k = 0;
		while (students[index].adress[k] != '\0')
		{
			printf("%c", students[index].adress[k]);
			k++;
		}
		//**************************************************************
		printf("\nTelephone:");
		k = 0;
		while (students[index].telephone[k] != '\0')
		{
			printf("%c", students[index].telephone[k]);
			k++;
		}
		printf("\n");
		//**************************************************************
		printf("Enter course number (5 digits) :");
		scanf("%s", &course_num);
		getchar();
		k = 0;
		j = 0;
		while (students[index].listed_courses[k] != '\0')
		{
			if (students[index].listed_courses[k] == ',')
			{
				k++;
				j = 0;
			}
			if (students[index].listed_courses[k] == course_num[j])
				counter++;
			k++;
			j++;
			if (counter == 5)
			{
				printf("\nThe student is alredy registed to this course!\n");
				exit(1);
			}
			if (j == 5)
			{
				j = 0;
				counter = 0;
			}
		}
		//**************************************************************
		fptr2 = fopen("choice_courses.txt", "r");
		if (fptr2 == NULL)
		{
			printf("ERROR\n");
			exit(1);
		}
		//**************************************************************	
		i = 0;
		while (!feof(fptr2))
		{
			temp_arr1[i] = fgetc(fptr2);
			i++;
		}
		temp_arr1[i - 1] = '\0';
		//**************************************************************	
		i = 0;
		j = 0;
		k = 0;
		while (temp_arr1[i] != '\0')
		{
			while (temp_arr1[i] != '-')
			{
				courses[j].course_num[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].course_num[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].course_name[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].course_name[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].department[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].department[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].points[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].points[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].lecturer_name[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].lecturer_name[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].trainer_name[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].trainer_name[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].lecture_time[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].lecture_time[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].practice_time[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].practice_time[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].name_previous_courses[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].name_previous_courses[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].home_work[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].home_work[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].exames_date[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].exames_date[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '-')
			{
				courses[j].test_date[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].test_date[k] = '\0';
			//**************************************************************
			i++;
			k = 0;
			while (temp_arr1[i] != '$')
			{
				courses[j].places[k] = temp_arr1[i];
				k++;
				i++;
			}
			courses[j].places[k] = '\0';
			//**************************************************************
			i++;
			if (temp_arr1[i] != '\0')
				i++;

			k = 0;
			j++;
			num_courses++;
		}
		printf("\n");
		//**************************************************************
		i = 0;
		while (i < num_courses)
		{
			if (strcmp(courses[i].course_num, course_num) == 0)
			{
				course_exist = 1;
				_index = i;
			}
			i++;
		}
		//**************************************************************
		if (course_exist == 0)
			printf("\nThe course %s  is not exist!!!\n", course_num);
		//**************************************************************
		else
		{
			j = 0;
			printf("\nNumber of places in course:\n");
			while (courses[_index].places[j] != '\0')
			{
				printf("%c", courses[_index].places[j]);
				j++;
			}
			printf("\nEnter new number of places in course:\n");
			scanf("%s", &num_places);
			getchar();



			i = 0;
			j = 0;
			while (num_places[i] != '\0')
			{
				courses[_index].places[j] = num_places[i];
				i++;
				j++;
			}
			courses[_index].places[j] = num_places[i];


			fclose(fptr2);
			//**************************************************************
			fptr2 = fopen("choice_courses.txt", "w+");
			j = 0;
			while (j < num_courses)
			{
				for (k = 0; courses[j].course_num[k] != '\0'; k++)
					fputc(courses[j].course_num[k], fptr2);

				if (courses[j].course_num[k] == '\0')
				{
					fputc('-', fptr2);
				}


				//**************************************************************
				for (k = 0; courses[j].course_name[k] != '\0'; k++)
					fputc(courses[j].course_name[k], fptr2);


				if (courses[j].course_name[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].department[k] != '\0'; k++)
					fputc(courses[j].department[k], fptr2);


				if (courses[j].department[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].points[k] != '\0'; k++)
					fputc(courses[j].points[k], fptr2);


				if (courses[j].points[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].lecturer_name[k] != '\0'; k++)
					fputc(courses[j].lecturer_name[k], fptr2);


				if (courses[j].lecturer_name[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].trainer_name[k] != '\0'; k++)
					fputc(courses[j].trainer_name[k], fptr2);


				if (courses[j].trainer_name[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].lecture_time[k] != '\0'; k++)
					fputc(courses[j].lecture_time[k], fptr2);


				if (courses[j].lecture_time[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].practice_time[k] != '\0'; k++)
					fputc(courses[j].practice_time[k], fptr2);


				if (courses[j].practice_time[k] == '\0')
				{
					fputc('-', fptr2);
				}

				//**************************************************************
				for (k = 0; courses[j].name_previous_courses[k] != '\0'; k++)
					fputc(courses[j].name_previous_courses[k], fptr2);


				if (courses[j].name_previous_courses[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].home_work[k] != '\0'; k++)
					fputc(courses[j].home_work[k], fptr2);


				if (courses[j].home_work[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].exames_date[k] != '\0'; k++)
					fputc(courses[j].exames_date[k], fptr2);


				if (courses[j].exames_date[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].test_date[k] != '\0'; k++)
					fputc(courses[j].test_date[k], fptr2);


				if (courses[j].test_date[k] == '\0')
				{
					fputc('-', fptr2);
				}
				//**************************************************************
				for (k = 0; courses[j].places[k] != '\0'; k++)
					fputc(courses[j].places[k], fptr2);


				if (courses[j].places[k] == '\0')
				{
					fputc('$', fptr2);
					fputc('\n', fptr2);
				}


				j++;
			}
			fclose(fptr2);
			//**************************************************************
			i = 0;
			j = 0;
			k = 0;

			while (students[index].listed_courses[k] != '\0')
				k++;
			while (course_num[i] != '\0')
			{
				students[index].listed_courses[k] = course_num[i];
				i++;
				k++;
			}
			students[index].listed_courses[k] = ',';
			k++;
			students[index].listed_courses[k] = '\0';

			for (k = 0; students[index].listed_courses[k] != '\0'; k++)
				printf("%c", students[index].listed_courses[k]);
			fclose(fptr1);

			//**************************************************************
			if (strcmp(department, "software") == 0 && semester == 'a')
				fptr1 = fopen("students software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr1 = fopen("students software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr1 = fopen("students electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr1 = fopen("students electrical-a.txt", "w+");
			//**************************************************************

			i = 0;
			j = 0;
			k = 0;


			while (j < student_num)
			{

				for (k = 0; students[j].num_id[k] != '\0'; k++)
					fputc(students[j].num_id[k], fptr1);

				if (students[j].num_id[k] == '\0')
				{
					fputc('-', fptr1);
				}



				//**************************************************************
				for (k = 0; students[j].name[k] != '\0'; k++)
					fputc(students[j].name[k], fptr1);


				if (students[j].name[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].last_name[k] != '\0'; k++)
					fputc(students[j].last_name[k], fptr1);


				if (students[j].last_name[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].listed_courses[k] != '\0'; k++)
					fputc(students[j].listed_courses[k], fptr1);


				if (students[j].listed_courses[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].exames[k] != '\0'; k++)
					fputc(students[j].exames[k], fptr1);


				if (students[j].exames[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].bill[k] != '\0'; k++)
					fputc(students[j].bill[k], fptr1);


				if (students[j].bill[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].birthday[k] != '\0'; k++)
					fputc(students[j].birthday[k], fptr1);


				if (students[j].birthday[k] == '\0')
				{
					fputc('-', fptr1);
				}
				//**************************************************************
				for (k = 0; students[j].mail[k] != '\0'; k++)
					fputc(students[j].mail[k], fptr1);


				if (students[j].mail[k] == '\0')
				{
					fputc('-', fptr1);
				}

				//**************************************************************
				for (k = 0; students[j].adress[k] != '\0'; k++)
					fputc(students[j].adress[k], fptr1);


				if (students[j].adress[k] == '\0')
				{
					fputc('-', fptr1);
				}
				//**************************************************************
				for (k = 0; students[j].telephone[k] != '\0'; k++)
					fputc(students[j].telephone[k], fptr1);


				if (students[j].telephone[k] == '\0')
				{
					fputc('$', fptr1);
					fputc('\n', fptr1);
				}
				j++;
			}
			fclose(fptr1);
		}

	}
	fclose(fptr1);
	fclose(fptr2);

};
// Registration manager menu
void main_page()
{
	int user_choice = 0;
	int choice = 0;
	int choice1 = 0;
	do {
		printf("Press: \n1 for Students\n2 for Courses\n3 for Posts\n4 for Exams\n5 for Reports\n6 for Exit\n");
		scanf("%d", &user_choice);
		switch (user_choice) {
		case 1:
			printf("Students:\n");
			student_main();
			break;

		case 2:
			printf("Courses:\n");
			Courses();
			break;

		case 3:
			printf("Posts:\n");
			updateAddPost();
			break;

		case 4:
			printf("Exams:\n");
			printf("To change date of exam or test press 1. To add exam date press 2.\n");
			scanf("%d", &choice1);
			if (choice1 == 1)
				update_exam_date();

			else if (choice1 == 2)
				addExamDate();
			break;

		case 5:
			printf("Reports\n");
			printf("For Software Flowchart press 1\nFor Electrical Flowchart press 2\nFor amount of students report press 3\n");
			scanf("%d", &choice);
			if (choice == 1)
				software_flowchart();
			if (choice == 2)
				electrical_flowchart();
			if (choice == 3)
				amount_student_report();

			break;

		case 6:
			printf("Exit.\n");
			exit(1);
			break;

		default:
			if (user_choice < 1 || user_choice > 6)
				printf("Invalid choice.\nPlease select another option.\n");
		}
	} while (user_choice != 6);
}

void addGrade()
{
	struct  Grade grade[1000];
	int i = 0, k = 0, j = 0, choice = 0, numbStd = 0, index = 0, numbGrade = 0, gradeExist = 0;
	char department[35], number_semester[10], stdTemp[2000], ID_std[10], theTemp[100], theTempStd[100], couresTemp[2000], gradeTemp[20000], first_exam_[4], second_exam_[4], special_exam_[4];
	FILE* fp;
	fp = NULL;
	printf("Enter Id:\n");
	scanf("%s", &ID_std);
	getchar();
	do {
		for (i = 0; i < (int)strlen(ID_std); i++)
		{
			if (ID_std[i] < '0' || ID_std[i]>'9' || strlen(ID_std) < 9)
			{
				printf("Please enter again ID:\n");
				scanf("%s", &ID_std);
				getchar();
			}
		}
	} while ((ID_std[i] >= '0' && ID_std[i] <= '9') && strlen(ID_std) == 9);

	printf("Confirm the action:1 for Ok,2 for No\n");
	scanf("%d", &choice);

	if (choice == 1)
	{
		printf("\nEnter number semester:\n");
		scanf("%s", &number_semester);
		getchar();
		printf("Enter department:\n");
		fgets(department, 35, stdin);
		i = 0;
		while (department[i] != '\n')
			i++;
		if (department[i] == '\n')
			department[i] = '\0';


		if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
		{
			fp = fopen("students software-b.txt", "r");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}
		}
		else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
		{
			fp = fopen("students software-a.txt", "r");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}

		}
		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
		{
			fp = fopen("students electrical-a.txt", "r");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}

		}
		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
		{
			fp = fopen("students electrical-b.txt", "r");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}
		}
		fseek(fp, 0, SEEK_SET);
		// Copy text file contents into an array//
		for (i = 0; !feof(fp); i++)
		{
			stdTemp[i] = fgetc(fp);
		}
		stdTemp[i - 1] = '\0';
		fclose(fp);

		k = 0;

		index = stringSearch(stdTemp, ID_std);

		for (int i = index; stdTemp[i] != '$'; i++)
		{
			theTemp[k++] = stdTemp[i];


		}
		theTemp[k] = '\0';
		printf(" *** data of student ***\n");
		printf(" id-first name-last name-listed courses-exames-bill-birthday-mail-adress-telephone\n ");
		printf("%s\n", theTemp);
	}
	/************************************************************************/

	printf("Update score?:1 for Ok,2 for No\n");
	scanf("%d", &choice);

	if (choice == 1)
	{
		if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
		{
			fp = fopen("courses software-a.txt", "r");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}

		}
		else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
		{
			fp = fopen("courses software-a.txt", "r");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}
		}
		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
		{
			fp = fopen("courses electrical-a.txt", "r");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}

		}
		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
		{
			fp = fopen("courses electrical-b.txt", "r");
			if (fp == NULL)
			{
				printf(" unable to open file \n");
				exit(1);
			}
		}

		fseek(fp, 0, SEEK_SET);
		// Copy text file contents into an array//
		for (i = 0; !feof(fp); i++)
		{
			couresTemp[i] = fgetc(fp);
		}
		couresTemp[i - 1] = '\0';
		fclose(fp);
		printf("\n*** The list coures ***\n");
		printf("course mum- course name- department- points-lecturer name-trainer name-lecture time-practice time-name privious courses-home work-exames data-test data-places\n");
		printf("%s\n\n", couresTemp);
	}

	/*****************************************************************/
	if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
	{
		fp = fopen("grades software-b.txt", "r");

	}
	else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
	{
		fp = fopen("grades software-a.txt", "r");

	}
	else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
	{
		fp = fopen("grades electrical-a.txt", "r");

	}

	else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
	{
		fp = fopen("grades electrical-b.txt", "r");
	}

	if (fp == NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}

	// Copy text file contents into an array//
	fseek(fp, 0, SEEK_SET);
	for (i = 0; !feof(fp); i++)
	{
		gradeTemp[i] = fgetc(fp);
	}
	gradeTemp[i - 1] = '\0';
	//printf("us=%s\n", gradeTemp);
	/****************************************/

	i = 0;
	j = 0;
	k = 0;
	while (gradeTemp[i] != '\0')
	{
		while (gradeTemp[i] != '-')
		{
			grade[j].student_id[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].student_id[k] = '\0';
		i++;
		k = 0;
		while (gradeTemp[i] != '-')
		{
			grade[j].course_id[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].course_id[k] = '\0';
		i++;
		k = 0;
		while (gradeTemp[i] != '-')
		{
			grade[j].first_exam[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].first_exam[k] = '\0';
		i++;
		k = 0;
		while (gradeTemp[i] != '-')
		{
			grade[j].second_exam[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].second_exam[k] = '\0';
		i++;
		k = 0;
		while (gradeTemp[i] != '$')
		{
			grade[j].special_exam[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].special_exam[k] = '\0';

		i++;
		if (gradeTemp[i] != '\0')
			i++;

		k = 0;
		j++;
		numbGrade++;
	}
	printf("\n");
	i = 0;

	for (i = 0; i < numbGrade; i++)
	{
		if (strcmp(grade[i].student_id, ID_std) == 0)
		{
			gradeExist = 1;
			index = i;
			break;

		}
	}

	if (gradeExist == 0)
	{
		printf("\nThe id is not exist!!!\n");
	}
	else
	{
		gradeExist = 0;
		printf("\n enter data first exam:\n");
		scanf("%s", &first_exam_);
		//fgetchar();


		printf("enter data second exam:\n");
		scanf("%s", &second_exam_);
		//fgetchar();

		printf("enter data special exam:\n");
		scanf("%s", &special_exam_);
		//fgetchar();

		i = 0;
		j = 0;

		while (first_exam_[i] != '\0')
		{
			grade[index].first_exam[j] = first_exam_[i];
			i++;
			j++;
		}
		grade[index].first_exam[j] = first_exam_[i];

		i = 0;
		j = 0;

		while (second_exam_[i] != '\0')
		{
			grade[index].second_exam[j] = second_exam_[i];
			i++;
			j++;
		}
		grade[index].second_exam[j] = second_exam_[i];

		i = 0;
		j = 0;

		while (special_exam_[i] != '\0')
		{
			grade[index].special_exam[j] = special_exam_[i];
			i++;
			j++;
		}

		grade[index].special_exam[j] = special_exam_[i];

		i = 0;
		j = 0;
		fclose(fp);

		/*********************************************************************/
		if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
		{
			fp = fopen("grades software-b.txt", "w+");

		}
		else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
		{
			fp = fopen("grades software-a.txt", "w+");

		}
		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
		{
			fp = fopen("grades electrical-a.txt", "w+");
		}

		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
		{
			fp = fopen("grades electrical-b.txt", "w+");

		}
		if (fp == NULL)
		{
			printf(" unable to open file \n");
			exit(1);
		}

		while (j < numbGrade)
		{
			for (k = 0; grade[j].student_id[k] != '\0'; k++)
				fputc(grade[j].student_id[k], fp);
			if (grade[j].student_id[k] == '\0')
			{
				fputc('-', fp);
			}

			for (k = 0; grade[j].course_id[k] != '\0'; k++)
				fputc(grade[j].course_id[k], fp);

			if (grade[j].course_id[k] == '\0')
			{
				fputc('-', fp);
			}

			for (k = 0; grade[j].first_exam[k] != '\0'; k++)
				fputc(grade[j].first_exam[k], fp);
			if (grade[j].first_exam[k] == '\0')
			{
				fputc('-', fp);
			}


			for (k = 0; grade[j].second_exam[k] != '\0'; k++)
				fputc(grade[j].second_exam[k], fp);

			if (grade[j].second_exam[k] == '\0')
			{
				fputc('-', fp);
			}

			for (k = 0; grade[j].special_exam[k] != '\0'; k++)
				fputc(grade[j].special_exam[k], fp);

			if (grade[j].special_exam[k] == '\0')
			{
				fputc('$', fp);
				fputc('\n', fp);
			}
			j++;
		}
	}
	fclose(fp);
}

void updateAddPost()
{
	int choice = 0, i = 0, j = 0, k = 0;
	char department[35], number_semester[35], data[35];
	FILE* fp;
	fp = NULL;
	printf("enter department:\n");
	getchar();
	fgets(department, 35, stdin);
	i = 0;
	while (department[i] != '\n')
		i++;
	if (department[i] == '\n')
		department[i] = '\0';

	printf("enter number semester:\n");
	scanf("%s", &number_semester);
	getchar();

	printf("enter Message by Format : Updated Date - Content\n");
	fgets(data, 35, stdin);
	i = 0;
	while (data[i] != '\n')
		i++;
	if (data[i] == '\n')
		data[i] = '$';
	data[i + 1] = '\0';

	if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
		fp = fopen("messages for students-software b.txt", "a");

	else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
		fp = fopen("messages for students-software a.txt", "a");

	else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
		fp = fopen("messages for students-electrical a.txt", "a");

	else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
		fp = fopen("messages for students-electrical b.txt", "a");
	if (fp == NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	fprintf(fp, "%s\n", data);
	fclose(fp);

} //A function that sends an update for a particular class//

//A function that checks whether a student does not take one of the exams, if he does not access it, adds it to a special date file, otherwise does nothing.//
void addExamDate()
{
	struct  Grade grade[1000];
	struct spacialExam spacieal;
	int i, k, j, choice = 0, index = 0, numbGrade = 0, gradeExist = 0;
	char department[35], number_semester[10];
	char temp[1000];
	char gradeTemp[20000];
	FILE* fp;
	fp = NULL;
	printf("\nEnter number semester:\n");
	scanf("%s", &number_semester);
	getchar();
	printf("Enter department:\n");
	fgets(department, 35, stdin);
	i = 0;
	while (department[i] != '\n')
		i++;
	if (department[i] == '\n')
		department[i] = '\0';

	if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
	{
		fp = fopen("grades software-b.txt", "r");

	}
	else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
	{
		fp = fopen("grades software-a.txt", "r");

	}
	else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
	{
		fp = fopen("grades electrical-a.txt", "r");

	}

	else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
	{
		fp = fopen("grades electrical-b.txt", "r");
	}

	if (fp == NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}

	// Copy text file contents into an array//
	fseek(fp, 0, SEEK_SET);
	for (i = 0; !feof(fp); i++)
	{
		gradeTemp[i] = fgetc(fp);
	}
	gradeTemp[i - 1] = '\0';
	/****************************************/

	i = 0;
	j = 0;
	k = 0;
	while (gradeTemp[i] != '\0')
	{
		while (gradeTemp[i] != '-')
		{
			grade[j].student_id[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].student_id[k] = '\0';
		i++;
		k = 0;
		while (gradeTemp[i] != '-')
		{
			grade[j].course_id[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].course_id[k] = '\0';
		i++;
		k = 0;
		while (gradeTemp[i] != '-')
		{
			grade[j].first_exam[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].first_exam[k] = '\0';
		i++;
		k = 0;
		while (gradeTemp[i] != '-')
		{
			grade[j].second_exam[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].second_exam[k] = '\0';
		i++;
		k = 0;
		while (gradeTemp[i] != '$')
		{
			grade[j].special_exam[k] = gradeTemp[i];
			k++;
			i++;
		}
		grade[j].special_exam[k] = '\0';

		i++;
		if (gradeTemp[i] != '\0')
			i++;

		k = 0;
		j++;
		numbGrade++;
	}
	printf("\n");
	i = 0;

	for (i = 0; i < numbGrade; i++)
	{
		if ((strcmp(grade[i].second_exam, "0") == 0) || (strcmp(grade[i].first_exam, "0") == 0))
		{
			gradeExist = 1;
			index = i;
			strcpy(temp, grade[index].student_id);
			break;

		}

	}

	fclose(fp);
	if (gradeExist == 0)
	{
		printf("\nThe grade is not exist!!!\n");
	}
	else
	{

		printf("Please enter a test date:\n");
		fgets(spacieal.data_exam, 10, stdin);
		i = 0;
		while (spacieal.data_exam[i] != '\n')
			i++;
		if (spacieal.data_exam[i] == '\n')
			spacieal.data_exam[i] = '\0';

		printf("Please enter a course num:\n");

		if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
		{
			fp = fopen("spacieal software-b.txt", "r");
			printf("enter course number:00001 or 00002 or 00003 or 00004 or 00005  \n");
			fgets(spacieal.course_num, 6, stdin);
		}
		else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
		{
			fp = fopen("spacieal software-a.txt", "r");
			printf("enter course number:00011 or 00012 or 00013 or 00014 or 00015  \n");
			fgets(spacieal.course_num, 6, stdin);

		}
		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
		{
			fp = fopen("spacieal electrical-a.txt", "r");
			printf("enter course number:00111 or 00112 or 00113 or 00114 or 00115  \n");
			fgets(spacieal.course_num, 6, stdin);
		}

		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
		{
			fp = fopen("spacieal electrical-b.txt", "r");
			printf("enter course number:01111 or 01112 or 01113 or 01114 or 01115  \n");
			fgets(spacieal.course_num, 6, stdin);
		}
		i = 0;
		while (spacieal.course_num[i] != '\n')
			i++;
		if (spacieal.course_num[i] == '\n')
			spacieal.course_num[i] = '\0';


		strcat(temp, "-");
		strcat(temp, spacieal.course_num);
		strcat(temp, "-");
		strcat(temp, spacieal.data_exam);
		strcat(temp, "$");

		if (strcmp(department, "students software") == 0 && strcmp(number_semester, "b") == 0)
		{
			fp = fopen("spacieal software-b.txt", "a");

		}
		else if (strcmp(department, "students software") == 0 && strcmp(number_semester, "a") == 0)
		{
			fp = fopen("spacieal software-a.txt", "a");

		}
		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "a") == 0))
		{
			fp = fopen("spacieal electrical-a.txt", "a");
		}

		else if ((strcmp(department, "students electrical") == 0) && (strcmp(number_semester, "b") == 0))
		{
			fp = fopen("spacieal electrical-b.txt", "a");
		}
		if (fp == NULL)
		{
			printf(" unable to open file \n");
			exit(1);
		}
		fseek(fp, 0, SEEK_END);
		fprintf(fp, "%s\n", temp);
		fclose(fp);
	}
}
//*************Registration manager(coordinator) functions end************