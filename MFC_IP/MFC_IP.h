
// MFC_IP.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_IPApp:
// �йش����ʵ�֣������ MFC_IP.cpp
//

class CMFC_IPApp : public CWinApp
{
public:
	CMFC_IPApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_IPApp theApp;