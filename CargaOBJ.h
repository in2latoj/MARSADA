#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <Windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <glut.h>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

#include "ManejadorBitmap.h"

#define BYTES_LINEA_FICHERO 1024
#define NUM_MAX_VERTICES_CARA 1024

using namespace cv;
using namespace std;

class CargaOBJ
{
public:
	CargaOBJ(string ruta, string rutaTextura);
	~CargaOBJ();
	string PintarModelo();

private:
	FILE* archivo;
	string trim(const string& str);
	string rutaText;

	CManejadorBitmap * 	Tierra;
	GLuint TexturaTierra;
};