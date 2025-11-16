#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,d,e,f,g=2;                  /*宣告整數變數a,b,c,d,e,f.*/
    char ch,input;                        /*宣告字元變數ch,input.*/
    printf("period    = ");
    fflush(stdin);
    d=scanf("%d",&a);                     /*輸入週期*/
    while(a<2||d!=1)                      /*防呆程式*/
    {
                    printf("\a");
                    printf("Error\n");
                    printf("It must be an integer and larger than 2\n");
                    printf("period    = ");
                    fflush(stdin);
                    d=scanf("%d",&a);
    }
    printf("amplitude = ");
    fflush(stdin);
    e=scanf("%d",&b);                     /*輸入振幅*/ 
    while(b<0||e!=1)                      /*防呆程式*/
    {
                    printf("\a");
                    printf("Error\n");
                    printf("It must be an integer and larger than 0\n");
                    printf("amplitude = ");
                    fflush(stdin);
                    e=scanf("%d",&b);
    }
    printf("time      = ");
    fflush(stdin);
    f=scanf("%d",&c);                     /*輸入總共顯示時間*/ 
    while(c<1||f!=1)                      /*防呆程式*/
    {
                    printf("\a");
                    printf("Error\n");
                    printf("It must be an integer and larger than 1\n");
                    printf("time      = ");
                    fflush(stdin);
                    f=scanf("%d",&c);
    }
    system("cls");
    printf("Please provide a symbol for the square waveform : ");
    fflush(stdin);
    scanf(" %c",&ch);                     /*輸入方波構成圖案*/
    do
    {
              while(a<2)                  /*防呆程式*/
              {
                             printf("\a");
                             a++;
              }
              while(b<0)                  /*防呆程式*/
              {
                             printf("\a");
                             b++;
              }
              while(c<1)                  /*防呆程式*/
              {
                             printf("\a");
                             c++;
              }
              while(g<0)                  /*防呆程式*/
              {
                             printf("\a");
                             g++;
              }
              system("cls");
              printf("period(a,d) = %3d , amplitude(w,s) = %3d , time(z,x) = %3d , bias(c,v) = %3d . \n",a,b,c,g);
              printf("You can press q to quit . \n");
              for(int i=1;i<=g+2*b+1;i++)   /*作圖 by using a nested for loop*/
              {
                      for(int j=1;j<=c;j++)
                      {
                              if((i==g+1&&(j-1)%(2*a-2)>a-3)||(i>g+1&&i<g+2*b+1&&j%(a-1)==0)||(i==g+2*b+1&&j%(2*a-2)<a))
                              {
                                  printf("%c",ch);
                              }
                              else
                              {
                                  printf("%c",32);
                              }
                      }
                      printf("\n");
              }
              switch(input=getch())
              {
                        case 'd':a++;
                             break;
                        case 'a':a--;
                             break;
                        case 'w':b++;
                             break;
                        case 's':b--;
                             break;
                        case 'x':c++;
                             break;
                        case 'z':c--;
                             break;
                        case 'v':g++;
                             break;
                        case 'c':g--;
                             break;
                        default:
                             break;
              }
    }
    while(input!='q');
    return 0;
}
