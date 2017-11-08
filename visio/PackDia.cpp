// PackDia.cpp : 实现文件
//

#include "stdafx.h"
#include "Homework-Visio.h"
#include "PackDia.h"
#include "afxdialogex.h"


// PackDia 对话框

IMPLEMENT_DYNAMIC(PackDia, CDialogEx)

PackDia::PackDia(CWnd* pParent /*=NULL*/)
	: CDialogEx(PackDia::IDD, pParent)
{

}

PackDia::~PackDia()
{
}

void PackDia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PackDia, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PackDia::OnBnClickedButton1)
END_MESSAGE_MAP()


// PackDia 消息处理程序


BOOL PackDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_EDIT1)->SetWindowText(Name);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常:  OCX 属性页应返回 FALSE
}


void PackDia::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT1, Name);
}
