// CDialogNewProject.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogNewProject.h"
#include "afxdialogex.h"


// CDialogNewProject 对话框

IMPLEMENT_DYNAMIC(CDialogNewProject, CDialogEx)

CDialogNewProject::CDialogNewProject(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NEW_PROJECT, pParent)
{

}

CDialogNewProject::~CDialogNewProject()
{
}

void CDialogNewProject::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_NEW_PROJECT, c_tab_new_project);
}


BEGIN_MESSAGE_MAP(CDialogNewProject, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_NEW_PROJECT, &CDialogNewProject::OnTcnSelchangeTabNewProject)
END_MESSAGE_MAP()


// CDialogNewProject 消息处理程序


BOOL CDialogNewProject::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化	
	//给TabControl定义名称
	c_tab_new_project.InsertItem(0, _T("选择图像"));
	c_tab_new_project.InsertItem(1, _T("三维重建"));
	c_tab_new_project.InsertItem(2, _T("设置定点"));
	c_tab_new_project.InsertItem(3, _T("设置靶点"));
	c_tab_new_project.InsertItem(4, _T("实施TMS"));

	//添加样式
	m_tab_font.CreatePointFont(100, _T("微软雅黑"));
	c_tab_new_project.SetFont(&m_tab_font);

	CSize size(100, 30), sizeReturn;
	c_tab_new_project.SetItemSize(size);

	//创建对话框
	m_tab_3dRebuild.Create(IDD_DIALOG_3D_rebuild,&c_tab_new_project);
	m_tab_runtms.Create(IDD_DIALOG_run_tms, &c_tab_new_project);
	m_tab_selectimg.Create(IDD_DIALOG_Select_img, &c_tab_new_project);


	//设置位置
	CRect rc;
	c_tab_new_project.GetClientRect(rc);
	rc.top += 30;//与CSize对应
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;

	m_tab_3dRebuild.MoveWindow(&rc);
	m_tab_runtms.MoveWindow(&rc);
	m_tab_selectimg.MoveWindow(&rc);

	
	//把新增的对话框保存在数组里
	pTabDialog[0] = &m_tab_selectimg;
	pTabDialog[1] = &m_tab_3dRebuild;
	pTabDialog[4] = &m_tab_runtms;

	//设置显示第一个
	pTabDialog[0]->ShowWindow(SW_SHOW);
	pTabDialog[1]->ShowWindow(SW_HIDE);
	pTabDialog[4]->ShowWindow(SW_HIDE);

	m_CurSelTab = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogNewProject::OnTcnSelchangeTabNewProject(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	//面板定点设置和靶点设置都是需要弹出新的窗口，因此这里加上判断做DoModal操作
	if (m_CurSelTab!=2 && m_CurSelTab!=3)
	{
		pTabDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	}
	
	m_CurSelTab = c_tab_new_project.GetCurSel();
	if (m_CurSelTab==2)
	{
		m_tab_setpoint.DoModal();
	}
	else if (m_CurSelTab==3)
	{
		m_tab_setspot.DoModal();
	}
	else {
		pTabDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	}
	
	*pResult = 0;
}
