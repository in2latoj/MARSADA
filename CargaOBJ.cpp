#include "StdAfx.h"
#include "CargaOBJ.h"

struct Vertices {
	int numVertice;
	GLfloat verticeX;
	GLfloat verticeY;
	GLfloat verticeZ;
};
struct CarasPoligono {
	int numCara;
	int numVertices = 0;
	int verticeReferencia[NUM_MAX_VERTICES_CARA];

};

CargaOBJ::CargaOBJ(std::string ruta, std::string rutaTextura)
{
	rutaText = rutaTextura;
	archivo = fopen(ruta.c_str(), "r");
	if (archivo == NULL) {
		printf("ERROR: No se puede abrir el fichero.\n");
		exit(-1);
	}
}

CargaOBJ::~CargaOBJ()
{
	fclose(archivo);
}

string CargaOBJ::PintarModelo()
{
	// Variables para los vértices
	int numVertice = 0;
	int numCara = 0;
	std::vector< Vertices > vertices;
	std::vector< CarasPoligono > carasPoligono;
	// Variables para el fichero
	char linea[BYTES_LINEA_FICHERO];
	while (fgets(linea, BYTES_LINEA_FICHERO, archivo) != NULL)
	{
		// Quitamos espacios en blanco, en la primera y última posición
		string lineaMod = trim(linea);
		if (strcmp(lineaMod.substr(0, 2).c_str(), "v ") == 0)
		{
			Vertices nuevoVertice;
			nuevoVertice.numVertice = numVertice;
			numVertice++;
			lineaMod = trim(lineaMod.substr(1));
			nuevoVertice.verticeX = strtof(lineaMod.substr(0, lineaMod.find_first_of(' ')).c_str(), 0);
			lineaMod = trim(lineaMod.substr(lineaMod.find_first_of(' ')));
			nuevoVertice.verticeY = strtof(lineaMod.substr(0, lineaMod.find_first_of(' ')).c_str(), 0);
			lineaMod = trim(lineaMod.substr(lineaMod.find_first_of(' '), lineaMod.find_first_of('\n')));
			nuevoVertice.verticeZ = strtof(lineaMod.substr(0, lineaMod.find_first_of(' ')).c_str(), 0);
			vertices.push_back(nuevoVertice);
			glBegin(GL_POINTS);
			glVertex3f(nuevoVertice.verticeX, nuevoVertice.verticeY, nuevoVertice.verticeZ);
			glEnd();
		}
		else if (strcmp(lineaMod.substr(0, 2).c_str(), "f ") == 0)
		{
			int i = 0;
			CarasPoligono nuevaCara;
			nuevaCara.numCara = numCara;
			numCara++;
			lineaMod = trim(lineaMod.substr(1));
			lineaMod.insert(lineaMod.length() - 1, " ");
			while (lineaMod != "\n")
			{
				if (i > 4) {
					i = i;
				}
				nuevaCara.verticeReferencia[i] = atoi(lineaMod.substr(0, lineaMod.find_first_of(' ')).c_str());
				i++;
				lineaMod = trim(lineaMod.substr(lineaMod.find_first_of(' ')));
			}
			nuevaCara.numVertices = i;
			carasPoligono.push_back(nuevaCara);
		}
	} // Fin del While

	/*
	//Textura de la tierra
	Tierra = new CManejadorBitmap("Grass.BMP");
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

	static GLfloat v[4][3] =
	{ 0., 0., 0.,
	0., 0., 0.,
	0., 0., 0.,
	0., 0., 0. };
	

	for (int i = 0; i < numCara; i++)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, TexturaTierra);
		glBegin(GL_QUADS);
		//glBegin(GL_POLYGON);
		CarasPoligono cara = carasPoligono[i];


		if (cara.numVertices == 4) {
			// Pinta la cara del modelo 3D
			for (int j = 0; j < cara.numVertices; j++)
			{
				Vertices vertice = vertices[cara.verticeReferencia[j] - 1];
				v[j][0] = vertice.verticeX;
				v[j][1] = vertice.verticeY;
				v[j][2] = vertice.verticeZ;
			}

			glNormal3i(0, 0, 1);
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
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	*/

	
	// Carga la imagen de la textura y se inicializan las variables
	string rutaImagen = rutaText;
	Mat image = imread(rutaImagen.c_str());
	Vec3b buf;
	int iRows = 0;
	int jCols = 0;
	// Pintar las caras
	for (int i = 0; i < numCara; i++)
	{
		glBegin(GL_POLYGON);
		CarasPoligono cara = carasPoligono[i];
		// Pinta la cara del modelo 3D
		for (int j = 0; j < cara.numVertices; j++)
		{
			buf = image.at<Vec3b>(iRows, jCols);
			float rValue = ((float)buf[2]) / 256.0f;
			float gValue = ((float)buf[1]) / 256.0f;
			float bValue = ((float)buf[0]) / 256.0f;
			glColor3f(rValue, gValue, bValue);//rojo
			iRows++;
			if (iRows == image.rows) {
				iRows = 0;
				jCols++;
				if (jCols == image.cols) {
					jCols = 0;
				}
			}
			Vertices vertice = vertices[cara.verticeReferencia[j] - 1];
			// TODO: OBTENER VÉRTICE CORRESPONDIENTE
			//		PINTARLO
			glVertex3f(vertice.verticeX, vertice.verticeY, vertice.verticeZ);

		}
		glEnd();

		//TODO: PINTAR LAS BOLAS DE COLISION Y PONERLAS INVISIBLES
		glMatrixMode(GL_MODELVIEW);
		// Pinta la cara del modelo 3D
		for (int j = 0; j < cara.numVertices / 4; j++)
		{
			Vertices vertice = vertices[cara.verticeReferencia[j] - 1];

			//glPushMatrix();

			//glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//rojo
			//glTranslatef(vertice.verticeX, vertice.verticeY, vertice.verticeZ);
			//glutSolidSphere(0.25, 10, 10);

			//glPopMatrix();

		}
		glEnd();
	}
	
	return "";
}

string CargaOBJ::trim(const string& linea)
{
	size_t first = linea.find_first_not_of(' ');
	if (string::npos == first)
	{
		return linea;
	}
	size_t last = linea.find_last_not_of(' ');
	return linea.substr(first, (last - first + 1));
}