#include <stdio.h>

int strLen(char *s);

int main()
{
	char array[100];
	for (int i = 0; i < 100; i++)
		array[i] = '0';
	printf("length of \"hello, world\" is: %d\n", strLen("hello, world"));
	printf("length of the array is: %d\n", strLen(array));
}

int strLen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;

	return n;
}