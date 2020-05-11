// CDialogRegistration.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogRegistration.h"
#include "afxdialogex.h"


// CDialogRegistration 对话框

IMPLEMENT_DYNAMIC(CDialogRegistration, CDialogEx)

CDialogRegistration::CDialogRegistration(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_registration, pParent)
{

}

CDialogRegistration::~CDialogRegistration()
{
}

void CDialogRegistration::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogRegistration, CDialogEx)
END_MESSAGE_MAP()


// CDialogRegistration 消息处理程序


BOOL CDialogRegistration::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	//设置显示图标
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_put_pic); // 得到 Picture Control 句柄
	CImage image;
	image.Load(_T("res\\put.png"));
	HBITMAP hBmp = image.Detach();
	pWnd->SetBitmap(hBmp);
	pWnd->SetWindowPos(NULL,
		0,
		0,
		40,
		40,
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);

	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
