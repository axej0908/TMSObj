#pragma once


// CDialogTargets 对话框

class CDialogTargets : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogTargets)

public:
	CDialogTargets(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogTargets();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_targets };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
