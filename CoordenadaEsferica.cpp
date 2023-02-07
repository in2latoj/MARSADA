// CoordenadaEsferica.cpp: implementation of the CCoordenadaEsferica class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Lander.h"
#include <math.h>
#include "CoordenadaEsferica.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCoordenadaEsferica::CCoordenadaEsferica()
{

}

CCoordenadaEsferica::~CCoordenadaEsferica()
{

}

/*CCoordenadaCartesiana CCoordenadaEsferica::EsfericaACartesiana(void)
{

	float x= r*sin(teta)*cos(si);
	float y= r*sin(teta)*sin(si);
	float z= r*cos(teta);

	CCoordenadaCartesiana coord(x,y,z);
    return(coord);
 
	

}*/

CCoordenadaEsferica::CCoordenadaEsferica(float n_r, float n_teta, float n_si)
{
   r=n_r;
   teta=n_teta;
   si=n_si;


}

float CCoordenadaEsferica::DarTeta()
{
	return teta;
}

float CCoordenadaEsferica::DarSi()
{

	return si;
}



float CCoordenadaEsferica::DarRadio()
{

	return r;
}

void CCoordenadaEsferica::MoverYZ(float dist)
{
	float angAux = dist/r;

	//teta = (teta + angAux)%(2*PI);
	teta = (float)fmod(teta+angAux,(float)PI);
}

void CCoordenadaEsferica::MoverXY(float dist)
{
	float angAux = dist/r;

	//si = (si + angAux)%(PI);
	si = (float)fmod(si+angAux,2*(float)PI);
}

void CCoordenadaEsferica::MoverRadio(float dist)
{
	r += dist;
}