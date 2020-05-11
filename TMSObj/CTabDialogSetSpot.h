#pragma once


// CTabDialogSetSpot 对话框

class CTabDialogSetSpot : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDialogSetSpot)

public:
	CTabDialogSetSpot(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDialogSetSpot();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_set_spot };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_spot_name_list;
};
