#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXLINE 1000

void shell_sort(int v[], int n);
void insertion_sort(int v[], int n);
void quick_sort(int v[], int left, int right);
void swap(int v[], int i, int j);

/* Compare the computation time between shell sort, quick sort and insertion sort 
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
*/
int times = 0;

int main()
{
	srand(time(NULL)); // reset the seed for the random number generator

	int a[MAXLINE], b[MAXLINE], c[MAXLINE];

	// create 1000 random number between 1 to 1000
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		a[i] = rand() % 1000 + 1;
		b[i] = a[i];
		c[i] = a[i];
		//printf("%d %d %d\n", a[i], b[i],c[i]);
	}
	printf("\n");

	quick_sort(a, 0, sizeof(a)/sizeof(a[0]) - 1);

	//for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	//	printf("%d ", a[i]);
	printf("\nquick sort: %d\n", times);

	shell_sort(b, sizeof(b)/sizeof(b[0]));
	insertion_sort(c, sizeof(c)/sizeof(c[0]));
}

// quick sort, everytime use the middle element to divide the array into two sub array
void quick_sort(int v[], int left, int right)
{
	int i, last;

	if (left >= right)
	{
		return;
	}

	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left])
		{
			times++;
			swap(v, ++last, i);
		}
	swap(v, left, last);
	quick_sort(v, left, last - 1);
	quick_sort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
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

	//for (int x = 0; x < n; x++)
	//	printf("%d ", v[x]);
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

	//for (int x = 0; x < n; x++)
	//	printf("%d ", v[x]);
	printf("\ninsertion sort: %d\n", count);
}




