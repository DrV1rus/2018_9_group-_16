//yana 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <math.h>

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
	char home_work[35];
	char exames_date[35];
	char test_date[35];
	char places[3];
};

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
	char moed_test[10];
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
			fptr1 = fopen("software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr1 = fopen("software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr1 = fopen("electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr1 = fopen("electrical-a.txt", "r");
	}
	else if (user_choice1 == 2)
		fptr1 = fopen("choice_courses.txt", "r");

	//**************************************************************
	if (fptr1 == NULL)
	{
		printf("ERROR\n");
		return 1;
		
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
				fptr1 = fopen("software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr1 = fopen("software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr1 = fopen("electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr1 = fopen("electrical-a.txt", "w+");
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
	char course_num[6];
	char course_name[35];
	int i = 0, j = 0, k = 0;
	int num_courses = 0;
	int course_exist = 0;
	int index;
	int student_num = 0;
	int user_choice;
	char _places[20] = "Amount of students:";
	char _students[20] = "Students:";
	char _course_name[20]="Course name:";
	char _lecturer_name[20]="Lecturer name:";
	char _num_id[20]="Id:";
	char _name[20]="First name:";
	char _last_name[20]="Last name:";
	char _listed_courses[20]="Listed courses:";
	char _exames[20]="Exames:";
	char _bill[20]="Bill:";
	char _birthday[20]="Birthday:";
	char _mail[20]="Mail:";
	char _adress[20]="Address:";
	char _telephone[20]="telephone:";
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
			fptr1 = fopen("software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr1 = fopen("software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr1 = fopen("electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr1 = fopen("electrical-a.txt", "r");
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
			return 1;
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
		if (strcmp(courses[i].course_name, course_name) == 0 )
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
			return 1;
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



		printf("\Do you wanna save this information in file?\nIf yes press 1:\n");
		scanf("%d", &user_choice);
		if (user_choice == 1)
		{
			fptr3 = fopen("amount student report.txt", "w+");
			if (fptr3 == NULL)
			{
				printf("ERROR\n");
				return 1;
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
		return 1;
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
				fptr2 = fopen("software-a.txt", "r");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr2 = fopen("software-b.txt", "r");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr2 = fopen("electrical-b.txt", "r");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr2 = fopen("electrical-a.txt", "r");

		//**************************************************************
		if (fptr2 == NULL)
		{
			printf("ERROR\n");
			return 1;
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
				return 1;
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
					fptr1 = fopen("software-a.txt", "w+");
				if (strcmp(department, "software") == 0 && semester == 'b')
					fptr1 = fopen("software-b.txt", "w+");
				if (strcmp(department, "electrical") == 0 && semester == 'b')
					fptr1 = fopen("electrical-b.txt", "w+");
				if (strcmp(department, "electrical") == 0 && semester == 'a')
					fptr1 = fopen("electrical-a.txt", "w+");

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

	while (user_choice1 != 1  && user_choice1 != 2)
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
	fgets(course_name,35, stdin);
	i = 0;
	while (course_name[i] != '\n')
		i++;
	if (course_name[i] == '\n')
		course_name[i] = '\0';
	//**************************************************************
	if (user_choice1 == 1)
	{
		if (strcmp(department, "software") == 0 && semester == 'a')
			fptr = fopen("software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr = fopen("software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr = fopen("electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr = fopen("electrical-a.txt", "r");
	}
	if (user_choice1 == 2)
		fptr = fopen("choice_courses.txt", "r");
	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		return 1;
	}
	//**************************************************************
	i = 0;
	while (!feof(fptr))
	{
		temp_arr[i] = fgetc(fptr);
		i++;
	}
	temp_arr[i-1] = '\0';
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
				fptr = fopen("software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr = fopen("software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr = fopen("electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr = fopen("electrical-a.txt", "w+");
		}
		if (user_choice1 == 2)
			fptr = fopen("choice_courses.txt", "w+");
	
		j = 0;
		if (j == index )
			j++;
		while (j<num_courses)
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
			fptr = fopen("software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr = fopen("software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr = fopen("electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr = fopen("electrical-a.txt", "r");
	}
	if (user_choice1 == 2)
		fptr = fopen("choice_courses.txt", "r");


	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		return 1;
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
		i=0;
		j=0;
		while (course_num[i] != '\0')
		{
			courses[num_courses].course_num[j] =course_num[i];
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
				fptr = fopen("software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr = fopen("software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr = fopen("electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr = fopen("electrical-a.txt", "w+");
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
	int i = 0 , j=0 , k=0;
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
			fptr = fopen("software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr = fopen("software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr = fopen("electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr = fopen("electrical-a.txt", "r");
	}
	if (user_choice1 == 2)
		fptr = fopen("choice_courses.txt", "r");
	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		return 1;
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
		printf("\nThe course %s is not exist!!!\n",  course_num);
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
				fptr = fopen("software-a.txt", "w+");
			if (strcmp(department, "software") == 0 && semester == 'b')
				fptr = fopen("software-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'b')
				fptr = fopen("electrical-b.txt", "w+");
			if (strcmp(department, "electrical") == 0 && semester == 'a')
				fptr = fopen("electrical-a.txt", "w+");
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
			fptr = fopen("software-a.txt", "r");
		if (strcmp(department, "software") == 0 && semester == 'b')
			fptr = fopen("software-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'b')
			fptr = fopen("electrical-b.txt", "r");
		if (strcmp(department, "electrical") == 0 && semester == 'a')
			fptr = fopen("electrical-a.txt", "r");
	}
	if (user_choice1 == 2)
		fptr = fopen("choice_courses.txt", "r");
	//**************************************************************
	if (fptr == NULL)
	{
		printf("ERROR\n");
		return 1;
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
			 printf("%d)\n",num);
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
		return 1;
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
		return 1;
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
		printf("Press: \n1 to update new course to student\n2 to registe student to full course\n3 back to main page\n4 for exit\n");
		scanf("%d", &user_choice);

		switch (user_choice) {
		case 1:
			printf("Update new course to student:\n");
			students_update();
			break;

		case 2:
			printf("Registe student to full course:\n");
			full_course();
			break;

		case 3:
			printf("back to main page:\n");
			main_page();
			break;

		case 4:
			printf("exit\n");
			exit(1);
			break;

		default:
			if (user_choice < 1 || user_choice > 4)
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
		fptr1= fopen("students electrical-a.txt", "r");
	//**************************************************************
	if (fptr1 == NULL)
	{
		printf("ERROR\n");
		return 1;
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
		fptr2 = fopen("choice_courses.txt", "r");
		if (fptr2 == NULL)
		{
			printf("ERROR\n");
			return 1;
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
				printf("%c",students[index].listed_courses[k]);
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

void main_page()
{
	int user_choice;
	int choice;
	int choice1;
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
			break;

		case 4:
			printf("Exams:\n");
			printf("To change date of exam or test press 1\n");
			scanf("%d",&choice1);
			if (choice1 == 1)
			{
				update_exam_date();
			}
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
			printf("Exit\n");
			break;

		default:
			if (user_choice < 1 || user_choice > 6)
				printf("Invalid choice.\nPlease select another option.\n");
		}
	} while (user_choice != 6);
}

int main() 
{
	main_page();
	return 0;
}