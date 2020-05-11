#pragma once


// CDialogSetPoint 对话框

class CDialogSetPoint : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogSetPoint)

public:
	CDialogSetPoint(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogSetPoint();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_set_point };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
