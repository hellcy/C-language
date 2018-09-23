#include <stdio.h>

void findComment(int c);
void inComment(void);
void echoQuote(int c);

/* remove all comments from a valid C program */
int main()
{
	int c, d;
	while ((c = getchar()) != EOF)
		findComment(c);
	return 0;
}

/* find places that begin a comment '/*' 
or begin a quote with single quote or double quote */
void findComment(int c)
{
	int d;
	if (c == '/')
	{
		if ((d = getchar()) == '*')
			inComment();
		else if (d == '/')
		{
			putchar(c);
			findComment(d);
		}
		else
		{
			putchar(c);
			putchar(d);
		}
	}
	else if (c == '\'' || c == '"')
		echoQuote(c);
	else
		putchar(c);
}

/* inside a valid comment */
void inComment(void)
{
	int c, d;
	c = getchar();
	d = getchar();

	while (c != '*' || d != '/')
	{
		c = d;
		d = getchar();
	}
}

/* echo charaters within quotes, make sure they will not be removed.
Even if there were comments inside the quotes */
void echoQuote(int c)
{
	int d;

	putchar(c);
	while ((d = getchar()) != c)
	{
		putchar(d);
		if (d == '\\') // make sure it doesn't recgonize the single quote after the escape tab as the end of the quote
			putchar(getchar());
	}
	putchar(d);
}


