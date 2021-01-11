
// AssignmentView.cpp : implementation of the CAssignmentView class
//
#include<cmath>

#include "pch.h"
#include"windows.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Assignment.h"
#endif

#include "AssignmentDoc.h"
#include "AssignmentView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CAssignmentView

IMPLEMENT_DYNCREATE(CAssignmentView, CView)

BEGIN_MESSAGE_MAP(CAssignmentView, CView)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_RBUTTONUP()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// CAssignmentView construction/destruction

CAssignmentView::CAssignmentView() noexcept
{
	// TODO: add construction code here

}

CAssignmentView::~CAssignmentView()
{
}

BOOL CAssignmentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CAssignmentView drawing

void CAssignmentView::OnDraw(CDC* /*pDC*/)
{
	CAssignmentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC* pDC = GetDC();
	HDC hRes = *pDC;
	pDC->FillSolidRect(0,0, 480, 480, RGB(16,36,70));

	pDoc->gameobj.display(pDC);
	SetTimer(1, 100, NULL);

	//cimage->Destroy();

}


// CAssignmentView diagnostics

#ifdef _DEBUG
void CAssignmentView::AssertValid() const
{
	CView::AssertValid();
}

void CAssignmentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAssignmentDoc* CAssignmentView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAssignmentDoc)));
	return (CAssignmentDoc*)m_pDocument;
}
#endif //_DEBUG


// CAssignmentView message handlers
void CAssignmentView::ResizeWindow()
{

	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);
	//  Calculate the difference
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();
	//  Change the window size as 100x100
	rcWindow.right = rcWindow.left + 480 + nWidthDiff;
	rcWindow.bottom = rcWindow.top + 480 + nHeightDiff;
	//  The MoveWindow function resizes the frame window
	GetParentFrame()->MoveWindow(&rcWindow);
}


void CAssignmentView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CAssignmentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC* pDC = GetDC();
	HDC hRes = *pDC;
	if (nChar == 'W')
	{

		if (pDoc->gameobj.getCellValueAt((pDoc->gameobj.getCurrRow() - 1), pDoc->gameobj.getCurrCol()) == '.')
		{
			pDoc->gameobj.moveUp();
			pDC->FillSolidRect((pDoc->gameobj.getCurrCol()) * 40, (pDoc->gameobj.getCurrRow() + 1) * 40, 40, 40, RGB(0, 0, 0));
			pDoc->gameobj.display(pDC);
		}

	}
	if (nChar =='D')
	{
		if (pDoc->gameobj.getCellValueAt(pDoc->gameobj.getCurrRow(), pDoc->gameobj.getCurrCol() + 1) == '.')

		{
			pDoc->gameobj.moveRight();
			pDC->FillSolidRect((pDoc->gameobj.getCurrCol() - 1) * 40, pDoc->gameobj.getCurrRow() * 40, 40, 40, RGB(0, 0, 0));
			pDoc->gameobj.display(pDC);
		}

		if (pDoc->gameobj.DestinationReached() == 1)
		{
			CImage* cimage2 = new CImage();
			cimage2->Load(L"images\\youwin.png");//images folder is placed in working directory 	                  	
			cimage2->Draw(hRes, 0, 0, 480, 480);

		}
	}
	if (nChar == 'S')
	{


		if (pDoc->gameobj.getCellValueAt(pDoc->gameobj.getCurrRow() + 1, pDoc->gameobj.getCurrCol()) == '.')
		{
			pDoc->gameobj.moveDown();
			pDC->FillSolidRect((pDoc->gameobj.getCurrCol()) * 40, (pDoc->gameobj.getCurrRow() - 1) * 40, 40, 40, RGB(0, 0, 0));
			pDoc->gameobj.display(pDC);
		}
	}
	if (nChar == 'A')
	{
		if (pDoc->gameobj.getCellValueAt(pDoc->gameobj.getCurrRow(), pDoc->gameobj.getCurrCol() - 1) == '.')
		{
			pDoc->gameobj.moveLeft();
			pDC->FillSolidRect((pDoc->gameobj.getCurrCol() + 1) * 40, pDoc->gameobj.getCurrRow() * 40, 40, 40, RGB(0, 0, 0));
			pDoc->gameobj.display(pDC);
		}

	}
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CAssignmentView::OnTimer(UINT_PTR nIDEvent)
{
//	// TODO: Add your message handler code here and/or call default
//	CAssignmentDoc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
//	if (!pDoc)
//		return;
//	CDC* pDC = GetDC();
//	if (nIDEvent == 2) {
//		pDoc->gameobj.moveToNextCell();
//		pDoc->gameobj.display(pDC);
//		//pDC->FillSolidRect((pDoc->m.getCurrCol()) * 40, (pDoc->m.getCurrRow() + 1) * 40, 40, 40, RGB(0, 0, 0));
//	}
//	CView::OnTimer(nIDEvent);
}


void CAssignmentView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnRButtonUp(nFlags, point);
}
void CAssignmentView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{

	// TODO: Add your message handler code here
}
