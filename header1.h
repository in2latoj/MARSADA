#ifndef HEADER1_H
#define HEADER1_H

#define NULL 0

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

#include <istream>
//#include <fstream.h>

#include <sys/types.h>

#include <math.h>
//#include <string.h>
#include <queue>
using namespace std ;

/*
//Informacion acerca del grado de asociacion y experiencia acumulada
//de un patron de percepcion y una accion
struct puntero
{
	int patron_accion;
	//float valoracion_pa;
	float grado_asociacion;
	float certeza;
};

*/
//Estructura para mantener la informacion acerca de las asociaciones
//de cada patron de percepcion (valoracion propagada y asociacion con las
//distintas acciones)
/*struct asociaciones
{
	float valoracion_pp;
	puntero *vector_de_punteros;
	int num_acciones_asociadas;
	float factor_certeza;
};
*/
/*asociaciones & operator=(asociaciones &dest, asociaciones &origen)
{
	dest.valoracion_pp = origen.valoracion_pp;
	dest.vector_de_punteros=origen.vector_de_punteros;
	dest.num_acciones_asociadas=origen.num_acciones_asociadas;
	return dest;
};

struct p_a_v
{
	int pat_percepcion;
	int pat_accion;
};
typedef deque<p_a_v>  PAVQUEUE;
*/
//Esto es headertab
#include <string>


#define HASHSIZE 101

//tipo de la tabla hash para establecer la equivalencia 
//entre numero de patron y cadena de patron
/*
struct nlist{
struct nlist *sig;
string nombre;
int num_patron;
};
*/

//La percepcion de cada sensor es una cadena de caracteres
typedef  string percepciones;
typedef  string patrones_perc;

enum direcciones{NORTE,NORESTE, ESTE, SURESTE, SUR, SUROESTE, OESTE, NOROESTE };
enum movimientos{PARAR,GIRAR_DCHA,GIRAR_IZDA, AVANZAR, SUBIR, BAJAR};

/*
 
//Valoracion con sus componentes positiva y negativa
struct pv_nv
{
	float pv;
	float nv;
};
*/
//Estructura empleada para indexar el fichero deresultados y recoger 
//informacion general acerca de cada intento el vector desplazamiento representa el
//desplazamiento de la informacion de cada ciclo del intento en el fichero de resultados
struct indice
{
	int num_intento;
	int num_ciclos;
	int resultado;
	long *desplazamientos;
public:
	//float valoracion;
};




// Para representar en qué zona está el agente dentro de la esfera del radar
typedef struct
{ 
	int capa;
	int sector;
	int zona;
	char contacto;        // A: agente, P: pared del cono
} Tterna;


#endif