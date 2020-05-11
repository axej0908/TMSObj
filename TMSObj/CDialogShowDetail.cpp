// CDialogShowDetail.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogShowDetail.h"
#include "afxdialogex.h"


// CDialogShowDetail 对话框

IMPLEMENT_DYNAMIC(CDialogShowDetail, CDialogEx)

CDialogShowDetail::CDialogShowDetail(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_show_detail, pParent)
{

}

CDialogShowDetail::~CDialogShowDetail()
{
}

void CDialogShowDetail::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_layout_text, m_layout_text);
	DDX_Control(pDX, IDC_COMBO_layout, m_combox_layout);
	DDX_Control(pDX, IDC_image_data, m_image_data);
}


BEGIN_MESSAGE_MAP(CDialogShowDetail, CDialogEx)
END_MESSAGE_MAP()


// CDialogShowDetail 消息处理程序


BOOL CDialogShowDetail::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_layout_font.CreatePointFont(100, _T("微软雅黑"));
	m_layout_text.SetFont(&m_layout_font);

	m_combox_layout.AddString(_T("2 x 2"));
	m_combox_layout.AddString(_T("4 x 4"));

	m_combox_layout.SetCurSel(0);//默认选中第一个选项

	//设置表格样式
    CRect rect;

    // 获取编程语言列表视图控件的位置和大小   
    m_image_data.GetClientRect(&rect);

    // 为列表视图控件添加全行选中和栅格风格   
    m_image_data.SetExtendedStyle(m_image_data.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    // 为列表视图控件添加2列   
    m_image_data.InsertColumn(0, _T("key"), LVCFMT_CENTER, rect.Width() / 2, 0);
    m_image_data.InsertColumn(1, _T("value"), LVCFMT_CENTER, rect.Width() / 2, 1);

	//设置自动滚动
	m_image_data.EnsureVisible(m_image_data.GetItemCount() - 1, FALSE);

    // 在列表视图控件中插入列表项，并设置列表子项文本   
    m_image_data.InsertItem(0, _T("Java"));
    m_image_data.SetItemText(0, 1, _T("1"));

    m_image_data.InsertItem(1, _T("C"));
    m_image_data.SetItemText(1, 1, _T("2"));



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
