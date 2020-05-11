// CTabDialogSetSpot.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CTabDialogSetSpot.h"
#include "afxdialogex.h"


// CTabDialogSetSpot 对话框

IMPLEMENT_DYNAMIC(CTabDialogSetSpot, CDialogEx)

CTabDialogSetSpot::CTabDialogSetSpot(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_set_spot, pParent)
{

}

CTabDialogSetSpot::~CTabDialogSetSpot()
{
}

void CTabDialogSetSpot::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_spot_name_list, m_spot_name_list);
}


BEGIN_MESSAGE_MAP(CTabDialogSetSpot, CDialogEx)
END_MESSAGE_MAP()


// CTabDialogSetSpot 消息处理程序


BOOL CTabDialogSetSpot::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_spot_name_list.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_spot_name_list.SetExtendedStyle(m_spot_name_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_spot_name_list.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, rect.Width() / 1, 0);
	
	// 在列表视图控件中插入列表项，并设置列表子项文本   
	m_spot_name_list.InsertItem(0, _T("Java"));
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
