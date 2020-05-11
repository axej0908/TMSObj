// CDialogNewBrain.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogNewBrain.h"
#include "afxdialogex.h"


// CDialogNewBrain 对话框

IMPLEMENT_DYNAMIC(CDialogNewBrain, CDialogEx)

CDialogNewBrain::CDialogNewBrain(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_new_brain, pParent)
{

}

CDialogNewBrain::~CDialogNewBrain()
{
}

void CDialogNewBrain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogNewBrain, CDialogEx)
END_MESSAGE_MAP()


// CDialogNewBrain 消息处理程序


BOOL CDialogNewBrain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
