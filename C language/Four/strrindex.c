#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

char pattern[] = "key";
char line[] = "there is no key in this line key";

int main()
{
	printf("%d\n", strindex(line, pattern));
}

/* return the position of t in s start from the right, or return -1 if not found */
int strindex(char s[], char t[])
{
	 int i, j, k;

	 for (i = strlen(s); i >= 0; i--)
	 {
	 	for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
	 		;
	 	if (k > 0 && t[k] == '\0')
	 		return i;
	 }
	 return -1;
}