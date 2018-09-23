#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "key";

/* find all lines contain the pattern and print lines */
int main()
{
	char line[MAXLINE];
	int found = 0;

	while (getLine(line, MAXLINE) > 0)
	{
		if (strindex(line, pattern) >= 0)
		{
			printf("%s", line);
			found++;
		}
	}
	return found;
}

/* save lines into s and return the length of the line */
int getLine(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* return the position of t in s, or return -1 if not found */
int strindex(char s[], char t[])
{
	 int i, j, k;

	 for (i = 0; s[i] != '\0'; i++)
	 {
	 	for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
	 		;
	 	if (k > 0 && t[k] == '\0')
	 		return i;
	 }
	 return -1;
}

