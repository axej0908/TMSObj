#pragma once


// CDialogValidation 对话框

class CDialogValidation : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogValidation)

public:
	CDialogValidation(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogValidation();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_validation };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
