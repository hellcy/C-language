#include <stdio.h>
#include <stdlib.h> // to use the atof function
#include <math.h> // to use fmod function
#include <string.h> // to use strlen function
#include "calc.h"

#define MAXOP 100 // max length of an operator or an operands
#define NAME 'n' // signal that a name is found

/* reverse polish calculator
***************** compile with stack.c getop.c and getch.c ***********************
update 1: now main function can handle the reminder operand %. And the getop function can handle negative nunbers 
update 2: now main function can print the top most element without pop it
			can clear the stack
			can duplicate the top most element in the stack
			can swap the top two elements */
int main()
{
	int type;
	double op1, op2; // make sure minus and division are calculated in correct order, we store the first value poped from the stack into vaiable op2
	char s[MAXOP]; // next operator or operand

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case NAME:
				mathfnc(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else 
					printf("error: zero divisor\n");
			case '?': // print the most top element in the stack, without pop it
				op2 = pop();
				printf("\t%.8g\n", op2);
				push(op2);
				break;
			case 'c': // clear the stack
				clear();
				break;
			case 'd': // duplicate the top most element 
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 's': // swap the top two elements
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2)); // fmod was used to calculate the reminder of two operators
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				//printf("\t%.8g\n", pop()); // calculate the result and print out
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

/* mathfnc, check string s for supported math functions */
void mathfnc(char s[])
{
	double op2;

	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(s, "cos") == 0)
		push(cos(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0)
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("error: %s is not supported\n", s);

}
