// Demo_Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Demo_Server.h"
#include "afxsock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

DWORD WINAPI function_cal(LPVOID arg)
{
	SOCKET* hConnected = (SOCKET*) arg;
	CSocket mysock;
	//Chuyen ve lai CSocket
	mysock.Attach(*hConnected);
	
	int number_continue = 0;

	do {
		fflush(stdin); 
		int number_a, number_b, number_result;
		char letter;
		//Nhan phep toan
		mysock.Receive(&letter, sizeof(letter), 0);
		//Nhan so thu nhat
		mysock.Receive(&number_a, sizeof(number_a), 0);
		//Nhan so thu hai
		mysock.Receive(&number_b, sizeof(number_b), 0);

		//So sanh neu client muon thuc hien phep cong
		if(letter == '+')
			number_result = number_a + number_b;
		else if (letter == '-')
			number_result = number_a  - number_b;
			
		//Gui ket qua tinh toan cho client
		mysock.Send(&number_result, sizeof(number_result), 0);

		//Nhan number xem client co tiep tuc hay khong
		mysock.Receive(&number_continue, sizeof(number_continue), 0);

	}while(number_continue);
	delete hConnected;
	return 0;
	//return 0;
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
			AfxSocketInit(NULL);
			CSocket server, s;
			DWORD threadID;
			HANDLE threadStatus;

			server.Create(4567);
			do {
				printf("Server lang nghe ket noi tu client\n");
				server.Listen();
				server.Accept(s);
				//Khoi tao con tro Socket
				SOCKET* hConnected = new SOCKET();
				//Chuyển đỏi CSocket thanh Socket
				*hConnected	= s.Detach();
				//Khoi tao thread tuong ung voi moi client Connect vao server.
				//Nhu vay moi client se doc lap nhau, khong phai cho doi tung client xu ly rieng
				threadStatus = CreateThread(NULL, 0, function_cal, hConnected, 0, &threadID);
			}while(1);
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


