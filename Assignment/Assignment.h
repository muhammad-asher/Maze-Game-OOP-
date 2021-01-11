
// Assignment.h : main header file for the Assignment application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CAssignmentApp:
// See Assignment.cpp for the implementation of this class
//

class CAssignmentApp : public CWinApp
{
public:
	CAssignmentApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAssignmentApp theApp;
