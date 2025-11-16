#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dir.h>
#include<direct.h>
#include<dirent.h>
#include<unistd.h>
#include<windows.h>
#include<sys/stat.h>
#include<iostream>

#define PATH_SIZE 512
#define NAME_SIZE 21
#define FOLD_AMOUNT 512

void sort(char a[FOLD_AMOUNT][NAME_SIZE], int size);

int main()
{
	char path_name[PATH_SIZE];
	char path_name_assign[PATH_SIZE] = "";
	
	printf("指定するディレクトリを入力してください。\n");
	
	//...
	fflush(stdin);
	if(scanf("%511[^\n]%*[^\n]", path_name_assign) != 1)//**
	{
		int msgboxID = MessageBoxW(NULL, (LPCWSTR)L"Please input a directory!", (LPCWSTR)L"error", MB_ICONWARNING | MB_OK);
		return 1;
	}
	if(chdir(path_name_assign) != 0)//**
	{
		int msgboxID = MessageBoxW(NULL, (LPCWSTR)L"Directory not exit!", (LPCWSTR)L"error", MB_ICONWARNING | MB_OK);
		return 1;
	}
	
	//ディレクトリ設定
	getcwd(path_name, PATH_SIZE);
	printf("%s\n", path_name);
	
	//処理：読み込みと絞り込み
	DIR *dir;
	struct dirent *dp;
	int count = 0;
	char foldlist[FOLD_AMOUNT][NAME_SIZE];
	
	dir = opendir(path_name);
	
	if(dir == NULL)
	{
		return 1;
	}
	while((dp = readdir(dir)))
	{
		if((dp->d_name[0]=='B')&&(dp->d_name[1]=='U')&&(dp->d_name[2]=='I')&&(dp->d_name[3]=='L')&&(dp->d_name[4]=='D')&&(dp->d_name[5]=='_')&&(dp->d_name[6]=='D')&&(dp->d_name[7]=='C')&&(dp->d_name[8]=='X')&&(dp->d_name[9]=='_')&&(dp->d_name[10]>=48)&&(dp->d_name[10]<=57)&&(dp->d_name[11]>=48)&&(dp->d_name[11]<=57)&&(dp->d_name[12]>=48)&&(dp->d_name[12]<=57)&&(dp->d_name[13]>=48)&&(dp->d_name[13]<=57)&&(dp->d_name[14]>=48)&&(dp->d_name[14]<=57)&&(dp->d_name[15]>=48)&&(dp->d_name[15]<=57)&&(dp->d_name[16]>=48)&&(dp->d_name[16]<=57)&&(dp->d_name[17]>=48)&&(dp->d_name[17]<=57)&&(dp->d_name[18]=='.')&&(dp->d_name[19]>=48)&&(dp->d_name[19]<=57)&&(dp->d_name[20]=='\0'))
		{
			for(int j=0; j<NAME_SIZE; j++)
			{
				foldlist[count][j] = dp->d_name[j];
			}
			count++;
		}
	}
	if(dir != NULL)
	{
		closedir(dir);
	}
	
	//処理：ソート
	sort(foldlist, count);
	
	//処理：分岐
	if(4<count)
	{
		char g;
		printf("以下のビルドフォルダが検出されました：\n");
		for(int a=0; a<count; a++)
		{
			printf("%s\n", foldlist[a]);
		}
		fflush(stdin);
		getch();
		
		do
		{
			system("cls");
			printf("最新四つのフォルダ：\n");
			for(int b=0; b<4; b++)
			{
				printf("%s\n", foldlist[b]);
			}
			printf("最新四つのフォルダ以外を削除します：\n");
			for(int b=4; b<count; b++)
			{
				printf("%s\n", foldlist[b]);
			}
			printf("上記のフォルダを削除します。よろしいですか。\n");
			printf("（１）はい　　　　　　　　　（０）いいえ\n");
			fflush(stdin);
			g = getch();
		}
		while((g!='1')&&(g!='0'));
		
		if(g == '1')
		{
			//shori
			for(int b=4; b<count; b++)
			{
				if(rmdir(foldlist[b]) == 0)
				{
					//
					printf("%sを削除しました。\n", foldlist[b]);
				}
				else
				{
					perror("rmdir");
				}
			}
			//shori
			printf("削除が完了しました。\n");
		}
		else if(g == '0')
		{
			printf("プログラムを終了する。\n");
		}
		else
		{
			return 1;
		}
	}
	else if((0<count)&&(count<=4))
	{
		printf("以下のビルドフォルダが検出されました：\n");
		for(int a=0; a<count; a++)
		{
			printf("%s\n", foldlist[a]);
		}
		printf("フォルダ数＜＝４のため、削除するフォルダがありません。\n");
		printf("プログラムを終了する。\n");
	}
	else
	{
		printf("検出されましたビルドフォルダがありません。\n");
		printf("プログラムを終了する。\n");
	}
	
	fflush(stdin);
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

void sort(char a[FOLD_AMOUNT][NAME_SIZE], int size)
{
	int count;
	char temp[NAME_SIZE];
	
	do
	{
		count = 0;
		
		for(int i=0; i<size-1; i++)
		{
			if((a[i][10]<a[i+1][10])||(a[i][10]==a[i+1][10]&&a[i][11]<a[i+1][11])||(a[i][10]==a[i+1][10]&&a[i][11]==a[i+1][11]&&a[i][12]<a[i+1][12])||(a[i][10]==a[i+1][10]&&a[i][11]==a[i+1][11]&&a[i][12]==a[i+1][12]&&a[i][13]<a[i+1][13])||(a[i][10]==a[i+1][10]&&a[i][11]==a[i+1][11]&&a[i][12]==a[i+1][12]&&a[i][13]==a[i+1][13]&&a[i][14]<a[i+1][14])||(a[i][10]==a[i+1][10]&&a[i][11]==a[i+1][11]&&a[i][12]==a[i+1][12]&&a[i][13]==a[i+1][13]&&a[i][14]==a[i+1][14]&&a[i][15]<a[i+1][15])||(a[i][10]==a[i+1][10]&&a[i][11]==a[i+1][11]&&a[i][12]==a[i+1][12]&&a[i][13]==a[i+1][13]&&a[i][14]==a[i+1][14]&&a[i][15]==a[i+1][15]&&a[i][16]<a[i+1][16])||(a[i][10]==a[i+1][10]&&a[i][11]==a[i+1][11]&&a[i][12]==a[i+1][12]&&a[i][13]==a[i+1][13]&&a[i][14]==a[i+1][14]&&a[i][15]==a[i+1][15]&&a[i][16]==a[i+1][16]&&a[i][17]<a[i+1][17])||(a[i][10]==a[i+1][10]&&a[i][11]==a[i+1][11]&&a[i][12]==a[i+1][12]&&a[i][13]==a[i+1][13]&&a[i][14]==a[i+1][14]&&a[i][15]==a[i+1][15]&&a[i][16]==a[i+1][16]&&a[i][17]==a[i+1][17]&&a[i][19]<a[i+1][19]))
			{
				for(int j=0; j<NAME_SIZE; j++)
				{
					temp[j] = a[i][j];
					a[i][j] = a[i+1][j];
					a[i+1][j] = temp[j];
				}
				count++;
			}
		}
	}
	while(count != 0);
}
