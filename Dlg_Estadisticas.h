#if !defined(AFX_DLG_ESTADISTICAS_H__A06E9AA0_D446_11D5_9FE7_C761DE8ACB44__INCLUDED_)
#define AFX_DLG_ESTADISTICAS_H__A06E9AA0_D446_11D5_9FE7_C761DE8ACB44__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_Estadisticas.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_Estadisticas dialog

class CDlg_Estadisticas : public CDialog
{
// Construction
public:
	CDlg_Estadisticas(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_Estadisticas)
	enum { IDD = IDD_RESULTADOS };
	CString	m_media;
	CString	m_desviacion;
	CString	m_porcentage;
	CString	m_patrones;

	// KIKO 26-01-2006
	CString	m_porcentaje_real;
	CString	m_horas;
	CString	m_minutos;
	CString	m_segundos;
	CString	m_int1;
	CString	m_int2;
	CString	m_int3;
	CString	m_int4;
	CString	m_int5;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_Estadisticas)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_Estadisticas)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_ESTADISTICAS_H__A06E9AA0_D446_11D5_9FE7_C761DE8ACB44__INCLUDED_)
