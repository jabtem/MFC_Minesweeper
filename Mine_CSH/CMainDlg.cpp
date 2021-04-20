// CMainDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Mine_CSH.h"
#include "CMainDlg.h"
#include "afxdialogex.h"
#include <time.h>

// CMainDlg 대화 상자

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_DIALOG, pParent)
{

}

CMainDlg::~CMainDlg()
{
	delete[]cel;
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	for (int i = 0;i < 36;++i)
	{
		DDX_Control(pDX, IDC_BUTT1+i, cel[i]);
	}
	
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_COMMAND_RANGE(IDC_BUTT1, IDC_BUTT36, &CMainDlg::OnBnClickedButt)
	ON_BN_CLICKED(IDC_BUTT_TEST, &CMainDlg::OnBnClickedButtTest)
END_MESSAGE_MAP()


// CMainDlg 메시지 처리기


BOOL CMainDlg::OnInitDialog()
{
	
	cel = new CButton[36];
	srand((unsigned)time(NULL));

	for (int i = 0;i < 36;++i)
	{
		mine_con.Insert(new Mine);
	}
	int len = mine_con.GetElemSum();
	int lastIdx = len - 1;//배열의 마지막 인덱스넘버
	for (int i = 0;i < 3;++i)
	{
		
		int idx = rand() % len;//0~35까지 난수
		if (mine_con.GetItem(idx)->GetIsMine() == 1)
			--i;
		else
			mine_con.GetItem(idx)->SetIsMine(1);
	}

	//지뢰 탐색
	for (int i = 0;i < len;++i)
	{
		int sqrtlen = sqrt(len); // 배열크기의 제곱근 정사각형이면 한행의 길이가 나옴
								 // 5x5 = 5;

		int top = i - sqrtlen;//위
		int bottom = i + sqrtlen;//아래

		int right = i + 1;//오른
		int right_B = i + (sqrtlen+1);//오른아래
		int right_T = i - (sqrtlen-1);//오른위

		int left = i - 1;//왼
		int left_B = i + (sqrtlen-1);//왼아래
		int left_T = i - (sqrtlen+1);//왼위

		

		if (top > -1)
		{
			if (mine_con.GetItem(top)->GetIsMine() == 1)//위
				mine_con.GetItem(i)->MineDetect();
		}
		if (bottom < len)
		{
			if (mine_con.GetItem(bottom)->GetIsMine() == 1)//아래
				mine_con.GetItem(i)->MineDetect();
		}
		if (left > -1 && left_T > -1 && right_T > -1)
		{
			if (mine_con.GetItem(left)->GetIsMine() == 1 && (left % sqrtlen) != sqrtlen-1)//왼쪽
				mine_con.GetItem(i)->MineDetect();

			if (mine_con.GetItem(left_T)->GetIsMine() == 1 && (left_T % sqrtlen) != sqrtlen - 1)//왼쪽위
				mine_con.GetItem(i)->MineDetect();

			if (mine_con.GetItem(right_T)->GetIsMine() == 1 && (right_T % sqrtlen) !=0)//오른쪽위
				mine_con.GetItem(i)->MineDetect();
		}

		if (left_B < len && right < len && right_B < len)
		{
			if (mine_con.GetItem(left_B)->GetIsMine() == 1 && (left_B % sqrtlen) != sqrtlen - 1)//왼쪽아래
				mine_con.GetItem(i)->MineDetect();


			if (mine_con.GetItem(right)->GetIsMine() == 1 && (right % sqrtlen) != 0)//오른쪽
				mine_con.GetItem(i)->MineDetect();

			if (mine_con.GetItem(right_B)->GetIsMine() == 1 && (right_B % sqrtlen) != 0)//오른쪽아래
				mine_con.GetItem(i)->MineDetect();
		}
	}

	

	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CMainDlg::OnBnClickedButt(UINT uid)
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int idx = uid-1012;
	int len = mine_con.GetElemSum();
	CString str;
	Stack<int> st(len);
	//str.Format(_T("%d"),idx);
	//str.Format(_T("%d"),mine_con.GetItem(idx)->GetMineCnt());

	if (mine_con.GetItem(idx)->GetIsMine() == 1)
	{
		cel[idx].SetWindowText(_T("X"));
		cel[idx].EnableWindow(FALSE);
	}
	else
	{
		//cel[idx].SetWindowText(_T(" "));
		cel[idx].EnableWindow(FALSE);


			int sqrtlen = sqrt(len); // 배열크기의 제곱근 정사각형이면 한행의 길이가 나옴
									 // 5x5 = 5;

			int top = idx - sqrtlen;//위
			int bottom = idx + sqrtlen;//아래

			int right = idx + 1;//오른
			int right_B = idx + (sqrtlen + 1);//오른아래
			int right_T = idx - (sqrtlen - 1);//오른위

			int left = idx - 1;//왼
			int left_B = idx + (sqrtlen - 1);//왼아래
			int left_T = idx - (sqrtlen + 1);//왼위



		
			if (top > -1)//위
			{
				if (mine_con.GetItem(top)->GetMineCnt()==0)
				{
					cel[top].EnableWindow(FALSE);
				}
				else 
				{
					str.Format(_T("%d"), mine_con.GetItem(top)->GetMineCnt());
					cel[top].SetWindowText(str);
				}

			}
			if (bottom < len)//아래
			{
				if (mine_con.GetItem(bottom)->GetMineCnt() == 0)
				{
					cel[bottom].EnableWindow(FALSE);
				}
				else
				{
					str.Format(_T("%d"), mine_con.GetItem(bottom)->GetMineCnt());
					cel[bottom].SetWindowText(str);
				}
			}
			if (left > -1 && left_T > -1 && right_T > -1)
			{
				if ((left % sqrtlen) != sqrtlen - 1)//왼쪽
				{
					str.Format(_T("%d"), mine_con.GetItem(left)->GetMineCnt());
					cel[left].SetWindowText(str);
				}


				if ((left_T % sqrtlen) != sqrtlen - 1)//왼쪽위
				{
					str.Format(_T("%d"), mine_con.GetItem(left_T)->GetMineCnt());
					cel[left_T].SetWindowText(str);
				}

				if ((right_T % sqrtlen) != 0)//오른쪽위
				{
					str.Format(_T("%d"), mine_con.GetItem(right_T)->GetMineCnt());
					cel[right_T].SetWindowText(str);
				}
			}

			if (left_B < len && right < len && right_B < len)
			{
				if ((left_B % sqrtlen) != sqrtlen - 1)//왼쪽아래
				{
					str.Format(_T("%d"), mine_con.GetItem(left_B)->GetMineCnt());
					cel[left_B].SetWindowText(str);
				}

				if ((right % sqrtlen) != 0)//오른쪽
				{
					str.Format(_T("%d"), mine_con.GetItem(right)->GetMineCnt());
					cel[right].SetWindowText(str);
				}

				if ((right_B % sqrtlen) != 0)//오른쪽아래
				{
					str.Format(_T("%d"), mine_con.GetItem(right_B)->GetMineCnt());
					cel[right_B].SetWindowText(str);
				}
			}
	}
}

//void CMainDlg::OnBnDoubleClickedButt(UINT uid)
//{
//	int idx = uid - 1012;
//	CString str;
//
//	cel[idx].SetWindowText(_T("F"));
//	cel[idx].EnableWindow(FALSE);
//}
void CMainDlg::OnBnClickedButtTest()
{
	CString str;
	for (int i = 0;i < mine_con.GetElemSum();++i)
	{
		str.Format(_T("%d"), mine_con.GetItem(i)->GetIsMine());
		cel[i].SetWindowText(str);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
