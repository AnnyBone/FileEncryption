// Screat.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Resource.h"
#include "Screat.h"
#include "afxdialogex.h"
#include <io.h>
#include "blowfishencryptionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define CONFIG_FILE_NAME   "config.ini"
#define CONFIG_VALUE_LENGTH 64


// Screat �Ի���

IMPLEMENT_DYNAMIC(Screat, CDialogEx)

Screat::Screat(CWnd* pParent /*=NULL*/)
	: CDialogEx(Screat::IDD, pParent)
{

}

Screat::~Screat()
{
}

void Screat::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Screat, CDialogEx)
	ON_BN_CLICKED(IDOK, &Screat::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Screat::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT_ADMINAME, &Screat::OnEnChangeEditAdminame)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &Screat::OnEnChangeEditPassword)
END_MESSAGE_MAP()


// Screat ��Ϣ�������


void Screat::OnBnClickedOk()
{
	//�Ӵ��ڶ�����û���������
	CString gtAdmin;
	CString gtPassWord;

	memset(szPassWord, 0, CONFIG_VALUE_LENGTH);
	memset(szAdmin, 0, CONFIG_VALUE_LENGTH);
	memset(szCurrentPath, 0, 512);

	GetCurrentDirectory(512, szCurrentPath);     //ȡ��config.ini�ĵ�ַ
	strcat(szCurrentPath, "\\");
	strcat(szCurrentPath, CONFIG_FILE_NAME);

	if(-1 == access(szCurrentPath, 0))    //ini�ļ�������
	{
		MessageBox("���������ĵ�������","��ʾ��Ϣ");
	}
	else
	{
		GetDlgItemText(IDC_EDIT_ADMINAME,gtAdmin);
		GetDlgItemText(IDC_EDIT_PASSWORD,gtPassWord);

		GetPrivateProfileString("admin", "admin", "admin", szAdmin, CONFIG_VALUE_LENGTH, szCurrentPath);
		GetPrivateProfileString("password", "password", "password", szPassWord, CONFIG_VALUE_LENGTH, szCurrentPath);



		if ((0 == strcmp(szAdmin,gtAdmin))&&(0 == strcmp(szPassWord,gtPassWord)))
		{
			MessageBox("��½�ɹ���","��ʾ��Ϣ");
			CblowfishencryptionDlg *p = (CblowfishencryptionDlg*)GetParent();
			p->m_LonginButton.ShowWindow(SW_HIDE);//���ص�½����
			p->m_logoutButton.ShowWindow(SW_SHOW);//��ʾע�����޸Ľ�
			p->m_changeButton.ShowWindow(SW_SHOW);
			p->m_static_adminName.ShowWindow(SW_SHOW);
			p->m_static_adminName.SetWindowTextA(gtAdmin);

			p->m_generatekeyButton.ShowWindow(SW_SHOW);
			p->m_openfileButton.ShowWindow(SW_SHOW);//��ʾ���������Կ�İ�ť
			CDialogEx::OnCancel();
		}
		else
		{
			MessageBox("�û������������","��ʾ��Ϣ");
			SetDlgItemText(IDC_EDIT_PASSWORD,"");
		}
	}


	//CDialogEx::OnOK();
}


void Screat::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void Screat::OnEnChangeEditAdminame()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Screat::OnEnChangeEditPassword()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
