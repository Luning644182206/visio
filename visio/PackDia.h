#pragma once
#include"resource.h"

// PackDia �Ի���

class PackDia : public CDialogEx
{
	DECLARE_DYNAMIC(PackDia)

public:
	PackDia(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PackDia();

	// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString Name;
	afx_msg void OnBnClickedButton1();
};
