#include <stdio.h>
#include "calc.h"

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

/* clear the stack */
void clear(void)
{
	sp = 0;
}