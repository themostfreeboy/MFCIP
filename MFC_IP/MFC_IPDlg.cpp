
// MFC_IPDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_IP.h"
#include "MFC_IPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_IPDlg 对话框




CMFC_IPDlg::CMFC_IPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_IPDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_IPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_IPDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFC_IPDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFC_IPDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BIP, &CMFC_IPDlg::OnBnClickedBip)
END_MESSAGE_MAP()


// CMFC_IPDlg 消息处理程序

BOOL CMFC_IPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_IPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_IPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_IPDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	exit(0);
}


void CMFC_IPDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	exit(0);
}


void CMFC_IPDlg::OnBnClickedBip()
{
	// TODO: 在此添加控件通知处理程序代码
	WSADATA wsadata;
    if(0 != WSAStartup(MAKEWORD(2, 2), &wsadata))//初始化
    {
		AfxMessageBox(_T("初始化网络环境失败!"),MB_OK,NULL);
    }

	if(!AfxSocketInit()) 
    {
		AfxMessageBox(_T("加载套接字库失败!"),MB_OK,NULL); 
    }

	char szHostName[MAX_PATH + 1];
    gethostname(szHostName, MAX_PATH);//获得本机主机名

    hostent* hn;
    hn = gethostbyname(szHostName);//根据本机主机名得到本机IP

	if(hn == NULL)
    {
		AfxMessageBox(_T("得到本机网络信息失败!"),MB_OK,NULL);
    }

	CString cstr_Hostname(szHostName);//把本机主机名char*换成CString形式

    char* strIPAddr = inet_ntoa(*(in_addr *)hn->h_addr_list[0]);//把IP换成字符串形式
    CString cstr_IP(strIPAddr);//把IP地址char*换成CString形式

    CString strHostName = _T("");
    strHostName.Format(_T("本机主机名：%s"),cstr_Hostname);
    SetDlgItemText(IDC_SHOSTNAME,strHostName);
 
    CString cstrIPAddr = _T("");
    cstrIPAddr.Format(_T("本机IP：%s"),cstr_IP);
    SetDlgItemText(IDC_SIP,cstrIPAddr);

    CString result = _T("");
    result.Format(_T("本机主机名：%s\n本机IP：%s"),cstr_Hostname,cstr_IP);
    AfxMessageBox(result,MB_OK,NULL);
}
