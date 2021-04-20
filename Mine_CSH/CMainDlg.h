#pragma once
#include "Mine.h"
#include "Container.h"
#include "Stack.h"
// CMainDlg 대화 상자

class CMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMainDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	Container <Mine*> mine_con;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	
	CButton* cel;
	afx_msg void OnBnClickedButt(UINT uid);
	afx_msg void OnBnClickedButtTest();
};
