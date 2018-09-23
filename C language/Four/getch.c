#include <stdio.h>

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