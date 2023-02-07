// Dlg_Estadisticas.cpp : implementation file
//

#include "stdafx.h"
#include "Lander.h"
#include "Dlg_Estadisticas.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_Estadisticas dialog


CDlg_Estadisticas::CDlg_Estadisticas(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Estadisticas::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Estadisticas)
	m_media = _T("");
	m_desviacion = _T("");
	m_porcentage = _T("");
	m_patrones = _T("");

	// KIKO 26-01-2006
	m_porcentaje_real = _T("");
	m_horas = _T("");
	m_minutos = _T("");
	m_segundos = _T("");
	m_int1 = _T("");
	m_int2 = _T("");
	m_int3 = _T("");
	m_int4 = _T("");
	m_int5 = _T("");
	//}}AFX_DATA_INIT
}


void CDlg_Estadisticas::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Estadisticas)
	DDX_Text(pDX, IDC_STATIC_MEDIA, m_media);
	DDX_Text(pDX, IDC_STATIC_DESVTIP, m_desviacion);
	DDX_Text(pDX, IDC_STATIC_PORCENTAGE, m_porcentage);
	DDX_Text(pDX, IDC_STATIC_PATRONES, m_patrones);

	// KIKO 26-01-2006
	DDX_Text(pDX, IDC_STATIC_PORCENTAGE2, m_porcentaje_real);
	DDX_Text(pDX, IDC_STATIC_HORAS, m_horas);
	DDX_Text(pDX, IDC_STATIC_MINUTOS, m_minutos);
	DDX_Text(pDX, IDC_STATIC_SEGUNDOS, m_segundos);
	DDX_Text(pDX, IDC_STATIC_INT1, m_int1);
	DDX_Text(pDX, IDC_STATIC_INT2, m_int2);
	DDX_Text(pDX, IDC_STATIC_INT3, m_int3);
	DDX_Text(pDX, IDC_STATIC_INT4, m_int4);
	DDX_Text(pDX, IDC_STATIC_INT5, m_int5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_Estadisticas, CDialog)
	//{{AFX_MSG_MAP(CDlg_Estadisticas)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_Estadisticas message handlers
