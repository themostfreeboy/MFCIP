
// MFC_IPDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_IP.h"
#include "MFC_IPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_IPDlg �Ի���




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


// CMFC_IPDlg ��Ϣ�������

BOOL CMFC_IPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_IPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_IPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_IPDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	exit(0);
}


void CMFC_IPDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	exit(0);
}


void CMFC_IPDlg::OnBnClickedBip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	WSADATA wsadata;
    if(0 != WSAStartup(MAKEWORD(2, 2), &wsadata))//��ʼ��
    {
		AfxMessageBox(_T("��ʼ�����绷��ʧ��!"),MB_OK,NULL);
    }

	if(!AfxSocketInit()) 
    {
		AfxMessageBox(_T("�����׽��ֿ�ʧ��!"),MB_OK,NULL); 
    }

	char szHostName[MAX_PATH + 1];
    gethostname(szHostName, MAX_PATH);//��ñ���������

    hostent* hn;
    hn = gethostbyname(szHostName);//���ݱ����������õ�����IP

	if(hn == NULL)
    {
		AfxMessageBox(_T("�õ�����������Ϣʧ��!"),MB_OK,NULL);
    }

	CString cstr_Hostname(szHostName);//�ѱ���������char*����CString��ʽ

    char* strIPAddr = inet_ntoa(*(in_addr *)hn->h_addr_list[0]);//��IP�����ַ�����ʽ
    CString cstr_IP(strIPAddr);//��IP��ַchar*����CString��ʽ

    CString strHostName = _T("");
    strHostName.Format(_T("������������%s"),cstr_Hostname);
    SetDlgItemText(IDC_SHOSTNAME,strHostName);
 
    CString cstrIPAddr = _T("");
    cstrIPAddr.Format(_T("����IP��%s"),cstr_IP);
    SetDlgItemText(IDC_SIP,cstrIPAddr);

    CString result = _T("");
    result.Format(_T("������������%s\n����IP��%s"),cstr_Hostname,cstr_IP);
    AfxMessageBox(result,MB_OK,NULL);
}
