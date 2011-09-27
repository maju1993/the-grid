
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
	// funkcja generuj¹ca scenê 3D
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::DisplayScene()
	{
    // czyszczenie bufora koloru, bufora g³êbokoœci i bufora szblonowego
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

		// skierowanie poleceñ do wykonania
		//glFlush();
		glutSwapBuffers();
		glutPostRedisplay();
	}

	//////////////////////////////////////////////////////////////////////
	// inicjalizacja sta³ych elementów maszyny stanu OpenGL
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::InitScene()
	{
    // kolor t³a - zawartoœæ bufora koloru
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

		
    // w³¹czenie mechanizmów u¿ywanych podczas renderingu tekstu
    //InitDrawText();
    glEnable( GL_DEPTH_TEST );
	}

	//////////////////////////////////////////////////////////////////////
	// zmiana wielkoœci okna
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::Reshape( int width, int height )
	{
		// obszar renderingu - ca³e okno
		glViewport( 0, 0, width, height );
	}

	void GraphicEng::DeleteScene()
	{
		// usuniêcie obiektów shadera

		// usuniêcie obiektu programu

		// usuniêcie obiektów bufora wierzcho³ków

		// usuniêcie obiektu tablic wierzcho³ków
		
    // usuniêcie mechanizmów u¿ywanych podczas renderingu tekstu
    //DeleteDrawText();
	}