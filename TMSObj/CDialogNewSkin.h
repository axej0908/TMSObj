#pragma once


// CDialogNewSkin 对话框

class CDialogNewSkin : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogNewSkin)

public:
	CDialogNewSkin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogNewSkin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_new_skin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
