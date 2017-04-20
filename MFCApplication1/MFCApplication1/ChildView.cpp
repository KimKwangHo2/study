
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_pt.x = 100;
	m_pt.y = 100;
	m_dy = 10;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//CPoint m_pt;

	dc.Ellipse(m_pt.x, m_pt.y, m_pt.x + 100, m_pt.y + 100);
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



//void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	switch (nChar)
//	{
//	case VK_LEFT:
//		m_pt.x -= 10;
//		break;
//	case VK_RIGHT:
//		m_pt.x += 10;
//		break;
//	case VK_UP:
//		m_pt.y -= 10;
//		break;
//	case VK_DOWN:
//		m_pt.y += 10;
//		break;
//	}
//
//	Invalidate();
//
//	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
//}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	SetTimer(0, 30, NULL);
	SetTimer(1, 500, NULL);


	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nIDEvent == 0)
	{
		CRect rect;
		GetClientRect(&rect);
		if (m_pt.y + 100 > rect.bottom) {
			m_dy = -10;
		}

		if (m_pt.y < 0) {
			m_dy = 10;
		}

		m_pt.y += m_dy;
		Invalidate();
	}

	if (nIDEvent == 0)
	{
		CRect rect;
		GetClientRect(&rect);


	}

	CWnd::OnTimer(nIDEvent);
}
