// Dlg_Datos.cpp : implementation file
//

#include "stdafx.h"
#include "Lander.h"
#include "Dlg_Datos.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_Datos dialog


CDlg_Datos::CDlg_Datos(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_Datos::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Datos)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	//Create(IDD_DATOS);

}


void CDlg_Datos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Datos)
	DDX_Control(pDX, IDC_STATIC_B6, m_bitmap6);
	DDX_Control(pDX, IDC_STATIC_B5, m_bitmap5);
	DDX_Control(pDX, IDC_STATIC_B4, m_bitmap4);
	DDX_Control(pDX, IDC_STATIC_B3, m_bitmap3);
	DDX_Control(pDX, IDC_STATIC_B2, m_bitmap2);
	DDX_Control(pDX, IDC_STATIC_B1, m_bitmap1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Datos, CDialog)
	//{{AFX_MSG_MAP(CDlg_Datos)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_Datos message handlers

void CDlg_Datos::Actualiza(CDatosCiclo Datos)
{

	//Titulo de la ventana

	// Estas dos lineas las cambia Kiko.19/12/2005
	CString Titulo="Datos del Agente ";
	Titulo.AppendChar('0'+Datos.numAgenteMovido);
	//Titulo = Titulo + ('0'+Datos.numAgenteMovido);

	this->SetWindowText(Titulo);

	//VALORACIONES
	CString ValProp,ValPatron,ValP,ValN,Patron;

	ValProp.Format(_T("%3.2f"),Datos.valoracionPropagada);
		SetDlgItemText(IDC_STATIC_VAL_PROP,ValProp);
	ValPatron.Format(_T("%3.2f"),Datos.valoracionPatron); // Olivia 28/06/2006
		SetDlgItemText(IDC_STATIC_VAL_PATR,ValPatron); // Olivia 28/06/2006
	ValP.Format(_T("%3.2f"),Datos.valoracionPos);
		SetDlgItemText(IDC_STATIC_VAL_P,ValP);
	ValN.Format(_T("%3.2f"),Datos.valoracionNeg);
		SetDlgItemText(IDC_STATIC_VAL_N,ValN);
	Patron.Format(_T("%i"),Datos.numPatron);
		SetDlgItemText(IDC_STATIC_PATRON,Patron);

	//ACCIONES
	CString arriba,abajo,dcha,izda,avanzar,parar;

	arriba.Format(_T("%3.2f"),Datos.seleccion.elementos[4]);
		SetDlgItemText(IDC_STATIC_S1,arriba);
	abajo.Format(_T("%3.2f"),Datos.seleccion.elementos[5]);
		SetDlgItemText(IDC_STATIC_S2,abajo);
	dcha.Format(_T("%3.2f"),Datos.seleccion.elementos[1]);
		SetDlgItemText(IDC_STATIC_S4,dcha);
	izda.Format(_T("%3.2f"),Datos.seleccion.elementos[2]);
		SetDlgItemText(IDC_STATIC_S3,izda);
	avanzar.Format(_T("%3.2f"),Datos.seleccion.elementos[3]);
		SetDlgItemText(IDC_STATIC_S6,avanzar);
	parar.Format(_T("%3.2f"),Datos.seleccion.elementos[0]);
		SetDlgItemText(IDC_STATIC_S5,parar);


	//GRADOS ASOCIACION
	CString GAsociacion;
	
	GAsociacion.Format(_T("NO EXPL"));
	
	SetDlgItemText(IDC_STATIC_G6,GAsociacion);
	SetDlgItemText(IDC_STATIC_G1,GAsociacion);
	SetDlgItemText(IDC_STATIC_G2,GAsociacion);
	SetDlgItemText(IDC_STATIC_G3,GAsociacion);
	SetDlgItemText(IDC_STATIC_G4,GAsociacion);
	SetDlgItemText(IDC_STATIC_G5,GAsociacion);
	
	for (int i=0;i<Datos.num_acciones_asoc;i++)
	{
		int k=Datos.grados_asociacion[i].num_accion;
		GAsociacion.Format(_T("%.2f"),Datos.grados_asociacion[i].grado_asoc);
		switch (k)
		{
			case 0:	SetDlgItemText(IDC_STATIC_G5,GAsociacion);
				    break;
			case 1:	SetDlgItemText(IDC_STATIC_G4,GAsociacion);
				    break;
			case 2:	SetDlgItemText(IDC_STATIC_G3,GAsociacion);
				    break;
			case 3:	SetDlgItemText(IDC_STATIC_G6,GAsociacion);
				    break;
			case 4:	SetDlgItemText(IDC_STATIC_G1,GAsociacion);
				    break;
			case 5:	SetDlgItemText(IDC_STATIC_G2,GAsociacion);
				    break;
			
		}
	}
	//Orientacion
	CString zonaXY,zonaYZ;

	// Kiko 31/03/2006
	CString X,Y,Z;

	X.Format(_T("%3.2f"),Datos.Posicion.DarX());
	Y.Format(_T("%3.2f"),Datos.Posicion.DarY());
	Z.Format(_T("%3.2f"),Datos.Posicion.DarZ());

	zonaXY.Format(_T("%i"),Datos.Orientacion.DarZonaXY());
	SetDlgItemText(IDC_STATIC_ZONAXY,zonaXY);
	SetDlgItemText(IDC_STATIC_ZONAYZ,zonaYZ);

	// Posicion // Kiko 31/03/2006
	SetDlgItemText(IDC_STATIC_ZONAXY2,X);
	SetDlgItemText(IDC_STATIC_ZONAXY3,Y);
	SetDlgItemText(IDC_STATIC_ZONAXY4,Z);

	//Bitmaps (Flechitas)
	m_bitmap1.ShowWindow(SW_HIDE);
	m_bitmap2.ShowWindow(SW_HIDE);
	m_bitmap3.ShowWindow(SW_HIDE);
	m_bitmap4.ShowWindow(SW_HIDE);
	m_bitmap5.ShowWindow(SW_HIDE);
	m_bitmap6.ShowWindow(SW_HIDE);
	switch (Datos.numAccion)
		{
			case 0: m_bitmap5.ShowWindow(SW_SHOW);
				    break;
			case 1:	m_bitmap4.ShowWindow(SW_SHOW);
				    break;
			case 2:	m_bitmap3.ShowWindow(SW_SHOW);
				    break;
			case 3:	m_bitmap6.ShowWindow(SW_SHOW);
				    break;
			case 4:	m_bitmap1.ShowWindow(SW_SHOW);
				    break;
			case 5:	m_bitmap2.ShowWindow(SW_SHOW);
				    break;
			
		}
	//Devuelve el control a la ventana principal
		//this->SetFocus();
		//this->ShowWindow(SW_SHOW);
	CWnd * ventana=GetParent();
	ventana->SetActiveWindow();
}
