
#include "stdafx.h"
#include "graphic_engine.h"

extern int framesPerSecond;
GraphicEng* GraphicEng::instance = NULL;
GLBatch triBach;
GLfloat blockSize = 0.1f;
GLfloat vVerts[] = { -blockSize, -blockSize, 0.0f, 
	                  0.0f, blockSize, 0.0f,
					  blockSize,  -blockSize, 0.0f};
GLBatch triBach2;
GLfloat vVerts2[] = { -blockSize+0.5f, -blockSize+0.5f, 0.5f, 
	                  0.5f, blockSize+0.5f, 0.5f,
					  blockSize+0.5f,  -blockSize+0.5f, 0.5f};


	//////////////////////////////////////////////////////////////////////
	// funkcja generuj�ca scen� 3D
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::DisplayScene()
	{
    // czyszczenie bufora koloru, bufora g��boko�ci i bufora szblonowego
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
		
		shaderManager.UseStockShader(GLT_SHADER_IDENTITY, clRed);
		triBach.Draw();
		shaderManager.UseStockShader(GLT_SHADER_IDENTITY, clPink);
		triBach2.Draw();

		if(this->showFpsInfo)
		{
			std::ostringstream txt;
			txt << "FPS: " << framesPerSecond;
			glDisable( GL_DEPTH_TEST );
			shaderManager.UseStockShader(GLT_SHADER_IDENTITY, clBlack);
			glColor3f(0, 0, 0); 
			glRasterPos4d(-1, -1, 0, 1);
			glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char *)txt.str().c_str());
			glEnable( GL_DEPTH_TEST );
		}

		// skierowanie polece� do wykonania
		//glFlush();
		glutSwapBuffers();
		glutPostRedisplay();
	}

	//////////////////////////////////////////////////////////////////////
	// inicjalizacja sta�ych element�w maszyny stanu OpenGL
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::InitScene()
	{
    // kolor t�a - zawarto�� bufora koloru
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
		shaderManager.InitializeStockShaders();
		
		// Load up a triangle
		triBach.Begin(GL_TRIANGLES, 3);
		triBach.CopyVertexData3f(vVerts);
		triBach.End();
		// Load up a triangle
		triBach2.Begin(GL_TRIANGLES, 3);
		triBach2.CopyVertexData3f(vVerts2);
		triBach2.End();

		
    // w��czenie mechanizm�w u�ywanych podczas renderingu tekstu
    //InitDrawText();
    glEnable( GL_DEPTH_TEST );
	}

	//////////////////////////////////////////////////////////////////////
	// zmiana wielko�ci okna
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::Reshape( int width, int height )
	{
		// obszar renderingu - ca�e okno
		glViewport( 0, 0, width, height );
	}

	void GraphicEng::DeleteScene()
	{
		// usuni�cie obiekt�w shadera

		// usuni�cie obiektu programu

		// usuni�cie obiekt�w bufora wierzcho�k�w

		// usuni�cie obiektu tablic wierzcho�k�w
		
    // usuni�cie mechanizm�w u�ywanych podczas renderingu tekstu
    //DeleteDrawText();
	}