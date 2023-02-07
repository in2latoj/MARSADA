// LanderView.cpp : implementation of the CLanderView class
//

#include "stdafx.h"
#include "Lander.h"

#include "LanderDoc.h"
#include "LanderView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLanderView

IMPLEMENT_DYNCREATE(CLanderView, CView)

BEGIN_MESSAGE_MAP(CLanderView, CView)
	//{{AFX_MSG_MAP(CLanderView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BUTCICLO_ADEL, OnButcicloAdel)
	ON_COMMAND(ID_BUTCICLO_ATRAS, OnButcicloAtras)
	ON_COMMAND(ID_BUTINTEN_ADEL, OnButintenAdel)
	ON_COMMAND(ID_BUTINTEN_ATRAS, OnButintenAtras)
	ON_COMMAND(ID_BUT_GRAFICAS, OnButGraficas)
	ON_COMMAND(ID_BUT_GRAFICAS2, OnButGraficas1)
	ON_COMMAND(ID_BUT_PP,OnButPlayPause)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLanderView construction/destruction

CLanderView::CLanderView()
{
	TranslacionGrafica=0.;
	EscalaGrafica=1.;
	TranslacionGrafica1=0.;
	EscalaGrafica1=1.;

	VistaGraficas=false;
	VistaGraficas1=false;

	m_hGLContext = NULL;
	m_GLPixelIndex = 0;
	m_vista=3;
	m_LButton=FALSE;
	m_RButton=FALSE;
	m_mov_x=120.;
	m_mov_y=250.;
	m_mov_z=50.;
	m_mov2_x=30.;
	m_mov2_y=30.;
	m_mov2_z=60.;
	m_mov8_x=0.;
	m_mov8_y=0.;
	m_mov8_z=0.;
	m_rot_y=0.;
	m_rot_x=0.;
	m_rot_z=0.;
	MovimientoZ=0;
	aspect_ratioV=(GLdouble)1;
	aspect_ratioH=(GLdouble)1;
	pause=true;

	m_mov8_circ = CCoordenadaEsferica(230.,1.31,1.31);

	centro_rot=0;
	pos_centro.x = 0.;
	pos_centro.y = 0.;
	pos_centro.z = 0.;

	pos_objetivo.x = 0.;
	pos_objetivo.y = 0.;
	pos_objetivo.z = 0.;
}

CLanderView::~CLanderView()
{
}

BOOL CLanderView::PreCreateWindow(CREATESTRUCT& cs)
{

	cs.style |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS);

	return CView::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CLanderView diagnostics

#ifdef _DEBUG
void CLanderView::AssertValid() const
{
	CView::AssertValid();
}

void CLanderView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLanderDoc* CLanderView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLanderDoc)));
	return (CLanderDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLanderView message handlers

BOOL CLanderView::CreateViewGLContext(HDC hDC)
{
	m_hGLContext = wglCreateContext(hDC);
	if (m_hGLContext == NULL)
	{
		DWORD errorCode = GetLastError();
		CString errorStr;
		errorStr.Format(_T("wglCreateContext returned error code %d."), errorCode);
		AfxMessageBox(errorStr);
		return FALSE;
	}

	if (wglMakeCurrent(hDC, m_hGLContext)==FALSE)
	{
		DWORD errorCode = GetLastError();
		CString errorStr;
		errorStr.Format(_T("wglCreateContext returned error code %d."), errorCode);
		AfxMessageBox(errorStr);
		return FALSE;
	}

	return TRUE;

}

BOOL CLanderView::SetWindowPixelFormat(HDC hDC)
{
PIXELFORMATDESCRIPTOR pixelDesc;

	pixelDesc.nSize		= sizeof(PIXELFORMATDESCRIPTOR);
	pixelDesc.nVersion	= 1;

	pixelDesc.dwFlags	=	PFD_DRAW_TO_WINDOW | 
							PFD_SUPPORT_OPENGL | 
							PFD_DOUBLEBUFFER | 
							PFD_STEREO_DONTCARE;							PFD_STEREO_DONTCARE;

	pixelDesc.iPixelType		= PFD_TYPE_RGBA;
	pixelDesc.cColorBits		= 32;
	pixelDesc.cRedBits			= 8;
	pixelDesc.cRedShift			= 8;
	pixelDesc.cGreenBits		= 8;
	pixelDesc.cGreenShift		= 8;
	pixelDesc.cBlueBits			= 8;
	pixelDesc.cBlueShift		= 8;
	pixelDesc.cAlphaBits		= 0;
	pixelDesc.cAlphaShift		= 0;
	pixelDesc.cAccumBits		= 64;	
	pixelDesc.cAccumRedBits		= 16;
	pixelDesc.cAccumGreenBits	= 16;
	pixelDesc.cAccumBlueBits	= 16;
	pixelDesc.cAccumAlphaBits	= 0;
	pixelDesc.cDepthBits		= 32;
	pixelDesc.cStencilBits		= 8;
	pixelDesc.cAuxBuffers		= 0;
	pixelDesc.iLayerType		= PFD_MAIN_PLANE;
	pixelDesc.bReserved			= 0;
	pixelDesc.dwLayerMask		= 0;
	pixelDesc.dwVisibleMask		= 0;
	pixelDesc.dwDamageMask		= 0;

	m_GLPixelIndex = ChoosePixelFormat(hDC, 
										&pixelDesc);
	if (m_GLPixelIndex==0)
	{
		m_GLPixelIndex = 1;	// Let's choose a default index.
		if (DescribePixelFormat( hDC, 
								 m_GLPixelIndex, 
								 sizeof(PIXELFORMATDESCRIPTOR), 
								 &pixelDesc)==0)
		{
			DWORD errorCode = GetLastError();
			CString errorStr;
			errorStr.Format(_T("DescribePixelFormat returned error code %d."), errorCode);
			AfxMessageBox(errorStr);
			return FALSE;
		}
	}

	if (SetPixelFormat(	hDC, 
						m_GLPixelIndex, 
						&pixelDesc)==FALSE)
	{
		DWORD errorCode = GetLastError();
		CString errorStr;
		errorStr.Format(_T("SetPixelFormat returned error code %d."), errorCode);
		AfxMessageBox(errorStr);
		return FALSE;
	}

	return TRUE;

}

int CLanderView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	HWND hWnd = GetSafeHwnd();
	HDC hDC = ::GetDC(hWnd);

	if (SetWindowPixelFormat(hDC)==FALSE)
		return 0;

	if (CreateViewGLContext(hDC)==FALSE)
		return 0;
	
	return 0;

}

void CLanderView::OnDestroy() 
{
	if(wglGetCurrentContext()!=NULL) 
	{
		// make the rendering context not current
		wglMakeCurrent(NULL, NULL) ;
	}
	
	if (m_hGLContext!=NULL)
	{
		wglDeleteContext(m_hGLContext);
		m_hGLContext = NULL;
	}

	// Now the associated DC can be released.
	CView::OnDestroy();
	
}

void CLanderView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CLanderDoc* pDoc = GetDocument();
	float camara=60./2.;
	
	CCoordenadaCartesiana aux;

	pDoc->VistaActual=m_vista;
	if (!pDoc->ExisteFicheroAbto())
	{	//Dibuja el titulo inicial
		glDisable(GL_DEPTH_TEST);
		pDoc->DibujaEscena();
		glEnable(GL_DEPTH_TEST);
	}
	else
	{
		if (VistaGraficas)
		{
		pDoc->PintarGraficas(TranslacionGrafica,EscalaGrafica);	
	
		}
		else if (VistaGraficas1)
		{
		pDoc->PintarGraficas1(TranslacionGrafica1,EscalaGrafica1);
		}
	
		else
		{
		
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glEnable(GL_LIGHTING);

		switch(m_vista)
		{
		case 1:	
			Vista1();
			break;
		case 2:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(5.0, aspect, 1.0, 2000.0);
			gluLookAt(120.0,250.0,50.0,	0.,0.,0., 0.0,0.0,1.0);	
			glViewport(0, 0, ancho, alto);
			pDoc->DibujaEscena();
			break;
		case 3:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(5.0, aspect, 1.0, 2000.0);
			glViewport(0, 0, ancho, alto);
			gluLookAt(m_mov_x,m_mov_y,m_mov_z,	
				m_rot_x,m_rot_y,m_rot_z, 0.0,0.0,1.0);
			pDoc->DibujaEscena();
			break;
		case 4://y-z
			glViewport(0, 0, ancho, alto);
			gluLookAt(camara,camara,camara,0.,camara,camara,0.0,0.0,1.0);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-camara, camara, -camara, camara,-camara,1000.0);
			pDoc->DibujaEscena();
			break;
		case 5://x-z
			glViewport(0, 0, ancho, alto);
			gluLookAt(camara,camara,camara, camara,0.,camara, 0.,0.,1.);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-camara, camara, -camara, camara,-camara,1000.0);
			pDoc->DibujaEscena();
			break;
		case 6://x-y
			glViewport(0, 0, ancho, alto);
			gluLookAt(camara,camara,camara, camara,camara,0., 0.0,-1.0,0.0);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-camara*aspect_ratioH, camara*aspect_ratioH, -camara*aspect_ratioV, camara*aspect_ratioV,-camara,1000.0);
			pDoc->DibujaEscena();
			break;
		case 7://x-y en perspectiva
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45.0, aspect, 1.0, 2000.0);
			gluLookAt(m_mov2_x,m_mov2_y,m_mov2_z,
				m_mov2_x,m_mov2_y,0., 0.0,-1.0,0.0);
			pDoc->DibujaEscena();
			/* Texto */

			glDisable(GL_DEPTH_TEST);
			glViewport(0 , 0, ancho, alto);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(0, ancho, 0, alto); 
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			char temp[6];
			_snprintf(temp, 6, "%f", m_mov2_z);
			temp[5]=0;

			glColor3ub(5, 5, 5);

			glRasterPos2i(3*ancho/4, 5);
			text("Altura: ");
			text(temp);
			glEnable(GL_DEPTH_TEST);

			break;
		case 8:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(5.0, aspect, 1.0, 2000.0);
			glViewport(0, 0, ancho, alto);

			aux.EsfericaACartesiana(m_mov8_circ);
			gluLookAt(aux.x + pos_centro.x,aux.y + pos_centro.y,aux.z + pos_centro.z, pos_centro.x, pos_centro.y, pos_centro.z, 0.0,0.0,1.0);

			//gluLookAt(m_mov8_x,m_mov8_y,m_mov8_z, pos_centro.x, pos_centro.y, pos_centro.z, 0.0,0.0,1.0);
			pDoc->DibujaEscena();
			break;
		case 9:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(5.0, aspect, 1.0, 2000.0);
			glViewport(0, 0, ancho, alto);

			aux.EsfericaACartesiana(m_mov8_circ);

			if (pos_centro.x > pos_objetivo.x)
				varStaticX += 1;
			else if (pos_centro.x < pos_objetivo.x)
				varStaticX -= 1;

			varStaticY = 0;
			gluLookAt(varStaticX + pos_centro.x, varStaticY + pos_centro.y + 80.0, pos_centro.z + 6.0,
				//pos_objetivo.x, pos_objetivo.y, pos_objetivo.z,
				pos_centro.x, pos_centro.y, pos_centro.z,
					//pos_centro.x, pos_centro.y, pos_centro.z,
				0.0, 0.0, 1.0);
			//glViewport(0, 0, ancho, alto);
			
			//if (pos_centro.x - pos_objetivo.x > 1)
			//	varStatic = -100;
			//else if (pos_centro.x - pos_objetivo.x < 1)
			//	varStatic = +100;
			//glRotatef(pos_centro.x - 100, 0.0f, 0.0f, 1.0f);
			//glRotatef(orientacion_centro.anguloGiro*orientacion_centro.zonaYZ, 0.0f, 0.0f, 1.0f);

			//glTranslatef(-pos_centro.x, -pos_centro.y, -pos_centro.z);

			pDoc->DibujaEscena();
			break;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(5.0, aspect, 1.0, 2000.0);
			//aux.EsfericaACartesiana(m_mov8_circ);
			//gluLookAt(pos_centro.x, pos_centro.y + 60.0, pos_centro.z + 3.0, pos_objetivo.x, pos_objetivo.y, pos_objetivo.z, 0.0, 0.0, 1.0);
			//gluLookAt(pos_centro.x, pos_centro.y + 40.0, pos_centro.z + 6.0, 
			/*
			gluLookAt(pos_centro.x, pos_centro.y + 120.0, pos_centro.z + 6.0,
				//orientacion_centro.DarAnguloGiro(), orientacion_centro.DarZonaXY(), orientacion_centro.DarZonaYZ(),
				pos_centro.x, pos_centro.y, pos_centro.z,
				//orientacion_centro.zonaXY, orientacion_centro.zonaYZ, pos_centro.z,
				//m_rot_x, m_rot_y, m_rot_z,
				0.0, 0.0, 1.0);
*/
			glRotatef(orientacion_centro.anguloGiro*orientacion_centro.zonaXY, 1.0f, 0.0f, 0.0f);
			glRotatef(orientacion_centro.anguloGiro*orientacion_centro.zonaYZ, 0.0f, 1.0f, 0.0f);
			glTranslatef(-pos_centro.x, -pos_centro.y, -pos_centro.z);

			/*gluLookAt(pos_centro.x, pos_centro.y + 120.0, pos_centro.z + 6.0,
				//orientacion_centro.DarAnguloGiro(), orientacion_centro.DarZonaXY(), orientacion_centro.DarZonaYZ(),
				pos_centro.x + valorXY, pos_centro.y - valorXY*orientacion_centro.anguloGiro, pos_centro.z,
				//orientacion_centro.zonaXY, orientacion_centro.zonaYZ, pos_centro.z,
				//m_rot_x, m_rot_y, m_rot_z,
				0.0, 0.0, 1.0);
*/
			//glViewport(0, 0, ancho, alto);
			pDoc->DibujaEscena();
			break;
		default:
			break;
		}
		}
	}
	glFlush();
	SwapBuffers(dc.m_ps.hdc);
	CView::OnPaint();

}

void CLanderView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	


	ancho = cx;
	alto = cy;

	if (cy==0)
		aspect = (GLdouble)ancho;
	else
		aspect = (GLdouble)ancho/(GLdouble)alto;

	glViewport(0, 0, ancho, alto);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 10.0, 2000.0);
    
	
	glDrawBuffer(GL_BACK);
	
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	//LUZ y MATERIALES

	GLfloat ambientLight[] = { 1.0, 1.0, 1.0, 1.0 };
	
	GLfloat light_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0 };
	GLfloat light_diffuse[] = { 0.7f, 0.7f, 0.7f, 0. };
	GLfloat light_position[] = { 20.0, 20.0, 20.0, 1.0 };
	//GLfloat light_position[] = { 40.0, 40.0, 80.0, .0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	GLfloat mat_amb[]={0.5f,0.5f,0.5f,1.0};
	GLfloat mat_dif[]={0.7,0.7,0.7,1.0};
	GLfloat mat_spec[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shin[]={10.0};

	glMaterialfv(GL_FRONT,GL_AMBIENT, mat_amb);
	glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_dif);
	glMaterialfv(GL_FRONT,GL_SPECULAR, mat_spec);
	glMaterialfv(GL_FRONT,GL_SHININESS, mat_shin);

	glShadeModel(GL_SMOOTH);	// Sombras suaves

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientLight);
	glEnable(GL_COLOR_MATERIAL);	// Enable Material color tracking
	// Front material ambient and diffuse colors track glColor
	glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

	

}


// KIKO 26-01-2006
void CLanderView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CLanderDoc* pDoc = NULL;
	BOOL Repinta=FALSE;
	switch (nChar)
		{
			case '1' :
				m_vista=1;
				Repinta=TRUE;
				break;
			case '2' :
				m_vista=2;
				Repinta=TRUE;
				break;
			case '3' :
				m_vista=3;
				Repinta=TRUE;
				break;
			case '4' :
				m_vista=4;
				Repinta=TRUE;
				break;
			case '5' :
				m_vista=5;
				Repinta=TRUE;
				break;
			case '6' :
				m_vista=6;
				Repinta=TRUE;
				break;
			case '7' :
				m_vista=7;
				Repinta=TRUE;
				break;
			case '8' :
				m_vista=8;
				pDoc = GetDocument();
				this->CambiarCentro(pDoc);
				Repinta=TRUE;
				break;
			case '9':
				m_vista = 9;
				pDoc = GetDocument();
				this->CambiarCentro(pDoc);
				this->CambiarCentroObjetivo(pDoc);
				this->CambiarOrientacion(pDoc);
				Repinta = TRUE;
				break;
			case 'z':
			case 'Z':
				MovimientoZ=!MovimientoZ;
				break;
			case VK_ADD:
				if (VistaGraficas)
					EscalaGrafica+=1.;
				if (VistaGraficas1)
					EscalaGrafica1+=1.;
				Repinta=TRUE;
				break;
			case VK_SUBTRACT:
				if (VistaGraficas)
				{
					EscalaGrafica-=1.;
					if (EscalaGrafica<1.) EscalaGrafica=1.;
				}
				if (VistaGraficas1)
				{
					EscalaGrafica1-=1.;
					if (EscalaGrafica1<1.) EscalaGrafica1=1.;
				}
				Repinta=TRUE;
				break;
			/* Añadido vito */
			case 'R':
			case 'r':
				if (m_vista == 3)
				{
					m_mov_x=120.;
					m_mov_y=250.;
					m_mov_z=50.;
					m_rot_y=0.;
					m_rot_x=0.;
					m_rot_z=0.;
				}
				else if (m_vista == 7)
				{
					m_mov2_x=30.;
					m_mov2_y=30.;
					m_mov2_z=60.;
				}
				else if (m_vista == 8)
				{
					m_mov8_x=120.;
					m_mov8_y=250.;
					m_mov8_z=50.;
				}
				else
				{
					aspect_ratioV = (GLdouble)1;
					aspect_ratioH = (GLdouble)1;
				}
				Repinta=TRUE;
				break;
			case 'I':
			case 'i':
				pDoc = GetDocument();
				pDoc->AbrirIrA();
				break;
			case 'V':
			case 'v':
				aspect_ratioV = (GLdouble)alto/(GLdouble)ancho;
				aspect_ratioH = (GLdouble)1;
				Repinta=TRUE;
				break;
			case 'H':
			case 'h':
				aspect_ratioH = (GLdouble)ancho/(GLdouble)alto;
				aspect_ratioV = (GLdouble)1;
				Repinta=TRUE;
				break;
			case 'P':
			case 'p':
				this->OnButPlayPause();				
				break;
			case 'C':
			case 'c':
				pDoc = GetDocument();

				this->centro_rot=(centro_rot+1)%(pDoc->DarNumAgentes());

				this->CambiarCentro(pDoc);
				if (this->m_vista == 8)
					Repinta=TRUE;
				break;
			/* Fin añadido */
			default: break;
		}
	if (Repinta) InvalidateRect(NULL,FALSE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CLanderView::OnMouseMove(UINT nFlags, CPoint point) 
{
	
	if (m_LButton)
	{
		
		CSize movRaton = m_LButtonPos - point;
		m_LButtonPos = point;
		if (VistaGraficas)
		{
			TranslacionGrafica-=movRaton.cx*EscalaGrafica;
			if (TranslacionGrafica>0) TranslacionGrafica=0;
			
		}
		else if (VistaGraficas1)
		{
			TranslacionGrafica1-=movRaton.cx*EscalaGrafica1;
			if (TranslacionGrafica1>0) TranslacionGrafica1=0;
		}
		else
			if (MovimientoZ)
			{
				/* Modificado vito 3-mayo-2007 */
				switch (m_vista)
				{
				case 3:
					m_mov_y += movRaton.cx/3;
					if (m_mov_y<10) m_mov_y=10;
					//if (m_mov_y>200) m_mov_y=200;
					break;
				case 7:
					m_mov2_y += movRaton.cx/3;
					if (m_mov2_y<10) m_mov2_y=10;
					break;
				case 8:
					m_mov8_y += movRaton.cx/3;
					break;
				default: break;
				}
				/* fin modificado */
			}
			else
			{
				/* Modificado vito 3-mayo-2007 */
				switch (m_vista)
				{
				case 3:
					m_mov_x += movRaton.cx/3;
					m_mov_z += movRaton.cy/3;
					if (m_mov_x<-10) m_mov_x=-10;
					if (m_mov_x>200) m_mov_x=200;
					if (m_mov_z<10) m_mov_z=10;
					if (m_mov_z>200) m_mov_z=200;
					break;
				case 7:
					m_mov2_x += movRaton.cx/3;
					m_mov2_y += movRaton.cy/3;
					if (m_mov2_x<-10) m_mov2_x=-10;
					if (m_mov2_x>200) m_mov2_x=200;
					if (m_mov2_y<10) m_mov2_y=10;
					if (m_mov2_y>200) m_mov2_y=200;
					break;
				case 8:
					m_mov8_circ.MoverXY(movRaton.cx/3);
					m_mov8_circ.MoverYZ(movRaton.cy/3);
					/*m_mov8_circ.teta = m_mov8_circ.teta + movRaton.cx/3;
					m_mov8_circ.si = m_mov8_circ.si + movRaton.cx/3;
					/*m_mov8_x += movRaton.cx/3;
					m_mov8_z += movRaton.cy/3;*/
				default: break;
				}
				/* fin modificado */
			}
		InvalidateRect(NULL, FALSE);
		
	}
	if (m_RButton)
	{
		CSize movimiento = m_RButtonPos - point;
		m_RButtonPos = point;
		if (MovimientoZ)
		{
			m_rot_y += movimiento.cx/3;
		}
		else
		{
			m_rot_x += movimiento.cx/3;
			m_rot_z += movimiento.cy/3;
		}
		
		InvalidateRect(NULL, FALSE);
		
	}
	CView::OnMouseMove(nFlags, point);
}

/* Añadido vito */
BOOL CLanderView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	int despl = 0;
	/* Si se desplaza la rueda en direccion opuesta a uno mismo se acerca */
	if (zDelta < 1)
		despl = 5;
	/* Si se desplaza la rueda hacia uno mismo se aleja */
	if (zDelta > 1)
		despl = -5;

	switch (m_vista)
	{
	case 3:
		m_mov_y += despl;
		break;
	case 7:
		m_mov2_z += despl;
		break;
	case 8:
		m_mov8_circ.MoverRadio((float)despl);
		//m_mov8_circ.r += despl;
	default: break;
	}
	InvalidateRect(NULL, FALSE);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
/* fin añadido */

void CLanderView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_LButton=TRUE;	
	m_LButtonPos=point;
	CView::OnLButtonDown(nFlags, point);
}

void CLanderView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_LButton=FALSE;	
	CView::OnLButtonUp(nFlags, point);
}

void CLanderView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	m_RButtonPos=point;
	m_RButton=TRUE;
	CView::OnRButtonDown(nFlags, point);
}

void CLanderView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	m_RButton=FALSE;	
	CView::OnRButtonUp(nFlags, point);
}


void
CLanderView::text(char* string)
{
    char* p;

    for (p = string; *p; p++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
}

void
CLanderView::projection(int width, int height, int perspective)
{
   float ratio = (float)width/height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (perspective)
      gluPerspective(60, ratio, 1, 256);
    else 
      glOrtho(-ratio, ratio, -ratio, ratio, 1, 256);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(20.0, 20.0, 20.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}


void CLanderView::Vista1()
{
	CPaintDC dc(this); 

	int width =  ancho;
    int height = alto;
	float ratio = (float)width/height;
	CLanderDoc* pDoc = GetDocument();
	float camara=60./2.;


    glViewport(0 , 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glDisable(GL_LIGHTING);

	////PROYECCION
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(5.0, aspect, 1.0, 2000.0);
	glViewport(ancho/2, 0, ancho/2, alto/2);
	gluLookAt(m_mov_x,m_mov_y,m_mov_z,	
			m_rot_x,m_rot_y,m_rot_z, 0.0,0.0,1.0);
	pDoc->DibujaEscena();

	///PLANO PERFIL
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glViewport(0, 0, ancho/2, alto/2);
	gluLookAt(camara,camara,camara,0.,camara,camara,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-camara, camara, -camara, camara,-camara,1000.0);
	
	pDoc->DibujaEscena();
    
	///PLANO ALZADO
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glViewport(0, alto/2, ancho/2, alto/2);
	gluLookAt(camara,camara,camara, camara,0.,camara, 0.,0.,1.);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-camara, camara, -camara, camara,-camara,1000.0);

	pDoc->DibujaEscena();

	///PLANO PLANTA
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glViewport(ancho/2, alto/2, ancho/2, alto/2);
	gluLookAt(camara,camara,camara, camara,camara,0., 0.0,-1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-camara, camara, -camara, camara,-camara,1000.0);

	pDoc->DibujaEscena();
    
	//TEXTO
	glDisable(GL_DEPTH_TEST);
	glViewport(0 , 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
	glColor3ub(127, 0, 0);
	//glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(width/2,0);
    glVertex2i(width/2,height);
    glVertex2i(0,height/2);
    glVertex2i(width,height/2);
    glEnd();

	glColor3ub(5, 5, 5);

	glRasterPos2i(5, 5);
    text("Perfil"); 
    glRasterPos2i(width/2+5, 5);
    text("Perspectiva");
    glRasterPos2i(5, height/2+5);
    text("Alzado");
    glRasterPos2i(width/2+5, height/2+5);
    text("Planta");
	glEnable(GL_DEPTH_TEST);

    
}

void CLanderView::OnButcicloAdel() 
{

	CLanderDoc* pDoc = GetDocument();

	// Este if lo pone Kiko 26-01-2006
	if (pDoc->ExisteFicheroAbto())
	{
		if (!pDoc->Fichero->SiguienteCiclo(false))
		{
			pDoc->ActualizarDatos();
			this->CambiarCentro(pDoc);
			this->CambiarCentroObjetivo(pDoc);
			this->CambiarOrientacion(pDoc);
			InvalidateRect(NULL, FALSE);
		}
	}
	
}

void CLanderView::OnButcicloAtras() 
{
	CLanderDoc* pDoc = GetDocument();
	// Este if lo pone Kiko 26-01-2006
	if (pDoc->ExisteFicheroAbto())
	{
		if (!pDoc-> Fichero->AnteriorCiclo(false))
		{
			pDoc->ActualizarDatos();
			this->CambiarCentro(pDoc);
			this->CambiarCentroObjetivo(pDoc);
			this->CambiarOrientacion(pDoc);
			InvalidateRect(NULL, FALSE);
		}
	}
}

void CLanderView::OnButintenAdel() 
{
	CLanderDoc* pDoc = GetDocument();
	// Este if lo pone Kiko 26-01-2006
	if (pDoc->ExisteFicheroAbto())
	{
		if (!pDoc->Fichero->SiguienteIntento())
		{
			pDoc->ActualizarDatos();
			this->CambiarCentro(pDoc);
			this->CambiarCentroObjetivo(pDoc);
			this->CambiarOrientacion(pDoc);
			InvalidateRect(NULL, FALSE);
		}
	}
	
}

void CLanderView::OnButintenAtras() 
{
	CLanderDoc* pDoc = GetDocument();
	// Este if lo pone Kiko 26-01-2006
	if (pDoc->ExisteFicheroAbto())
	{
		if (!pDoc-> Fichero->AnteriorIntento())
		{
			pDoc->ActualizarDatos();
			this->CambiarCentro(pDoc);
			this->CambiarCentroObjetivo(pDoc);
			this->CambiarOrientacion(pDoc);
			InvalidateRect(NULL, FALSE);
		}
	}
	
}

void CLanderView::OnButGraficas() 
{
	VistaGraficas=!VistaGraficas;
	InvalidateRect(NULL, FALSE);

}

// KIKO 26-01-2006
void CLanderView::OnButGraficas1() 
{
	VistaGraficas1=!VistaGraficas1;
	InvalidateRect(NULL, FALSE);

}


void CLanderView::OnDraw(CDC* pDC) 
{
	
}

/***********************/
/* manejo temporizador */

void CLanderView::OnTimer(UINT_PTR nIDEvent)
{
	CLanderDoc* pDoc = GetDocument();

	// Este if lo pone Kiko 26-01-2006
	if (pDoc->ExisteFicheroAbto())
	{
		if (!pDoc->Fichero->SiguienteCiclo(false))
		{
			pDoc->ActualizarDatos();
			//if (this->m_vista==8)
			this->CambiarCentro(pDoc);
			this->CambiarCentroObjetivo(pDoc);
			this->CambiarOrientacion(pDoc);
			InvalidateRect(NULL, FALSE);
		}
		else
		{
			this->KillTimer(IDC_TIMER);
			pause = !pause;
		}
	}
	CView::OnTimer(nIDEvent);
}

void CLanderView::OnButPlayPause()
{
	if (pause)
		this->SetTimer(IDC_TIMER,25,NULL);
	else
		this->KillTimer(IDC_TIMER);
	pause = !pause;
}

/******************************************/
/* Funcion Privada						  */
void CLanderView::CambiarCentro(CLanderDoc* pDoc)
{
	this->pos_centro = pDoc->DarPosAgente(centro_rot);
}

void CLanderView::CambiarCentroObjetivo(CLanderDoc* pDoc)
{
	this->pos_objetivo = pDoc->DarPosObjetivo(centro_rot);
}

void CLanderView::CambiarOrientacion(CLanderDoc* pDoc)
{
	orientacion_centro = pDoc->DarOrientacionAgente(centro_rot);
}