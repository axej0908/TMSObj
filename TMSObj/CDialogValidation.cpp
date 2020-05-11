// CDialogValidation.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogValidation.h"
#include "afxdialogex.h"


// CDialogValidation 对话框

IMPLEMENT_DYNAMIC(CDialogValidation, CDialogEx)

CDialogValidation::CDialogValidation(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_validation, pParent)
{

}

CDialogValidation::~CDialogValidation()
{
}

void CDialogValidation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogValidation, CDialogEx)
END_MESSAGE_MAP()


// CDialogValidation 消息处理程序


BOOL CDialogValidation::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
