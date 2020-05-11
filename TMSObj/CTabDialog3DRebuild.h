#include "CDialogNewSkin.h"
#include "CDialogNewBrain.h"

#pragma once


// CTabDialog3DRebuild 对话框

class CTabDialog3DRebuild : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDialog3DRebuild)

public:
	CTabDialog3DRebuild(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDialog3DRebuild();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_3D_rebuild };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_reconstractions_list;
	virtual BOOL OnInitDialog();
	CStatic m_recons_text;
	CFont m_recons_font;
	CComboBox m_combox_new;
	afx_msg void OnSelchangeComboNew();

	CDialogNewSkin m_dialog_skin;
	CDialogNewBrain m_dialog_brain;
	CEdit m_search_words;
};
