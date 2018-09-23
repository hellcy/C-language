#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s1[], char s2[]);

/* delete each other character in s1 which is in s2 */
int main()
{
	char s1[MAXLINE] = "aaapaabbbfbcccfccdddfddeeee";
	char s2[MAXLINE] = "fp";

	squeeze(s1, s2);
	printf("%s\n", s1);
}

void squeeze(char s1[], char s2[])
{
	int i, j, t;

	for (t = 0; s2[t] != '\0'; t++)
	{
		for (i = j = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] != s2[t])
				s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}