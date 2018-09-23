#include <stdio.h>

#define IN 1
#define OUT 0

/* count the number of lines, words and characters from the input */
void count()
{
	int c, newLine, newWord, newCharacter, state;

	newCharacter = 0;
	newWord = 0;
	newLine = 0;

	state = OUT;

	while ((c = getchar()) != EOF)
	{
		++newCharacter;
		if (c == '\n')
			++newLine;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++newWord;
		}
	}
	printf("#lines: %d\n #words: %d\n #characters: %d\n", newLine, newWord, newCharacter);
}

/* print words from input one word for each line */
void print()
{
	int c, state;

	state = OUT;

	while ((c = getchar()) != EOF)
	{

		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
			printf("\n");
		}
		else if (state == OUT)
		{
			putchar(c);
			state = IN;
		}
		else
			putchar(c);
	}
}

int main()
{
	print();
}