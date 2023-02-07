// LanderView.h : interface of the CLanderView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LANDERVIEW_H__0D31CB8C_0599_11D5_9FE5_B2B36BD66F63__INCLUDED_)
#define AFX_LANDERVIEW_H__0D31CB8C_0599_11D5_9FE5_B2B36BD66F63__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CLanderView : public CView
{
protected: // create from serialization only
	CLanderView();
	DECLARE_DYNCREATE(CLanderView)

// Attributes
public:
	CLanderDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLanderView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLanderView();
	//virtual void OnTimer(UINT_PTR nIDEvent);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLanderView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnButcicloAdel();
	afx_msg void OnButcicloAtras();
	afx_msg void OnButintenAdel();
	afx_msg void OnButintenAtras();
	afx_msg void OnButGraficas();
	afx_msg void OnButGraficas1();// KIKO 26-01-2006
	afx_msg void OnTimer(UINT_PTR nIDEvent); // vito
	afx_msg void OnButPlayPause();	// vito
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Vista1();
	void text(char* string);
	void projection(int width, int height, int perspective);
	BOOL MovimientoZ;
	GLdouble aspect;
	GLdouble aspect_ratioV;
	GLdouble aspect_ratioH;
	float m_mov_z;
	float m_mov_y;
	float m_mov_x;
	/* Variables para vista cenital movil */
	float m_mov2_z; // vito 
	float m_mov2_y; // vito
	float m_mov2_x; // vito
	/* Variables para la vista desde el aparato */
	float m_mov8_z;
	float m_mov8_y;
	float m_mov8_x;
	CCoordenadaEsferica m_mov8_circ;
	//short m_WheelPos; // vito -> para rueda de raton, distancia
	float TranslacionGrafica;
	float TranslacionGrafica1;// KIKO 26-01-2006
	float EscalaGrafica;
	float EscalaGrafica1;// KIKO 26-01-2006
	CPoint m_RButtonPos;
	BOOL m_RButton;
	CPoint m_LButtonPos;
	BOOL m_LButton;
	float m_rot_y;
	float m_rot_x;
	float m_rot_z;
	bool VistaGraficas;
	bool VistaGraficas1;// KIKO 26-01-2006
	int alto;
	int ancho;
	int m_vista;
	int centro_rot;
	CCoordenadaCartesiana pos_centro;
	CCoordenadaCartesiana pos_objetivo;
	COrientacion orientacion_centro;
	void CambiarCentro(CLanderDoc* pDoc);
	void CambiarCentroObjetivo(CLanderDoc* pDoc);
	void CambiarOrientacion(CLanderDoc* pDoc);
	BOOL SetWindowPixelFormat(HDC hDC);
	BOOL CreateViewGLContext(HDC hDC);
	int m_GLPixelIndex;
	HGLRC m_hGLContext;
	bool pause;

	int varStaticX = 0;
	int varStaticY = 0;
};

#ifndef _DEBUG  // debug version in LanderView.cpp
inline CLanderDoc* CLanderView::GetDocument()
   { return (CLanderDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LANDERVIEW_H__0D31CB8C_0599_11D5_9FE5_B2B36BD66F63__INCLUDED_)
