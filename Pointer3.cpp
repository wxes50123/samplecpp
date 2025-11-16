#include<conio.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int a = 0;

void signalHandler(int signum)
{
	a = 100;
}

int main()
{
	int i;
	void (*result)(int);
	result = signal(SIGINT, signalHandler);
	if(result==SIG_ERR)
	{
		return -1;
	}
	for(i=0; i<10; i++)
	{
		printf("%d\n", a);
		usleep(500000);
	}
	return 0;
}
