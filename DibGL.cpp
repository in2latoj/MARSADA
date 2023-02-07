// DibGL.cpp: implementation of the CDibGL class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Lander.h"
#include "DibGL.h"
#include "texture.h"
#include "auxiliar.h"
#include "CargaOBJ.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

#define M_PI 3.1416

/* Constante que contiene los colores para 10 grupos */
struct color ColorObjetivo[10] = { { 255, 140, 0 }, { 148, 0, 211 }, { 47, 79, 79 }, { 220, 20, 60 }, { 50, 205, 50 }, { 128, 0, 0 }, { 210, 105, 30 }, { 172, 255, 47 }, { 255, 255, 0 }, { 255, 20, 47 } };

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDibGL::CDibGL()
{

	Titulo = new CManejadorBitmap("Lander.BMP");
	//Textura de la tierra
	Tierra = new CManejadorBitmap("Grass.BMP");
	//Textura del cielo
	Cielo = new CManejadorBitmap("Sky.BMP");


}

CDibGL::~CDibGL()
{
	delete Tierra;
	delete Cielo;
	delete Titulo;
}

void CDibGL::DPPista(CCoordenadaCartesiana pos, float ancho)
{
	float longitud = 10.;

	glBegin(GL_POLYGON);
	glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
	glVertex3f(pos.x - ancho, pos.y, 0.1f);
	glVertex3f(pos.x + ancho, pos.y, 0.1f);
	glVertex3f(pos.x + ancho, pos.y + longitud, 0.1f);
	glVertex3f(pos.x - ancho, pos.y + longitud, 0.1f);
	glEnd();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(8, 0xAAAA);

	glBegin(GL_LINES);
	glColor4f(1.f, 1.f, 1.0f, 1.0f);
	glVertex3f(pos.x, pos.y, 0.11f);
	glVertex3f(pos.x, pos.y + longitud, 0.11f);
	glEnd();

	glDisable(GL_LINE_STIPPLE);
}

void CDibGL::DFlecha(CCoordenadaCartesiana pos, float ancho)
{
	float longitud = 10.;

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
	glVertex3f(pos.x, pos.y, pos.z);
	glVertex3f(pos.x + ancho, pos.y + longitud / 2, pos.z);
	glVertex3f(pos.x - ancho, pos.y + longitud / 2, pos.z);
	// Para darle más profundidad al objetivo
	//glVertex3f(pos.x,pos.y+longitud/2,pos.z+1.0f);
	//glVertex3f(pos.x,pos.y+longitud/2,pos.z-1.0f);
	glEnd();
}

void CDibGL::DObjetivo(CCoordenadaCartesiana pos, float ancho, int grupo)
{
	glEnable(GL_BLEND);
	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, .5f);
	glVertex3f(pos.x, pos.y, pos.z + ancho / 2.);
	glVertex3f(pos.x, pos.y, pos.z - ancho / 2.);
	glVertex3f(pos.x, pos.y + ancho / 2., pos.z);
	glVertex3f(pos.x, pos.y - ancho / 2., pos.z);
	glVertex3f(pos.x + ancho / 2., pos.y, pos.z);
	glVertex3f(pos.x - ancho / 2., pos.y, pos.z);
	glEnd();

	// dibujo de esfera en el centro
	glMatrixMode(GL_MODELVIEW);
	glColor4ub(ColorObjetivo[grupo].red, ColorObjetivo[grupo].green, ColorObjetivo[grupo].blue, 150);
	//glColor4f(0.9f,0.3f,0.05f,1.0f);//rojo
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glutSolidSphere(0.30, 8, 8);
	glPopMatrix();
	glDisable(GL_BLEND);
}

void CDibGL::DEjes(int longitud)
{
	glEnable(GL_BLEND);
	for (int i = 0; i <= longitud; i++)
	{
		glBegin(GL_LINES);
		//PLANO X-Y
		//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glColor4f(0.7f, 0.7f, 0.7f, 0.3f); //vito
		glVertex3i(0, i, 0);
		//glVertex3i(-1.0f, i,0);
		glVertex3i(longitud, i, 0);
		glVertex3i(i, 0, 0);
		//glVertex3i(i, -1.0f,0);
		glVertex3i(i, longitud, 0);
		//PLANO Y-Z
		//glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		//glColor4f(1.0f, 1.0f, 1.0f, 0.7f); //vito
		//glColor4f(0.7f, 0.7f, 0.7f, 0.3f); //vito
		glVertex3i(0, i, 0);
		glVertex3i(0, i, longitud);
		glVertex3i(0, 0, i);
		glVertex3i(0, longitud, i);
		//PLANO X-Z
		//glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		//glColor4f(0.7f, 0.7f, 0.7f, 0.3f); //vito
		glVertex3i(0, 0, i);
		glVertex3i(longitud, 0, i);
		glVertex3i(i, 0, 0);
		glVertex3i(i, 0, longitud);
		glEnd();
	}

	glDisable(GL_BLEND);
}


void CDibGL::DSuelo()
{
	/*static GLfloat v[4][3]=
		{-1000., -1000., -0.1f,
		1000., -1000., -0.1f,
		1000., 1000., -0.1f,
		-1000., 1000., -0.1f};*/
	static GLfloat v[4][3] =
	{ -1000., -200., -0.1f,
	1000., -200., -0.1f,
	1000., 1000., -0.1f,
	-1000., 1000., -0.1f };

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TexturaTierra);
	glBegin(GL_QUADS);
	glNormal3i(0, 0, 1);
	//glColor4f(0.6f, 0.8f, 0.6f, 1.0f);
	glColor4f(0.6f, 0.8f, 0.6f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3fv(v[0]);
	glTexCoord2f(50.0f, 0.0f);
	glVertex3fv(v[1]);
	glColor4f(0.2f, 0.5f, 0.2f, 1.f);
	glTexCoord2f(50.0f, 50.0f);
	glVertex3fv(v[2]);
	glColor4f(0.8f, 1.0f, 0.8f, 1.0f);
	glTexCoord2f(0.0f, 50.0f);
	glVertex3fv(v[3]);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawSphere(float x, float y, float z, float radius, int color)
{
	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	switch (color)
	{
	case 0:
		glColor3f(1, 0, 0);//rojo
		break;
	case 1:
		glColor3f(0, 1, 0);//verde
		break;
	case 2:
		glColor3f(0, 0, 1);//azul
		break;
	case 3:
		glColor3f(0, 1, 1);
		break;
	default:
		glColor3f(1, 1, 0);
		break;
	}
	glTranslatef(x, y, z);
	//La funcion gluSPhere dibuja una esfera en el origen, por eso desplazamos
	//el origen hasta x,y, luego dibujamos la esfera y deshacemos la translacion
	gluSphere(qobj, radius, 10, 10);
	glTranslatef(-x, -y, -z);
}


void CDibGL::DibujaVariosObj(int NumObjetivos, CCoordenadaCartesiana* Objetivos)
{
	for (int i = 0; i < NumObjetivos; i++)
		DObjetivo(Objetivos[i], 1, i);
}

//  NEW: NUEVO METODO DE DIBUJAR UN OBSTACULO
void CDibGL::DibMontana(int numPtos, CCoordanadaCartesiana *Ptos)
{
	// Función modificada. Kiko 7/4/06
	//glMatrixMode(GL_MODELVIEW);
	//glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//rojo
	//for (int i = 0; i<numPtos; i++)
	//{
	//	glPushMatrix();
	//	glTranslatef(Ptos[i].DarX(), Ptos[i].DarY(), Ptos[i].DarZ());
	//	glutSolidSphere(0.25, 10, 10);
	//	// Cargar modelo a dibujar
	//	CargaOBJ cargaFichero("C:\\Users\\Victor\\Dropbox\\Personal\\Workspace\\VS2013\\Figuras\\Cube01.obj");
	//	// Dibujar modelo
	//	string result = cargaFichero.PintarModelo();

	//	glPopMatrix();
	//}

}

// NUEVO
void CDibGL::DibObstaculo(int numPtos, CCoordenadaCartesiana * Ptos, std::string rutaFichero)
{
	// Función modificada. Kiko 7/4/06

	std::string rutaFichero2 = rutaFichero + ".asl";
	FILE* archivo = fopen(rutaFichero2.c_str(), "r");
	if (archivo != NULL) {
		glMatrixMode(GL_MODELVIEW);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);//verde
		char linea[BYTES_LINEA_FICHERO];
		int p = 0;
		glPushMatrix();
		while (fgets(linea, BYTES_LINEA_FICHERO, archivo) != NULL)
		{
			string lineaMod = linea;
			// Posición Montaña
			if (p == 0) {
				float verticeX = strtof(lineaMod.substr(0, lineaMod.find_first_of(' ')).c_str(), 0);
				lineaMod = lineaMod.substr(lineaMod.find_first_of(' ') + 1);
				float verticeY = strtof(lineaMod.substr(0, lineaMod.find_first_of(' ')).c_str(), 0);
				lineaMod = lineaMod.substr(lineaMod.find_first_of(' ') + 1, lineaMod.find_first_of('\n'));
				float verticeZ = strtof(lineaMod.substr(0, lineaMod.find_first_of(' ')).c_str(), 0);
				glTranslatef(verticeX, verticeY, verticeZ);
				p++;
			}
			else if (p == 1) {
				char lineaTextura[BYTES_LINEA_FICHERO];
				fgets(lineaTextura, BYTES_LINEA_FICHERO, archivo);
				if (lineaMod.substr(lineaMod.size() - 1, lineaMod.size()) == "\n") {
					CargaOBJ cargaFichero(lineaMod.substr(0, lineaMod.size() - 1), lineaTextura);//"C:\\Users\\Victor\\Dropbox\\Montana05v2.obj"
					string result = cargaFichero.PintarModelo();
				}
				else {
					CargaOBJ cargaFichero(lineaMod.c_str(), lineaTextura);//"C:\\Users\\Victor\\Dropbox\\Montana05v2.obj"
					string result = cargaFichero.PintarModelo();
				}
				p++;
			}
		}
		glPopMatrix();
	}

	// NUEVO: OCULTAR O PONER A INVISIBLE LAS BOLAS O ESFERAS DE LOS OBSTÁCULOS
	/*
	glMatrixMode(GL_MODELVIEW);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//rojo
	for (int i=0;i<numPtos;i++)
	{
	glPushMatrix();
	glTranslatef(Ptos[i].DarX(),Ptos[i].DarY(),Ptos[i].DarZ());
	glutSolidSphere(0.25,10,10);
	glPopMatrix();
	}
	*/

}
void CDibGL::DCielo()
{
	/*//10 TRIANGULOS
static GLint v[8][3]=
{100, -10, 0,
100, 100, 0,
-10, -10, 0,
-10, 100, 0,
100, -10, 100,
100, 100, 100,
-10, -10, 100,
-10, 100, 100,};



glBegin(GL_TRIANGLE_STRIP);
glNormal3i(-1,0,0);
glColor4f(0.3f, 0.4f, 0.8f, 1.0f);
glVertex3iv(v[1]);
glVertex3iv(v[0]);
glColor4f(0.5f, 0.6f, 0.8f, 1.0f);
glVertex3iv(v[5]);
glVertex3iv(v[4]);
glColor4f(0.4f, 0.3f, 0.7f, 1.0f);
glNormal3i(0,0,-1);
glVertex3iv(v[7]);
glVertex3iv(v[6]);
glColor4f(0.3f, 0.4f, 0.8f, 1.0f);
glNormal3i(1,0,0);
glVertex3iv(v[3]);
glVertex3iv(v[2]);
glEnd();
glBegin(GL_TRIANGLE_STRIP);
glColor4f(0.3f, 0.4f, 0.8f, 1.0f);
glNormal3i(0,1,0);
glVertex3iv(v[0]);
glVertex3iv(v[2]);
glColor4f(0.5f, 0.6f, 0.8f, 1.0f);
glVertex3iv(v[4]);
glColor4f(0.4f, 0.3f, 0.7f, 1.0f);
glVertex3iv(v[6]);
glEnd();*/

	/* Draw the sky */
	float VistaTerreno = 500., ct = 0., st = 0.;
	glFrontFace(GL_CW);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TexturaCielo);
	glColor3f(0.3, 0.5, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0.0, 0.0, VistaTerreno);
	for (float theta = 0.0; theta < (2.1 * M_PI); theta += (float)M_PI / 8)
	{
		ct = cos(theta);
		st = sin(theta);
		glTexCoord2f(0.5 + 0.3 * ct, 0.5 + 0.3 * st);
		glVertex3f(ct * VistaTerreno * 0.7071,
			st * VistaTerreno * 0.7071,
			VistaTerreno * 0.7071);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (float theta = 0.0; theta < (2.1 * M_PI); theta += (float)M_PI / 8)
	{
		ct = cos(theta);
		st = sin(theta);
		glTexCoord2f(0.5 + 0.3 * ct, 0.5 + 0.3 * st);
		glVertex3f(ct * VistaTerreno * 0.7071,
			st * VistaTerreno * 0.7071,
			VistaTerreno * 0.7071);
		glTexCoord2f(0.5 + 5.5 * ct, 0.5 + 5.5 * st);
		glVertex3f(ct * VistaTerreno,
			st * VistaTerreno, -100.0);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glFrontFace(GL_CCW);

}



void CDibGL::inicializar()
{
	//CREAMOS LAS TEXTURAS
	//Textura de Tierra
	if (Tierra->BitmapBits != NULL) //Si se ha cargado bien el fichero BMP
	{
		glGenTextures(1, &TexturaTierra);
		glBindTexture(GL_TEXTURE_2D, TexturaTierra);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, Tierra->BitmapInfo->bmiHeader.biWidth,
			Tierra->BitmapInfo->bmiHeader.biHeight, GL_RGB,
			GL_UNSIGNED_BYTE, Tierra->BitmapBits);

	}
	//Textura de Cielo
	if (Cielo->BitmapBits != NULL) //Si se ha cargado bien el fichero BMP
	{
		glGenTextures(1, &TexturaCielo);
		glBindTexture(GL_TEXTURE_2D, TexturaCielo);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, Cielo->BitmapInfo->bmiHeader.biWidth,
			Cielo->BitmapInfo->bmiHeader.biHeight, GL_RGB,
			GL_UNSIGNED_BYTE, Cielo->BitmapBits);

	}
	//FIN DE CARGA DE TEXTURAS




}




void
CDibGL::drawstr(GLuint x, GLuint y, char* format, ...)
{
	va_list args;
	char buffer[255], *s;

	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);

	CRect rect;
	HWND ventana = GetActiveWindow();
	GetClientRect(ventana, &rect);
	glDisable(GL_DEPTH_TEST);

	//	glViewport(0 , 0, rect.right, rect.bottom);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//    gluOrtho2D(0, rect.right, 0, rect.bottom);
	gluOrtho2D(0, 500, 0, 600);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3ub(0, 0, 0);

	glRasterPos2i(x, y);

	for (s = buffer; *s; s++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *s);
	glEnable(GL_DEPTH_TEST);

}

void CDibGL::DibujaTitulo()
{
	GLint		xoffset,		/* X offset of image */
		yoffset;		/* Y offset of image */
	GLint		xsize,			/* X size of scaled image */
		ysize;			/* Y size of scaled image */
	GLfloat	xscale,			/* Scaling in X direction */
		yscale;			/* Scaling in Y direction */

	CRect rect;
	HWND ventana = GetActiveWindow();
	GetClientRect(ventana, &rect);

	int derecha = rect.right;
	int abajo = rect.bottom - 40;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, derecha - 1.0, 0.0, abajo - 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT);
	if (Titulo->BitmapBits != NULL)
	{
		xsize = derecha;
		ysize = Titulo->BitmapInfo->bmiHeader.biHeight * xsize /
			Titulo->BitmapInfo->bmiHeader.biWidth;
		if (ysize > abajo)
		{
			ysize = abajo;
			xsize = Titulo->BitmapInfo->bmiHeader.biWidth * ysize /
				Titulo->BitmapInfo->bmiHeader.biHeight;
		};
		xscale = (float)xsize / (float)Titulo->BitmapInfo->bmiHeader.biWidth;
		yscale = (float)ysize / (float)Titulo->BitmapInfo->bmiHeader.biHeight;

		xoffset = (derecha - xsize) * 0.5;
		yoffset = (abajo - ysize) * 0.5;

		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
		glPixelZoom(xscale, yscale);
		glRasterPos2i(xoffset, yoffset);
		glDrawPixels(Titulo->BitmapInfo->bmiHeader.biWidth,
			Titulo->BitmapInfo->bmiHeader.biHeight,
			GL_RGB, GL_UNSIGNED_BYTE, Titulo->BitmapBits);

	};

}
