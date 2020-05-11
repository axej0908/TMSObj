// CDialogCoil.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogCoil.h"
#include "afxdialogex.h"


// CDialogCoil 对话框

IMPLEMENT_DYNAMIC(CDialogCoil, CDialogEx)

CDialogCoil::CDialogCoil(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_coil_calibration, pParent)
{

}

CDialogCoil::~CDialogCoil()
{
}

void CDialogCoil::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogCoil, CDialogEx)
END_MESSAGE_MAP()


// CDialogCoil 消息处理程序


BOOL CDialogCoil::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
