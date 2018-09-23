#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int lower(int c);
void lowerStr(char c[]);

/* change capital letters to their lower forms. */
int main()
{
	char c[MAXLINE] = "sdfs";
	printf("%lu %lu\n", strlen(c), sizeof(c)/sizeof(c[0]));
	printf("%c\n", lower('b'));
	lowerStr("AACFGH");
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

void lowerStr(char c[])
{
	int i = 0;
	char new[MAXLINE];

	while (c[i] != '\0')
	{
		new[i] = (c[i] >= 'A' && c[i] <= 'Z') ? c[i] + 'a' - 'A' : c[i];
		i++;
	}
	for (int i = 0; i < strlen(new) - 1; i++)
	{
		printf("%c", new[i]);
	}
	printf("\n");
}