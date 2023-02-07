// DatosIniciales.h: interface for the CDatosIniciales class.

#if !defined(AFX_DATOSINICIALES_H__BE8B4CA7_6A91_11D5_B120_90318C050B29__INCLUDED_)
#define AFX_DATOSINICIALES_H__BE8B4CA7_6A91_11D5_B120_90318C050B29__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CoordenadaCartesiana.h"

typedef struct
{
	int numPuntos;
	CCoordenadaCartesiana *puntos;
	CCoordenadaCartesiana vertice;
}TGeometria ;

class CDatosIniciales  
{
public:
	int NumeroTotalCabeceras;
	//CCoordenadaCartesiana *cabeceraPista;
	CCoordenadaCartesiana cabeceraPista;
	CDatosIniciales(int numIntentos,int numGrupos,int numTotalAgentes,int numObjetivos);
	virtual ~CDatosIniciales();
	int numIntentos;
	int numMaxCiclos;  // Nº ciclos máximo por cada intento
	int numGrupos;     // Cada grupo tiene su propia geometría
	int *numAgentes;   // nº de agentes por cada grupo
	TGeometria *conos;
    int numTotalAgentes;
	CCoordenadaCartesiana *posIniciales;
	COrientacion *orientIniciales;
    int *numAcciones;  // Nº acciones de cada agente
	int numObstaculos; //Obstaculos a evitar
	int numObjetivos;
	CCoordenadaCartesiana * PosObjetivo;
	CCoordenadaCartesiana * PosObstaculos;
	// Kiko 26-01-2006
	// Para la media de ciclos/intento. Kiko 26-01-2006
	int n_elem;
	int *medias;
	// Para la tasa de aciertos por intervalos
	float int1,int2,int3,int4,int5;
	// Otros datos estadisticos
	int numPatrones;//Kiko
	float tasa_real;//Kiko
	int horas,min,seg;//Kiko
	int tam_intervalo; // Kiko
	// Metodos de establecimiento de valores para parametros
	void EstablecerNumeroPatrones(int numPatr); //Kiko
	void Set_Tasa(float tasa);//Kiko
	void Set_Tam_Intervalo(int  t_int);//Kiko
	void Set_Horas(int hor);//Kiko
	void Set_Minutos(int minutos);//Kiko
	void Set_Segundos(int segundos);//Kiko
	void Set_Tasas(float t1,float t2,float t3, float t4, float t5);//Kiko
	// Metodos para acceder a los valores de los parametros
	int DevolverNumeroPatrones(); //Kiko
	int Get_Tam_Intervalo();//Kiko
	float Get_Tasa();//Kiko
	int Get_Horas();//Kiko
	int Get_Minutos();//Kiko
	int Get_Segundos();//Kiko
	void Get_Tasas(float &t1,float &t2,float &t3,float &t4,float &t5);//Kiko
	int tipoEscenario; // Olivia
	void InsertarTipo(int tipoEscenario); // Olivia
};

#endif // !defined(AFX_DATOSINICIALES_H__BE8B4CA7_6A91_11D5_B120_90318C050B29__INCLUDED_)
