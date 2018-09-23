#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

/* convert string type floating number into double type
also could skip white spaces, detect decimal point */
int main()
{
	char a[] = "-12355.456";
	printf("%.3f\n", atof(a));
}

double atof(char s[])
{
	double val, power;

	int i, sign;

	// skip all the white spaces
	for (i = 0; isspace(s[i]); i++)
		;

	// get the value of sign
	sign = (s[i] == '-') ? -1 : 1;

	// skip the sign position
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power = power * 10.0;
	}
	return sign * val / power;

}