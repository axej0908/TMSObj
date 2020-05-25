

#include "CDialogShowDetail.h"
#pragma once


// CTabDialogSelectImg 对话框

class CTabDialogSelectImg : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDialogSelectImg)

public:
	CTabDialogSelectImg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDialogSelectImg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Select_img };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_file_text;
	CFont m_text_font;
	CFont m_static_font;
	virtual BOOL OnInitDialog();
	CStatic m_name_text;
	CStatic m_sex_text;
	CStatic m_scan_time_text;
	CStatic m_scan_type_text;
	CStatic m_img_size_text;
	afx_msg void OnBnClickedBtnopenfile();
	afx_msg void OnBnClickedshowdetails();
	CDialogShowDetail c_dialog_details;
	int showPointsInVtkSingle(char* filePath,int IDCX);
	CStatic m_static_name;
	CStatic m_static_sex;
	CStatic m_static_scandate;
	CStatic m_static_scantype;
	CStatic m_static_imgsize;

	CString openFilePath;

};
