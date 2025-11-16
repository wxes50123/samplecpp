#include "windows.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SYSTEMTIME tm;
	char s[80];
	int iRet;
	
	GetLocalTime(&tm);
	int tmh = tm.wHour;
	/*
	iRet = MessageBox(NULL, "?", "MsgBox", MB_YESNO);
	
	if (iRet == IDYES)
	{
		lstrcpy(s, "yes");
	}
	else if (iRet == IDNO)
	{
		lstrcpy(s, "no");
	}
	*/
	iRet = MessageBox(NULL, "?", "MsgBox", MB_OK);
	
	return 0;
}
