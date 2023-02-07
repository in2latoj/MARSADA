// DatosIniciales.cpp: implementation of the CDatosIniciales class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Lander.h"

#include "DatosIniciales.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDatosIniciales::CDatosIniciales(int numIntentos,int numGrupos,int numTotalAgentes,int numObjetivos)
{
   this->numIntentos     = numIntentos;
   this->numGrupos       = numGrupos;
   this->numTotalAgentes = numTotalAgentes;
   this->numObjetivos	 = numObjetivos;
   this->numAgentes      = new int[numGrupos];
   this->conos           = new TGeometria[numGrupos];
   this->orientIniciales = new COrientacion[numTotalAgentes];
   this->posIniciales    = new CCoordenadaCartesiana[numTotalAgentes];
   this->numAcciones     = new int[numTotalAgentes];
}

CDatosIniciales::~CDatosIniciales()
{

	/*if(numIntentos >0)
		delete [] numCiclos;*/
	
	// Liberamos memoria
	if ( this->n_elem > 0 ) // Kiko 26-01-2006
		delete medias;


	for (int i=0; i<numGrupos; i++)
	{
	    if(conos[i].numPuntos >0)
			delete [] conos[i].puntos;
	}

	if (numTotalAgentes >0)
	{
		delete [] orientIniciales;
		delete [] posIniciales;
		delete [] numAcciones;
	}
	
	if(numObstaculos >0)
		delete [] PosObstaculos;

	if (numObjetivos>0)
		delete [] PosObjetivo;
	if(numGrupos >0)
		delete [] numAgentes;
}

//Metodos de establecimiento de valores para parametros
void CDatosIniciales::EstablecerNumeroPatrones(int numPatr) //Kiko
{
	numPatrones = numPatr;
}
void CDatosIniciales::Set_Tasa(float tasa) {tasa_real = tasa; };//Kiko
void CDatosIniciales::Set_Tam_Intervalo(int  t_int) {tam_intervalo = t_int; };//Kiko
void CDatosIniciales::Set_Horas(int hor) {horas = hor; };//Kiko
void CDatosIniciales::Set_Minutos(int minutos) {min =minutos; };//Kiko
void CDatosIniciales::Set_Segundos(int segundos) {seg = segundos; };//Kiko
void CDatosIniciales::Set_Tasas(float t1,float t2,float t3, float t4, float t5)//Kiko
{
	int1 = t1;
	int2 = t2;
	int3 = t3;
	int4 = t4;
	int5 = t5;
}

// Metodos para acceder a los valores de los parametros
float CDatosIniciales::Get_Tasa() { return tasa_real;};//Kiko
int CDatosIniciales::Get_Tam_Intervalo() {return tam_intervalo; };//Kiko
int CDatosIniciales::Get_Horas() { return horas;};//Kiko
int CDatosIniciales::Get_Minutos() { return min;};//Kiko
int CDatosIniciales::Get_Segundos() { return seg;};//Kiko
void CDatosIniciales::Get_Tasas(float &t1,float &t2,float &t3,float &t4,float &t5)//Kiko
{
	t1 = int1;
	t2 = int2;
	t3 = int3;
	t4 = int4;
	t5 = int5;
}
int CDatosIniciales::DevolverNumeroPatrones()//Kiko
{
	return numPatrones;
}

void CDatosIniciales::InsertarTipo(int tipoEscenario) // Olivia
{
	this->tipoEscenario = tipoEscenario;
}