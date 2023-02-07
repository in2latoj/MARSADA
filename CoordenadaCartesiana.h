// CoordenadaCartesiana.h: interface for the CCoordenadaCartesiana class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDENADACARTESIANA_H__96B04082_1165_11D5_AD8D_00105A4E3CAF__INCLUDED_)
#define AFX_COORDENADACARTESIANA_H__96B04082_1165_11D5_AD8D_00105A4E3CAF__INCLUDED_

//#include "CoordenadaEsferica.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CoordenadaEsferica.h"
#include "Orientacion.h"
#include "header1.h"

class CCoordenadaEsferica;

class CCoordenadaCartesiana  
{
public:
	
	void Trasladar(COrientacion o, int pasos );
	void Girar(float angulo1, float angulo2,float radio);
	CCoordenadaCartesiana operator+(CCoordenadaCartesiana p);
    CCoordenadaCartesiana operator-(CCoordenadaCartesiana p);	
    CCoordenadaCartesiana operator=(CCoordenadaCartesiana c);
    friend ::ostream &operator<<(::ostream &stream, CCoordenadaCartesiana &obj);


	float ObtenerDistancia(CCoordenadaCartesiana punto );
	void PonerZ(float z);
	void PonerY(float y);
	void PonerX(float x);
	float DarX(void);
	float DarZ(void);
	float DarY(void);

	void EsfericaACartesiana(CCoordenadaEsferica coord); // Añadido vito

	CCoordenadaEsferica CartesianaAEsferica();
	 CCoordenadaCartesiana(float x,float y,float z);
	CCoordenadaCartesiana();
	virtual ~CCoordenadaCartesiana();

//private: //Los hago publicos es mas comodo
	float z;
	float y;
	float x;
};

#endif // !defined(AFX_COORDENADACARTESIANA_H__96B04082_1165_11D5_AD8D_00105A4E3CAF__INCLUDED_)
