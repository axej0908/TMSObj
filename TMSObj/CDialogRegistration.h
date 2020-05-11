#pragma once


// CDialogRegistration 对话框

class CDialogRegistration : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogRegistration)

public:
	CDialogRegistration(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogRegistration();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_registration };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
