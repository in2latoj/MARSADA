// DibGL.h: interface for the CDibGL class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBGL_H__24A281C0_698E_11D5_9FE7_C457043C126C__INCLUDED_)
#define AFX_DIBGL_H__24A281C0_698E_11D5_9FE7_C457043C126C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CoordenadaCartesiana.h"
#include "ManejadorBitmap.h"

class CDibGL  
{
public:
	// NEW: DIBUJAR MONTANA
	void DibMontana(int numPtos, CCoordanadaCartesiana * Ptos);
	void DibObstaculo(int numPtos,CCoordenadaCartesiana *Ptos, std::string rutaFichero);
	void inicializar(void);
	void DCielo();
	void DSuelo();
	void DEjes(int longitud);
	void DPPista(CCoordenadaCartesiana pos, float ancho);
	void DFlecha(CCoordenadaCartesiana pos, float ancho); // Kiko
	void DObjetivo(CCoordenadaCartesiana pos, float ancho, int grupo); // Vito
	void DibujaVariosObj(int NumObjetivos,CCoordenadaCartesiana* Objetivos);
	CDibGL();
	virtual ~CDibGL();
	void drawstr(GLuint x,GLuint y, char* format, ...);
	void DibujaTitulo();

private:
	CManejadorBitmap * 	Tierra;
	CManejadorBitmap * Cielo;
	CManejadorBitmap * Titulo;
    GLuint TexturaTierra;
    GLuint TexturaCielo;

};

#endif // !defined(AFX_DIBGL_H__24A281C0_698E_11D5_9FE7_C457043C126C__INCLUDED_)
