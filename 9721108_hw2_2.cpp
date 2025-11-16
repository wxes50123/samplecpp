// EE2310 王珩 9721108 HW2 2.2 12/17/2009
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<iostream>

int Bubble_sort(int array[],int size);

int main()
{
     int count=0,g,h,m,n,r=500;                   /*宣告變數*/
     
     do                                           /*輸入 N值*/
     {
          printf("產生 N 筆亂數 (n>100)\n");
          printf("輸入 N 值     (n>100)\n");
          printf("     N = ");
          
          fflush(stdin);
          h=scanf("%d",&n);
          fflush(stdin);
          
          system("cls");
          
          if(h!=1||n<=100)
          {
               printf("\a");
          }
     }
     while(h!=1||n<=100);                         /*防呆程式*/
     
     do                                           /*選擇模式*/
     {
          printf("選擇模式\n");
          printf("(0)橫軸為序(No.)  ，縱軸為值(Value) As wiki\n");
          printf("(1)橫軸為值(Value)，縱軸為序(No.)   As demo\n");
          
          fflush(stdin);
          g=scanf("%d",&m);
          fflush(stdin);
          
          system("cls");
          
          if(g!=1||(m!=0&&m!=1&&m!=2&&m!=3))
          {
               printf("\a");
          }
     }
     while(g!=1||(m!=0&&m!=1&&m!=2&&m!=3));       /*防呆程式*/
     
     srand(time(NULL));                           /*產生亂數*/
     int a[n],b[r],c[6]={18,18,18,520,1000,520};
     for(int j=0;j<r;j++)
     {
          b[j]=0;
     }
     for(int i=0;i<n;i++)
     {
          a[i]=rand()%r;/*
          while(b[a[i]])
          {
               a[i]=rand()%r;
          }
          b[a[i]]=1;*/                            /*不得重複*/
     }
     initwindow(1018,538,"9721108_hw2_2");        /*開啟畫布*/
     do
     {
          cleardevice();
          drawpoly(3,c);                          /*橫軸縱軸*/
          
          for(int k=0;k<n;k++)
          {
               if(m==0)
               {
                    circle(19+k,519-a[k],1);
               }
               if(m==1)
               {
                    circle(519-a[k],519-n+k,1);
               }
               if(m==2)                           /*隱藏功能*/
               {
                    circle(19+n-k,19+a[k],1);     /*.m=0,m=1*/
               }                                  /*,m=2,m=3*/
               if(m==3)                           /*的      */
               {                                  /*冒泡方向*/
                    circle(19+a[k],519-k,1);      /*  分別為*/
               }                                  /*左上右下*/
          }
          
          if(!count)
          {
               Sleep(3000);
          }
          
          count++;
     }
     while(Bubble_sort(a,n)>0);
     while(!kbhit());
     {
          closegraph();
     }
}

int Bubble_sort(int array[],int size)             /*冒泡排序*/
{
     int count=0,temp;
     for(int l=0;l<size-1;l++)
     {
          if(array[l]>array[l+1])
          {
               temp=array[l];
               array[l]=array[l+1];
               array[l+1]=temp;
               count++;
          }
     }
     return count;
}
