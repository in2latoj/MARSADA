// ManejadorFichero.cpp: implementation of the CManejadorFichero class.
#include "stdafx.h"
#include "Lander.h"


#include "ManejadorFichero.h"

#include "CoordenadaCartesiana.h"
#include "Orientacion.h"
#include <string.h>

#include "auxiliar.h"

// Tamaño constante para todos los ciclos de la simulación
#define TAM  (4*sizeof(int)+ 3*sizeof(float) )
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CManejadorFichero::CManejadorFichero(CString nombre)
{
	int numGrupos;
	int numTotalAgentes;
	float aux;
	float angulo;
	int zona;
	int tipo=0;
	int i,j;
	int numObjetivos;

	//Abrimos los ficheros: simulación e índice    
	CString nombreSim= nombre+".sim";
	ficheroSimulacion.open(nombreSim, ios::in | ios::binary);

	int asdf = ficheroSimulacion.is_open();

	CString nombreInd= nombre + ".ind";	
	ficheroIndice.open(nombreInd);
	// Leemos los datos iniciales
	ficheroSimulacion.read(reinterpret_cast<char *>(&numIntentos),sizeof(int));
	ficheroSimulacion.read(reinterpret_cast<char *>(&numGrupos),sizeof(int));
	ficheroSimulacion.read(reinterpret_cast<char *>(&numTotalAgentes),sizeof(int));
	ficheroSimulacion.read(reinterpret_cast<char *>(&numObjetivos),sizeof(int));
	
    datosIniciales = new CDatosIniciales(numIntentos,numGrupos,numTotalAgentes,numObjetivos);
	for(i=0; i< numGrupos; i++)
		ficheroSimulacion.read(reinterpret_cast<char *>(&(datosIniciales->numAgentes[i])),sizeof(int));
	ficheroSimulacion.read(reinterpret_cast<char *>(&(datosIniciales->numMaxCiclos)),sizeof(int));
	// Leemos el entorno
	ficheroSimulacion.read(reinterpret_cast<char *>(&tipo),sizeof(int));
	datosIniciales->InsertarTipo(tipo);
	if (tipo == 0)
	{
		// Leemos el vértice
		ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
		datosIniciales->conos[0].vertice.PonerX(aux);
		datosIniciales->cabeceraPista.PonerX(aux);
		//datosIniciales->cabeceraPista.PonerX(aux);
		ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
		datosIniciales->conos[0].vertice.PonerY(aux);
		datosIniciales->cabeceraPista.PonerY(aux);
		//datosIniciales->cabeceraPista->PonerY(aux);
		ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
		datosIniciales->conos[0].vertice.PonerZ(aux);
		datosIniciales->cabeceraPista.PonerZ(aux);
		//datosIniciales->cabeceraPista->PonerZ(aux);
		// Leemos el nº de puntos de la base del cono
		ficheroSimulacion.read(reinterpret_cast<char *>(&(datosIniciales->conos[0].numPuntos)),sizeof(int));
		datosIniciales->conos[0].puntos = 
			new CCoordenadaCartesiana [datosIniciales->conos[0].numPuntos];
		// Leemos los puntos
		for(j=0; j< datosIniciales->conos[0].numPuntos; j++)
		{
			ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
			datosIniciales->conos[0].puntos[j].PonerX(aux);
			ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
			datosIniciales->conos[0].puntos[j].PonerY(aux);
			ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
			datosIniciales->conos[0].puntos[j].PonerZ(aux);
		}
	}
	else
	{
		//en este caso puede haber varias cabeceras de pista y habra que pintar todas
		// En este caso cabeceraPista representa un objetivo intermedio a alcanzar
		ficheroSimulacion.read(reinterpret_cast<char *>(&datosIniciales->numObjetivos),sizeof(int));
		datosIniciales->PosObjetivo=new CCoordenadaCartesiana[datosIniciales->numObjetivos];
		for (i =0;i < datosIniciales-> numObjetivos;i++)
		{
			ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
			datosIniciales->PosObjetivo[i].PonerX(aux);
			//datosIniciales->cabeceraPista->PonerX(aux);
			ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
			datosIniciales->PosObjetivo[i].PonerY(aux);
			//datosIniciales->cabeceraPista->PonerY(aux);
			ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
			datosIniciales->PosObjetivo[i].PonerZ(aux);
			//datosIniciales->cabeceraPista->PonerZ(aux);
		}
	}

	//Leemos las posiciones de los obstaculos
	ficheroSimulacion.read(reinterpret_cast<char *>(&datosIniciales->numObstaculos),sizeof(int));
	datosIniciales->PosObstaculos=new CCoordenadaCartesiana[datosIniciales->numObstaculos];
	for(i=0; i< datosIniciales->numObstaculos; i++)
	{
		ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
		datosIniciales->PosObstaculos[i].PonerX(aux);
		ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
		datosIniciales->PosObstaculos[i].PonerY(aux);
		ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
		datosIniciales->PosObstaculos[i].PonerZ(aux);
	}

	for(i=0; i< numTotalAgentes; i++)
	{
		// Leemos las posiciones iniciales
		ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
		datosIniciales->posIniciales[i].PonerX(aux);
		ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
		datosIniciales->posIniciales[i].PonerY(aux);
		ficheroSimulacion.read(reinterpret_cast<char *>(&aux),sizeof(float));
		datosIniciales->posIniciales[i].PonerZ(aux);
		// Leemos las orientaciones iniciales
		ficheroSimulacion.read(reinterpret_cast<char *>(&angulo),sizeof(float));
		datosIniciales->orientIniciales[i].PonerAnguloGiro(angulo);
		ficheroSimulacion.read(reinterpret_cast<char *>(&zona),sizeof(int));
		datosIniciales->orientIniciales[i].PonerZonaXY(zona);
		ficheroSimulacion.read(reinterpret_cast<char *>(&zona),sizeof(int));
		datosIniciales->orientIniciales[i].PonerZonaYZ(zona);
	}
	// Leemos el fichero índice y lo metemos en una estructura en memoria
	ficheroIndice >> numMuestras;
	intentos= new indice[numMuestras];
	for(i=0; i< numMuestras; i++)
	{
		ficheroIndice >> intentos[i].num_intento;
		ficheroIndice >> intentos[i].num_ciclos;
		ficheroIndice >> intentos[i].resultado;
		intentos[i].desplazamientos= new long [intentos[i].num_ciclos];
		for(int j=0; j< intentos[i].num_ciclos;j++)
			ficheroIndice >> intentos[i].desplazamientos[j];
	}
	//Datos del intento y el ciclo
	cicloActual   = 0;
	intentoActual = 0;
	ficheroIndice.close();
	CString nombreSta= nombre + ".sta";	
	ficheroIndice.open(nombreSta);
	// Leemos los datos estadisticos (Kiko 26-01-2006)
    // El tamaño de los intervalos
	int t_int;
	ficheroIndice >> t_int;
	datosIniciales->Set_Tam_Intervalo(t_int);
	// Las tasas
	float tasa1,tasa2,tasa3,tasa4,tasa5;
	ficheroIndice >> tasa1;
	ficheroIndice >> tasa2;
	ficheroIndice >> tasa3;
	ficheroIndice >> tasa4;
	ficheroIndice >> tasa5;
	datosIniciales->Set_Tasas(tasa1,tasa2,tasa3,tasa4,tasa5);
	// Otros valores
	int h,m,s,pat;
	float t_real;
	ficheroIndice >> h;
	ficheroIndice >> m;
	ficheroIndice >> s;
	ficheroIndice >> t_real;
	ficheroIndice >> pat;
	datosIniciales->Set_Horas(h);
	datosIniciales->Set_Minutos(m);
	datosIniciales->Set_Segundos(s);
	datosIniciales->Set_Tasa(t_real);
	datosIniciales->EstablecerNumeroPatrones(pat);
	// Ahora leemos las medias
	ficheroIndice >> datosIniciales->n_elem;
	datosIniciales->medias = new int[datosIniciales->n_elem];
	for (i=0;i<datosIniciales->n_elem;i++)
		ficheroIndice >> datosIniciales->medias[i];
	// FIN de Leemos los datos estadisticos (Kiko 26-01-2006)

	// NEW

}

CManejadorFichero::~CManejadorFichero()
{
    // Cerramos los ficheros 
	ficheroSimulacion.close();
	ficheroIndice.close();



	delete datosIniciales;

	if (datosIniciales->numIntentos >0)
	{
       for(int i=0; i< datosIniciales->numIntentos ; i++)
		   if (intentos[i].num_ciclos >0)
			   delete [] intentos[i].desplazamientos;  
	}

}

bool CManejadorFichero::IrACiclo(int numeroCiclo)
{

	bool error=false;

	if( numeroCiclo >= intentos[intentoActual].num_ciclos )
		error=true;
	else
	{
	  cicloActual= numeroCiclo;
      long desplazamiento= intentos[intentoActual].desplazamientos[numeroCiclo];
	  ficheroSimulacion.seekg(desplazamiento, ::ios::beg);
	}


    return error;
}


// Va al ciclo 0 del intento especificado
bool  CManejadorFichero::IrAIntento(int numeroIntento)
{
	float desplazamiento;
	bool error=false,Encontrado=false;
	int i=0;
	
	if((numeroIntento <0) || (numeroIntento >= datosIniciales->numIntentos))
		error=true;

	else
	{
		//Hay que calcular el intentoActual que en realidad es la muestra actual
		while ((i<numMuestras) && (!Encontrado))
		{
			if (intentos[i].num_intento >= numeroIntento) Encontrado=true;
			i++;
		}
		//if (i<numMuestras)
		//{ //Se queda en el intento más proximo (<=)
			intentoActual= i-1;
			cicloActual=0;
			desplazamiento= intentos[intentoActual].desplazamientos[0];
			ficheroSimulacion.seekg(desplazamiento, ::ios::beg);
		//}
		//else error = true;
	}
	return error;
}


CDatosCiclo CManejadorFichero::DarDatosCiclo()
{
   int numAgente;
   int numAccs;

   ficheroSimulacion.read(reinterpret_cast<char *>(&numAgente),sizeof(int));
//   numAccs = datosIniciales->numAcciones[numAgente];
#if TIPOAGENTE == 1
   numAccs = 11;
#elif TIPOAGeNTE == 0
   numAccs = 6;
#endif
   CDatosCiclo resultado(numAccs);
   resultado.numAgenteMovido = numAgente;
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.Posicion.x)),sizeof(float));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.Posicion.y)),sizeof(float));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.Posicion.z)),sizeof(float));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.Orientacion.anguloGiro)),sizeof(float));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.Orientacion.zonaXY)),sizeof(int));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.Orientacion.zonaYZ)),sizeof(int));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.numGrupo)),sizeof(int));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.numPatron)),sizeof(int));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.numAccion)),sizeof(int));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.valoracionPos)),sizeof(float));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.valoracionNeg)),sizeof(float));
   ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.valoracionPropagada)),sizeof(float));
   resultado.valoracionPatron = resultado.valoracionPropagada * 2
								- resultado.valoracionPos
								+ resultado.valoracionNeg; // Olivia 29/07/2006
	for(int i=0; i< numAccs; i++)
		ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.seleccion.elementos[i])),sizeof(float));
	ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.num_acciones_asoc)),sizeof(int));
	for (int i=0;i< resultado.num_acciones_asoc;i++)
	{
		ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.grados_asociacion[i].num_accion)),sizeof(int));
		ficheroSimulacion.read(reinterpret_cast<char *>(&(resultado.grados_asociacion[i].grado_asoc)),sizeof(float));
	}
	return resultado;
}

// Avanza un ciclo hacia adelante
bool CManejadorFichero::SiguienteCiclo(bool PasarIntento)
{
	bool error = false;

	if ((cicloActual+2) == intentos[intentoActual].num_ciclos)
	{ 
		if (PasarIntento) // Pasamos al siguiente intento
		{
			if ((intentoActual+1) == numMuestras) // Estamos al final
				error = true;         
			else // El siguiente intento está dentro de la simulación
			{
				cicloActual=0;
				intentoActual ++;
				long desplazamiento= intentos[intentoActual].desplazamientos[0]; 
				ficheroSimulacion.seekg(desplazamiento, ::ios::beg);
			}
		}
		else
			error = true;
	}
	else // Avanzamos un ciclo dentro del mismo intento
	{
		cicloActual++;
		long desplazamiento=intentos[intentoActual].desplazamientos[cicloActual]; 
		ficheroSimulacion.seekg(desplazamiento, ::ios::beg);
	}
	return error;
}

bool CManejadorFichero::SiguienteIntento()
{
	bool error = false;

    if((intentoActual +1) == numMuestras)
		error = true;
	else
	{
		intentoActual ++;
		cicloActual = 0;
		long desplazamiento= intentos[intentoActual].desplazamientos[0]; 
		ficheroSimulacion.seekg(desplazamiento, ::ios::beg);	   
	}
	return error;
}

CDatosIniciales *CManejadorFichero::DarDatosIniciales()
{
	return datosIniciales;
}

//Busca un patrón hacia atrás posicionándose en el ciclo donde lo encontró
bool CManejadorFichero::BuscarPatronAtras(int numPatron)
{
	bool encontrado = false;
	bool comienzo;
	int basura,nPatron;
	float basuraf;

	// Hasta que no lleguemos al primer ciclo del primer intento ...	
    while (!(comienzo=AnteriorCiclo(true) ) && (!encontrado))
	{
		ficheroSimulacion.read(reinterpret_cast<char *>(&basura),sizeof(int));
		for (int i=0;i<3;i++)
			ficheroSimulacion.read(reinterpret_cast<char *>(&basuraf),sizeof(float));
		for (int i=0;i<4;i++)
			ficheroSimulacion.read(reinterpret_cast<char *>(&basura),sizeof(int));
		ficheroSimulacion.read(reinterpret_cast<char *>(&nPatron),sizeof(int));
		if (numPatron == nPatron)
			encontrado = true;	   
	}
	return encontrado;
}

//Devuelve cierto si intentamos retroceder un ciclo estando en el ciclo 0 intento 0
bool CManejadorFichero::AnteriorCiclo(bool PasarIntento)
{
	bool error = false;

	if (cicloActual == 0) // Pasamos al anterior intento
	{ 
		if (PasarIntento)
		{
			if ( intentoActual == 0)  // Estamos al principio
				error = true;         
			else 
			{
				intentoActual --;
				cicloActual = intentos[intentoActual].num_ciclos -1;		 
				long desplazamiento = intentos[intentoActual].desplazamientos[cicloActual]; 
				ficheroSimulacion.seekg(desplazamiento, ::ios::beg);
			}
		}
		else error = true;
	}
	else // Pasamos al ciclo anterior del mismo intento
	{ 
		cicloActual--;
		long desplazamiento = intentos[intentoActual].desplazamientos[cicloActual]; 
		ficheroSimulacion.seekg(desplazamiento, ::ios::beg);
	}
	return error;
}

bool CManejadorFichero::AnteriorIntento()
{   
	bool error = false;
	
	if (intentoActual ==0) // Ya estamos al comienzo 
		error = true;
	else
	{
		intentoActual --;
		cicloActual=0;
		long desplazamiento = intentos[intentoActual].desplazamientos[0]; 
		ficheroSimulacion.seekg(desplazamiento, ::ios::beg);	   
	}
	return error;
}

// Devuelve el nº de ciclo actual
int CManejadorFichero::DarCiclo()
{
   return cicloActual;
}

// Devuelve el nº de intento actual
int CManejadorFichero::DarIntento()
{
   return intentos[intentoActual].num_intento;
}

//Busca un patrón hacia adelante posicionándose en el ciclo donde lo encontró
bool CManejadorFichero::BuscarPatronAdelante(int numPatron)
{
   	bool encontrado = false;
	bool comienzo;
	int basura,nPatron;
	float basuraf;

	// Hasta que no lleguemos al ultimo ciclo del ultimo intento ...	
    while (!(comienzo=SiguienteCiclo(true)) && (!encontrado))
	{
		ficheroSimulacion.read(reinterpret_cast<char *>(&basura),sizeof(int));
		for (int i=0;i<3;i++)
			ficheroSimulacion.read(reinterpret_cast<char *>(&basuraf),sizeof(float));
		for (int i=0;i<4;i++)
			ficheroSimulacion.read(reinterpret_cast<char *>(&basura),sizeof(int));
	   ficheroSimulacion.read(reinterpret_cast<char *>(&nPatron),sizeof(int));
	   if (numPatron == nPatron)
		   encontrado = true;	   
	}
	return encontrado;
}

int CManejadorFichero::DarMuestra()
{
	return intentoActual;
}