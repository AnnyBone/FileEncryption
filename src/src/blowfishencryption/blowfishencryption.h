
// blowfishencryption.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CblowfishencryptionApp:
// �йش����ʵ�֣������ blowfishencryption.cpp
//

class CblowfishencryptionApp : public CWinApp
{
public:
	CblowfishencryptionApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CblowfishencryptionApp theApp;