#pragma once
#include "CDialogTargets.h"
#include "CDialogPolaris.h"
#include "CDialogRegistration.h"
#include "CDialogValidation.h"
#include "CDialogPerform.h"
#include "CDialogCoil.h"


// CDialogOnlineSession 对话框

class CDialogOnlineSession : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogOnlineSession)

public:
	CDialogOnlineSession(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogOnlineSession();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_online_session };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTabCtrl m_online_tab;

	CDialogTargets m_dialog_targets;
	CDialogPolaris m_dialog_polaris;
	CDialogRegistration m_dialog_registration;
	CDialogValidation m_dialog_validation;
	CDialogPerform m_dialog_perform;
	CDialogCoil m_dialog_coil;

	CDialog* pDialog[6];

	int m_CurSelTab;

	

	afx_msg void OnTcnSelchangetabonline(NMHDR* pNMHDR, LRESULT* pResult);
};
