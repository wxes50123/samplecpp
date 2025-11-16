#include<conio.h>
#include<stdio.h>
#include<iostream>

void show_value(float f)
{
	std::cout << f << std::endl;
}

int main()
{
	int i = 42.195f;
	float j = 42.195;
	float k = 42.195f;
	
	show_value(i);
	show_value(j);
	show_value(k);
	
	getch();
	return 0;
}
