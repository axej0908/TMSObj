// CDialogOnlineSession.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogOnlineSession.h"
#include "afxdialogex.h"


// CDialogOnlineSession 对话框

IMPLEMENT_DYNAMIC(CDialogOnlineSession, CDialogEx)

CDialogOnlineSession::CDialogOnlineSession(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_online_session, pParent)
{

}

CDialogOnlineSession::~CDialogOnlineSession()
{
}

void CDialogOnlineSession::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_tab_online, m_online_tab);
}


BEGIN_MESSAGE_MAP(CDialogOnlineSession, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_tab_online, &CDialogOnlineSession::OnTcnSelchangetabonline)
END_MESSAGE_MAP()


// CDialogOnlineSession 消息处理程序


BOOL CDialogOnlineSession::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	

	m_online_tab.InsertItem(0, _T("Targets"));
	m_online_tab.InsertItem(1, _T("Polaris"));
	m_online_tab.InsertItem(2, _T("Registration"));
	m_online_tab.InsertItem(3, _T("Validation"));
	m_online_tab.InsertItem(4, _T("Coil Calibration"));
	m_online_tab.InsertItem(5, _T("Perform")); 

	//添加样式
	CFont m_tab_font;
	m_tab_font.CreatePointFont(100, _T("微软雅黑"));
	m_online_tab.SetFont(&m_tab_font);

	CSize size(100, 30), sizeReturn;
	m_online_tab.SetItemSize(size);


	m_dialog_targets.Create(IDD_DIALOG_targets,&m_online_tab);
	m_dialog_polaris.Create(IDD_DIALOG_polaris, &m_online_tab);
	m_dialog_registration.Create(IDD_DIALOG_registration, &m_online_tab);
	m_dialog_validation.Create(IDD_DIALOG_validation, &m_online_tab);
	m_dialog_perform.Create(IDD_DIALOG_perform, &m_online_tab);
	m_dialog_coil.Create(IDD_DIALOG_coil_calibration, &m_online_tab);

	CRect rc;
	m_online_tab.GetClientRect(rc);
	rc.top += 30;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	m_dialog_targets.MoveWindow(&rc);
	m_dialog_polaris.MoveWindow(&rc);
	m_dialog_registration.MoveWindow(&rc);
	m_dialog_validation.MoveWindow(&rc);
	m_dialog_perform.MoveWindow(&rc);
	m_dialog_coil.MoveWindow(&rc);

	//把对话框对象指针保存起来
	pDialog[0] = &m_dialog_targets;
	pDialog[1] = &m_dialog_polaris;
	pDialog[2] = &m_dialog_registration;
	pDialog[3] = &m_dialog_validation;
	pDialog[4] = &m_dialog_coil;
	pDialog[5] = &m_dialog_perform;

	//显示初始页面
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	pDialog[2]->ShowWindow(SW_HIDE);
	pDialog[3]->ShowWindow(SW_HIDE);
	pDialog[4]->ShowWindow(SW_HIDE);
	pDialog[5]->ShowWindow(SW_HIDE);

	//保存当前选择
	m_CurSelTab = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogOnlineSession::OnTcnSelchangetabonline(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	m_CurSelTab = m_online_tab.GetCurSel();
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);


	*pResult = 0;
}
