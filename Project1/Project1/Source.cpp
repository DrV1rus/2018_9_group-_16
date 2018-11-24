// C program to evaluate value of a postfix 
// expression having multiple digit operands 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <math.h>

//-----------Part 1----------------
struct node
{
	char data;
	int data1;
	struct node* next;
};
typedef struct node node;

node* head;

void create();
void push(char val);  // to work with infix->postfix funcion.
void push_int(int val); // to work with evaluation funcion.
char pop();  // to work with infix->postfix funcion.
int pop_int(); // to work with evaluation funcion.
int IsEmpty();
//----------------------------------

//---------------Part 2 ------------
int evaluatePostfix(char* exp);
void infixTopostfix(char infix[], char postfix[]);
void PrintExpDetails(char exp[]);
int precedence(char symbol);
int is_operator(char symbol);
//----------------------------------



// Driver program to test the above functions 
int main()
{
	char ex[][50] = { "10*5-3", "(5-2)*13", "18-3*5", "4*5-2", "(10+3)*2", "20-3*5", "12-12/3", "(7+4)^2",
		"(4*5)^2", "(15-7)-4*(18-30)^2", "(23-2)*2^4" };

	for (int i = 0; i < 11; i++)
		PrintExpDetails(ex[i]);
	return 0;
}

//----------------Part 1------------------
void create()
{
	head = NULL;
}

void push(char val)
{
	node* temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = val;
	if (IsEmpty())
	{
		head = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = head;
		head = temp;
	}

}

void push_int(int val)
{
	node* temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data1 = val;
	if (IsEmpty())
	{
		head = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = head;
		head = temp;
	}

}

char pop()
{
	char k;
	node* temp;
	temp = head;
	k = temp->data;
	head = head->next;
	free(temp);
	return k;
}

int pop_int()
{
	int k;
	node* temp;
	temp = head;
	k = temp->data1;
	head = head->next;
	free(temp);
	return k;
}

int IsEmpty()
{
	return head == NULL;
}


//------------------Part 2 --------------------

// The main function that returns value 
// of a given postfix expression 

int evaluatePostfix(char* exp)
{
	create();
	int i = 0, op1, op2, rez, data = -1;
	for (i; i < strlen(exp); i++)
	{
		if (isdigit(exp[i]))
		{
			data = (data == -1) ? 0 : data;
			data = (data * 10) + (exp[i] - 48);
			continue;
		}
		if (data != -1)
			push_int(data);
		if (is_operator(exp[i]))
		{
			op2 = pop_int();
			op1 = pop_int();
			if (op1 == -1 || op2 == -1)
				break;
			switch (exp[i])
			{
			case '+':
				rez = op1 + op2;
				push_int(rez);
				break;
			case '-':
				rez = op1 - op2;
				push_int(rez);
				break;
			case '*':
				rez = op1 * op2;
				push_int(rez);
				break;
			case '/':
				rez = op1 / op2;
				push_int(rez);
				break;
			case '^':
				rez = pow(op1, op2);
				push_int(rez);
				break;
			}
		}
		data = -1;
	}
	if (head != NULL && head->next == NULL)
	{
		return head->data1;
	}
}


void infixTopostfix(char infix[], char postfix[])
{
	create(); // empty stack
	char x = 0, symbol = 0;
	char temp_str[100] = { '0' };
	int i = 0, j = 0;
	for (i; infix[i] != '\0'; i++)
	{
		symbol = infix[i];
		switch (symbol)
		{
		case '(':
			push(symbol);
			break;
		case ')':
			x = pop();
			while (x != '(')
			{
				temp_str[j] = x;
				j++;
				temp_str[j] = ' ';
				j++;
				x = pop();
			}
			break;
		case '^': case '*': case '/': case '+': case '-':
			if (IsEmpty())
				push(symbol);
			else
			{
				x = pop();
				while (precedence(symbol) <= precedence(x))
				{
					temp_str[j] = x;
					j++;
					temp_str[j] = ' ';
					j++;
					x = pop();
				}
			}
			if (precedence(symbol) >= precedence(x))
				push(x);
			push(symbol);
			break;
		default:
			if (isdigit(infix[i + 1]))
			{
				temp_str[j] = symbol;
				j++;
			}
			else
			{
				temp_str[j] = symbol;
				j++;
				temp_str[j] = ' ';
				j++;
			}
		}
	}

	while (!IsEmpty())
	{
		x = pop();
		temp_str[j] = x;
		j++;
		temp_str[j] = ' ';
		j++;
	}
	temp_str[j] = '\0';
	int k;
	for (k = 0; k < j - 5; k++)
		postfix[k] = temp_str[k];
	postfix[k] = '\0';
}

void PrintExpDetails(char exp[])
{
	char sol[100] = { 0 };
	infixTopostfix(exp, sol);
	printf("Infix expression: %s\n", exp);
	printf("Postfix expression: %s\n", sol);
	printf("It's Value: %d\n", evaluatePostfix(sol));
	printf("***********************************\n");
}

int precedence(char symbol)
{
	if (symbol == '^')
		return 5;
	else if (symbol == '*' || symbol == '/')
		return 4;
	else if (symbol == '+' || symbol == '-')
		return 3;
	else
		return 2;
}


int is_operator(char symbol)
{
	return (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-');
}
 // test
//test3