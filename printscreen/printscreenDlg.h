// printscreenDlg.h : 头文件
//

#pragma once


// CprintscreenDlg 对话框
class CprintscreenDlg : public CDialog
{
// 构造
public:
	CprintscreenDlg(CWnd* pParent = NULL);	// 标准构造函数
	

// 对话框数据
	enum { IDD = IDD_PRINTSCREEN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void CreateRun(void);

protected:
	
public:
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
};
