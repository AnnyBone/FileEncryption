
// blowfishencryptionDlg.cpp : ʵ���ļ�
//
#include"resource.h"
#include "stdafx.h"
#include "blowfishencryption.h"
#include "blowfishencryptionDlg.h"
#include "afxdialogex.h"
#include "../Enc_Blowfish/Blowfish.h"//C/C++��ͬ�ļ����°���ͷ�ļ��ķ�����#include��ʹ����һ���Ĺ���
#include "EncryptionInterface.h"
#include "run.h"
#include "MD5.h"
#include"Folderoperate.h"

#include "stdafx.h"
#include "afxdialogex.h"
#include "Screat.h"
#include "Change.h"

#include "Random.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//#ifndef EncryptionInterface.h
//#define EncryptionInterface.h
//#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CblowfishencryptionDlg �Ի���




CblowfishencryptionDlg::CblowfishencryptionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CblowfishencryptionDlg::IDD, pParent)
	, m_editquerenmima(_T(""))
{   //BlowFishEnc encryption;
	//BlowFishEnc encryption(const char *pwd);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//m_mima = _T("");
	m_editmima = _T("");
	m_editmima1 = _T("");
}

void CblowfishencryptionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_mima, m_mima);
	DDX_Text(pDX, IDC_EDITmima, m_editmima);
	DDX_Text(pDX, IDC_EDITquerenmima, m_editmima1);
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LoginButton, m_LonginButton);
	DDX_Control(pDX, IDC_BUTTON_LOGOUT, m_logoutButton);
	DDX_Control(pDX, IDC_adminName, m_static_adminName);

	DDX_Control(pDX, IDC_BUTTON_CHANGE, m_changeButton);



	DDX_Control(pDX, IDC_BUTTON_KEYS, m_generatekeyButton);
	DDX_Control(pDX, IDC_BUTTON_OPENFILE, m_openfileButton);
}

BEGIN_MESSAGE_MAP(CblowfishencryptionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Btnchosesrcfile, &CblowfishencryptionDlg::OnBnClickedBtnchosesrcfile)
	ON_BN_CLICKED(IDC_Btnenorden, &CblowfishencryptionDlg::OnBnClickedBtnenorden)
	ON_BN_CLICKED(IDC_Btnchoosedestfile, &CblowfishencryptionDlg::OnBnClickedBtnchoosedestfile)
	ON_BN_CLICKED(IDC_Btnsuaxin, &CblowfishencryptionDlg::OnBnClickedBtnsuaxin)
	ON_BN_CLICKED(IDC_RADIOjimi, &CblowfishencryptionDlg::OnBnClickedRadiojimi)
	ON_BN_CLICKED(IDC_RADIOjiemi, &CblowfishencryptionDlg::OnBnClickedRadiojiemi)
	ON_BN_CLICKED(IDC_RADIOblowfish, &CblowfishencryptionDlg::OnBnClickedRadioblowfish)
	ON_BN_CLICKED(IDC_RADIO3des, &CblowfishencryptionDlg::OnBnClickedRadio3des)
	ON_BN_CLICKED(IDC_LoginButton, &CblowfishencryptionDlg::OnBnClickedLoginbutton)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &CblowfishencryptionDlg::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &CblowfishencryptionDlg::OnBnClickedButtonChange)
	ON_BN_CLICKED(IDC_TWICE, &CblowfishencryptionDlg::OnBnClickedTwice)
	ON_BN_CLICKED(IDC_BUTTON_KEYS, &CblowfishencryptionDlg::OnBnClickedButtonKeys)
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &CblowfishencryptionDlg::OnBnClickedButtonOpenfile)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &CblowfishencryptionDlg::OnBnClickedButtonLog)
	ON_BN_CLICKED(IDC_BUTTON_DRIVER, &CblowfishencryptionDlg::OnBnClickedButtonDriver)
END_MESSAGE_MAP()


// CblowfishencryptionDlg ��Ϣ�������

BOOL CblowfishencryptionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CblowfishencryptionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CblowfishencryptionDlg::OnPaint()
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
HCURSOR CblowfishencryptionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//ѡ��Ҫ�ӽ��ܵ��ļ����ļ���
void CblowfishencryptionDlg::OnBnClickedBtnchosesrcfile()
{
	// TODO: Add your control notification handler code here
     char resultFile[MAX_PATH];
	 char destfile[MAX_PATH];
	  if((IsDlgButtonChecked(IDC_RADIOblowfish) != BST_CHECKED)&&(IsDlgButtonChecked(IDC_RADIO3des)!= BST_CHECKED)&&(IsDlgButtonChecked(IDC_TWICE)!= BST_CHECKED))
	  MessageBox("��ѡ������㷨");
	  else
	  {
		  if (IsDlgButtonChecked(IDC_RADIOjimi) == BST_CHECKED)//���Ϊ����
		  {  
			  if (IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//���Ϊ��һ�ļ�
			  {
				  CFileDialog filedlg(true);//�������ļ��Ի���
				  filedlg.m_ofn.lpstrTitle=(_T("ѡ������ļ�"));//��Ӵ򿪶Ի�����
				  filedlg.m_ofn.lpstrFilter=_T("All Files(*.*)\0*.*\0\0");//���öԻ������ļ�����
				  if(IDOK==filedlg.DoModal())
				  {
					  SetDlgItemText(IDC_srcfile,filedlg.GetPathName());//����ļ�·��
					  GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
					  
						  if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
						  strcat(resultFile,".enc");
					      if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
                          strcat(resultFile,".encD");
						  else if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
						  {
								strcat(resultFile,".encD.enc");
						  }
						  SetDlgItemText(IDC_destfile,resultFile);
					 // }
				  }
				  return;
			  }
			  if (IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//���Ϊ�ļ��м���
			  {

				  SetDlgItemText(IDC_srcfile,folderoperate.openFloder());
				  GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
				 // GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
				 // if(strlen(destfile)==0)
				  //{
					  //strcat(resultFile,".encD.enc");//Ŀ���ļ��ı�������ʾ��׺
					  SetDlgItemText(IDC_destfile,resultFile);
				  //}
				  return;
			  }
		  }
		  else if(IsDlgButtonChecked(IDC_RADIOjiemi) == BST_CHECKED)//���Ϊ����
		  {  
			  if (IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//���Ϊ��һ�ļ�
			  {
				  CFileDialog filedlg(FALSE);//���������ļ��Ի���
				  filedlg.m_ofn.lpstrTitle=(_T("��������ļ�"));//��Ӵ򿪶Ի�����
				  filedlg.m_ofn.lpstrFilter=_T("All Files(*.*)\0*.*\0\0");//���öԻ������ļ�����
				  if(IDOK==filedlg.DoModal())
				  {  
					  SetDlgItemText(IDC_srcfile,filedlg.GetPathName());
					  GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);//����ļ�·��
					  GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
					 
					  if(strlen(destfile)>4)
					  {
						  destfile[strlen(destfile)-4]=0;
						  if(resultFile!=destfile)
							  MessageBox("ȷ��Ҫ��дԴ�ļ��ļ���");
					  }
				  }
				  return;
			  }
			  if (IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//���Ϊ�ļ��н���
			  {

				  SetDlgItemText(IDC_destfile,folderoperate.openFloder());
				  GetDlgItemText(IDC_destfile,resultFile,MAX_PATH);
				  GetDlgItemText(IDC_srcfile,destfile,MAX_PATH);
				  if(strlen(destfile)==0)
				  {
					  //strcat(resultFile,".encD.enc");
					  SetDlgItemText(IDC_srcfile,resultFile);
				  }
				  return;
			  }
		  }

	  }

	return ;
}


//�ӽ���
void CblowfishencryptionDlg::OnBnClickedBtnenorden()
{
	// TODO: Add your control notification handler code here
	//�������·��������·��������
	char source[MAX_PATH];
	GetDlgItemText(IDC_srcfile, source, MAX_PATH);
	char dest[MAX_PATH];
	GetDlgItemText(IDC_destfile, dest, MAX_PATH);

	char tempfile[MAX_PATH];
	GetDlgItemText(IDC_srcfile, tempfile, MAX_PATH);
	if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED && IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)
	{
		strcat(tempfile,".encD");//����������жϣ��������ļ��м����к�׺����
	}
	/*
	if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED  && IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)
	{
		strcat(tempfile,".encD.enc");
	}
	*/
	char password[57];//��Կ1
	GetDlgItemText(IDC_EDITmima, password, 56);
	password[56]=0;
    char passverify[57];//��Կ2
	GetDlgItemText(IDC_EDITquerenmima, passverify, 56);
	passverify[56] = 0;

	//�жϼ������ü�·���Ƿ���ȷ
    strncpy(_password, password, 100);
	strncpy(_password1, passverify, 100);
	bool mark=true;//��־λ������ʱΪtrue������ʱΪfalse
    run runing;//����������һ������
	if (IsDlgButtonChecked(IDC_RADIOjimi) == BST_CHECKED)//���Ϊ���ܹ���
	{
		if (!PathFileExists(source))
		{
			MessageBox("�����ļ�������.", "����");
			wipePwds(password, passverify);
			return ;
		}

		strcpy(_readFile,source );
		strcpy(_writeFile, dest);
		const char*hashresultvalue;
		if(IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//��Ϊ��һ�ļ�����
		{
			//�ж��Ƿ�����ļ������Լ��
			//if(IsDlgButtonChecked(IDC_CHECKfile) == BST_CHECKED)
			//{
			//����MD5��������hashֵ
			//MD5 iMD5;
			hashresult=iMD5.md5file(_readFile);
			hashresultvalue=(LPCTSTR)hashresult;
			//}
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
				runing.processing(mark,_readFile,_writeFile,password);//����blowfish����/���ܺ���
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
				runing.desprocess(mark,_readFile,_writeFile,password,passverify);//����3DES�ӽ��ܺ���
			if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			{					
				runing.desprocess(mark,_readFile,tempfile,password,passverify);//����3DES�ӽ��ܺ���				
				runing.processing(mark,tempfile,_writeFile,password);//����blowfish����/���ܺ���
				runing.clearing(tempfile);
			}

			AfxMessageBox("�������");
			runing.clearing(_readFile);//����ɾ���ļ�������ɾ��Դ�ļ�			
			//��hashֵд�뵽������
			//if(IsDlgButtonChecked(IDC_CHECKfile) == BST_CHECKED)
			//{

			//MD5 iMD5;
			iMD5.writehashtofile(_writeFile,hashresultvalue);
			//}
			//������д�뵽�����ļ���
            runing.writemimatofile(_writeFile,password);//�����루1��д�뵽������
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED||(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED))//��Ϊ3DES���ܣ�Ҫ�ֿ�������Կ���ã������
			{
			   char *str=";";
	           runing.writemimatofile(_writeFile,str);//�ã��ֿ�������Կ
			   runing.writemimatofile(_writeFile,passverify);//������2д�뵽������
			}
            wipePwds(password, passverify);
			return;
		}

		if(IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//��Ϊָ��Ŀ¼����
		{
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
				folderoperate.EncDencFolder(mark,source,dest,password);//����blowfish�ļ��мӽ��ܺ���
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
				folderoperate.EncDencDESFolder(mark,source,dest,password,passverify);//����3des�ļ��мӽ��ܺ���
			if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			{
				folderoperate.EncDencDESFolder(mark,source,tempfile,password,passverify);
				folderoperate.EncDencFolder(mark,tempfile,dest,password);
				//runing.clearing(tempfile);//ǰ���Ѿ�ɾ�����ٴ�ɾ���ᱨ��
			}
			AfxMessageBox("�������");
			wipePwds(password, passverify);
			return;
		}
	}
	else if (IsDlgButtonChecked(IDC_RADIOjiemi) == BST_CHECKED)//��Ϊ���ܹ���
	{
		if (!PathFileExists(dest))
		{
			MessageBox("Ҫ�����ļ�������.", "����");
			wipePwds(password, passverify);
			return ;
		}
		mark=false;//���ܱ�־
		strcpy(_readFile, dest);
		strcpy(_writeFile, source);
		//����֮ǰ�������ж�ȡhash
		 CString readhash;
       if(IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//���Ϊ�ļ�����
	    {
			//if(IsDlgButtonChecked(IDC_CHECKfile) == BST_CHECKED)//��������ļ�����
			//{
			if((IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED) ||(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED))//��Ϊ3DES
			{
				readmima1=runing.readmimafromfile(_readFile);//�������ж�ȡ����2
				readmima=runing.readmima1fromfile(_readFile,readmima1.GetLength());//�������ж�ȡ����1
			// runing.rebackencfile(_readFile,readmima1.GetLength()+1);//ɾ������2�ͷֺţ���ԭ����
			}
			else if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			{
				readmima=runing.readmimafromfile(_readFile);//�������ж�ȡ����
			}
			//���������жϱ���������λ�ã�������벻�ԣ����ܶ��������κδ��������޷����ܣ��ж�����ٻ�ԭ����
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED||(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED))//���Ϊ3DES�ж���������
			{
               if((readmima!=password)&&(readmima1!=passverify))
			   { 
				   AfxMessageBox("�������������������������");
			       return;
			   }
              runing.rebackencfile(_readFile,readmima.GetLength()+readmima1.GetLength()+2);//ɾ�����룬��ԭ����,ע�⣺�������ж�������󣬲���ɾ�������е�����
			}
			else if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			{
				if(readmima!=password)//���Ϊblowfish�ж���������
				{
					{
						AfxMessageBox("�������������������������");
						return;
					}
				}
				runing.rebackencfile(_readFile,readmima.GetLength()+1);//ɾ�����룬��ԭ����,ע�⣺�������ж�������󣬲���ɾ�������е�����
			}
			readhash=iMD5.readhashfromfile(_readFile);//�������ж�ȡhash
			runing.rebackencfile(_readFile,32);//ɾ�����Ľ�β��hashֵ���ڽ��н���
			// }
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			{
				runing.processing(mark,_readFile,_writeFile,password);//����blowfish����/���ܺ���
				hashresult1=iMD5.md5file(_writeFile);
			}
			if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
			{
				runing.desprocess(mark,_readFile,_writeFile,password,passverify);//����3DES�ӽ��ܺ���
				hashresult1=iMD5.md5file(_writeFile);
			}
			else if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			{
				runing.processing(mark,_readFile,tempfile,password);//blowfish
				runing.desprocess(mark,tempfile,_writeFile,password,passverify);//3des
				runing.clearing(tempfile);//ɾ����ʱ�ļ�
				hashresult1=iMD5.md5file(_writeFile);
			}
			//runing.processing(mark,_readFile,_writeFile,password);//���ü���/���ܺ���
			AfxMessageBox("�������");
			runing.clearing(_readFile);//����ɾ���ļ�������ɾ������
			wipePwds(password, passverify);

			//�ж��Ƿ�����ļ������Լ��
			// if(IsDlgButtonChecked(IDC_CHECKfile) == BST_CHECKED)
			// {
			//����MD5��������hashֵ
			// MD5 iMD5;
			//hashresult1=iMD5.md5file(_writeFile);

			
			if(hashresult1==readhash)
			{
				MessageBox("���ܽ��ܺ��ļ�����������");
			}
			else if(hashresult1!=readhash)
			{
				MessageBox("���ܽ��ܺ��ļ����ƻ�");
			}
			
             return;
		 }
		  
	   
	   if(IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//��Ϊָ��Ŀ¼����
	   {   
		   int mimamark;
		   if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			    mimamark= folderoperate.EncDencFolder(mark,source,dest,password);//����blowfish�ļ��м��ܺ���
		   if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
			    mimamark=folderoperate.EncDencDESFolder(mark,source,dest,password,passverify);//����3des�ļ��м��ܺ���
		   if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
		   {
			    mimamark= folderoperate.EncDencFolder(mark,tempfile,dest,password);
				mimamark=folderoperate.EncDencDESFolder(mark,source,tempfile,password,passverify);
		   }
		  if(mimamark==1)
		  return;
		  AfxMessageBox("�������");
		  wipePwds(password, passverify);
          return ;
		}		
	}	
	else
	{
		MessageBox("��ѡ���ļ�������ʽ", "����");
	}
	//wipePwds(password, passverify);
	return ;	
}

//����·��ѡ��
void CblowfishencryptionDlg::OnBnClickedBtnchoosedestfile()
{
	// TODO: Add your control notification handler code here
	char resultFile[MAX_PATH]; 
	char destfile[MAX_PATH];
	//CFileDialog filedlg(mark);//�������ļ��Ի���
	if (IsDlgButtonChecked(IDC_RADIOjimi) == BST_CHECKED)//���Ϊ����
	{  
		if (IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//���Ϊ��һ�ļ�
		{
			CFileDialog filedlg(FALSE);//���������ļ��Ի���
			filedlg.m_ofn.lpstrTitle=(_T("��������ļ�"));//��Ӵ򿪶Ի�����
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
			{
				filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc)\0*.enc\0\0");//���öԻ������ļ�����	
			}
            else if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
			{
				filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.encD)\0*.encD\0\0");//���öԻ������ļ�����	
			}
			/*
			else if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			{
				filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc.encD)\0*.enc.encD\0\0");
			}
			*/

			if(IDOK==filedlg.DoModal())
			{  
				SetDlgItemText(IDC_destfile,filedlg.GetPathName());
				GetDlgItemText(IDC_destfile,destfile,MAX_PATH);//����ļ�·��
				GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
				if(strlen(resultFile)!=0)
				{
					strcat(resultFile,".enc");
					if(resultFile!=destfile)
						MessageBox("ȷ��Ҫ��д�����ļ���");
				}
			}
			return;
		}
		if (IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//���Ϊ�ļ��м���
		  {
            
			 SetDlgItemText(IDC_destfile,folderoperate.openFloder());
			 GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
			 GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
				 if(strlen(resultFile)==0)
				 {
					 //strcat(resultFile,".enc");
					 SetDlgItemText(IDC_srcfile,destfile);
				 }
			 return;
		  }

	} 
	else if(IsDlgButtonChecked(IDC_RADIOjiemi) == BST_CHECKED)//���Ϊ����
	{
		if (IsDlgButtonChecked(IDC_RADIOfileenc) == BST_CHECKED)//���Ϊ��һ�ļ�
		{
			CFileDialog filedlg(true);//�������ļ��Ի���
			filedlg.m_ofn.lpstrTitle=(_T("ѡ������ļ�"));//��Ӵ򿪶Ի�����
			if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)
            filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc)\0*.enc\0\0");//���öԻ������ļ�����		  
            else if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)
            filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.encD)\0*.encD\0\0");//���öԻ������ļ�����		               
			/*
			else if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
			filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc.encD)\0*.encD\0\0");
			*/	
			//filedlg.m_ofn.lpstrFilter=_T("Encrypted Files (*.enc)\0*.enc\0\0");//���öԻ������ļ�����
			if(IDOK==filedlg.DoModal())
			{

				SetDlgItemText(IDC_destfile,filedlg.GetPathName());//����ļ�·��
				GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
				if(IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)//��Ϊ3DES+blowfish����ԭ����·��
					destfile[strlen(destfile)-9]=0;
				else if(IsDlgButtonChecked(IDC_RADIOblowfish) == BST_CHECKED)//��Ϊblowfish����ԭ����·��
					destfile[strlen(destfile)-4]=0;
				else if(IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED)//��Ϊ3DES����ԭ����·��
				{
					destfile[strlen(destfile)-5]=0;
					strcpy(resultFile,destfile);
					SetDlgItemText(IDC_srcfile,resultFile);
				}
			}
			return;
		}
		if (IsDlgButtonChecked(IDC_RADIOfolderenc) == BST_CHECKED)//���Ϊ�ļ��н���
		  {
            
			 SetDlgItemText(IDC_destfile,folderoperate.openFloder());
			 GetDlgItemText(IDC_destfile,destfile,MAX_PATH);
			// GetDlgItemText(IDC_srcfile,resultFile,MAX_PATH);
				 //if(strlen(resultFile)==0)
				 //{
					 //strcat(resultFile,".enc");
					 SetDlgItemText(IDC_srcfile,destfile);
				// }
			 return;
		  }
	}

	
	return ;


}

//�����������Ϊ��
void CblowfishencryptionDlg::wipePwds(char *pwd, char *verify)
{
	if (pwd != 0)		ZeroMemory(pwd, 57);
	if (verify != 0)	ZeroMemory(verify, 57);
}

//�������
void CblowfishencryptionDlg::OnBnClickedBtnsuaxin()
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_EDITmima,0);
	SetDlgItemText(IDC_EDITquerenmima,0);
	SetDlgItemText(IDC_srcfile,0);
	SetDlgItemText(IDC_destfile,0);

}

//���ѡ������ļ���������Ӧ��ť
void CblowfishencryptionDlg::OnBnClickedRadiojimi()
{
	// TODO: Add your control notification handler code here
   GetDlgItem(IDC_Btnchosesrcfile)->EnableWindow(true);//ʹ����·��ѡ��ť��Ч
   GetDlgItem(IDC_Btnchoosedestfile)->EnableWindow(false);//ʹ����·��ѡ��ť��Ч

}

//���ѡ������ļ���������Ӧ��ť
void CblowfishencryptionDlg::OnBnClickedRadiojiemi()
{
	// TODO: Add your control notification handler code here
	 GetDlgItem(IDC_Btnchosesrcfile)->EnableWindow(false);//ʹ����·��ѡ��ť��Ч
	 GetDlgItem(IDC_Btnchoosedestfile)->EnableWindow(true);//ʹ����·��ѡ��ť��Ч
}

//��Ϊblowfish����Կ2�������Ч
void CblowfishencryptionDlg::OnBnClickedRadioblowfish()
{
	// TODO: Add your control notification handler code here
	 GetDlgItem(IDC_EDITquerenmima)->EnableWindow(false);//ʹ����·��ѡ��ť��Ч

}


//��Ϊblowfish��������Կ�������Ч
void CblowfishencryptionDlg::OnBnClickedRadio3des()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDITquerenmima)->EnableWindow(true);//ʹ����·��ѡ��ť��Ч
}


void CblowfishencryptionDlg::OnBnClickedLoginbutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Screat dlg;
	dlg.DoModal();
}


void CblowfishencryptionDlg::OnBnClickedButtonLogout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_LonginButton.ShowWindow(SW_SHOW);
	
	m_logoutButton.ShowWindow(SW_HIDE);
	m_changeButton.ShowWindow(SW_HIDE);
	m_static_adminName.ShowWindow(SW_HIDE);
}


void CblowfishencryptionDlg::OnBnClickedButtonChange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Change dlg;
	dlg.DoModal();
}


void CblowfishencryptionDlg::OnBnClickedTwice()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CblowfishencryptionDlg::OnBnClickedButtonKeys()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	//���������ԿΪ�գ����Զ�������Կ������
	if( m_editmima == "")
	{
		CString szKey2;
		srand(time(NULL));
		char name[LEN_NAME + 2];
		CRandom random;
		szKey2 = random.rand_str(name,LEN_NAME);
		if (IsDlgButtonChecked(IDC_RADIO3des) == BST_CHECKED || IsDlgButtonChecked(IDC_TWICE) == BST_CHECKED)
		{
			m_editmima = szKey2;
			m_editmima1 = szKey2;
		} else {
			m_editmima = szKey2;
		}
	}

	if(m_editmima1 == "")
	{
		m_editmima1 = m_editmima;
	}

	UpdateData(FALSE);

	//����ֱ��ƴ�������ʱ���ʹ�ַ�������
	//���¸���һ�½���,�ӽ����ж�ȡ�Ͳ�����ִ˴���
	UpdateData(TRUE);
	
	  

	UpdateData(FALSE);

	CTime time; 
	time =CTime::GetCurrentTime();//��õ�ǰʱ�� 
	CString timeStr = time.Format("\r\n %Y-%m-%d %H:%M:%S ");

	//���ַ�������Ϊ ʱ��+����
	CString str = _T("�����롿��");
	str =  timeStr + str ;
	str += m_editmima;

	CFile file( KEYFILE_NAME, CFile::modeNoTruncate| CFile::modeWrite);
	file.SeekToEnd();
	file.Write(str,strlen(str));
	file.Close();
}


void CblowfishencryptionDlg::OnBnClickedButtonOpenfile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str = _T("notepad.exe ");
	str += KEYFILE_NAME;
	::WinExec(str, SW_SHOW);
}


void CblowfishencryptionDlg::OnBnClickedButtonLog()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*
	CString str = _T("notepad.exe ");
	str += KEYFILE_NAME;
	::WinExec(str, SW_SHOW);
	*/
}


void CblowfishencryptionDlg::OnBnClickedButtonDriver()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
/**
	ShellExecute(
		NULL,
		"open",
		"sc",
		"start encryptengine",
		NULL,
		SW_HIDE
		);

*/

	CString csCaption;
	GetDlgItemText(IDC_BUTTON_DRIVER,csCaption);

	if(csCaption == "��������")
	{
		SetDlgItemText(IDC_BUTTON_DRIVER,"�ر�����");



		ShellExecute(
			NULL,
			"open",
			"sc",
			"start encryptengine",
			NULL,
			SW_HIDE
			);

	}

	if(csCaption == "�ر�����")
	{
		SetDlgItemText(IDC_BUTTON_DRIVER,"��������");
		ShellExecute(
			NULL,
			"open",
			"sc",
			"stop encryptengine",
			NULL,
			SW_HIDE
			);
	}

}
