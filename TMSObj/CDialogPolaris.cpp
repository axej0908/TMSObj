// CDialogPolaris.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogPolaris.h"
#include "afxdialogex.h"


// CDialogPolaris 对话框

IMPLEMENT_DYNAMIC(CDialogPolaris, CDialogEx)

CDialogPolaris::CDialogPolaris(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_polaris, pParent)
{

}

CDialogPolaris::~CDialogPolaris()
{
}

void CDialogPolaris::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogPolaris, CDialogEx)
END_MESSAGE_MAP()


// CDialogPolaris 消息处理程序


BOOL CDialogPolaris::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
