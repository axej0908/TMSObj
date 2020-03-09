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
}


BEGIN_MESSAGE_MAP(CDialogNewProject, CDialogEx)
END_MESSAGE_MAP()


// CDialogNewProject 消息处理程序
