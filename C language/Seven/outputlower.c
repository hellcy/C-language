#include <stdio.h>
#include <ctype.h>

/* convert all content to lower letters from input and output it to another file
./a.out < input > output */
int main()
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}