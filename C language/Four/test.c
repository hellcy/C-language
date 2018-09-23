#include <stdio.h>

void get(char x[])
{
	x[0] = getchar();
}
int main()
{
	char s[] = "";
	get(s);
	printf("%c %c\n", s[0], getchar());
}