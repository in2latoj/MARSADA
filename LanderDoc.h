// LanderDoc.h : interface of the CLanderDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LANDERDOC_H__0D31CB8A_0599_11D5_9FE5_B2B36BD66F63__INCLUDED_)
#define AFX_LANDERDOC_H__0D31CB8A_0599_11D5_9FE5_B2B36BD66F63__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "DibGL.h"
#include "DibAgente.h"
#include "ManejadorFichero.h"
#include "DatosCiclo.h"
#include "DatosIniciales.h"
#include "Dlg_Estadisticas.h"


class CLanderDoc : public CDocument
{
	void TextoEjes(GLuint x,GLuint y, char* format, ...);

protected: // create from serialization only
	CLanderDoc();
	DECLARE_DYNCREATE(CLanderDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLanderDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	// KIKO 26-01-2006
	// Metodo que nos dice si existe un fichero abierto
	bool ExisteFicheroAbto();

	void ActualizarDatos();
	void Inicializa(std::string rutaFichero);
	void DibujaEscena();
	void PintarGraficas(float translacion,float escala);
	void PintarGraficas1(float translacion,float escala); // KIKO 26-01-2006
	void AbrirIrA(); // Vito 9-mayo-2007
	int	 DarNumAgentes(); // Vito
	CCoordenadaCartesiana DarPosAgente(int numAgente);
	CCoordenadaCartesiana CLanderDoc::DarPosObjetivo(int numObjetivo);
	COrientacion DarOrientacionAgente(int numAgente);
	CDibGL Dibuja;	
	virtual ~CLanderDoc();
//Atributos	
	CManejadorFichero * Fichero;
	int VistaActual;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLanderDoc)
	afx_msg void OnFileOpen();
	afx_msg void OnButPatronAdel();
	afx_msg void OnButPatronAtras();
	afx_msg void OnButIrA();
	afx_msg void OnButBuscar();
	afx_msg void OnButDatos();
	afx_msg void OnButtonEstadisticas();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDibAgente * Agentes;
	
	CDlg_Estadisticas DlgEstadisticas;
	CDatosCiclo DatosCiclo;
	CDatosIniciales *datosInic;
	bool ficheroCargado;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LANDERDOC_H__0D31CB8A_0599_11D5_9FE5_B2B36BD66F63__INCLUDED_)
