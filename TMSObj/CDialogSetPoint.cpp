// CDialogSetPoint.cpp: 实现文件
//

#include "pch.h"
#include "TMSObj.h"
#include "CDialogSetPoint.h"
#include "afxdialogex.h"


// CDialogSetPoint 对话框

IMPLEMENT_DYNAMIC(CDialogSetPoint, CDialogEx)

CDialogSetPoint::CDialogSetPoint(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_set_point, pParent)
{

}

CDialogSetPoint::~CDialogSetPoint()
{
}

void CDialogSetPoint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogSetPoint, CDialogEx)
END_MESSAGE_MAP()


// CDialogSetPoint 消息处理程序
