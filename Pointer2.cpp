#include<conio.h>
#include<stdio.h>

int add(int x, int y, int z)
{
	return x+y+z;
}

int func(int (*callback)(int, int, int), int x)
{
	return callback(x, x, x);
}

int main()
{
	int result;
	result = func(add, 100);
	printf("%d\n", result);
	getch();
	return 0;
}
