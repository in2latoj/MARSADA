#if !defined(AFX_DLG_DATOS_H__4D9BA860_CB1B_11D5_9FE7_8BFE28E81040__INCLUDED_)
#define AFX_DLG_DATOS_H__4D9BA860_CB1B_11D5_9FE7_8BFE28E81040__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Dlg_Datos.h : header file
#include "DatosCiclo.h"
#include "DatosIniciales.h"

class CDlg_Datos : public CDialog
{
// Construction
public:
	void Actualiza(CDatosCiclo Datos);
	CDlg_Datos(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_Datos)
	enum { IDD = IDD_DATOS };
	CStatic	m_bitmap6;
	CStatic	m_bitmap5;
	CStatic	m_bitmap4;
	CStatic	m_bitmap3;
	CStatic	m_bitmap2;
	CStatic	m_bitmap1;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_Datos)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlg_Datos)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_DATOS_H__4D9BA860_CB1B_11D5_9FE7_8BFE28E81040__INCLUDED_)
