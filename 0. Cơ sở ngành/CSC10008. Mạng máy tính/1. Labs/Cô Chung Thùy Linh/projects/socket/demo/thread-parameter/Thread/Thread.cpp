// Thread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Thread.h"
#include "conio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

typedef struct
{
	int i;
	char s[100];
}MyStruct;


int nCount=0;
int bESCPressed = 0;

DWORD WINAPI CounterThread(LPVOID lp)
{
	MyStruct a;
	a = *(MyStruct*)lp;
	 while (1)
	 {
		nCount++;
		Sleep(100);
		printf("%s\n",a.s);
	 }
	 
	 return 0;
}

DWORD WINAPI GetKeyThread(LPVOID)
{ 	
	do 
	{
		bESCPressed = (_getch() == 27);
		printf("%d\n", nCount);
    } while (!bESCPressed);

	return 0;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
			printf("\nChuong trinh tang bien dem nCount (2 tieu trinh)");
			printf("\nNhan ESC de thoat khoi thread va chuong trinh\n");
		
			DWORD dwCounterThreadId;
			DWORD dwGetKeyThreadId;
		
			HANDLE hCounterThread;
			HANDLE hGetKeyThread;
		
			MyStruct b;
			b.i = 10;
			strcpy(b.s,"Hello");

			hCounterThread = CreateThread(NULL, 0, CounterThread, (LPVOID)&b, 0, &dwCounterThreadId);
			hGetKeyThread = CreateThread(NULL, 0, GetKeyThread, NULL, 0, &dwGetKeyThreadId);
		 		
			while (!bESCPressed);	// Chuong trinh dung lai de cho, neu khong thread chinh tat thi cac thread con cung tat theo
			return 0;
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}