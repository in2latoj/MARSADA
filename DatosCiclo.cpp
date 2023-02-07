// DatosCiclo.cpp: implementation of the CDatosCiclo class.

#include "stdafx.h"
#include "Lander.h"

#include "DatosCiclo.h"

CDatosCiclo::CDatosCiclo(int numAcciones)
{
   seleccion.numElementos=numAcciones;
   for(int i=0; i<numAcciones; i++)
	   seleccion.elementos[i]= 1/numAcciones;
}

CDatosCiclo::CDatosCiclo()
{
	seleccion.numElementos = 6;
	for(int i=0; i<6; i++)
		seleccion.elementos[i] = 1/6;
	numPatron           = 0;
	numAccion	        = 0;
	valoracionNeg       = 0;
	valoracionPos       = 0;
	valoracionPropagada = 0;
	valoracionPatron    = 0; // Olivia 28/06/2006
}

CDatosCiclo::~CDatosCiclo()
{
}