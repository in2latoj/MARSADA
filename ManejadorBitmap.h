// ManejadorBitmap.h: interface for the CManejadorBitmap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANEJADORBITMAP_H__33360AA0_B73F_11D5_9FE7_C2584473A35C__INCLUDED_)
#define AFX_MANEJADORBITMAP_H__33360AA0_B73F_11D5_9FE7_C2584473A35C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CManejadorBitmap  
{
public:
	CManejadorBitmap(char * nombreFichero);
	virtual ~CManejadorBitmap();
	BITMAPINFO	*BitmapInfo ;	/* Current bitmap information */
	void		*BitmapBits ;	/* Current bitmap pixel bits */
private:
	GLubyte * ConvertRGB(BITMAPINFO *info,void *bits);
	void * LoadDIBitmap(char *filename,BITMAPINFO **info);

};

#endif // !defined(AFX_MANEJADORBITMAP_H__33360AA0_B73F_11D5_9FE7_C2584473A35C__INCLUDED_)
