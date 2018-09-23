#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINE 100

void shell_sort(int v[], int n);
void insertion_sort(int v[], int n);

/* Compare the computation time between shell sort and insertion sort */
int main()
{
	srand(time(NULL)); // reset the seed for the random number generator

	int a[MAXLINE];

	// create 1000 random number between 1 to 1000
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		a[i] = rand() % 1000 + 1;

	shell_sort(a, sizeof(a)/sizeof(a[0]));
	insertion_sort(a, sizeof(a)/sizeof(a[0]));
}

// normal shell sort, the gap will decrease in half everytime
void shell_sort(int v[], int n)
{
	int gap, i, j, temp, count;

	count = 0;

	for (gap = n / 2; gap > 0; gap = gap / 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && v[j] > v[i]; j-=gap)
			{
				temp = v[j];
				v[j] = v[i];
				v[i] = temp;
				count++;
			}
		}
	}

	for (int x = 0; x < n; x++)
		printf("%d ", v[x]);
	printf("\nshell sort: %d\n", count);
}

// insertion sort
void insertion_sort(int v[], int n)
{
	int i, j, temp, count;

	count = 0;

	for (i = 1; i < n; i++)
	{
		temp = v[i];
		for (j = i; j > 0 && v[j - 1] > temp; j--)
		{
			count++;
			v[j] = v[j - 1];
		}
		v[j] = temp;
	}

	for (int x = 0; x < n; x++)
		printf("%d ", v[x]);
	printf("\ninsertion sort: %d\n", count);
}




