
// blowfishencryptionDlg.h : ͷ�ļ�
//
//#include "resource.h��
#include "stdafx.h"
#include "afxdialogex.h"
#include"string.h"
#include "../Enc_Blowfish/Blowfish.h"//C/C++��ͬ�ļ����°���ͷ�ļ��ķ�����#include��ʹ����һ���Ĺ���
#include "EncryptionInterface.h"
#include"MD5.h"
#include"Folderoperate.h"

#pragma once


// CblowfishencryptionDlg �Ի���
class CblowfishencryptionDlg : public CDialogEx
{
// ����
public:
	CblowfishencryptionDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BLOWFISHENCRYPTION_DIALOG };
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnchosesrcfile();
	afx_msg void OnBnClickedBtnenorden();

	//CIPHER _cipher;
	char _readFile[MAX_PATH];
	char _writeFile[MAX_PATH];
    char _password[100];
	char _password1[100];
	char md5hash[MAX_PATH];
	CString hashresult;//����ǰ��hashֵ
	CString hashresult1;//���ܺ��hashֵ
   // BlowFishEnc encryption;
	MD5 iMD5;
	Folderoperate folderoperate;
	CString readmima;
	CString readmima1;
	CString m_editmima;
	CString m_editmima1;
	afx_msg void OnBnClickedBtnchoosedestfile();
	void wipePwds(char *pwd, char *verify);
	afx_msg void OnBnClickedBtnsuaxin();
	afx_msg void OnBnClickedRadiojimi();
	afx_msg void OnBnClickedRadiojiemi();
	afx_msg void OnBnClickedRadioblowfish();
	afx_msg void OnBnClickedRadio3des();
	afx_msg void OnBnClickedLoginbutton();
	afx_msg void OnBnClickedButtonLogout();
	afx_msg void OnBnClickedButtonChange();

//��¼
public:
	//afx_msg void OnBnClickedLoginbutton();
	// ��½��ť
	CButton m_LonginButton;
	// ע��
	CButton m_logoutButton;
	// ��ʾ��½���û���
	CStatic m_static_adminName;

	//afx_msg void OnBnClickedButtonLogout();

	// �޸��û��������button
	CButton m_changeButton;
	//afx_msg void OnBnClickedButtonChange();

	afx_msg void OnStnClickedadminname();

	afx_msg void OnBnClickedTwice();

	afx_msg void OnBnClickedButtonKeys();
	afx_msg void OnBnClickedButtonOpenfile();

	CString m_editquerenmima;
	afx_msg void OnBnClickedButtonLog();

	CButton m_generatekeyButton;
	CButton m_openfileButton;

	//��ȡ�ļ�����
	CString	FilePath;
	int typetotal;
	// ���ҵ�ǰĿ¼�µ��ļ�
	void FindFiles(CString sPath);
	CStringArray typeArray;
	struct typeCount{
		CString type;
		int num;
	}TypeCount[1000];
	afx_msg void OnBnClickedButtonDriver();
};
