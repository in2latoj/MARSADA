// Orientacion.h: interface for the COrientacion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ORIENTACION_H__8EDA5FE0_1D21_11D5_AD8D_00105A4E3CAF__INCLUDED_)
#define AFX_ORIENTACION_H__8EDA5FE0_1D21_11D5_AD8D_00105A4E3CAF__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "header1.h"

// Definimos la orientaci�n del agente en funci�n de dos circunferencias : una en el plano XY
// y otra en el plano YZ
// Dividimos dichas circunferencias en zonas que vendr�n determinadas por el �ngulo de giro del
// agente

class COrientacion  
{
public:
	void PonerAnguloGiro(float angulo);
	void PonerZonaYZ(int zona);
	void PonerZonaXY(int zona);

	 COrientacion(float angulo, int zonaXY,int zonaYZ);
	float DarAnguloGiro();
	void Mover(movimientos mov);
    COrientacion(float angulo );     // El �ngulo determina el tama�o de cada zona
	int DarZonaXY();
	int DarZonaYZ();
	COrientacion();
	virtual ~COrientacion();
	friend ::ostream &operator<<(::ostream &salida, COrientacion &obj);

	int zonaXY;			//La orientaci�n del agente viene dada por dos zonas
	int zonaYZ;
	float anguloGiro;
	int numZonas;       // En funci�n del �ngulo de giro del agente sacamos el n�mero de zonas
				        // que tiene cada plano
};

#endif // !defined(AFX_ORIENTACION_H__8EDA5FE0_1D21_11D5_AD8D_00105A4E3CAF__INCLUDED_)
