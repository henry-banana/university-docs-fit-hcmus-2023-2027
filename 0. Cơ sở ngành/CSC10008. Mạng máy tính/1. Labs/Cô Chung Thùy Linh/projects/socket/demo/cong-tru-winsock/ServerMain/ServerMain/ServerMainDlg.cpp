
// ServerMainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ServerMain.h"
#include "ServerMainDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CServerMainDlg dialog




CServerMainDlg::CServerMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServerMainDlg::IDD, pParent)
	, m_msgString(_T(""))	//Khoi tao
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_BOXCHAT, m_msgString);
}

BEGIN_MESSAGE_MAP(CServerMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SOCKET,SockMsg)	//Gan ham SockMsg vao su kien WM_SOCKET
	ON_BN_CLICKED(IDC_LISTEN, &CServerMainDlg::OnBnClickedListen)
	ON_BN_CLICKED(IDC_CANCEL, &CServerMainDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CServerMainDlg message handlers

BOOL CServerMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested=MAKEWORD(2,2);
	int err=WSAStartup(wVersionRequested,&wsaData);
	if (err!=0)
		MessageBox((LPCTSTR)"Can't initialize socket");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServerMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CServerMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CServerMainDlg::Split(CString src,CString des[2])
{
	int p1,p2;

	p1=src.Find(_T("\r\n"),0);
	des[0]=src.Mid(0,p1);

	p2=src.Find(_T("\r\n"),p1+1);
	des[1]=src.Mid(p1+2,p2-(p1+2));

}

char* CServerMainDlg::ConvertToChar(const CString &s)
{
	int nSize = s.GetLength();
	char *pAnsiString = new char[nSize+1];
	memset(pAnsiString,0,nSize+1);
	wcstombs(pAnsiString, s, nSize+1);
	return pAnsiString;
}

void CServerMainDlg::mSend(SOCKET &sk, CString &Command)
{
	int Len=Command.GetLength();
	Len+=Len;
	PBYTE sendBuff = new BYTE[1000];
	memset(sendBuff,0,1000);
	memcpy(sendBuff,(PBYTE)(LPCTSTR)Command, Len);
	send(sk,(char*)&Len,sizeof(Len),0);
	send(sk,(char*)sendBuff,Len,0);
	delete sendBuff;
}

int CServerMainDlg::mRecv(SOCKET &sk, CString &Command)
{
	PBYTE buffer = new BYTE[1000];
	memset(buffer,0, 1000);
	recv(sk ,(char*)&buffLength,sizeof(int),0);
	recv(sk,(char*)buffer,buffLength,0);
	TCHAR* ttc = (TCHAR*)buffer;
	Command = ttc;

	if(Command.GetLength()==0)
		return -1;
	return 0;

}

void CServerMainDlg::OnBnClickedListen()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	sockServer =socket(AF_INET,SOCK_STREAM,0);
	serverAdd.sin_family=AF_INET;
	serverAdd.sin_port=htons(PORT);
	serverAdd.sin_addr.s_addr =htonl(INADDR_ANY);
	bind(sockServer,(SOCKADDR*)&serverAdd,sizeof (serverAdd));
	listen(sockServer,5);
	int err =WSAAsyncSelect(sockServer,m_hWnd,WM_SOCKET,FD_READ|FD_ACCEPT|FD_CLOSE);
	if (err)
		MessageBox((LPCTSTR)"Cant call WSAAsyncSelect");	
	GetDlgItem(IDC_LISTEN)->EnableWindow(FALSE);
	number_Socket=0;
	pSock=new SockName[200];

	srand((unsigned)time(NULL));
	R = rand(); 

	m_msgString += "Dang lang nghe ket noi...\r\n";
	UpdateData(FALSE);
}

LRESULT CServerMainDlg::SockMsg(WPARAM wParam, LPARAM lParam)
{
	if (WSAGETSELECTERROR(lParam))
	{
		// Display the error and close the socket
		closesocket(wParam);
	}
	switch(WSAGETSELECTEVENT(lParam))
	{
	case FD_ACCEPT:
		{
			pSock[number_Socket].sockClient = accept(wParam,NULL,NULL);
			GetDlgItem(IDC_LISTEN)->EnableWindow(FALSE);
			number_Socket++;
			break;
		}
	case FD_READ:
		{

			int post = -1, dpos = -1;
			for(int i=0;i<number_Socket;i++)
			{
				if(pSock[i].sockClient==wParam)
				{
					if (i<number_Socket)
						post=i;
				}
			}

			CString temp;
			if(mRecv(pSock[post].sockClient, temp) < 0)
				break;
			Split(temp,strResult);
			int flag =_ttoi(strResult[0]);
			char* tem = ConvertToChar(strResult[1]);
			switch(flag)
			{
			case 1://Login
				{
					int post = -1, dpos = -1;
					for(int i=0;i<number_Socket;i++)
					{
						if(pSock[i].sockClient==wParam)
						{
							if (i<number_Socket)
								post=i;
						}
					}

					int t = 0;
					if(number_Socket>0)
					{
						for(int i=0;i<number_Socket;i++)
						{
							if(strcmp(tem,pSock[i].Name)==0)//Trung ten user
							{
								t=1;
								break;
							}
						}
					}

					if(t==0)
					{
						strcpy(pSock[post].Name,tem);
						Command=_T("1\r\n1\r\n");
						m_msgString+= strResult[1] + _T(" login\r\n");
						UpdateData(FALSE);
					}
					else
						Command=_T("1\r\n0\r\n");
					mSend(pSock[post].sockClient,Command);
					UpdateData(FALSE);
					break;
				}

			case 2:
				{
					int post = -1;
					for(int i=0;i<number_Socket;i++)
					{
						if(pSock[i].sockClient==wParam)
						{
							if (i<number_Socket)
								post=i;
						}
					}

					if(strResult[1]=="+")
					{

						R +=1;
						char pszNum [32] = {0};
						CString strTest (_itoa (R, pszNum, 10));

						m_msgString+=pSock[post].Name ;
						m_msgString+=" vua gui lenh +, R = ";
						m_msgString+= strTest;
						m_msgString+="\r\n";
						
						Command = "2\r\n";
						Command += strTest;
						Command +="\r\n";
					}
					else
					{
						R -=1;
						char pszNum [32] = {0};
						CString strTest (_itoa (R, pszNum, 10));

						m_msgString+=pSock[post].Name ;
						m_msgString+=" vua gui lenh -, R = ";
						m_msgString+= strTest;
						m_msgString+="\r\n";

						Command = "2\r\n";
						Command += strTest;
						Command += "\r\n";
					}
					
					mSend(pSock[post].sockClient,Command);
					UpdateData(FALSE);

					break;
				}
			}
			break;
		}

	case FD_CLOSE:
		{
			UpdateData();
			int post = -1;
			for(int i=0;i<number_Socket;i++)
			{
				if(pSock[i].sockClient==wParam)
				{
					if (i<number_Socket)
						post=i;
				}
			}

			m_msgString+=pSock[post].Name;
			m_msgString+=" logout\r\n";
			closesocket(pSock[post].sockClient);
			for(int j = post; j < number_Socket;j++)
			{
				pSock[post].sockClient = pSock[post+1].sockClient;
				strcpy(	pSock[post].Name,pSock[post+1].Name);				
			}
			number_Socket--;
			UpdateData(FALSE);
			break;
		}

	}
	return 0;
}

void CServerMainDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
