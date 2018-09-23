#include <stdio.h>

/* connect multiple files 
copy all other files to the first argument, if doesn't exist, create one*/
int main(int argc, char const *argv[])
{
	FILE *fp, *afp;
	void filecopy(FILE *, FILE *);

	if (argc == 1) // no other command line parameters, copy input from stdin
		filecopy(stdin, stdout);
	else
	{
		if ((afp = fopen(*++argv, "a")) == NULL)
		{
			printf("cat: can't add to file: %s\n", *argv);
			return 1;
		}
		else
		{
			--argc;
			while (--argc > 0)
				if ((fp = fopen(*++argv, "r")) == NULL)
				{
					printf("cat: can't open %s\n", *argv);
					return 1;
				}
				else 
				{
					filecopy(fp, afp);
					fclose(fp);
				}
			fclose(afp);
		}
	}
	return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}