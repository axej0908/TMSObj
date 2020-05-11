// CTabDialogSelectImg.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CTabDialogSelectImg.h"
#include "afxdialogex.h"


// CTabDialogSelectImg 对话框

IMPLEMENT_DYNAMIC(CTabDialogSelectImg, CDialogEx)

CTabDialogSelectImg::CTabDialogSelectImg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Select_img, pParent)
{

}

CTabDialogSelectImg::~CTabDialogSelectImg()
{
}

void CTabDialogSelectImg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_File_text, m_file_text);
	DDX_Control(pDX, IDC_name_text, m_name_text);
	DDX_Control(pDX, IDC_sex_text, m_sex_text);
	DDX_Control(pDX, IDC_text_san_time, m_scan_time_text);
	DDX_Control(pDX, IDC_text_scan_type, m_scan_type_text);
	DDX_Control(pDX, IDC_text_img_size, m_img_size_text);
}


BEGIN_MESSAGE_MAP(CTabDialogSelectImg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_open_file, &CTabDialogSelectImg::OnBnClickedBtnopenfile)
	ON_BN_CLICKED(IDC_show_details, &CTabDialogSelectImg::OnBnClickedshowdetails)
END_MESSAGE_MAP()


// CTabDialogSelectImg 消息处理程序


BOOL CTabDialogSelectImg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_text_font.CreatePointFont(120,L"微软雅黑",NULL);
	m_static_font.CreatePointFont(100, L"微软雅黑", NULL);

	m_file_text.SetFont(&m_text_font, true);

	m_name_text.SetFont(&m_static_font, true);
	m_sex_text.SetFont(&m_static_font, true);
	m_scan_time_text.SetFont(&m_static_font, true);
	m_scan_type_text.SetFont(&m_static_font, true);
	m_img_size_text.SetFont(&m_static_font, true);

	

	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_select_img); // 得到 Picture Control 句柄
	CImage image;
	image.Load(_T("C:\\template.png"));
	HBITMAP hBmp = image.Detach();
	pWnd->SetBitmap(hBmp);
	pWnd->SetWindowPos(NULL,
		0,
		0,
		200,
		200,
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTabDialogSelectImg::OnBnClickedBtnopenfile()
{
	// TODO: 在此添加控件通知处理程序代码

	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_BTN_open_file, strFilePath);
	}
}


void CTabDialogSelectImg::OnBnClickedshowdetails()
{
	// TODO: 在此添加控件通知处理程序代码

	c_dialog_details.DoModal();


}
