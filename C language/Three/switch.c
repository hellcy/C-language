#include <stdio.h>

void escape(char s[], char t[]);

/* expand newline and tab into visible sequences
while copying the string t to s */
int main()
{
	char a[] = "helloo";
	char b[] = "wor\tld\n";
	escape(a, b);
}

void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] !='\0'; i++)
	{
		switch (t[i])
		{
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
	printf("%s\n", s);
}