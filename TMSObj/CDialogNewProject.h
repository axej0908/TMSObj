#pragma once

#include "CTabDialog3DRebuild.h"
#include "CTabDialogRunTMS.h"
#include "CTabDialogSelectImg.h"
#include "CTabDialogSetPoint.h"
#include "CTabDialogSetSpot.h"


// CDialogNewProject 对话框

class CDialogNewProject : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogNewProject)

public:
	CDialogNewProject(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogNewProject();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW_PROJECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl c_tab_new_project;
	virtual BOOL OnInitDialog();

	CTabDialog3DRebuild m_tab_3dRebuild;

	CTabDialogRunTMS m_tab_runtms;

	CTabDialogSelectImg m_tab_selectimg;

	CTabDialogSetPoint m_tab_setpoint;

	CTabDialogSetSpot m_tab_setspot;

	CDialog* pTabDialog[5];

	int m_CurSelTab;

	CFont m_tab_font;

	afx_msg void OnTcnSelchangeTabNewProject(NMHDR* pNMHDR, LRESULT* pResult);
};
