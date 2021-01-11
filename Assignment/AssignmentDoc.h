
// AssignmentDoc.h : interface of the CAssignmentDoc class
//


#pragma once
#include"MazeTraversal.h"

class CAssignmentDoc : public CDocument
{
protected: // create from serialization only
	CAssignmentDoc() noexcept;
	DECLARE_DYNCREATE(CAssignmentDoc)

	// Attributes
public:
	MazeTraversal gameobj;

	// Operations
public:

	// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	// Implementation

	virtual ~CAssignmentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions

	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};