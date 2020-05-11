#include "CDialogOnlineSession.h"
#pragma once


// CTabDialogRunTMS 对话框

class CTabDialogRunTMS : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDialogRunTMS)

public:
	CTabDialogRunTMS(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDialogRunTMS();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_run_tms };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_tms_list;
	virtual BOOL OnInitDialog();

	CDialogOnlineSession m_dialog_onlineSession;

	afx_msg void OnBnClickedButton1();
};
