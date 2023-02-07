// Lander.h : main header file for the LANDER application
//

#if !defined(AFX_LANDER_H__0D31CB84_0599_11D5_9FE5_B2B36BD66F63__INCLUDED_)
#define AFX_LANDER_H__0D31CB84_0599_11D5_9FE5_B2B36BD66F63__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLanderApp:
// See Lander.cpp for the implementation of this class
//

class CLanderApp : public CWinApp
{
public:
	CLanderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLanderApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLanderApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LANDER_H__0D31CB84_0599_11D5_9FE5_B2B36BD66F63__INCLUDED_)
