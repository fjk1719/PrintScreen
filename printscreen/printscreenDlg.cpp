// printscreenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "printscreen.h"
#include "printscreenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CprintscreenDlg �Ի���




CprintscreenDlg::CprintscreenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CprintscreenDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CprintscreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CprintscreenDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HOTKEY()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CprintscreenDlg::OnBnClickedOk)
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()


// CprintscreenDlg ��Ϣ�������

BOOL CprintscreenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	CreateRun();
	//ע��ϵͳ�ȼ�
	
	if(!RegisterHotKey(this->m_hWnd,100,0,VK_HOME))
	{
		MessageBox("�ȼ�ע��ʧ�ܳ����˳�");
		exit(0);
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CprintscreenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CprintscreenDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CprintscreenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CprintscreenDlg::OnBnClickedOk()
{
// 	TCHAR szPath[MAX_PATH] = {0};
// 	SHGetSpecialFolderPath(m_hWnd, szPath, CSIDL_DESKTOP, FALSE);
// 	//MessageBox(szPath);
// 	int x;
// 	srand( (unsigned)time( NULL ) ); //srand()��������һ���Ե�ǰʱ�俪ʼ���������
// 	x=rand()%100;
// 	CString filename;
// 	filename.Format("\\%d.jpg",x);
// 	strcat_s(szPath,filename.GetBuffer(filename.GetLength()));
// 
// 	//ʵ�ֽ���Ϊλͼ
// 	HDC hdc = ::GetDC(NULL); // ��ȡ��ĻDC�ľ��
// 	CDC screenDC; // �������ĻDC����
// 	screenDC.Attach(hdc); // ճ����ĻDC���
// 	CDC mdc; // ������ڴ�DC����
// 	mdc.CreateCompatibleDC(&screenDC); // ��������ĻDC���ݵ��ڴ�DC
// 	CBitmap bmp, *pOldBmp; // ����λͼ�����ָ��
// 	int w = GetDeviceCaps(hdc, HORZRES); // ��ȡ��Ļ�����أ�
// 	int h = GetDeviceCaps(hdc, VERTRES); // ��ȡ��Ļ�ߣ����أ�
// 	bmp.CreateCompatibleBitmap(&screenDC, w, h); // ��������ĻDC���ݵ�λͼ����
// 	pOldBmp = mdc.SelectObject(&bmp); // ��λͼѡ���ڴ�DC
// 	ShowWindow(SW_HIDE); // ���س��򴰿�
// 	Sleep(100); // ����һ�Σ�0.1�룩ʱ��
// 	mdc.BitBlt(0, 0, w, h, &screenDC, 0, 0, SRCCOPY); // ץȡ��Ļ��ͼ���ڴ�DC�е�ͼ��
// 	ShowWindow(SW_SHOW); // ��ʾ���򴰿�
// 
// 	//����Ϊjpg��ʽ
// 	CImage img;
// 	img.Attach(bmp);
// 	img.Save(szPath,Gdiplus::ImageFormatJPEG);
// 	img.Save("C:\\123.bmp");
// 	mdc.SelectObject(pOldBmp);
// 	bmp.DeleteObject();
// 	screenDC.Detach();
// 	::ReleaseDC(NULL, hdc);















	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	//�����ļ�����·��
	TCHAR szPath[MAX_PATH] = {0};
	SHGetSpecialFolderPath(m_hWnd, szPath, CSIDL_DESKTOP, FALSE);
	//MessageBox(szPath);
	int x;
	srand( (unsigned)time( NULL ) ); //srand()��������һ���Ե�ǰʱ�俪ʼ���������
	x=rand()%100;
	CString filename;
	filename.Format("\\%d.jpg",x);
	strcat_s(szPath,filename.GetBuffer(filename.GetLength()));
// 	//////////////////////////////////////////////////////////////////////////
// 	//ģ�ⰴ��ʵ�ֱ������ݵ������
	//ShowWindow(SW_HIDE); // ���س��򴰿�
	//Sleep(100); // ����һ�Σ�0.1�룩ʱ��
	keybd_event(44,0,0,0);
	Sleep(100);
	keybd_event(44,0,0,0);
	Sleep(500);
	//ShowWindow(SW_SHOW); // ��ʾ���򴰿�

///////////////////////////////////////////////////////////////////
	//
	if (OpenClipboard())
	{
		if (IsClipboardFormatAvailable(CF_BITMAP))
		{
			HBITMAP handle=(HBITMAP)GetClipboardData(CF_BITMAP);
			CBitmap * bmp=CBitmap::FromHandle(handle);
			//int x=SaveBitmapToFile(handle,"ssss.bmp");
			
			
		
				CImage img;
			img.Attach(*bmp);
			
		img.Save(szPath,Gdiplus::ImageFormatJPEG);

		}
	}
	CloseClipboard();
}

void CprintscreenDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nHotKeyId==100)
	{
		OnBnClickedOk();
		return;
	}
	CDialog::OnHotKey(nHotKeyId, nKey1, nKey2);
}


void CprintscreenDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	CDialog::OnWindowPosChanging(lpwndpos);
	lpwndpos->flags &= SWP_HIDEWINDOW;

	// TODO: �ڴ˴������Ϣ����������
}

void CprintscreenDlg::CreateRun()
{
	HKEY   RegKey;   
	CString   sPath;   
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);   
	sPath.ReleaseBuffer();   
	int   nPos;   
	nPos=sPath.ReverseFind('\\');   
		sPath=sPath.Left(nPos);   
	CString   lpszFile=sPath+"\\printscreen.exe";//���������Ҫ���ҵ�ִ���ļ�����   
	CFileFind   fFind;   
	BOOL   bSuccess;   
	bSuccess=fFind.FindFile(lpszFile);   
	fFind.Close();   
	if(bSuccess)   
	{   
		CString   fullName;   
		fullName=lpszFile;   
		RegKey=NULL;   
		///////////////////////////
		// ��ע��� ʧ���˳�
		int iRegipen=RegOpenKey(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows\\CurrentVersion\\Run",&RegKey);
		if (iRegipen!=ERROR_SUCCESS)
		{
			AfxMessageBox("ע����ʧ��,���������ʧ��");
			return ;
		}
		////////
		//�жϼ���Ŀ���� ���ж��������ַ����ͳ���·���Ƿ�һ�� ��һ����������� һ���˳�
		LPBYTE owner_Get=new BYTE[80];
		DWORD type_1=REG_SZ;
		DWORD cbData_1=80;
		int ret1=::RegQueryValueEx(RegKey,"printscreen",NULL,&type_1,owner_Get,&cbData_1);
		if(ret1!=ERROR_SUCCESS)
		{
			AfxMessageBox("��ѯ�ļ������ڣ�");
		

		RegSetValueEx(RegKey,"printscreen",0,REG_SZ,(const   unsigned   char*)(LPCTSTR)fullName,fullName.GetLength());//�����������Ҫ��ע�����ע�������   
		this->UpdateData(FALSE);   
		}
		else
		{
			CString cstr_get;
			cstr_get=owner_Get;
			if (cstr_get==fullName)
			{
				return ;
			}
			else
			{
				RegSetValueEx(RegKey,"printscreen",0,REG_SZ,(const   unsigned   char*)(LPCTSTR)fullName,fullName.GetLength());//�����������Ҫ��ע�����ע�������   
				this->UpdateData(FALSE);  

			}
		}
	
	}   
	else   
	{   
		//theApp.SetMainSkin();   
		::AfxMessageBox("û�ҵ�ִ�г������������ʧ��");   
		exit(0);   
	}   
	return ;


}
