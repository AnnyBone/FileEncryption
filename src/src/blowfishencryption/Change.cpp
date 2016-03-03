// Change.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Change.h"
#include "afxdialogex.h"
#include "resource.h"
#include "blowfishencryption.h"
#include "blowfishencryptionDlg.h"
#include <io.h>

#define CONFIG_FILE_NAME  "config.ini"
#define CONFIG_VALUE_LENGTH 64

// Change �Ի���

IMPLEMENT_DYNAMIC(Change, CDialogEx)

Change::Change(CWnd* pParent /*=NULL*/)
	: CDialogEx(Change::IDD, pParent)
{

}

Change::~Change()
{
}

void Change::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Change, CDialogEx)
	ON_BN_CLICKED(IDOK, &Change::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Change::OnBnClickedCancel)
END_MESSAGE_MAP()


// Change ��Ϣ�������


void Change::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������	

	memset(szPassWord,0,CONFIG_VALUE_LENGTH);
	memset(szAdmin,0,CONFIG_VALUE_LENGTH);

	memset(szCurrentPath,0,512);

	//ȡ��config.ini�ĵ�ַ
	GetCurrentDirectory(512, szCurrentPath);     
	strcat(szCurrentPath, "\\");
	strcat(szCurrentPath, CONFIG_FILE_NAME);
	//GetPrivateProfileString("admin", "admin", "admin", szAdmin, CONFIG_VALUE_LENGTH, szCurrentPath);
	//GetPrivateProfileString("password", "password", "password", szPassWord, CONFIG_VALUE_LENGTH, szCurrentPath);

	//����༭�����
	CString m_newName;
	CString m_newPassWord;
	CString m_passWordAgine;

	GetDlgItemText(IDC_EDIT_NEWNAME, m_newName);
	GetDlgItemText(IDC_EDIT_NEWPASSWORD, m_newPassWord);
	GetDlgItemText(IDC_EDIT_PASSWORDAGINE, m_passWordAgine);

	if (m_newName == "")
	{
		MessageBox("�û�������Ϊ�գ�����������");
	}
	else if (0 != strcmp(m_passWordAgine, m_newPassWord))
	{
		MessageBox("������������벻һ��,����������");
		SetDlgItemText(IDC_EDIT_PASSWORDAGINE, "");
		SetDlgItemText(IDC_EDIT_NEWPASSWORD, "");
	} 
	else 
	{
		MessageBox("����ɹ�");
		WritePrivateProfileString("admin", "admin", m_newName, szCurrentPath);
		WritePrivateProfileString("password","password" , m_newPassWord, szCurrentPath);
		CblowfishencryptionDlg *p = (CblowfishencryptionDlg*)GetParent();
		p->m_static_adminName.SetWindowTextA(m_newName);
	}

	CDialogEx::OnCancel();
}


void Change::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
