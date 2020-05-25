// CDialogShowDetail.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogShowDetail.h"
#include "afxdialogex.h"

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
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
	DDX_Control(pDX, IDC_STATIC_show1, m_img_show1);
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
	
	USES_CONVERSION;
	showPointsInVtk(T2A(readFilePath),IDC_STATIC_show1);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

int CDialogShowDetail::showPointsInVtk(char* filePath, int IDCX)
{
	vtkRenderer* aRenderer = vtkRenderer::New();
	vtkRenderWindow* renWin = vtkRenderWindow::New();
	renWin->AddRenderer(aRenderer);
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::New();
	iren->SetRenderWindow(renWin);

	vtkDICOMImageReader* v = vtkDICOMImageReader::New();//vtkDicomImageReader用于读取医学DICOM图像
	v->SetDataByteOrderToLittleEndian();//设置为小端字节序

	v->SetDirectoryName(filePath);
	v->SetDataSpacing(3.2, 3.2, 1.5);//设置数据间距

	//已知500对应病人的皮肤，抽取值为500的等值面。然后通过vtkPolyDataNormals在面上产生法线
	vtkContourFilter* skinExtractor = vtkContourFilter::New();//过滤器vtkContourFilter用于从数据中抽取一系列等值面
	skinExtractor->SetInputConnection(v->GetOutputPort());
	skinExtractor->SetValue(0, 500);//对抽取等值面进行设置，表示从第0个抽取值开始，设为500
	vtkPolyDataNormals* skinNormals = vtkPolyDataNormals::New();//在面上产生法线，使渲染过程中的表面着色光滑些
	skinNormals->SetInputConnection(skinExtractor->GetOutputPort());
	skinNormals->SetFeatureAngle(80);//设置特征角度
	vtkPolyDataMapper* skinMapper = vtkPolyDataMapper::New();
	skinMapper->SetInputConnection(skinNormals->GetOutputPort());
	skinMapper->ScalarVisibilityOff();
	vtkActor* skin = vtkActor::New();
	skin->SetMapper(skinMapper);

	vtkCamera* aCamera = vtkCamera::New();

	aRenderer->AddActor(skin);
	aRenderer->SetActiveCamera(aCamera);
	aRenderer->ResetCamera();
	aCamera->Dolly(1.5);//将相机靠近焦点，以放大图像

	aRenderer->SetBackground(0, 0, 0);//设置背景为白色
	renWin->SetSize(400, 400);
	renWin->SetPosition(80, 60);//通过这个 控制成像的位置 

	//由于Dolly()方法移动了相机，所以要重设相机的剪切范围
	aRenderer->ResetCameraClippingRange();

	//搭上一个显示用的MFC窗口框架。
	CWnd* viewer_Wnd;
	viewer_Wnd = this->GetDlgItem(IDCX);
	HWND hWnd = (HWND)viewer_Wnd->m_hWnd;
	HWND hParent = ::GetParent(hWnd);
	//::ShowWindow(hParent, SW_HIDE);
	::ShowWindow(hParent, 1);
	renWin->SetParentId(this->m_hWnd);

	iren->Initialize();
	iren->Start();

	v->Delete();
	skinExtractor->Delete();
	skinNormals->Delete();
	skinMapper->Delete();
	skin->Delete();

	aCamera->Delete();
	iren->Delete();
	renWin->Delete();
	aRenderer->Delete();

	return 1;
}