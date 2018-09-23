#include <stdio.h>

#define MAXLINE 1000

int any(char s1[], char s2[]);

/* return first location in s1 where any character from s2 occurs */
int main()
{
	char s1[MAXLINE] = "aaapaabbbfbcccfccdddfddeeee";
	char s2[MAXLINE] = "f";

	printf("%d\n", any(s1, s2));
}

int any(char s1[], char s2[])
{
	int i, t;

	for (t = 0; s1[t] != '\0'; t++)
	{
		for (i = 0; s2[i] != '\0'; i++)
		{
			if (s1[t] == s2[i])
				return t + 1;
		}
	}
	return -1;
}