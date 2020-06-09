#pragma once


// CDialogNewBrain 对话框

class CDialogNewBrain : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogNewBrain)

public:
	CDialogNewBrain(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogNewBrain();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_new_brain };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	int showPointsInVtk(char* filePath, int IDCX);
	CStatic m_show3D;
};
