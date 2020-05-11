#pragma once


// CDialogShowDetail 对话框

class CDialogShowDetail : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogShowDetail)

public:
	CDialogShowDetail(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogShowDetail();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_show_detail };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic m_layout_text;
	CFont m_layout_font;
	CComboBox m_combox_layout;
	CListCtrl m_image_data;
};
