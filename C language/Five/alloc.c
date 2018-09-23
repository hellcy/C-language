#include <stdio.h>

#define ALLOCSIZE 10000 // available size for the array

static char allocbuf[ALLOCSIZE];

static char *allocp = allocbuf; // at first, allocp points to the first element of allocbuf

char *alloc(int n);
void afree(char *p);

/* alloc will allocate a memory of size n in allocbuf,
afree will free the memory the pointer p points to,
%p is used to print the memory address in hexadecimal form */
int main()
{
	printf("allocbuf: %p\n", allocbuf);
	printf("allocp: %p\n", allocp);
	char *sp = alloc(100);
	printf("allocp after alloc 100: %p\n", allocp);
	afree(sp);
	printf("allocp after free 100: %p\n", allocp);
}

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp = allocp + n;
		return allocp - n;
	}
	else
		return 0;
}

void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
