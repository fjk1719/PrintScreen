// printscreenDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "printscreen.h"
#include "printscreenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CprintscreenDlg 对话框




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


// CprintscreenDlg 消息处理程序

BOOL CprintscreenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	CreateRun();
	//注册系统热键
	
	if(!RegisterHotKey(this->m_hWnd,100,0,VK_HOME))
	{
		MessageBox("热键注册失败程序退出");
		exit(0);
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CprintscreenDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
// 	srand( (unsigned)time( NULL ) ); //srand()函数产生一个以当前时间开始的随机种子
// 	x=rand()%100;
// 	CString filename;
// 	filename.Format("\\%d.jpg",x);
// 	strcat_s(szPath,filename.GetBuffer(filename.GetLength()));
// 
// 	//实现截屏为位图
// 	HDC hdc = ::GetDC(NULL); // 获取屏幕DC的句柄
// 	CDC screenDC; // 定义空屏幕DC对象
// 	screenDC.Attach(hdc); // 粘上屏幕DC句柄
// 	CDC mdc; // 定义空内存DC对象
// 	mdc.CreateCompatibleDC(&screenDC); // 创建与屏幕DC兼容的内存DC
// 	CBitmap bmp, *pOldBmp; // 定义位图对象和指针
// 	int w = GetDeviceCaps(hdc, HORZRES); // 获取屏幕宽（像素）
// 	int h = GetDeviceCaps(hdc, VERTRES); // 获取屏幕高（像素）
// 	bmp.CreateCompatibleBitmap(&screenDC, w, h); // 创建与屏幕DC兼容的位图对象
// 	pOldBmp = mdc.SelectObject(&bmp); // 将位图选入内存DC
// 	ShowWindow(SW_HIDE); // 隐藏程序窗口
// 	Sleep(100); // 休眠一段（0.1秒）时间
// 	mdc.BitBlt(0, 0, w, h, &screenDC, 0, 0, SRCCOPY); // 抓取屏幕截图到内存DC中的图像
// 	ShowWindow(SW_SHOW); // 显示程序窗口
// 
// 	//保存为jpg格式
// 	CImage img;
// 	img.Attach(bmp);
// 	img.Save(szPath,Gdiplus::ImageFormatJPEG);
// 	img.Save("C:\\123.bmp");
// 	mdc.SelectObject(pOldBmp);
// 	bmp.DeleteObject();
// 	screenDC.Detach();
// 	::ReleaseDC(NULL, hdc);















	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
	//生成文件保存路径
	TCHAR szPath[MAX_PATH] = {0};
	SHGetSpecialFolderPath(m_hWnd, szPath, CSIDL_DESKTOP, FALSE);
	//MessageBox(szPath);
	int x;
	srand( (unsigned)time( NULL ) ); //srand()函数产生一个以当前时间开始的随机种子
	x=rand()%100;
	CString filename;
	filename.Format("\\%d.jpg",x);
	strcat_s(szPath,filename.GetBuffer(filename.GetLength()));
// 	//////////////////////////////////////////////////////////////////////////
// 	//模拟按键实现保存数据到黏贴板
	//ShowWindow(SW_HIDE); // 隐藏程序窗口
	//Sleep(100); // 休眠一段（0.1秒）时间
	keybd_event(44,0,0,0);
	Sleep(100);
	keybd_event(44,0,0,0);
	Sleep(500);
	//ShowWindow(SW_SHOW); // 显示程序窗口

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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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

	// TODO: 在此处添加消息处理程序代码
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
	CString   lpszFile=sPath+"\\printscreen.exe";//这里加上你要查找的执行文件名称   
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
		// 打开注册表 失败退出
		int iRegipen=RegOpenKey(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows\\CurrentVersion\\Run",&RegKey);
		if (iRegipen!=ERROR_SUCCESS)
		{
			AfxMessageBox("注册表打开失败,启动项添加失败");
			return ;
		}
		////////
		//判断键项目存在 则判断启动项字符串和程序路径是否一致 不一致添加启动项 一致退出
		LPBYTE owner_Get=new BYTE[80];
		DWORD type_1=REG_SZ;
		DWORD cbData_1=80;
		int ret1=::RegQueryValueEx(RegKey,"printscreen",NULL,&type_1,owner_Get,&cbData_1);
		if(ret1!=ERROR_SUCCESS)
		{
			AfxMessageBox("查询的键不存在！");
		

		RegSetValueEx(RegKey,"printscreen",0,REG_SZ,(const   unsigned   char*)(LPCTSTR)fullName,fullName.GetLength());//这里加上你需要在注册表中注册的内容   
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
				RegSetValueEx(RegKey,"printscreen",0,REG_SZ,(const   unsigned   char*)(LPCTSTR)fullName,fullName.GetLength());//这里加上你需要在注册表中注册的内容   
				this->UpdateData(FALSE);  

			}
		}
	
	}   
	else   
	{   
		//theApp.SetMainSkin();   
		::AfxMessageBox("没找到执行程序，启动项加载失败");   
		exit(0);   
	}   
	return ;


}
