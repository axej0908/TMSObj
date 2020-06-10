// CTabDialogSelectImg.cpp: 实现文件
//

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);

#include "pch.h"
#include "TMSObj.h"
#include "CTabDialogSelectImg.h"
#include "afxdialogex.h"


#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkStructuredPoints.h>
#include <vtkImageReader.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkVolumeProperty.h>
#include <vtkAxesActor.h>
#include <vtkImageShiftScale.h>
#include <vtkImageCast.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkDICOMImageReader.h>
#include <vtkContourFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkPolyDataMapper.h>
#include <vtkOutlineFilter.h>
#include <vtkCamera.h>
#include <vtkImageViewer2.h>

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
	DDX_Control(pDX, IDC_STATIC_name, m_static_name);
	DDX_Control(pDX, IDC_STATIC_sex, m_static_sex);
	DDX_Control(pDX, IDC_STATIC_scandate, m_static_scandate);
	DDX_Control(pDX, IDC_STATIC_scantype, m_static_scantype);
	DDX_Control(pDX, IDC_STATIC_imgsize, m_static_imgsize);
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
	TCHAR szFilter[] = _T("所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("*"), NULL, 0, szFilter, this);
	CString strFilePath;
	CString strFirstFileName;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetFolderPath();
		strFirstFileName = fileDlg.GetPathName();
		openFilePath = strFilePath;
		SetDlgItemText(IDC_BTN_open_file, strFilePath);

		//补充新加，读取第一张图，及名字什么的显示
		USES_CONVERSION;
		showPointsInVtkSingle(T2A(strFirstFileName), IDC_select_img);
	}
}


void CTabDialogSelectImg::OnBnClickedshowdetails()
{
	// TODO: 在此添加控件通知处理程序代码
	c_dialog_details.readFilePath = openFilePath;
	c_dialog_details.DoModal();


}


int CTabDialogSelectImg::showPointsInVtkSingle(char* filePath,int IDCX)
{
	vtkSmartPointer<vtkDICOMImageReader> reader =
		vtkSmartPointer<vtkDICOMImageReader>::New();
	reader->SetFileName(filePath);
	reader->Update();
	CTime tm; 
	tm = CTime::GetCurrentTime();
	CString Filesize;
	//给页面赋值
	m_static_name.SetWindowTextW((CString)reader->GetPatientName());
	m_static_scandate.SetWindowTextW(tm.Format("%Y-%m-%d %X"));
	m_static_sex.SetWindowTextW(_T("未知"));
	m_static_scantype.SetWindowTextW(_T("未知"));
	m_static_imgsize.SetWindowTextW(_T("未知"));

	vtkSmartPointer<vtkImageViewer2> imageViewer =
		vtkSmartPointer<vtkImageViewer2>::New();
	imageViewer->SetInputConnection(reader->GetOutputPort());
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	
	//搭上一个显示用的MFC窗口框架。
	CWnd* viewer_Wnd;
	viewer_Wnd = this->GetDlgItem(IDCX);
	HWND hWnd = (HWND)viewer_Wnd->m_hWnd;
	HWND hParent = ::GetParent(hWnd);
	//::ShowWindow(hParent, SW_HIDE);
	::ShowWindow(hParent, 1);
	imageViewer->SetParentId(this->m_hWnd);

	imageViewer->SetSize(200,200);
	imageViewer->SetPosition(43, 158);
	imageViewer->SetupInteractor(renderWindowInteractor);
	imageViewer->Render();
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer->Render();

	renderWindowInteractor->Start();
	


	return 1;
}