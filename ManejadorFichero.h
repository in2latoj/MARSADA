// ManejadorFichero.h: interface for the CManejadorFichero class.

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sys/types.h>

#if !defined(AFX_MANEJADORFICHERO_H__BE8B4CA3_6A91_11D5_B120_90318C050B29__INCLUDED_)
#define AFX_MANEJADORFICHERO_H__BE8B4CA3_6A91_11D5_B120_90318C050B29__INCLUDED_

#include "DatosCiclo.h"	// Added by ClassView
#include "DatosIniciales.h"	// Added by ClassView

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CManejadorFichero
{
	::ifstream ficheroSimulacion;
    ::ifstream ficheroIndice;

	// NEW
	::ifstream ficheroObstaculos;

public:
	int DarMuestra();
	bool BuscarPatronAdelante ( int numPatron);
	int DarIntento();
	int DarCiclo();
	bool AnteriorIntento();
	bool AnteriorCiclo(bool PasarIntento);
	bool BuscarPatronAtras( int numPatron);
	bool SiguienteIntento();
	bool SiguienteCiclo(bool PasarIntento);
	CDatosCiclo DarDatosCiclo();
	CDatosIniciales *DarDatosIniciales();
	bool IrAIntento(int numero);
	bool IrACiclo(int numero);
    CManejadorFichero(CString nombre);
	virtual ~CManejadorFichero();

	indice *intentos; //Lo hago publico para poder acceder desde fuera
	int numIntentos;
	int numMuestras;

private:
	CDatosIniciales *datosIniciales;
	int cicloActual;
	int intentoActual;
};

#endif // !defined(AFX_MANEJADORFICHERO_H__BE8B4CA3_6A91_11D5_B120_90318C050B29__INCLUDED_)
