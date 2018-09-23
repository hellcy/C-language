#include <stdio.h>

int main()
{
	int x = 1, y = 2, z[10];
	int *ip;

	ip = &x; // ip now points to x
	printf("x: %d\n", x); // x has value of 1
	printf("ip: %d\n", ip); // ip has the value of its address
	printf("*ip %d\n", *ip); // *ip has the value of x, which is 1

	int *iq;
	iq = &y;
	printf("iq: %d\n", iq); // iq has the value of its address, the address of y, and its 4 bytes away from the address of x

	iq = ip;
	printf("iq: %d\n", iq); // iq has the value of its address, now its the address of x
	printf("*iq %d\n", *iq); // *iq has the value of x, which is 1

	int *pa;

	pa = &z[0];
	printf("pa: %d\n", pa);
	printf("z: %d\n", z); // the varible z points to the address of the first element in the array

	z[5] = 8;
	printf("pa[5]: %d\n", pa[5]); // 有下标的pointer

	char a[] = "hello, world!";

	char *message = a;
	printf("message[3]: %c\n", message[4]); // print the fifth element
	printf("message + 3: %s\n", message + 3); // points to the fourth element in the array, and will print part of the string start at position 3.
	printf("message + 12: %s\n", message + 12);
	printf("message + 13: %c\n", message + 13);

	printf("correct: %d\n", (5==5));
	printf("wrong: %d\n", (5 == 6));
}