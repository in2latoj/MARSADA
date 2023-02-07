// Orientacion.cpp: implementation of the COrientacion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Lander.h"
#include "Orientacion.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COrientacion::COrientacion()
{

}

COrientacion::COrientacion(float angulo)
{
  
	numZonas= 360./angulo;
	anguloGiro=angulo;
    zonaXY=0;
	zonaYZ=0;
}

COrientacion::COrientacion(float angulo, int zonaXY, int zonaYZ)
{

	this->zonaXY= zonaXY;
	this->zonaYZ= zonaYZ;
	anguloGiro=angulo;
}



COrientacion::~COrientacion()
{

}


int COrientacion::DarZonaXY()
{
  return zonaXY;
}


int  COrientacion::DarZonaYZ()
{
  return zonaYZ;
}



void COrientacion::Mover(movimientos mov)
{

   switch(mov)
   {

   case GIRAR_DCHA: zonaXY= (zonaXY +1) % numZonas;
					break;

   case GIRAR_IZDA: zonaXY= (zonaXY -1) % numZonas;					
			        break;

   case BAJAR: zonaYZ= (zonaYZ +1) % numZonas;
					break;

   case SUBIR:zonaYZ= (zonaYZ -1) % numZonas;
			        break;
   }    				
   
}


float COrientacion::DarAnguloGiro()
{
  return anguloGiro;
}



::ostream &operator<<(::ostream &salida, COrientacion &obj)
{
	salida << obj.zonaXY << "\n";
	salida << obj.zonaYZ << "\n";

	return salida;
}

void COrientacion::PonerZonaXY(int zona)
{
  zonaXY=zona;
}

void COrientacion::PonerZonaYZ(int zona)
{
	zonaYZ=zona;

}

void COrientacion::PonerAnguloGiro(float angulo)
{
  anguloGiro=angulo;
}
