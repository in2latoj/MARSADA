// Dlg_BuscarPatron.cpp : implementation file
//

#include "stdafx.h"
#include "Lander.h"
#include "Dlg_BuscarPatron.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_BuscarPatron dialog


CDlg_BuscarPatron::CDlg_BuscarPatron(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_BuscarPatron::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_BuscarPatron)
	m_n_patron = 0;
	m_atras = FALSE;
	//}}AFX_DATA_INIT
}


void CDlg_BuscarPatron::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_BuscarPatron)
	DDX_Text(pDX, IDC_EDIT1, m_n_patron);
	DDX_Check(pDX, IDC_CHECK1, m_atras);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_BuscarPatron, CDialog)
	//{{AFX_MSG_MAP(CDlg_BuscarPatron)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_BuscarPatron message handlers
