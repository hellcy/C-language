#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
struct tree_node
{
	char *word;
	int count;
	struct tree_node *left;
	struct tree_node *right;
};
struct tree_node *addtree(struct tree_node *pt, char *s);
void treeprint(struct tree_node *pt);
int getword(char *s, int x);

/* calculate the keyword appear times */
int main()
{
	struct tree_node *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	treeprint(root);
	return 0;
}

struct tree_node *talloc(void);
char *str_dup(char *s);

/* add a new node in the tree, or increment the count for exist keywords */
struct tree_node *addtree(struct tree_node *p, char *w)
{
	int cond;

	if (p == NULL)
	{
		p = talloc();
		p->word = str_dup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);

	return p;
}

/* print out tree in order */
void treeprint(struct tree_node *p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* create a tree node and allocate memory for it */
struct tree_node *talloc(void)
{
	return (struct tree_node *) malloc(sizeof(struct tree_node));
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




