#include <stdio.h>
#include <string.h>

#define MAXLINES 5
#define MAXSTOR 50 // size of avaiable storage space

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines);

void quick_sort(char *lineptr[], int left, int right);

/* sort the lines from input */
int main()
{
	int nlines;
	char linestor[MAXSTOR];

	if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0)
	{
		quick_sort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000 // max length for one line

int getLine(char *p, int s);

/* read lines from input */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXSTOR;

	nlines = 0;

	while ((len = getLine(line, MAXLEN)) > 0)
		if (nlines >= maxlines)
		{
			printf("error: too many lines. MAXLINES is %d, but have %d\n", maxlines, nlines);
			return -1;
		}
		else if (p + len > linestop)
		{
			printf("error: not enough storage. MAXSTOR is %d, but have %d\n", MAXSTOR, (p+len-linestor));
			return -1;
		}
		else
		{
			line[len - 1] = '\0'; // delete \n
			strcpy(p, line);
			lineptr[nlines++] = p;
			p = p + len;
		}
		return nlines;
}

/* print out lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

void quick_sort(char *v[], int left, int right)
{
	int i, last;

	void swap(char *v[], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	quick_sort(v, left, last - 1);
	quick_sort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int getLine(char line[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		line[i] = c;
	}
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;

}




