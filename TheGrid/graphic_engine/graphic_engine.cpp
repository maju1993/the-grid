
#include "stdafx.h"
#include "graphic_engine.h"

extern int framesPerSecond;
GraphicEng* GraphicEng::instance = NULL;


	//////////////////////////////////////////////////////////////////////
	// funkcja generuj¹ca scenê 3D
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::DisplayScene()
	{
    // czyszczenie bufora koloru, bufora g³êbokoœci i bufora szblonowego
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );


		
    std::ostringstream txt;
    txt << "FPS: " << framesPerSecond;
    glDisable( GL_DEPTH_TEST );
    DrawText8x16( 3, 20, txt.str() );
    glEnable( GL_DEPTH_TEST );

		// skierowanie poleceñ do wykonania
		glFlush();
	}

	//////////////////////////////////////////////////////////////////////
	// inicjalizacja sta³ych elementów maszyny stanu OpenGL
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::InitScene()
	{
    // kolor t³a - zawartoœæ bufora koloru
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
		shaderManager.InitializeStockShaders();
		
    // w³¹czenie mechanizmów u¿ywanych podczas renderingu tekstu
    InitDrawText();
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
    DeleteDrawText();
	}