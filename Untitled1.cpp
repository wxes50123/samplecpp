#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dir.h>
#include<direct.h>
#include<unistd.h>

#define PATH_SIZE 512

int main()
{
	char path_name[PATH_SIZE];
	getcwd(path_name, PATH_SIZE);
	printf("%s\n", path_name);
	getch();
	return 0;
	/*
	if(_mkdir("abc")==0)
	{
		getch();
		return 0;
	}
	else
	{
		perror("_mkdir");
		getch();
		return 1;
	}
	*/
}
