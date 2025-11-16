// EE2310 也 9721108 HW2 2.1 12/17/2009
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<iostream>
#include"readstock.h"

float function0(float stock[],int size);
float function1(float stock[],int size);
float function2(float stock[],int size);
float function3(float stock[],int size);
float function4(float stock[],int size);
float function5(float stock[],int size);
float function6(float stock[],int size,int n,int poly0[],int poly1[]);
float function7(float stock[],int size,int m,int poly0[],int poly1[]);

int main()
{
     int a,b,size=330;                            /*跑计*/
     int k,l,m,n,t=30;
     int c[6]={18,18,18,520,1000,520};            /*皚*/
     int poly0[2*size];
     int poly1[2*size];
     float stock[size];
     
     readstock(stock_file,stock,size);
     for(int i=0;i<size;i++)
     {
          poly0[2*i]=19+3*i;
          poly0[2*i+1]=450-t*(stock[i]-100);
     }
     
     initwindow(1018,538,"9721108_hw2_1");        /*秨币礶ガ*/
     
     cleardevice();
     setcolor(15);
     drawpoly(3,c);
     drawpoly(size,poly0);
     
     do
     {
          system("cls");
          
          printf("匡拒\n");
          printf("(0) 秨絃基\n");
          printf("(1) Μ絃基\n");
          printf("(2) 程蔼基\n");
          printf("(3) 程基\n");
          printf("(4) 害禴碩\n");
          printf("(5) らА基\n");
          printf("(6) N だ牧絬\n");
          printf("(7) 籔玡琘ㄨゑ耕害禴 bar– M だ牧丁基畉\n");
          printf("(8) 瞒秨\n");
          
          fflush(stdin);
          a=scanf("%d",&b);
          fflush(stdin);
          
          system("cls");
          
          if(a!=1||(b!=0&&b!=1&&b!=2&&b!=3&&b!=4&&b!=5&&b!=6&&b!=7&&b!=8))
          {
               printf("\a");
               printf("块礚叫穝块\n");
          }
          if(b==0)
          {
               printf("秨絃基 = %f\n",function0(stock,size));
          }
          if(b==1)
          {
               printf("Μ絃基 = %f\n",function1(stock,size));
          }
          if(b==2)
          {
               printf("程蔼基 = %f\n",function2(stock,size));
          }
          if(b==3)
          {
               printf("程基 = %f\n",function3(stock,size));
          }
          if(b==4)
          {
               printf("害禴碩 = %f%%",function4(stock,size));
          }
          if(b==5)
          {
               printf("らА基 = %f\n",function5(stock,size));
          }
          if(b==6)
          {
               do
               {
                    printf("N = ");
                    
                    fflush(stdin);
                    l=scanf("%d",&n);
                    fflush(stdin);
                    
                    system("cls");
               }
               while(l!=1||n<0||n%2==0);
               
               cleardevice();
               function6(stock,size,n,poly0,poly1);
               setcolor(15);
               drawpoly(3,c);
               drawpoly(size,poly0);
               
               setcolor(14);
               drawpoly(size-(n-1),poly1);
               
               printf("礶ガ\n");
          }
          if(b==7)
          {
               do
               {
                    printf("M = ");
                    
                    fflush(stdin);
                    k=scanf("%d",&m);
                    fflush(stdin);
                    
                    system("cls");
               }
               while(k!=1||m<0||m%2==0);
               
               cleardevice();
               function7(stock,size,m,poly0,poly1);
               setcolor(15);
               drawpoly(3,c);
               drawpoly(size,poly0);
               
               printf("礶ガ\n");
          }
          if(b==4)
          {
               printf("\n");
          }
          system("pause");
     }
     while(b!=8);
     return 0;
}

float function0(float stock[],int size)
{
     return stock[0];
}

float function1(float stock[],int size)
{
     return stock[size-1];
}

float function2(float stock[],int size)
{
     float max=stock[0];
     for(int i=0;i<size;i++)
     {
          max=(stock[i]>max)?stock[i]:max;
     }
     return max;
}

float function3(float stock[],int size)
{
     float min=stock[0];
     for(int i=0;i<size;i++)
     {
          min=(stock[i]<min)?stock[i]:min;
     }
     return min;
}

float function4(float stock[],int size)
{
     return ((function1(stock,size)-function0(stock,size))/function0(stock,size))*100;
}

float function5(float stock[],int size)
{
     float sum=0;
     for(int i=0;i<size;i++)
     {
          sum=sum+stock[i];
     }
     return sum/size;
}

float function6(float stock[],int size,int n,int poly0[],int poly1[])
{
     for(int i=0;i<size-(n-1);i++)
     {
          int sum=0;
          for(int j=0;j<n;j++)
          {
               sum=sum+poly0[2*(i+j)+1];
          }
          poly1[2*i]=poly0[2*i+(n-1)];
          poly1[2*i+1]=sum/n;
     }
}

float function7(float stock[],int size,int m,int poly0[],int poly1[])
{
     for(int i=m/2;i<size-m/2;i++)
     {
          if(stock[i+m/2]-stock[i-m/2]>0)
          {
               setfillstyle(1,4);
               bar(17+3*i,poly0[2*i+1]+(poly0[2*i+m]-poly0[2*i-m+2]),21+3*i,poly0[2*i+1]);
          }
          if(stock[i+m/2]-stock[i-m/2]<0)
          {
               setfillstyle(1,2);
               bar(17+3*i,poly0[2*i+1],21+3*i,poly0[2*i+1]+(poly0[2*i+m]-poly0[2*i-m+2]));
          }
     }
}
