#include <stdio.h>

int add(int s);
int a = 0;

int main()
{
	printf("%d\n", add(5));
}

int add(int s)
{
	if (s == 0)
		return a;
	a = a + 2;
	return add(--s);
}