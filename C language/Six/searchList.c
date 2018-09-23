#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // for malloc and free function

#define HASHSIZE 13
#define MAXWORD 100

struct nlist
{
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtab[HASHSIZE];
struct nlist *lookup(char *);
char *str_dup(char *);
unsigned hash(char *);
struct nlist *install(char *, char *);
void printlist(void);
int getword(char *, int x);
void undef(char *s);

/* read words and its defination from input, store them into a pointer array,
each pointer points to a linked list, 
each time add new words to the beginning of the list 
note: need to be compiled with ************** getch.c ***************
update: now it can delete (word, defn) struct from a list */
int main()
{
	char word[MAXWORD];
	char defn[MAXWORD];
	while (getword(word, MAXWORD) != EOF && getword(defn, MAXWORD) != EOF)
		if (isalpha(word[0]) && isalpha(defn[0]))
			install(word, defn);

	printlist();
	undef("rambling");
	//undef("individual");
	//printlist();
	return 0;
}

/* generate hash value for the string s */
unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
	{
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

/* lookup the name s in the hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; //found s

	return NULL; // not find s
}

/* add the new name and defination into the hashtab, if already exist, replace the defination */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) // not find name
	{
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = str_dup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else
	{
		free((void *) np->defn); // free the previous defined defination
	}
	if ((np->defn = str_dup(defn)) == NULL)
		return NULL;

	return np;
}

char *str_dup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1); // for the '\0' at the end of the string
	if (p != NULL)
	{
		strcpy(p, s);
	}
	return p;
}

void printlist()
{
	struct nlist *np;
	struct nlist *plist;

	int count = 0;
	for (np = hashtab[0]; count < HASHSIZE; np++, count++)
	{
		for (plist = hashtab[count]; plist != NULL; plist = plist->next)
		{
			printf("%s -> %s ", plist->name, plist->defn);
		}
		printf("\n");

	}
}

/* read next word from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int s);
	char *w = word;

	while (isspace(c = getch())) // skip all white spaces
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}

	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}

	*w = '\0';
	return word[0];
}

/* remove a name and definition from the list
also free all memory allocated to that struct */
void undef(char *s)
{
	int hashval;
	struct nlist *prev, *current;

	prev = NULL;
	hashval = hash(s);

	for (current = hashtab[hashval]; current != NULL; current = current->next)
	{
		if (strcmp(s, current->name) == 0) //found name
			break;
		prev = current;
	}
	if (current != NULL) // found name
	{
		if (prev == NULL) // at the begining of the list
			hashtab[hashval] = current->next; // skip the first struct
		else
			prev->next = current->next; // skip the struct in the middle of the list

		free((void *) current->name);
		free((void *) current->defn);
		free((void *) current); // free allocated structure
	}
}





