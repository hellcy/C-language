struct point
{
	int x;
	int y;
};

struct point makepoint(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

struct key
{
	char c;
	int s;
};

int main(int argc, char const *argv[])
{
	struct key key_one = {'a', 5};
	printf("size of key_one: %d\n", sizeof(key_one)); // 8 not 5
	return 0;
}
