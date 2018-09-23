#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* lower: convert upper case to lower case
upper: convert lower case to upper case */
int main(int argc, char const *argv[])
{
	int c;
	if (strcmp(argv[1], "lower") == 0)
		while ((c = getchar()) != EOF)
			putchar(tolower(c));
	else
		while((c = getchar()) != EOF)
			putchar(toupper(c));
	return 0;
}