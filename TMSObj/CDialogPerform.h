#pragma once


// CDialogPerform 对话框

class CDialogPerform : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogPerform)

public:
	CDialogPerform(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogPerform();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_perform };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
