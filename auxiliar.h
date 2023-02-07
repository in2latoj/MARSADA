#ifndef AUXILIAR_H
#define AUXILIAR_H

#include "Resource.h"

	/* Registro que representa un color RGB */
	struct color 
	{
		GLubyte red;
		GLubyte green;
		GLubyte blue;
		//color(GLubyte R, GLubyte G, GLubyte B) : red(R), green(G), blue(B) {}
	};

	/* Constante que contiene los colores para 10 grupos */
	//struct color ColorGrupo[10];
	//const static struct color ColorGrupo=color(255,140,0);
	//struct color ColorGrupo = color(255,140,0);
	//ColorGrupo[0]={255,140,0};
	//struct color ColorGrupo[10]={{255,140,0},{148,0,211},{47,79,79},{220,20,60},{50,205,50},{128,0,0},{210,105,30},{172,255,47},{255,255,0},{255,20,47}};
	//							  Dark Orange,Dark Violet,DarkSlateGray,Crimson,Lime Green,Maroon,Chocolate,GreenYellow,Yellow,DeepPink
	//struct color ColorObjetivo[10]={{255,140,0},{148,0,211},{47,79,79},{220,20,60},{50,205,50},{128,0,0},{210,105,30},{172,255,47},{255,255,0},{255,20,47}};

//Instrucciones para cambiar entre dron y avion
// avion = 0
// dron = 1
#define TIPOAGENTE 1
// NUEVO:
//  ModeloDron = 0 => Dron predeterminado
//	ModeloDron = 1 => Carga Dron01 de la carpeta Modelos
#define MODELODRON 1

#endif
