#if !defined(AFX_DLG_BUSCARPATRON_H__50B0F6A0_C273_11D5_9FE7_BE0E6326FF5E__INCLUDED_)
#define AFX_DLG_BUSCARPATRON_H__50B0F6A0_C273_11D5_9FE7_BE0E6326FF5E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_BuscarPatron.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_BuscarPatron dialog

class CDlg_BuscarPatron : public CDialog
{
// Construction
public:
	CDlg_BuscarPatron(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_BuscarPatron)
	enum { IDD = IDD_BUSCAR_PATRON };
	int		m_n_patron;
	BOOL	m_atras;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_BuscarPatron)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_BuscarPatron)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_BUSCARPATRON_H__50B0F6A0_C273_11D5_9FE7_BE0E6326FF5E__INCLUDED_)
