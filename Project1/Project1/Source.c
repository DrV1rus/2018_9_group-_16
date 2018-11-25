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
	char user[MAX_USER_LENGTH];
	int password;
	int type;
}username;


void login();

int main()
{
	login();
}

void login()
{
	username u1;
	u1.type = 1;
	char inp_user[10];
	int inp_pass, flag=1;
	printf(" Enter your username and password:\n");
	scanf("%s", &inp_user);
	scanf("%d", &inp_pass);
	printf("Input test:\n");
	printf("Username: %s\n Password: %d\n", inp_user, inp_pass);
	FILE *fp;
		fp = fopen("login.txt", "r");
		if (fp == NULL)
		{
			printf("Cant open the file.\n");
			exit(1);
		}
		while (fscanf(fp, "%s%d", &(u1.user), &(u1.password)) != EOF)
		{
			if (strcmp(u1.user, inp_user) == 0 && inp_pass == u1.password)
				flag = 1;
			else
				flag = 0;
		}

		if (flag == 0)
			printf("Login failed.");
		else
			printf("Login successful.");
}