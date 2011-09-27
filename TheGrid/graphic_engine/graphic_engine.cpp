
#include "stdafx.h"
#include "graphic_engine.h"

extern int framesPerSecond;
GraphicEng* GraphicEng::instance = NULL;


	//////////////////////////////////////////////////////////////////////
	// funkcja generuj�ca scen� 3D
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::DisplayScene()
	{
    // czyszczenie bufora koloru, bufora g��boko�ci i bufora szblonowego
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );


		
    std::ostringstream txt;
    txt << "FPS: " << framesPerSecond;
    glDisable( GL_DEPTH_TEST );
    DrawText8x16( 3, 20, txt.str() );
    glEnable( GL_DEPTH_TEST );

		// skierowanie polece� do wykonania
		glFlush();
	}

	//////////////////////////////////////////////////////////////////////
	// inicjalizacja sta�ych element�w maszyny stanu OpenGL
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::InitScene()
	{
    // kolor t�a - zawarto�� bufora koloru
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
		shaderManager.InitializeStockShaders();
		
    // w��czenie mechanizm�w u�ywanych podczas renderingu tekstu
    InitDrawText();
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
    DeleteDrawText();
	}