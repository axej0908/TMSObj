#pragma once


// CDialogPolaris 对话框

class CDialogPolaris : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogPolaris)

public:
	CDialogPolaris(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogPolaris();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_polaris };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
