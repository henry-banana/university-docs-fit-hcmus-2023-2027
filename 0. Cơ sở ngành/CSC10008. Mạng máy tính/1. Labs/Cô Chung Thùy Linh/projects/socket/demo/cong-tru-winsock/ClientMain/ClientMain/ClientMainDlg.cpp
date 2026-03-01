
// ClientMainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientMain.h"
#include "ClientMainDlg.h"
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


// CClientMainDlg dialog




CClientMainDlg::CClientMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClientMainDlg::IDD, pParent)
	, IP(_T(""))
	, m_msgString(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_IP, IP);
	DDX_Text(pDX, IDC_USERNAME, m_userName);
	DDX_Text(pDX, IDC_BOXCHAT, m_msgString);
}

BEGIN_MESSAGE_MAP(CClientMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE (WM_SOCKET, SockMsg)
	ON_BN_CLICKED(IDC_CONNECT, &CClientMainDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_LOGIN, &CClientMainDlg::OnBnClickedLogin)
END_MESSAGE_MAP()


// CClientMainDlg message handlers

BOOL CClientMainDlg::OnInitDialog()
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
		MessageBox(_T("Can't initialize socket"),_T("ERROR"), 0);

	IP="127.0.0.1";
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientMainDlg::OnPaint()
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
HCURSOR CClientMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CClientMainDlg::Split(CString src,CString des[2])
{
	int p1,p2;

	p1=src.Find(_T("\r\n"),0);
	des[0]=src.Mid(0,p1);

	p2=src.Find(_T("\r\n"),p1+1);
	des[1]=src.Mid(p1+2,p2-(p1+2));

}

char* CClientMainDlg::ConvertToChar(const CString &s)
{
	int nSize = s.GetLength();
	char *pAnsiString = new char[nSize+1];
	memset(pAnsiString,0,nSize+1);
	wcstombs(pAnsiString, s, nSize+1);
	return pAnsiString;
}

void CClientMainDlg::mSend(CString &Command)
{
	int Len=Command.GetLength();
	Len+=Len;
	PBYTE sendBuff = new BYTE[1000];
	memset(sendBuff,0,1000);
	memcpy(sendBuff,(PBYTE)(LPCTSTR)Command, Len);
	send(sClient,(char*)&Len,sizeof(Len),0);
	send(sClient,(char*)sendBuff,Len,0);
	delete sendBuff;
}

int CClientMainDlg::mRecv(CString &Command)
{
	PBYTE buffer = new BYTE[1000];
	memset(buffer,0, 1000);
	recv(sClient ,(char*)&buffLength,sizeof(int),0);
	recv(sClient,(char*)buffer,buffLength,0);
	TCHAR* ttc = (TCHAR*)buffer;
	Command = ttc;

	if(Command.GetLength()==0)
		return -1 ;
	return 0;
}

LRESULT CClientMainDlg::SockMsg(WPARAM wParam, LPARAM lParam)
{

	if (WSAGETSELECTERROR(lParam))
	{
		// Display the error and close the socket
		closesocket(wParam);
	}
	switch(WSAGETSELECTEVENT(lParam))
	{
	case FD_READ:
		{
			CString temp;
			if(mRecv(temp)<0)
				break;

			Split(temp,strResult);
			int flag1=_ttoi(strResult[0]);
			int flag2=_ttoi(strResult[1]);
			switch(flag1)
			{
			case 1:
				{
					if(flag2==1)
					{
						m_msgString+=_T("Dang nhap thanh cong\r\n");
						GetDlgItem(IDC_LOGIN)->EnableWindow(FALSE);
					}
					else
					{
						m_msgString+=_T("Dang nhap that bai\r\n");
						return FALSE;
					}
											
					UpdateData(FALSE);
					break;
				}

			case 2:
				{
					m_msgString+= "Server: R = ";
					m_msgString+= strResult[1];
					m_msgString+= "\r\n";
					UpdateData(FALSE);
					break;
				}
			}
			break;
		}
	case FD_CLOSE:
		{
			closesocket(sClient);
			m_msgString+=_T("Server da dong ket noi\r\n");
			GetDlgItem(IDC_LOGIN)->EnableWindow(TRUE);
			UpdateData(FALSE);
			break;
		}

	}
	return 0;
}

void CClientMainDlg::OnBnClickedConnect()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	sClient = socket(AF_INET, SOCK_STREAM, 0);
	hostent* host=NULL;
	if (sClient == INVALID_SOCKET)
	{
		MessageBox(_T("socket() failed"),_T("ERROR"), 0);
		return;
	}

	servAdd.sin_family = AF_INET;
	servAdd.sin_port = htons(PORT);

	char* cIP=ConvertToChar(IP);

	servAdd.sin_addr.s_addr = inet_addr(cIP);

	CStringA cpy_IP(IP); 

	if (servAdd.sin_addr.s_addr==INADDR_NONE)
	{
		host = (gethostbyname(cpy_IP));
		if (host == NULL)
		{
			MessageBox(_T("Khong the ket noi den server."),_T("ERROR"), 0);
		}
		CopyMemory(&servAdd.sin_addr, host->h_addr_list[0],
			host->h_length);
		return;
	}

	int err=connect(sClient,(struct sockaddr*)&servAdd,sizeof(servAdd));
	if (err==SOCKET_ERROR){
		MessageBox(_T("Ket noi that bai"),_T("ERROR"), 0);
		return;
	}

	WSAAsyncSelect(sClient,m_hWnd,WM_SOCKET,FD_READ|FD_CLOSE);
	m_msgString += _T("Ket noi thanh cong \r\n");
	UpdateData(FALSE);
}


void CClientMainDlg::OnBnClickedLogin()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_userName=="")
	{
		MessageBox(_T("Vui long nhap username"));
		return;
	}
	Command=_T("1\r\n");
	Command+= m_userName+_T("\r\n");

	mSend(Command);
}
