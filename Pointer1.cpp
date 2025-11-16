#include<conio.h>
#include<stdio.h>

int main()
{
	char arr[5] = {'A', 'B', 'C', 'D', 'E'};
	char *ptr;
	ptr = &arr[1];
	ptr[0] = 'H';
	ptr[3] = 'K';
	for(int i=0; i<5; i++)
	{
		printf("%c ", arr[i]);
	}
	getch();
	return 0;
}
