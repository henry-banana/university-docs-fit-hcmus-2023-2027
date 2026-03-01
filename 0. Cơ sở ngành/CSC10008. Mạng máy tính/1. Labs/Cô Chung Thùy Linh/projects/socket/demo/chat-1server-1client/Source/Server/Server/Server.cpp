// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Server.h"
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

		// Khoi tao thu vien Socket
		if( AfxSocketInit() == FALSE)
		{ 
			cout<<"Khong the khoi tao Socket Libraray";
			return FALSE; 
		}

		CSocket ServerSocket; //cha
		// Tao socket cho server, dang ky port la 1234, giao thuc TCP
		if(ServerSocket.Create(1234,SOCK_STREAM,NULL) == 0) //SOCK_STREAM or SOCK_DGRAM.
		{
			cout << "Khoi tao that bai !!!"<<endl;
			cout << ServerSocket.GetLastError();
			return FALSE;
		}
		else
		{
			cout << "Server khoi tao thanh cong !!!"<<endl;

			if(ServerSocket.Listen(1)==FALSE)
			{
				cout<<"Khong the lang nghe tren port nay !!!"<<endl;
				ServerSocket.Close();
				return FALSE;
			}
		}

		CSocket Connector;
		// Khoi tao mot socket de duy tri viec ket noi va trao doi du lieu
		if (ServerSocket.Accept(Connector))
		{
			cout <<"Da co Client ket Noi !!!"<<endl<<endl;

			char ServerMsg[100];
			int MsgSize;
			char *temp;

			do
			{
				cout <<"Server: ";
				cin.getline(ServerMsg,100);

				MsgSize = strlen(ServerMsg);

				// Gui di do dai thong diep de server biet duoc do dai nay
				Connector.Send(&MsgSize,sizeof(MsgSize),0);

				// Gui di thong diep voi do dai la MsgSize
				Connector.Send(ServerMsg,MsgSize,0);

				//Nhan thong diep tu Client
				Connector.Receive((char*)&MsgSize,sizeof(int),0); // Neu nhan loi thi tra ve la SOCKET_ERROR.		
				temp = new char[MsgSize +1];
				Connector.Receive((char*)temp,MsgSize,0);

				// In thong diep ra
				temp[MsgSize] ='\0';
				cout<<"Client: "<<temp<<endl;
				delete temp;
			}while (1);
		}
		Connector.Close();
		ServerSocket.Close();
	}

	return nRetCode;
}
