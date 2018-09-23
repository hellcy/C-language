#include <ctype.h>
#include <stdio.h>

int atoi(char s[]);

/* convert string type integral number into int type
also could skip the white space and remain the sign value */
int main()
{
	char a[] = "-12355";
	printf("%d\n", atoi(a));
}

int atoi(char s[])
{
	int i, n, sign;

	// skip the white spaces
	for (i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1; // assign the value of sign to the variable 'sign'

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');

	return sign * n;
}