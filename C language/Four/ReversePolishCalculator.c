#include <stdio.h>
#include <stdlib.h> // to use the atof function
#include <ctype.h> // to use the isdigit function
#include <math.h> //  to use the fmod function
#include <string.h> // to use the strlen function in getop

#define MAXOP 100 // max length of an operator or an operands
#define NUMBER '0' // use to represent found a number
#define NAME 'n' // signal that a name is found

int getop(char s[]);
void push(double a);
double pop(void);
void clear(void);
void mathfnc(char s[]);

/* reverse polish calculator
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

#define MAXVAL 100

int sp = 0; // next available position in the stack
double val[MAXVAL]; // stack

/* push function, push the value into the stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop function, pop the most top value out from the stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getch(void);
void ungetch(int x);

/* getop function, get the next oprator or oprand from the input */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;

	/*
	if (islower(c))
	{
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		if (strlen(s) > 1)
			return NAME;
		else
			return c;
		
	}
	*/

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;
		else
		{
			if (c != EOF)
				ungetch(c);
			return '-'; // minus sign
		}
	}

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // buff area for ungetch
int bufp = 0; // next available position int the buff

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
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

/* clear the stack */
void clear(void)
{
	sp = 0;
}




