#pragma once


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
};
