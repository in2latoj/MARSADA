// CoordenadaEsferica.h: interface for the CCoordenadaEsferica class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDENADAESFERICA_H__96B04081_1165_11D5_AD8D_00105A4E3CAF__INCLUDED_)
#define AFX_COORDENADAESFERICA_H__96B04081_1165_11D5_AD8D_00105A4E3CAF__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define PI 3.14159265

//#include "CoordenadaCartesiana.h"

class CCoordanadaCartesiana;

class CCoordenadaEsferica  
{
public:
	float DarRadio(void);
	float DarSi(void);
	float DarTeta(void);
	/* Vito */
	void MoverXY(float dist);
	void MoverYZ(float dist);
	void MoverRadio(float dist);
	/* Fin */

	CCoordenadaEsferica(float r, float teta,float si);
//	CCoordenadaCartesiana EsfericaACartesiana();
	CCoordenadaEsferica();
	

	virtual ~CCoordenadaEsferica();

 

private:
	float r;		// distancia del punto al origen de coordenadas
	float si;	    // angulo en el plano XY (0 a 2*PI)
	float teta;     // angulo en el plano YZ (0 a PI)

};

#endif // !defined(AFX_COORDENADAESFERICA_H__96B04081_1165_11D5_AD8D_00105A4E3CAF__INCLUDED_)
