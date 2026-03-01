// ServerDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "stdlib.h"
#include "time.h"

#define PORT 25000
#define WM_SOCKET WM_USER+1

// CServerDlg dialog
class CServerDlg : public CDialog
{
	// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	enum { IDD = IDD_SERVER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	LRESULT SockMsg(WPARAM wParam, LPARAM lParam);
	char* ConvertToChar(const CString &s);
	void Split(CString src,CString des[2]);
	void mSend(SOCKET sk, CString Command);
	int mRecv(SOCKET sk, CString &Command);

	struct SockName
	{

		SOCKET sockClient;
		char Name[200];
	};

	SOCKET sockServer,sockClient,flag,sclient;
	struct sockaddr_in serverAdd;
	int msgType;
	int buffLength,t,lenguser,flagsend,kq, count_sock;
	int number_Socket;
	int first_send;
	SockName *pSock;
	CString strResult[2];
	CString Command;
	int R;


	CString m_msgString;
	afx_msg void OnBnClickedListen();
	afx_msg void OnBnClickedCancel();
};
