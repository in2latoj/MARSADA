// DibAgente.h: interface for the CDibAgente class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBAGENTE_H__AA031B40_6B00_11D5_9FE7_D2DC84024C6C__INCLUDED_)
#define AFX_DIBAGENTE_H__AA031B40_6B00_11D5_9FE7_D2DC84024C6C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CoordenadaCartesiana.h"
#include "Orientacion.h"
#include "DatosCiclo.h"
#include "DatosIniciales.h"
#include "Dlg_Datos.h"

class CDibAgente  
{
public:
	CDibAgente();	
	virtual ~CDibAgente();
	bool Llego();
	void MuestraDatos(CWnd * ventana);
	void DibujaCono();
	void TomaCono(TGeometria Puntos);
	void Actualiza(CDatosCiclo NuevosDatos);
	void DibujaAgente();
	void Inicializar(CCoordenadaCartesiana inicio,COrientacion orientacion,int numAgente,int numGrupo);
	void PonTipo(int tipoEscenario); // Olivia
	CCoordenadaCartesiana DarPosicion(); // Victor
	COrientacion DarOrientacion(); // Victor

private:
	bool DatosMostrados;
	int NumAgente;
	int NumGrupo;
	void DibujaSombras();
	void DibujaAltura();
	void dibuja();
	void dibujaDron();

	CDatosCiclo Datos;
	TGeometria Cono;
	CDlg_Datos DlgDatos;
	int tipoEscenario; // Olivia

};

#endif // !defined(AFX_DIBAGENTE_H__AA031B40_6B00_11D5_9FE7_D2DC84024C6C__INCLUDED_)
