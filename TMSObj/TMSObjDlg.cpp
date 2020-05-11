
// TMSObjDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "TMSObj.h"
#include "TMSObjDlg.h"
#include "afxdialogex.h"
#include "CDialogNewProject.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTMSObjDlg 对话框



CTMSObjDlg::CTMSObjDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TMSOBJ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTMSObjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDCANCEL, m_static_welcome);
	DDX_Control(pDX, IDC_STATIC_TITLE, m_static_title);
}

BEGIN_MESSAGE_MAP(CTMSObjDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NEW_PROJECT, &CTMSObjDlg::OnBnClickedButtonNewProject)
END_MESSAGE_MAP()


// CTMSObjDlg 消息处理程序

BOOL CTMSObjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	font_welcomeFont.CreatePointFont(110,L"微软雅黑");
	m_static_welcome.SetFont(&font_welcomeFont);

	font_titleFont.CreatePointFont(160,L"微软雅黑");
	m_static_title.SetFont(&font_titleFont);

	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_STATIC_ICO); // 得到 Picture Control 句柄
	CImage image;
	image.Load(_T("C:\\logo.png"));
	HBITMAP hBmp = image.Detach();
	pWnd->SetBitmap(hBmp);
	pWnd->SetWindowPos(NULL,
		0,
		0,
		77,
		77,
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);

	//版本更新

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTMSObjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTMSObjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CTMSObjDlg::OnBnClickedButtonNewProject()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogNewProject newProjectDiglog;
	newProjectDiglog.DoModal();
}

