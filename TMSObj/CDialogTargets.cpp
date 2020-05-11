// CDialogTargets.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogTargets.h"
#include "afxdialogex.h"


// CDialogTargets 对话框

IMPLEMENT_DYNAMIC(CDialogTargets, CDialogEx)

CDialogTargets::CDialogTargets(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_targets, pParent)
{

}

CDialogTargets::~CDialogTargets()
{
}

void CDialogTargets::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogTargets, CDialogEx)
END_MESSAGE_MAP()


// CDialogTargets 消息处理程序


BOOL CDialogTargets::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
