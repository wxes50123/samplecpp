#include<conio.h>
#include<stdio.h>
#include<time.h>

int main()
{
	time_t now;
	struct tm *ts;
	char buf[80];
	
	now = time(NULL);
	
	ts = localtime(&now);
	
	strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
	printf("%s\n", buf);
	printf("%lld\n", (long long)now);
	
	getch();
	return 0;
}
