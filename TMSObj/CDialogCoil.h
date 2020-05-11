#pragma once


// CDialogCoil 对话框

class CDialogCoil : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogCoil)

public:
	CDialogCoil(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogCoil();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_coil_calibration };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
