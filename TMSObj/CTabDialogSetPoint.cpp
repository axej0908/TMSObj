// CTabDialogSetPoint.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CTabDialogSetPoint.h"
#include "afxdialogex.h"


// CTabDialogSetPoint 对话框

IMPLEMENT_DYNAMIC(CTabDialogSetPoint, CDialogEx)

CTabDialogSetPoint::CTabDialogSetPoint(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_set_point, pParent)
{

}

CTabDialogSetPoint::~CTabDialogSetPoint()
{
}

void CTabDialogSetPoint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabDialogSetPoint, CDialogEx)
END_MESSAGE_MAP()


// CTabDialogSetPoint 消息处理程序


BOOL CTabDialogSetPoint::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
