#pragma once

#include "Resource.h"  
// Change �Ի���

class Change : public CDialogEx
{
	DECLARE_DYNAMIC(Change)

public:
	Change(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Change();

 	char szCurrentPath[512];
	char szAdmin[64];
	char szPassWord[64];

// �Ի�������
	enum { IDD = IDD_CHANGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEditNewname();
	afx_msg void OnEnChangeEditNewpassword();
	afx_msg void OnEnChangeEditPasswordagine();
};
