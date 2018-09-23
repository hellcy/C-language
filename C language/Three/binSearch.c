
int binSearch(int x, int v[], int n);

/* find target number x from a integer array using binary search */
int main()
{
	int array[10] = {1,2,3,4,5,6,7,8,9,0};
	printf("%d\n", binSearch(5, array, 10));
}

int binSearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else 
			return mid;
	}
	return -1;
}