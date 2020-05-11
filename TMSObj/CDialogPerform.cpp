// CDialogPerform.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogPerform.h"
#include "afxdialogex.h"


// CDialogPerform 对话框

IMPLEMENT_DYNAMIC(CDialogPerform, CDialogEx)

CDialogPerform::CDialogPerform(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_perform, pParent)
{

}

CDialogPerform::~CDialogPerform()
{
}

void CDialogPerform::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogPerform, CDialogEx)
END_MESSAGE_MAP()


// CDialogPerform 消息处理程序


BOOL CDialogPerform::OnInitDialog()
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
		30,
		30,
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);

	pWnd= (CStatic*)GetDlgItem(IDC_large_pic);
	image.Load(_T("res\\large.png"));
	hBmp = image.Detach();
	pWnd->SetBitmap(hBmp);
	pWnd->SetWindowPos(NULL,
		0,
		0,
		30,
		30,
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);

	pWnd = (CStatic*)GetDlgItem(IDC_view_pic);
	image.Load(_T("res\\view.png"));
	hBmp = image.Detach();
	pWnd->SetBitmap(hBmp);
	pWnd->SetWindowPos(NULL,
		0,
		0,
		30,
		30,
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);

	pWnd = (CStatic*)GetDlgItem(IDC_circle_pic);
	image.Load(_T("res\\circle.png"));
	hBmp = image.Detach();
	pWnd->SetBitmap(hBmp);
	pWnd->SetWindowPos(NULL,
		0,
		0,
		30,
		30,
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
