
// AssignmentView.h : interface of the CAssignmentView class
//

#pragma once

class CAssignmentView : public CView
{
protected: // create from serialization only
	CAssignmentView() noexcept;
	DECLARE_DYNCREATE(CAssignmentView)

	// Attributes
public:
	CAssignmentDoc* GetDocument() const;

	// Operations
public:

	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// Implementation
public:
	virtual ~CAssignmentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void ResizeWindow();


	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};

#ifndef _DEBUG  // debug version in AssignmentView.cpp
inline CAssignmentDoc* CAssignmentView::GetDocument() const
{
	return reinterpret_cast<CAssignmentDoc*>(m_pDocument);
}
#endif
