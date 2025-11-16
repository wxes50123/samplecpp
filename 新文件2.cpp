#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    for(int i=0;i<128;i++)
    {
                  printf("%c\n",i);
    }
    char ch=getch();
    while(ch!='q')
    {
                  printf("%c\n",ch);
                  printf("%d\n",ch);
                  fflush(stdin);
                  ch=getch();
    }
    return 0;
}
