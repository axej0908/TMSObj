// CTabDialog3DRebuild.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CTabDialog3DRebuild.h"
#include "afxdialogex.h"


// CTabDialog3DRebuild 对话框

IMPLEMENT_DYNAMIC(CTabDialog3DRebuild, CDialogEx)

CTabDialog3DRebuild::CTabDialog3DRebuild(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_3D_rebuild, pParent)
{

}

CTabDialog3DRebuild::~CTabDialog3DRebuild()
{
}

void CTabDialog3DRebuild::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_reconstructions, m_reconstractions_list);
    DDX_Control(pDX, IDC_recons_text, m_recons_text);
    DDX_Control(pDX, IDC_COMBO_new, m_combox_new);
    DDX_Control(pDX, IDC_search_words, m_search_words);
}


BEGIN_MESSAGE_MAP(CTabDialog3DRebuild, CDialogEx)
    ON_CBN_SELCHANGE(IDC_COMBO_new, &CTabDialog3DRebuild::OnSelchangeComboNew)
END_MESSAGE_MAP()


// CTabDialog3DRebuild 消息处理程序


BOOL CTabDialog3DRebuild::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

    //设置表格样式
    CRect rect;

    // 获取编程语言列表视图控件的位置和大小   
    m_reconstractions_list.GetClientRect(&rect);

    // 为列表视图控件添加全行选中和栅格风格   
    m_reconstractions_list.SetExtendedStyle(m_reconstractions_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    // 为列表视图控件添加2列   
    m_reconstractions_list.InsertColumn(0, _T("名称"), LVCFMT_CENTER, rect.Width() / 1, 0);

    //设置自动滚动
    m_reconstractions_list.EnsureVisible(m_reconstractions_list.GetItemCount() - 1, FALSE);

    // 在列表视图控件中插入列表项，并设置列表子项文本   
    m_reconstractions_list.InsertItem(0, _T("Java"));

    //设置文字样式
    m_recons_font.CreatePointFont(100,_T("微软雅黑"));
    m_recons_text.SetFont(&m_recons_font);


    //初始化下拉菜单的内容
    m_combox_new.AddString(_T("重建"));
    m_combox_new.AddString(_T("重建皮肤"));
    m_combox_new.AddString(_T("重建大脑"));

    m_combox_new.SetCurSel(0);

    //给搜索栏默认文字
    SetDlgItemText(IDC_search_words,_T("请输入关键词"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTabDialog3DRebuild::OnSelchangeComboNew()
{
    // TODO: 在此添加控件通知处理程序代码
    int m_CurSel = m_combox_new.GetCurSel();
    
    if (m_CurSel ==2)
    {
        m_dialog_skin.DoModal();
    }
    if (m_CurSel ==1)
    {
        m_dialog_brain.DoModal();
    }
}
