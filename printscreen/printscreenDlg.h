// printscreenDlg.h : ͷ�ļ�
//

#pragma once


// CprintscreenDlg �Ի���
class CprintscreenDlg : public CDialog
{
// ����
public:
	CprintscreenDlg(CWnd* pParent = NULL);	// ��׼���캯��
	

// �Ի�������
	enum { IDD = IDD_PRINTSCREEN_DIALOG };

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
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void CreateRun(void);

protected:
	
public:
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
};
