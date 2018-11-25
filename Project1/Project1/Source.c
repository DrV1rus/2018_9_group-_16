#define _CRT_SECURE_NO_WORNING
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 9
#define SIZE2 11


typedef struct
{
	char ID[SIZE];
	char Username[SIZE2];
}user;




int Permissions();
int main()
{
	int choice;

	do {
		printf("Please enter your selection: 1-Backup,2-Reset Password, 3-Database, 4-Permissions, 5-Payment arrangements, 6-Delete user, 7-Reports,8-exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			printf("Backup\n");
			break;
		}
		case 2:
		{
			printf("Reset Password\n");
			break;
		}
		case 3:
		{
			printf("Database\n");
			break;
		}
		case 4:
		{
			printf("Permissions\n");
			printf("%d\n", Permissions());
			break;
		}
		case 5:
		{
			printf("Payment arrangements\n");
			break;
		}
		case 6:
		{
			printf("Delete user\n");
			break;
		}
		case 7:
		{
			printf("Reports");
			break;
		}

		}
	} while (choice != 8);

	system("pause");
	return 0;
}
int Permissions()
{

	FILE* fp;
	fp = fopen("permissions.txt", "r");
	char NewID[SIZE];
	char NewUsername[SIZE2];
	user us;
	user us2;

	printf("Enter ID:\n");
	scanf("%s", &NewID);
	printf("Enter Username:\n");
	scanf("%s", &NewUsername);
	printf("%s %s\n", NewID, NewUsername);


	if (fp == NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}

	while (fscanf(fp, "%s %s", &(us.ID), &(us.Username)) != EOF)
	{
		if ((strcmp(us.ID, NewID) == 0) && strcmp(us.Username, NewUsername) == 0)
		{
			printf("User exist");
			fclose(fp);
			return 0;
		}
		else
		{
			fp = fopen("permissions.txt", "a");
			fprintf(fp, "\n***********************\n");
			fprintf(fp, "%s\n%s\n", NewID, NewUsername);
			fclose(fp);
			return 1;
		}
	}




}