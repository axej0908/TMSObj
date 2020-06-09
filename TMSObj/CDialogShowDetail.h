#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);

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

#pragma once

#pragma once


// CDialogShowDetail 对话框

class CDialogShowDetail : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogShowDetail)

public:
	CDialogShowDetail(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogShowDetail();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_show_detail };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic m_layout_text;
	CFont m_layout_font;
	CComboBox m_combox_layout;
	CListCtrl m_image_data;
	int showPointsInVtk(char* filePath, int IDCX);

	CString readFilePath;
	CStatic m_img_show1;
};
