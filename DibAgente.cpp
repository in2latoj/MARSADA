// DibAgente.cpp: implementation of the CDibAgente class.

#include "stdafx.h"
#include "Lander.h"
#include "DibAgente.h"
#include "auxiliar.h"
#include "CargaOBJ.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/* Constante que contiene los colores para 10 grupos */
struct color ColorGrupo[10]={{255,140,0},{148,0,211},{47,79,79},{220,20,60},{50,205,50},{128,0,0},{210,105,30},{172,255,47},{255,255,0},{255,20,47}};
/* La misma constante está creada en DibGl.cpp, pero se llama ColorObjetivo para colorear los objetivos de un mismo grupo */

CDibAgente::CDibAgente()
{
	//DlgDatos.Create(IDD_DATOS);
	DatosMostrados = false;
}

CDibAgente::~CDibAgente()
{
	DlgDatos.EndDialog(0);
}

void CDibAgente::Inicializar(CCoordenadaCartesiana inicio, COrientacion orientacion,int numAgente, int numGrupo)
{
	NumAgente         = numAgente;
	NumGrupo		  = numGrupo;
	//Creamos una lista para pintar al agente
	glNewList((numAgente+2),GL_COMPILE);//Ojo se le suma dos porque la primera lista es la del entorno

#if TIPOAGENTE == 0 
	dibuja();
#elif TIPOAGENTE == 1
	dibujaDron();
#endif
	glEndList();

	Datos.Posicion    = inicio;
	Datos.Orientacion = orientacion;	
}

void CDibAgente::dibuja()
{
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glPushMatrix();
	glColor3ub(ColorGrupo[this->NumGrupo].red,ColorGrupo[this->NumGrupo].green,ColorGrupo[this->NumGrupo].blue);
	//glColor3ub(220, 125, 0);
	glTranslatef(0.,0.,-0.5);
	//glutSolidCone(0.2,1.0,10,10);
	/* Dibuja 4 triangulos para el cuerpo */
	/* Los triangulos se dibujan cogiendo los vértices de 3 en 3 */
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.,-0.2,0.);
	glVertex3f(0.,0.2,0.);
	glVertex3f(0.,0.,1.); /* Vertice Superior de la piramide */
	glVertex3f(0.2,0.,0.);
	glVertex3f(0.,-0.2,0.);
	glVertex3f(0.,0.2,0.);
	glEnd();
	
	/* Fin dibujar el cuerpo */
	/* Añadir el dibujo de unas pequeñas alas */
	/* Ala izquierda */
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0,0,0);
	glVertex3f(0,0,0.3);
	glVertex3f(0,0.5,0.);
	glVertex3f(0.05,0,0);
	glVertex3f(0,0,0);
	glEnd();
	/* Ala derecha */
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0,0,0);
	glVertex3f(0,0,0.3);
	glVertex3f(0,-0.5,0);
	glVertex3f(0.05,0,0);
	glVertex3f(0,0,0);
	glEnd();
	/* Fin dibujo de las alas */
	/* Dibujo de alerón trasero */
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0,0.05,0);
	glVertex3f(0,0,0.5);
	glVertex3f(0.4,0,0);
	glVertex3f(0,-0.05,0);
	glVertex3f(0,0.05,0);
	glEnd();
	/* Fin dibujo de alerón trasero */
	/* Línea Contorno */
	glColor4ub(0, 0, 0, 200);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.,0.,1.); /* Vertice Superior de la piramide */
	glVertex3f(0.,0.2,0.);
	glVertex3f(0.,-0.2,0.);
	glVertex3f(0.,0.,1.); /* Vertice Superior de la piramide */
	glVertex3f(0.2,0.,0.);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.,0.2,0.);
	glVertex3f(0.2,0.,0.);
	glVertex3f(0.,-0.2,0.);
	glEnd();
	/* Fin Línea Contorno */
	glColor4ub(0, 125, 100, 200);
	glPushMatrix();
	glTranslatef(0.1f,0.f,0.3f);
	glutSolidSphere(0.105,8,8);
	glPopMatrix();
	glPopMatrix();
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_BLEND);
}

void CDibAgente::dibujaDron()
{
	if (MODELODRON == 1) 
	{
		glEnable(GL_BLEND);
		glEnable(GL_LINE_SMOOTH);
		glPushMatrix();
		glTranslatef(0., 0., -0.5);
		// Carpeta de ejecución
		wchar_t buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);
		std::string strBuffer = CW2A(buffer);
		string::size_type pos = string(strBuffer).find_last_of("\\/");
		std::string ruta = strBuffer.substr(0, pos);
		std::string rutaModeloDron = ruta + "\\ModelosDron\\Dron01.obj";
		std::string rutaTexturaDron = ruta + "\\ModelosDron\\TexturaDron01.jpg";
		// Carga del modelo
		CargaOBJ modeloDron(rutaModeloDron, rutaTexturaDron);
		string result = modeloDron.PintarModelo();
		glPopMatrix();
		glDisable(GL_LINE_SMOOTH);
		glDisable(GL_BLEND);
	}
	else if (MODELODRON == 0)
	{
		glEnable(GL_BLEND);
		glEnable(GL_LINE_SMOOTH);
		glPushMatrix();
		glColor3ub(ColorGrupo[this->NumGrupo].red, ColorGrupo[this->NumGrupo].green, ColorGrupo[this->NumGrupo].blue);
		glTranslatef(0., 0., -0.5);


		//dibuja el poligono que sera el cuerpo del dron
		//parte de abajo
		glBegin(GL_POLYGON);
		glVertex3f(0, -0.4, 0.6);
		glVertex3f(0, 0.4, 0.6);
		glVertex3f(0, 0.4, -0.6);
		glVertex3f(0, -0.4, -0.6);
		glEnd();
		//parte arriba
		glBegin(GL_POLYGON);
		glVertex3f(0.1, -0.4, 0.6);
		glVertex3f(0.1, 0.4, 0.6);
		glVertex3f(0.1, 0.4, -0.6);
		glVertex3f(0.1, -0.4, -0.6);
		glEnd();
		//parte derecha
		glBegin(GL_POLYGON);
		glVertex3f(0, 0.4, 0.6);
		glVertex3f(0.1, 0.4, 0.6);
		glVertex3f(0.1, 0.4, -0.6);
		glVertex3f(0, 0.4, -0.6);
		glEnd();
		//parte izquierda
		glBegin(GL_POLYGON);
		glVertex3f(0, -0.4, 0.6);
		glVertex3f(0.1, -0.4, 0.6);
		glVertex3f(0.1, -0.4, -0.6);
		glVertex3f(0, -0.4, -0.6);
		glEnd();
		//parte delantera
		glBegin(GL_POLYGON);
		glVertex3f(0, -0.4, 0.6);
		glVertex3f(0.1, -0.4, 0.6);
		glVertex3f(0.1, 0.4, 0.6);
		glVertex3f(0, 0.4, 0.6);
		glEnd();
		//parte trasera
		glBegin(GL_POLYGON);
		glVertex3f(0, -0.4, -0.6);
		glVertex3f(0.1, -0.4, -0.6);
		glVertex3f(0.1, 0.4, -0.6);
		glVertex3f(0, 0.4, -0.6);
		glEnd();

		//linea de contorno
		glColor3b(255, 255, 255);
		glBegin(GL_LINE_STRIP);
		glVertex3f(0, -0.4, 0.6);
		glVertex3f(0, 0.4, 0.6);
		glVertex3f(0, 0.4, -0.6);
		glVertex3f(0, -0.4, -0.6);
		glVertex3f(0, -0.4, 0.6);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex3f(0.1, -0.4, 0.6);
		glVertex3f(0.1, 0.4, 0.6);
		glVertex3f(0.1, 0.4, -0.6);
		glVertex3f(0.1, -0.4, -0.6);
		glVertex3f(0.1, -0.4, 0.6);
		glEnd();


		// Cargar modelo a dibujar
		//	CargaOBJ cargaFichero("C:\\Users\\Victor\\Dropbox\\Montana03.obj");//("C:\\Users\\Victor\\Dropbox\\Personal\\Workspace\\VS2013\\Figuras\\Cube01.obj");
		// Dibujar modelo
		//	string result = cargaFichero.PintarModelo();

		//dibuja helice delantera izquierda en azul
		GLUquadricObj *cilindro1;
		cilindro1 = gluNewQuadric();
		gluQuadricDrawStyle(cilindro1, GLU_FILL);
		gluQuadricOrientation(cilindro1, GLU_OUTSIDE);
		glColor3ub(0, 0, 255);
		glTranslatef(0, -0.5, 0.7);
		glRotatef(90, 0, 1, 0);
		gluCylinder(cilindro1, 0.2, 0.2, 0.1, 8, 1);
		gluQuadricDrawStyle(cilindro1, GLU_LINE);
		glColor3ub(0, 0, 0);
		gluCylinder(cilindro1, 0.2, 0.2, 0.1, 8, 1);
		glEnd();

		//dibuja elice delantera derecha en azul
		glColor3ub(0, 0, 255);
		GLUquadricObj *cilindro2;
		cilindro2 = gluNewQuadric();
		gluQuadricDrawStyle(cilindro2, GLU_FILL);
		gluQuadricOrientation(cilindro2, GLU_OUTSIDE);
		glTranslatef(0, 1, 0); //depende de las traslaciones y rotaciones anteriores
		//glRotatef(90, 0, 1, 0);
		gluCylinder(cilindro2, 0.2, 0.2, 0.1, 8, 1);
		gluQuadricDrawStyle(cilindro2, GLU_LINE);
		glColor3ub(0, 0, 0);
		gluCylinder(cilindro2, 0.2, 0.2, 0.1, 8, 1);
		glEnd();

		//dibuja elice trasera derecha en rojo
		glColor3ub(255, 0, 0);
		GLUquadricObj *cilindro3;
		cilindro3 = gluNewQuadric();
		gluQuadricDrawStyle(cilindro3, GLU_FILL);
		gluQuadricOrientation(cilindro3, GLU_OUTSIDE);
		glTranslatef(1.4, 0, 0); //depende de las traslaciones y rotaciones anteriores
		//glRotatef(90, 0, 1, 0);
		gluCylinder(cilindro3, 0.2, 0.2, 0.1, 8, 1);
		gluQuadricDrawStyle(cilindro3, GLU_LINE);
		glColor3ub(0, 0, 0);
		gluCylinder(cilindro3, 0.2, 0.2, 0.1, 8, 1);
		glEnd();

		//dibuja elice trasera izquierda en rojo
		glColor3ub(255, 0, 0);
		GLUquadricObj *cilindro4;
		cilindro4 = gluNewQuadric();
		gluQuadricDrawStyle(cilindro4, GLU_FILL);
		gluQuadricOrientation(cilindro4, GLU_OUTSIDE);
		glTranslatef(0, -1, 0); //depende de las traslaciones y rotaciones anteriores
		//glRotatef(90, 0, 1, 0);
		gluCylinder(cilindro4, 0.2, 0.2, 0.1, 8, 1);
		gluQuadricDrawStyle(cilindro4, GLU_LINE);
		glColor3ub(0, 0, 0);
		gluCylinder(cilindro4, 0.2, 0.2, 0.1, 8, 1);
		glEnd();

		glColor4ub(0, 125, 100, 200);
		glPushMatrix();
		glTranslatef(0.1f, 0.f, 0.3f);
		glutSolidSphere(0.105, 8, 8);
		glPopMatrix();
		glPopMatrix();
		glDisable(GL_LINE_SMOOTH);
		glDisable(GL_BLEND);
		glPopMatrix();
		glDisable(GL_LINE_SMOOTH);
		glDisable(GL_BLEND);
	}
}

void CDibAgente::DibujaAgente()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(Datos.Posicion.x,Datos.Posicion.y,Datos.Posicion.z);
	glRotatef(Datos.Orientacion.anguloGiro*Datos.Orientacion.zonaXY, 0.0f, 0.0f, 1.0f);
	glRotatef(Datos.Orientacion.anguloGiro*Datos.Orientacion.zonaYZ, 0.0f, 1.0f, 0.0f);
	glCallList((NumAgente+2));
	glPopMatrix();  	
	glColor4f(0.1f,0.1f,0.1f,1.f);
	glRasterPos3f(Datos.Posicion.x+1,Datos.Posicion.y+1,Datos.Posicion.z+1);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, '0'+NumAgente);
	/* Pone en número la altura a la que se encuentra el agente -> vito */
	int j; // Variable j para sumar a la posición z del texto 
	if (Datos.Posicion.z < 1)
		j = -1;
	else
		j = 1;
	glRasterPos3f(Datos.Posicion.x-1,Datos.Posicion.y-1,Datos.Posicion.z-j);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, 'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ':');
	
	/* Convierte un número en coma flotante a un string de 4 carácteres */
	char * temp, p[4] = "\0";
	_snprintf(p, 3, "%f", Datos.Posicion.z);
	p[3] = 0;

	//itoa(Datos.Posicion.DarZ(),temp,10); /* Convierte el entero posicion.z en un string
	for (temp = p;*temp;temp++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *temp);
	/* fin Añadido vito */
	DibujaSombras();
	DibujaAltura(); // vito
}

/* Añadido vito */
void CDibAgente::DibujaAltura()
{
	glBegin(GL_LINES);
		glColor4f(0.5,0.5,0.0,0.7);
		/* Dibuja una linea vertical que va desde el suelo hasta el agente */
		glVertex3f(Datos.Posicion.x,Datos.Posicion.y,Datos.Posicion.z);
		glVertex3f(Datos.Posicion.x,Datos.Posicion.y,0);
	glEnd();
}
/* Añadido vito */

void CDibAgente::DibujaSombras()
{
	glEnable(GL_BLEND);
	glColor4ub(140, 140, 140, 100);
	/* Plano X-Y */
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(Datos.Posicion.x,Datos.Posicion.y,0);
	glVertex3f(Datos.Posicion.x+1,Datos.Posicion.y,0);
	glVertex3f(Datos.Posicion.x,Datos.Posicion.y+1,0);
	glVertex3f(Datos.Posicion.x+1,Datos.Posicion.y+1,0);
	glEnd();
	/* Plano Y-Z */
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0,Datos.Posicion.y,Datos.Posicion.z);
	glVertex3f(0,Datos.Posicion.y+1,Datos.Posicion.z);
	glVertex3f(0,Datos.Posicion.y,Datos.Posicion.z+1);
	glVertex3f(0,Datos.Posicion.y+1,Datos.Posicion.z+1);
	glEnd();
	/* Plano X-Z */
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(Datos.Posicion.x,0,Datos.Posicion.z);
	glVertex3f(Datos.Posicion.x+1,0,Datos.Posicion.z);
	glVertex3f(Datos.Posicion.x,0,Datos.Posicion.z+1);
	glVertex3f(Datos.Posicion.x+1,0,Datos.Posicion.z+1);
	glEnd();
	glDisable(GL_BLEND);
}

void CDibAgente::Actualiza(CDatosCiclo NuevosDatos)
{
	Datos = NuevosDatos;
	//if (this->DatosMostrados)
		//DlgDatos.BringWindowToTop();
	//DlgDatos.Actualiza(NuevosDatos);
	
}

void CDibAgente::TomaCono(TGeometria Puntos)
{
	Cono = Puntos;
}

void CDibAgente::PonTipo(int tipoEscenario) // Olivia
{
	this->tipoEscenario = tipoEscenario;
}

void CDibAgente::DibujaCono()
{
	if (this->tipoEscenario == 0) // Olivia
	{
		glColor4f(1.f,1.f,1.f,1.f);
		for (int i=0;i<Cono.numPuntos;i++)
		{
			glBegin(GL_LINES);
			glVertex3f(Cono.vertice.x,Cono.vertice.y,Cono.vertice.z);
			glVertex3f(Cono.puntos[i].x,Cono.puntos[i].y,Cono.puntos[i].z);
			glEnd();
		}
		glEnable(GL_BLEND);
		glBegin(GL_TRIANGLE_FAN);
		glColor4f(0.4f,0.4f,0.4f,0.4f);
		glVertex3f(Cono.vertice.x,Cono.vertice.y,Cono.vertice.z);
		glColor4f(1.f,1.f,1.f,0.4f);
		for (int i=0;i<Cono.numPuntos;i++)
			glVertex3f(Cono.puntos[i].x,Cono.puntos[i].y,Cono.puntos[i].z);
		glVertex3f(Cono.puntos[0].x,Cono.puntos[0].y,Cono.puntos[0].z);
		glEnd();
		glDisable(GL_BLEND);
	}
	else if (this->tipoEscenario == 1) // Kiko
	{
		glEnable(GL_BLEND);
			glBegin(GL_POLYGON);
				glColor4f(1.f, 1.f, 1.f, 0.4f);
				glVertex3f(0.0f,0.0f,0.0f);			
				glVertex3f(1000.0f,0.0f,0.0f);
				glVertex3f(0.0f,1000.0f,0.0f);		
				glVertex3f(1000.0f,1000.0f,0.0f);	
			glEnd();
		glDisable(GL_BLEND);
	}
}

void CDibAgente::MuestraDatos(CWnd * ventana)
{
	if (DatosMostrados == false)
		DlgDatos.ShowWindow(SW_SHOW);
	else
		DlgDatos.ShowWindow(SW_HIDE);
	DatosMostrados =! DatosMostrados;
	ventana->SetActiveWindow();
}

bool CDibAgente::Llego()
{
	CCoordenadaCartesiana p = Datos.Posicion;
	COrientacion Orient     = Datos.Orientacion;
	bool bienOrientado= ( (Orient.DarZonaXY() == 2)&&(Orient.DarZonaYZ() == 6) );
	float cx = 20.;
	float cy = 0.;
	float cz = 0.;
	// Definimos un rectángulo tridimensional en torno a la cabecera de pista
	if ( (p.DarX() <= (cx + 2. ) && p.DarX() >= (cx - 2.) )  &&
		 (p.DarY() <= (cy + 10. ) && p.DarY() >= (cy) )  &&
		 (p.DarZ() <= (cz + 1.5 ) && p.DarZ() >= (cz) )  && bienOrientado)
       return true;
	else
		return false;
}

CCoordenadaCartesiana CDibAgente::DarPosicion()
{
	return this->Datos.Posicion;
}

COrientacion CDibAgente::DarOrientacion()
{
	return this->Datos.Orientacion;
}