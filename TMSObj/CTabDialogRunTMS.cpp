// CTabDialogRunTMS.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CTabDialogRunTMS.h"
#include "afxdialogex.h"


// CTabDialogRunTMS 对话框

IMPLEMENT_DYNAMIC(CTabDialogRunTMS, CDialogEx)

CTabDialogRunTMS::CTabDialogRunTMS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_run_tms, pParent)
{

}

CTabDialogRunTMS::~CTabDialogRunTMS()
{
}

void CTabDialogRunTMS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_tms_list, m_tms_list);
}


BEGIN_MESSAGE_MAP(CTabDialogRunTMS, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &CTabDialogRunTMS::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTabDialogRunTMS 消息处理程序


BOOL CTabDialogRunTMS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//给列表赋值表头
    CRect rect;

    // 获取编程语言列表视图控件的位置和大小   
    m_tms_list.GetClientRect(&rect);

    // 为列表视图控件添加全行选中和栅格风格   
    m_tms_list.SetExtendedStyle(m_tms_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    // 为列表视图控件添加三列   
    m_tms_list.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, rect.Width() / 2, 0);
    m_tms_list.InsertColumn(1, _T("数据"), LVCFMT_CENTER, rect.Width() / 2, 1);
    // 在列表视图控件中插入列表项，并设置列表子项文本   
    m_tms_list.InsertItem(0,_T("Java"));
    m_tms_list.SetItemText(0, 1, _T("1"));



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTabDialogRunTMS::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    m_dialog_onlineSession.DoModal();
}
