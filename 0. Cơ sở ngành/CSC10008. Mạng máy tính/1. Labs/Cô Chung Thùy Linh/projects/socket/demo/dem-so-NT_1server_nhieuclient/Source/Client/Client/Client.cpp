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
		CSocket client;
		char sAdd[1000];
		unsigned int port = 1234; //Cung port voi server
		AfxSocketInit(NULL);

		//1. Tao socket
		client.Create();

		// Nhap dic chi IP cua server
		printf("\n Nhap dia chi IP cua server: ");
		gets(sAdd);
		
		if (client.Connect(CA2W(sAdd),port))
		{
			printf("\n Client da ket noi toi server");
			//Nhan tu server, cho biet day la client thu may
			int id;
			client.Receive((char*)&id,sizeof(id),0);
			printf(" \nDay la client thu %d\n",id+1);
			srand( (unsigned)time( NULL ) );
			int numbers[2];
			numbers[0]=(int)(((float)rand()/RAND_MAX)*10);
			numbers[1]=(int)(((float)rand()/RAND_MAX)*10);

			//Gui so thu 1 cho server
			printf("Gui so thu 1, gia tri %d cho server\n",numbers[0]);
			client.Send((char*)&numbers[0],sizeof(int),0);
			//Gui so thu 2 cho server
			printf("Gui so thu 2, gia tri %d cho server\n",numbers[1]);
			client.Send((char*)&numbers[1],sizeof(int),0);
			//Nhan ket qua tra ve tu server
			int count;
			client.Receive((char*)&count,sizeof(count),0);
			printf("Tong so luong cac so nguyen to TAT CA cac client gui len:%d \n",count);
			client.Close();
		}
		else
			printf("Khong connect duoc toi server....");
		
	}
	getchar();
	return nRetCode;
}
