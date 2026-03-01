
// ClientMainDlg.h : header file
//

#pragma once
#define PORT 25000
#define WM_SOCKET WM_USER+2

// CClientMainDlg dialog
class CClientMainDlg : public CDialogEx
{
// Construction
public:
	CClientMainDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CLIENTMAIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	LRESULT SockMsg(WPARAM wParam,LPARAM lParam);
	char* ConvertToChar(const CString &s);
	void Split(CString src,CString des[2]);
	void mSend(CString &Command);
	int mRecv(CString &Command);

	SOCKET sClient;
	sockaddr_in servAdd;
	CString Command;
	int	buffLength;
	CString strResult[2];
	CString m_msgString;
	CString IP;
	CString m_userName;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedLogin();
};
