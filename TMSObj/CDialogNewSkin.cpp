// CDialogNewSkin.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogNewSkin.h"
#include "afxdialogex.h"


// CDialogNewSkin 对话框

IMPLEMENT_DYNAMIC(CDialogNewSkin, CDialogEx)

CDialogNewSkin::CDialogNewSkin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_new_skin, pParent)
{

}

CDialogNewSkin::~CDialogNewSkin()
{
}

void CDialogNewSkin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogNewSkin, CDialogEx)
END_MESSAGE_MAP()


// CDialogNewSkin 消息处理程序


BOOL CDialogNewSkin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
