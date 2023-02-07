#if !defined(AFX_DLG_IRA_H__86691CE0_BDBA_11D5_9FE7_A05EEF4A0B5C__INCLUDED_)
#define AFX_DLG_IRA_H__86691CE0_BDBA_11D5_9FE7_A05EEF4A0B5C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_IrA.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_IrA dialog

class CDlg_IrA : public CDialog
{
// Construction
public:
	CDlg_IrA(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_IrA)
	enum { IDD = IDD_IR_A };
	int		m_intento;
	int		m_ciclo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_IrA)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_IrA)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_IRA_H__86691CE0_BDBA_11D5_9FE7_A05EEF4A0B5C__INCLUDED_)
