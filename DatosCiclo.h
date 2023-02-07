// DatosCiclo.h: interface for the CDatosCiclo class.

#if !defined(AFX_DATOSCICLO_H__BE8B4CA_6A91_11D5_B120_90318C050B29__INCLUDED_)
#define AFX_DATOSCICLO_H__BE8B4CA6_6A91_11D5_B120_90318C050B29__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CoordenadaCartesiana.h"
#include "Orientacion.h"
#include "auxiliar.h"

typedef struct
{
	int numElementos;
	float elementos[6];
}TVector;

typedef struct
{
	int num_accion;
	float grado_asoc;
} TAsociacion;

class CDatosCiclo  
{

public:
	CDatosCiclo(int numAcciones);
	CDatosCiclo();
	virtual ~CDatosCiclo();

	CCoordenadaCartesiana Posicion;
	COrientacion Orientacion;
	int numAgenteMovido;
	int numGrupo;
	int numPatron;
	int numAccion;
	float valoracionNeg;
	float valoracionPos;
	TVector seleccion;
	int num_acciones_asoc;
#if TIPOAGENTE == 1
	TAsociacion grados_asociacion[11];
#elif TIPOAGENTE == 0
	TAsociacion grados_asociacion[6];
#endif
	float valoracionPropagada;
	float valoracionPatron; // Olivia 28/06/2006

};

#endif // !defined(AFX_DATOSCICLO_H__BE8B4CA6_6A91_11D5_B120_90318C050B29__INCLUDED_)
