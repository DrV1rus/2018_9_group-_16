// HACKTON test
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <math.h>


#define MAX_USER_LENGTH 10

typedef struct
{
	char user[10];
	int password;
	int type;
}username;


void login();
void backup();
int check_block(int);

int main()
{
	//login();
	backup();
}

void login()
{
	username u1[3];
	char inp_user[10];
	int inp_pass, flag=0, i=0;
	printf(" Enter your username and password:\n");
	scanf("%s",&inp_user);
	scanf("%d",&inp_pass);
	printf("Input test:\n");
	printf("Username: %s\n Password: %d\n", inp_user, inp_pass);
	FILE* file;
	file = fopen("login.txt", "r");
	if (file == NULL) {
		printf("Cant open the file.\n");
		exit(1);
	}
	while (fscanf(file, "%d%s%d", &(u1[i].type), &(u1[i].user), &(u1[i].password) ) != EOF)
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
		i++;
	}

	if (flag == 1)
	{
		printf(" Login for student was successful.\n");
	}
	else if (flag == 2)
	{
		printf(" Login for coordinator was successful.\n");
	}
	else if (flag == 3)
	{
		printf(" Login for data manager was successful.\n");
	}
	else
		printf(" User name was not found or password is incorrect. Login failed.\n");
	fclose(file);
}

void backup()
{
	FILE* OP, *BU;
	char c;
	OP= fopen("login.txt", "r");
	BU = fopen("loginbackup.txt", "w");
	if (OP == NULL || BU == NULL) 
	{
		printf("Cant open the file.\n");
		exit(1);
	}
	while ((c = fgetc(OP)) != EOF) 
		fputc(c, BU);
	fclose(OP); fclose(BU);
	printf("Backup was successful!\n");
}

int check_block(int pay)
{
	if (pay == 11500)
		return 1;
	else
		return 0;
}
