
// ChildView.cpp : CChildView Ŭ������ ����
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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//CPoint m_pt;

	dc.Ellipse(m_pt.x, m_pt.y, m_pt.x + 100, m_pt.y + 100);
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



//void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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


	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

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
