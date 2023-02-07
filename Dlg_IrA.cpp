// Dlg_IrA.cpp : implementation file
//

#include "stdafx.h"
#include "Lander.h"
#include "Dlg_IrA.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_IrA dialog


CDlg_IrA::CDlg_IrA(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_IrA::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_IrA)
	m_intento = 0;
	m_ciclo = 0;
	//}}AFX_DATA_INIT
}


void CDlg_IrA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_IrA)
	DDX_Text(pDX, IDC_EDIT1, m_intento);
	DDV_MinMaxInt(pDX, m_intento, 0, 999999999); // Kiko 26-01-2006
	DDX_Text(pDX, IDC_EDIT2, m_ciclo);
	DDV_MinMaxInt(pDX, m_ciclo, 0, 999999999); // Kiko 26-01-2006
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_IrA, CDialog)
	//{{AFX_MSG_MAP(CDlg_IrA)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_IrA message handlers
