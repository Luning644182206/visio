// PackDia.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Homework-Visio.h"
#include "PackDia.h"
#include "afxdialogex.h"


// PackDia �Ի���

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


// PackDia ��Ϣ�������


BOOL PackDia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_EDIT1)->SetWindowText(Name);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣:  OCX ����ҳӦ���� FALSE
}


void PackDia::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT1, Name);
}
