#include <stdio.h>
#include <string.h>

void strCat(char *s, char *t);

/* *****************note: **************
remember to initialize the size of char array or it will only be allocated its string length + 1 bytes
then when you add another string after it, it will result a buffer overflowing. Abort trap 6. */
int main()
{
	char a[100] = "hello, ";
	char b[100] = "world!\n";
	char *ap = a;
	char *bp = b;
	printf("ap: %s\n", ap);
	strCat(ap, bp);
	printf("ap: %s\n", ap);
}

void strCat(char *s, char *t)
{
	while (*s != '\0')
	{
		s++;
	}
	while (*t != '\0')
	{
		*s++ = *t++;
	}
}