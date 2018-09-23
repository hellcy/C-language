#include <stdio.h>

int strEnd(char *s, char *t);

/* return 1 if string t occurs at the end of s 
otherwise return 0 */
int main()
{
	char a[] = "hello, world";
	char b[] = "world";
	printf("%d\n", strEnd(a, b));
}

int strEnd(char *s, char *t)
{
	char *bs = s;
	char *bt = t;

	while (*s)
		s++;
	while (*t)
		t++;
	for ( ; *s == *t; s--, t--)
		if (t == bt || s == bs)
			break;

	if (*s == *t && t == bt && *s != '\0')
		return 1;
	else
		return 0;
}