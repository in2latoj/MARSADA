// LanderDoc.cpp : implementation of the CLanderDoc class

#include "stdafx.h"
#include "Lander.h"
#include "DibAgente.h"
#include "Punto.h"
#include "Orientacion.h"
#include "LanderDoc.h"
#include "Dlg_IrA.h"
#include "Dlg_BuscarPatron.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLanderDoc

IMPLEMENT_DYNCREATE(CLanderDoc, CDocument)

BEGIN_MESSAGE_MAP(CLanderDoc, CDocument)
	//{{AFX_MSG_MAP(CLanderDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_BUT_PATRON_ADEL, OnButPatronAdel)
	ON_COMMAND(ID_BUT_PATRON_ATRAS, OnButPatronAtras)
	ON_COMMAND(ID_BUT_IR_A, OnButIrA)
	ON_COMMAND(ID_BUT_BUSCAR, OnButBuscar)
	ON_COMMAND(ID_BUT_DATOS, OnButDatos)
	ON_COMMAND(ID_BUTTON_ESTADISTICAS, OnButtonEstadisticas)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CLanderDoc::CLanderDoc()
{
	ficheroCargado=false;
}

CLanderDoc::~CLanderDoc()
{
}

BOOL CLanderDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CLanderDoc serialization

void CLanderDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLanderDoc diagnostics

#ifdef _DEBUG
void CLanderDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLanderDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLanderDoc commands

void CLanderDoc::OnFileOpen() 
{
	static TCHAR BASED_CODE szFilter[] = _T("Ficheros de simulacion (*.sim)|*.sim|Ficheros de simulacion con modelo 3D(*.asl)|*.asl||");
	CFileDialog dlg(TRUE, _T("sim"),NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL );

	if (dlg.DoModal() == IDOK)
	{
		//Fichero=new CManejadorFichero(dlg.GetFileTitle( ));
		Fichero = new CManejadorFichero(dlg.GetFolderPath()+"\\"+dlg.GetFileTitle());
		CT2CA strPathCT(dlg.GetFolderPath());
		std::string strPath(strPathCT);
		CT2CA strTitleCT(dlg.GetFileTitle());
		std::string strTitle(strTitleCT);
		Inicializa(strPath + "\\" + strTitle);
		UpdateAllViews(NULL);
		ficheroCargado=true;
	}
}

void CLanderDoc::DibujaEscena()
{
	if(!ficheroCargado) 
	{
		Dibuja.DibujaTitulo();
	}
	else 
	{
		glCallList(1);
		//Dibujamos por EL MOMENTO las caras ocultas
		glDisable(GL_CULL_FACE);
		//Se dibujan todos los agentes
		for (int i=0;i<datosInic->numTotalAgentes;i++)
			if (!Agentes[i].Llego())
				Agentes[i].DibujaAgente();
		if (datosInic->tipoEscenario != 2) // Olivia
			Agentes[0].DibujaCono();
		glEnable(GL_CULL_FACE);
		if (VistaActual!=1)
		{
			//DATOS GENERALES
			if  (Fichero->intentos[Fichero->DarMuestra()].resultado)
				Dibuja.drawstr(5,10,"Intento: %i  Ciclo: %i exitoso (%i)",Fichero->DarIntento(),Fichero->DarCiclo(),Fichero->intentos[Fichero->DarMuestra()].num_ciclos-2);
			else
				Dibuja.drawstr(5,10,"Intento: %i  Ciclo: %i fracasado",Fichero->DarIntento(),Fichero->DarCiclo());
		}
		glFlush();
	}
}

// NUEVO
void CLanderDoc::Inicializa(std::string rutaFichero)
{
 	datosInic=Fichero->DarDatosIniciales();
	Agentes=new CDibAgente [datosInic->numTotalAgentes];
	Agentes->PonTipo(datosInic->tipoEscenario); // Olivia
	Dibuja.inicializar();

	// vito
	int grupo=0;
	int numAgentesG=datosInic->numAgentes[grupo];

	for (int i=0;i<datosInic->numTotalAgentes;i++)
	{
		if (!numAgentesG)
		{
			grupo++;
			numAgentesG=datosInic->numAgentes[grupo];
		}
		Agentes[i].Inicializar(datosInic->posIniciales[i],datosInic->orientIniciales[i],i,grupo);
		numAgentesG--;
	}
	//Listas de Visualizacion
	glNewList(1,GL_COMPILE);
	Dibuja.DSuelo();
	Dibuja.DCielo();
	//Dibuja.DEjes(60);
	if (datosInic->tipoEscenario == 0) // Olivia
		Dibuja.DPPista(datosInic->cabeceraPista,2.);
	else
	{
		
		//Dibuja.DFlecha(datosInic->,2.);
		Dibuja.DibujaVariosObj(datosInic->numObjetivos,datosInic->PosObjetivo);
		
	}

	// NEW: DIBUJA UNA MONTANA, Y SE COMENTA EL DIBUJAR LOS OBSTACULOS ORIGINALES


	Dibuja.DibObstaculo(datosInic->numObstaculos,datosInic->PosObstaculos, rutaFichero);
	glEndList();
	//Se dibujan todos los agentes
	for (int i=0;i<datosInic->numTotalAgentes;i++)
	{
		Agentes[i].TomaCono(datosInic->conos[0]);//Mucho ojo que hay que cambiarlo
		Agentes[i].DibujaAgente();
	}
}

void CLanderDoc::ActualizarDatos()
{
	DatosCiclo=Fichero->DarDatosCiclo();
	// Obtenemos que agente se ha movido
	int suma=0;
    //for(int i=0; i< DatosCiclo.numGrupo;i++)
		//suma+= datosInic->numAgentes[i];
	suma+= DatosCiclo.numAgenteMovido;
	
	// Actualizamos la posicion del agente que se ha movido
	Agentes[suma].Actualiza(DatosCiclo);
}

void CLanderDoc::OnButPatronAdel() 
{
	bool encontrado;
	// Este if lo pone Kiko 26-01-2006
	if (this->ficheroCargado)
	{
		encontrado=Fichero->BuscarPatronAdelante(DatosCiclo.numPatron);
		if (encontrado)
		{
			ActualizarDatos();
			UpdateAllViews(NULL);
		}
	}
}

void CLanderDoc::OnButPatronAtras() 
{
	bool encontrado;
	// Este if lo pone Kiko 26-01-2006
	if (this->ficheroCargado)
	{
		encontrado=Fichero->BuscarPatronAtras(DatosCiclo.numPatron);
		if (encontrado)
		{
			ActualizarDatos();
			UpdateAllViews(NULL);
		}
	}
}

void CLanderDoc::OnButIrA() 
{
	CDlg_IrA dlg;
	bool error;
	// Este if lo pone Kiko 26-01-2006
	if (this->ficheroCargado)
	{
		if (dlg.DoModal()==IDOK)
		{
			error=Fichero->IrAIntento(dlg.m_intento);
			error=(error||Fichero->IrACiclo(dlg.m_ciclo));
			if (!error)
			{
				ActualizarDatos();
				UpdateAllViews(NULL);
			}
		}
	}
	
}

void CLanderDoc::OnButBuscar() 
{
	// Este if lo pone Kiko 26-01-2006
	if (this->ficheroCargado)
	{
		CDlg_BuscarPatron dlg;
		bool encontrado;
		if (dlg.DoModal()==IDOK)
		{
			if (dlg.m_atras)
				encontrado=Fichero->BuscarPatronAtras(dlg.m_n_patron);
			else
				encontrado=Fichero->BuscarPatronAdelante(dlg.m_n_patron);
			if (encontrado)
			{
				ActualizarDatos();
				UpdateAllViews(NULL);
			}
		}
	}
}

void CLanderDoc::PintarGraficas(float translacion,float escala)
{
	CRect rect;
	HWND ventana=GetActiveWindow();
	GetClientRect(ventana,&rect);
	glViewport(0 , 0, rect.right, rect.bottom);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-40, datosInic->numIntentos+40, -40, datosInic->numMaxCiclos+100); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(255, 255, 255);
	//TITULO
	char *s, titulo[255];
	sprintf(titulo, "Grafica de Ciclos/Intento");
	glRasterPos2i((rect.right)/2-60,datosInic->numMaxCiclos+10);
    for (s = titulo; *s; s++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *s);
	glScalef(escala,1.f,1.f);
	glTranslatef(translacion,0,0);
	//Ejes de coordenadas
	glBegin(GL_LINES);
		glVertex2i(0,0);
		glVertex2i(datosInic->numIntentos+5,0);
		glVertex2i(0,0);
		glVertex2i(0,datosInic->numMaxCiclos+5);
    glEnd();
	//Ticks de los ejes
	glBegin(GL_LINES);
	//Eje Y	
	for (int i=0;i<=datosInic->numMaxCiclos;i=i+datosInic->numMaxCiclos/10)
	{
		glVertex2i(-3,i);
		glVertex2i(0,i);
	}
    glEnd();
	//Texto
	for (int i=0;i<=datosInic->numMaxCiclos;i=i+datosInic->numMaxCiclos/10)
		TextoEjes(-12,i-2,"%i",i);
	glBegin(GL_LINES);
	//Ticks Eje X
	for (int i=0;i<=datosInic->numIntentos;i=i+datosInic->numIntentos/10)
	{
		glVertex2i(i,-5);
		glVertex2i(i,0);
	}
    glEnd();
	//Texto Eje X
	for (int i=0;i<=datosInic->numIntentos;i=i+datosInic->numIntentos/10)
		TextoEjes(i-2,-12,"%i",i);
	//Mejor ciclo e intento
	int MejorCiclo=10000,MejorIntento=10000;
	//Grafica
	glBegin(GL_LINE_STRIP);
	for (int i=0;i<Fichero->numMuestras;i++)
	{
		glVertex2i(Fichero->intentos[i].num_intento,
				   Fichero->intentos[i].num_ciclos);
		if (Fichero->intentos[i].num_ciclos<MejorCiclo)
		{
			MejorCiclo=Fichero->intentos[i].num_ciclos;
			MejorIntento=Fichero->intentos[i].num_intento;
		}
	}
	glEnd();
	//Mejor ciclo
	glColor3ub(0, 255, 255);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(8, 0xAAAA);
	glBegin(GL_LINES);
	glVertex2i(MejorIntento,-5);
	glVertex2i(MejorIntento,MejorCiclo);
	glVertex2i(-3,MejorCiclo);
	glVertex2i(MejorIntento,MejorCiclo);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	TextoEjes(-12,MejorCiclo-2,"%i",MejorCiclo);
	TextoEjes(MejorIntento-2,-12,"%i",MejorIntento);
}

// KIKO 26-01-2006
void CLanderDoc::PintarGraficas1(float translacion,float escala)
{
	CRect rect;
	HWND ventana=GetActiveWindow();
	GetClientRect(ventana,&rect);
	glViewport(0 , 0, rect.right, rect.bottom);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-40, datosInic->n_elem+40, -40, datosInic->numMaxCiclos+100); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(255, 255, 255);
	//TITULO
	char *s, titulo[255];
	sprintf(titulo, "Grafica de Medias de Ciclos/Intento a Intervalos");
	glRasterPos2i(50,datosInic->numMaxCiclos+10);
    for (s = titulo; *s; s++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *s);
	glScalef(escala,1.f,1.f);
	glTranslatef(translacion,0,0);
	//Ejes de coordenadas
	glBegin(GL_LINES);
	glVertex2i(0,0);
	glVertex2i(datosInic->n_elem+5,0);
	glVertex2i(0,0);
	glVertex2i(0,datosInic->numMaxCiclos+5);
    glEnd();
	//Ticks de los ejes
	glBegin(GL_LINES);
	//Eje Y	
	for (int i=0;i<=datosInic->numMaxCiclos;i=i+datosInic->numMaxCiclos/10)
	{
		glVertex2i(-3,i);
		glVertex2i(0,i);
	}
    glEnd();
	//Texto
	for (int i=0;i<=datosInic->numMaxCiclos;i=i+datosInic->numMaxCiclos/10)
		TextoEjes(-12,i-2,"%i",i);
	glBegin(GL_LINES);
	//Ticks Eje X
	for (int i=0;i<=datosInic->n_elem;i=i+datosInic->n_elem/10)
	{
		glVertex2i(i,-5);
		glVertex2i(i,0);
	}
    glEnd();
	//Texto Eje X
	for (int i=0;i<=datosInic->n_elem;i=i+datosInic->n_elem/10)
	{
		TextoEjes(i,-12,"%i",i*(datosInic->Get_Tam_Intervalo()));
	}
	//Mejor ciclo e intento
	//Grafica
	glBegin(GL_LINE_STRIP);
	for (int i=0;i<datosInic->n_elem;i++)
		glVertex2i(i+1,datosInic->medias[i]);
	glEnd();
}

void CLanderDoc::AbrirIrA()
{
	this->OnButIrA();
}

void CLanderDoc::TextoEjes(GLuint x,GLuint y, char* format, ...)
{
    va_list args;
    char buffer[255], *s;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
	glRasterPos2i(x,y);
    for (s = buffer; *s; s++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *s);
}

void CLanderDoc::OnButDatos() 
{
	// Este if lo pone Kiko 26-01-2006
	if (this->ficheroCargado)
	{
		CWnd * ventana;
		ventana=ventana->GetActiveWindow();
		for (int i=0;i<datosInic->numTotalAgentes;i++)
			Agentes[i].MuestraDatos(ventana);
	}
}

void CLanderDoc::OnButtonEstadisticas() 
{
	// Este if lo pone Kiko 26-01-2006
	if (this->ficheroCargado)
	{
		static int creado=0;
		if (creado==0)
		{
			CWnd * ventana;
			ventana=ventana->GetActiveWindow();
			//Datos del dialogo
			//MEDIA
			CString Media;
			float total=0,MediaIntentos=0;
			for (int i=0;i<Fichero->numMuestras;i++)
				total+=Fichero->intentos[i].num_ciclos;
			MediaIntentos=total/Fichero->numMuestras;
			Media.Format(_T("%5.2f"),MediaIntentos);
			DlgEstadisticas.m_media=Media;
			//VARIANZA
			total=0;
			float MediaCuadrado=MediaIntentos*MediaIntentos;
			for (int i=0;i<Fichero->numMuestras;i++)
				total+=pow(Fichero->intentos[i].num_ciclos,2)-MediaCuadrado;
			float varianza =total/Fichero->numMuestras;
			//DESVIACION
			CString Desviacion;
			float desviacionTipica=sqrt(varianza);
			Desviacion.Format(_T("%5.2f"),desviacionTipica);
			DlgEstadisticas.m_desviacion=Desviacion;
			//PAtrones
			CString Patrones;
			int NumeroPatrones=datosInic->DevolverNumeroPatrones(); // Kiko
			Patrones.Format(_T("%i"),NumeroPatrones);
			DlgEstadisticas.m_patrones=Patrones;
			//PORCENTAGE
			CString porciento;
			total=0;
			for (int i=0;i<Fichero->numMuestras;i++)
				if (Fichero->intentos[i].resultado==1) total++;
			float porcentageExitosos =(total/Fichero->numMuestras)*100;
			porciento.Format(_T("%5.2f"),porcentageExitosos);
			DlgEstadisticas.m_porcentage=porciento;
			// Kiko 22-06-2006
			// Tasa Real
			CString porcientoReal;
			porcientoReal.Format(_T("%5.2f"),datosInic->Get_Tasa());
			DlgEstadisticas.m_porcentaje_real=porcientoReal;
			// Tiempo
			CString Tiempo;// Kiko
			int Aux=datosInic->Get_Horas(); 
			Tiempo.Format(_T("%i"),Aux);
			DlgEstadisticas.m_horas=Tiempo;
			Aux=datosInic->Get_Minutos(); 
			Tiempo.Format(_T("%i"),Aux);
			DlgEstadisticas.m_minutos=Tiempo;		
			Aux=datosInic->Get_Segundos(); 
			Tiempo.Format(_T("%i"),Aux);
			DlgEstadisticas.m_segundos=Tiempo;
			// Tasas por intervalos de ciclos
			// Kiko
			float t1,t2,t3,t4,t5;
			datosInic->Get_Tasas(t1,t2,t3,t4,t5);
			CString tasa;
			tasa.Format(_T("%5.3f"),t1*100);
			DlgEstadisticas.m_int1=tasa;
			tasa.Format(_T("%5.3f"),t3*100);
			DlgEstadisticas.m_int3=tasa;
			tasa.Format(_T("%5.3f"),t4*100);
			DlgEstadisticas.m_int4=tasa;
			tasa.Format(_T("%5.3f"),t5*100);
			DlgEstadisticas.m_int5=tasa;
			tasa.Format(_T("%5.3f"),(t2)*100);
			DlgEstadisticas.m_int2=tasa;
			// FINALMENTE Muestra la ventana
			DlgEstadisticas.Create(IDD_RESULTADOS);
			creado=1;
			DlgEstadisticas.ShowWindow(SW_SHOW);
			ventana->SetActiveWindow();
		}
		else
		{
			DlgEstadisticas.DestroyWindow();
			creado=0;
		}
	}
}

// KIKO 26-01-2006
// Metodo que nos dice si existe un fichero abierto
bool CLanderDoc::ExisteFicheroAbto()
{
	return ficheroCargado;
}

int CLanderDoc::DarNumAgentes()
{
	return (this->datosInic->numTotalAgentes);
}

CCoordenadaCartesiana CLanderDoc::DarPosAgente(int numAgente)
{
	return this->Agentes[numAgente].DarPosicion();
}

CCoordenadaCartesiana CLanderDoc::DarPosObjetivo(int numObjetivo)
{
	return datosInic->PosObjetivo[numObjetivo];
}

COrientacion CLanderDoc::DarOrientacionAgente(int numAgente)
{
	return this->Agentes[numAgente].DarOrientacion();
}