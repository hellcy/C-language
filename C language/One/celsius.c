#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void versionOne();
void versionTwo();
void versionThree();
void versionFour();

int main()
{
	versionFour();
}

/*
print fahr degrees and their corresponding celsius degrees
*/
void versionOne()
{
	int fahr, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}

/* This time we want to create a table 
and make all numbers align to the right by using %3d and %6d */
void versionTwo()
{
	int fahr, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%3d %6d\n", fahr, celsius);
		fahr = fahr + step;
	}
}

/* For accuracy, make the fahr and celsius to float type 
Also change the %d to %f */
void versionThree()
{
	float fahr, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("Fahr  Celsius\n");
	while (fahr <= upper)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%4.0f   %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

/* transfer fahr from celsius using for loop */
void versionFour()
{
	int fahr;

	for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
	{
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
	}
}
