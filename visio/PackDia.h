#pragma once
#include"resource.h"

// PackDia 对话框

class PackDia : public CDialogEx
{
	DECLARE_DYNAMIC(PackDia)

public:
	PackDia(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PackDia();

	// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString Name;
	afx_msg void OnBnClickedButton1();
};
