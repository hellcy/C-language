#include <stdio.h>

static char daytab[2][13] = 
{
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day of year, set day of year from month and day */
int day_of_year(int year, int month, int day)
{
	int leap;
	char *p;

	leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	p = daytab[leap];
	while (--month)
		day += *++p;
	return day;
}

/* set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p;

	leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	p = daytab[leap];

	while (yearday > *++p)
		yearday -= *p;

	*pmonth = p - *(daytab + leap);
	*pday = yearday;
}

int main()
{
	int year, yearday, month, day;
	year = 2018;
	month = 7;
	day = 1;

	yearday = day_of_year(year, month, day);
	printf("day of year: %d\n", yearday);

	month_day(year, yearday, &month, &day);
	printf("month: %d\n", month);
	printf("day: %d\n", day);

}



