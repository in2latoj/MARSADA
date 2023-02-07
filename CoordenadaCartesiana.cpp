// CoordenadaCartesiana.cpp: implementation of the CCoordenadaCartesiana class.
//
//////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "Lander.h"
#include "CoordenadaCartesiana.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCoordenadaCartesiana::CCoordenadaCartesiana()
{
}

CCoordenadaCartesiana::~CCoordenadaCartesiana()
{
}

CCoordenadaCartesiana::CCoordenadaCartesiana(float n_x, float n_y, float n_z)
{
	this->PonerX(n_x);
	this->PonerY(n_y);
	this->PonerZ(n_z);
}

CCoordenadaEsferica CCoordenadaCartesiana::CartesianaAEsferica()
{
	 float teta;
	 float si;
     float r;

	 teta =(float)atan( sqrt(x*x + y*y) / z);
     si   = (float)atan(y / x );
	 r    = (float) sqrt(x*x + y*y + z*z );
	 CCoordenadaEsferica posicion(r,teta,si);
     return(posicion);
}

float CCoordenadaCartesiana::DarX() {return this->x;}
float CCoordenadaCartesiana::DarY() {return this->y;}
float CCoordenadaCartesiana::DarZ() {return this->z;}

void CCoordenadaCartesiana::PonerX(float nx)
{
  x=nx;
}

void CCoordenadaCartesiana::PonerY(float ny)
{
  y=ny;
}

void CCoordenadaCartesiana::PonerZ(float nz)
{
  z=nz;
}

float CCoordenadaCartesiana::ObtenerDistancia(CCoordenadaCartesiana punto)
{
   
   return ( sqrt(  pow(x-punto.DarX(),2) +
		           pow(y-punto.DarY(),2) +
		           pow(z-punto.DarZ(),2) ) );
}


	

CCoordenadaCartesiana CCoordenadaCartesiana::operator+(CCoordenadaCartesiana p)
{
    CCoordenadaCartesiana temp;
	temp.x = x + p.x;
	temp.y = y + p.y;
	temp.z = z + p.z;
	
    return temp;
}


CCoordenadaCartesiana CCoordenadaCartesiana::operator-(CCoordenadaCartesiana p)
{
    CCoordenadaCartesiana temp;
	temp.x = x - p.x;
	temp.y = y - p.y;
	temp.z = z - p.z;
	
    return temp;
}



CCoordenadaCartesiana CCoordenadaCartesiana::operator=(CCoordenadaCartesiana c)
{
	this->x = c.DarX();
	this->y = c.DarY();
	this->z = c.DarZ();
	return *this;
}

void CCoordenadaCartesiana::Girar(float angulo1, float angulo2,float radio)
{

   x=x+ radio* cos(angulo1);
   y=y+ radio* sin(angulo1);
   z=z+ radio* sin(angulo2);


}

void CCoordenadaCartesiana::Trasladar(COrientacion o, int pasos)
{
   
   float angulo= o.DarAnguloGiro() * o.DarZonaXY();
   float angulo2= o.DarAnguloGiro() * o.DarZonaYZ();

   float xx= pasos * sin(angulo);
   float yy= pasos * cos(angulo);
   float zz= pasos * sin(angulo2);

   x += xx;
   y += yy;
   z += zz;

}


::ostream &operator<<(::ostream &salida, CCoordenadaCartesiana &obj)
{
   salida << obj.x << "\n";
	salida << obj.y << "\n";
	salida << obj.z << "\n";

	return salida;
}

// Vito
void CCoordenadaCartesiana::EsfericaACartesiana(CCoordenadaEsferica coord)
{
	x= coord.DarRadio()*sin(coord.DarTeta())*cos(coord.DarSi());
	y= coord.DarRadio()*sin(coord.DarTeta())*sin(coord.DarSi());
	z= coord.DarRadio()*cos(coord.DarTeta());
}