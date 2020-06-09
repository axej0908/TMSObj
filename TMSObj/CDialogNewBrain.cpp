// CDialogNewBrain.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogNewBrain.h"
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

// CDialogNewBrain 对话框

IMPLEMENT_DYNAMIC(CDialogNewBrain, CDialogEx)

CDialogNewBrain::CDialogNewBrain(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_new_brain, pParent)
{

}

CDialogNewBrain::~CDialogNewBrain()
{
}

void CDialogNewBrain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_show3D, m_show3D);
}


BEGIN_MESSAGE_MAP(CDialogNewBrain, CDialogEx)
END_MESSAGE_MAP()


// CDialogNewBrain 消息处理程序


BOOL CDialogNewBrain::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	char* readFilePath = "D:\\2020项目\\王贺\\t13d";
	// TODO:  在此添加额外的初始化
	USES_CONVERSION;
	showPointsInVtk(readFilePath, IDC_STATIC_show3D);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


int CDialogNewBrain::showPointsInVtk(char* filePath, int IDCX)
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
	renWin->SetSize(1000, 800);
	renWin->SetPosition(300, 90);//通过这个 控制成像的位置 

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