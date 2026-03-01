// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Client.h"
#include "afxsock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: MFC initialization failed\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.

		// Khoi tao Thu vien
		if( AfxSocketInit() == FALSE)
		{ 
			cout<<"Khong the khoi tao Socket Libraray";
			return FALSE; 
		}

		// Tao socket dau tien
		CSocket ClientSocket;
		ClientSocket.Create();

		// Ket noi den Server
		if(ClientSocket.Connect(_T("127.0.0.1"),1234)!=0)
		{
			cout<<"Ket noi toi Server thanh cong !!!"<<endl<<endl;

			char ClientMsg[100];		
			int MsgSize;
			char *temp;

			do 
			{
				// Nhan thong diep tu Server
				ClientSocket.Receive((char*)&MsgSize,sizeof(int),0); // Neu nhan loi thi tra ve la SOCKET_ERROR.			
				temp = new char[MsgSize +1];
				ClientSocket.Receive((char*)temp,MsgSize,0);

				// In thong diep ra
				temp[MsgSize] ='\0';
				cout<<"Server: "<<temp<<endl;
 
				cout <<"Client: ";
				cin.getline(ClientMsg,100);

				MsgSize = strlen(ClientMsg);

				// Gui di do dai thong diep de Server biet duoc do dai nay
				ClientSocket.Send(&MsgSize,sizeof(MsgSize),0);

				// Gui di thong diep voi do dai la MsgSize
				ClientSocket.Send(ClientMsg,MsgSize,0);
				delete temp;
			} while (1);
			
		}
		else
		{
			cout<<"Khong the ket noi den Server !!!"<<endl;
		}

		// Dong ket noi
		ClientSocket.Close();
	}

	return nRetCode;
}
