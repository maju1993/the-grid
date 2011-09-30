#include "stdafx.h"
#include "graphic_engine.h"

extern int framesPerSecond;
GraphicEng* GraphicEng::instance = NULL;

GLMatrixStack		modelViewMatrix;

	//////////////////////////////////////////////////////////////////////
	// funkcja generuj¹ca scenê 3D
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::DisplayScene()
	{
    // czyszczenie bufora koloru, bufora g³êbokoœci i bufora szblonowego
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
		
		glLineWidth(5);
		shaderManager.UseStockShader(GLT_SHADER_SHADED, modelViewMatrix.GetMatrix());

		if(LogicLayer::getI()->graphicsShouldRefreshBullets || LogicLayer::getI()->graphicsShouldRefreshCreeps || LogicLayer::getI()->graphicsShouldRefreshPlayer)
		{
			groundGrid->rescanState(LogicLayer::getI()->grid);
		}
	
		for(std::vector<ILayer*>::iterator it = layers.begin(); it<layers.end(); it++)
		{
			(*it)->Render((float*)modelViewMatrix.GetMatrix());
		}

		//grid.renderFields();
		//
  //  //private constructor
		//for(int i = 0; i<GRID_HEIGHT; i++)
		//	for(int j = 0; j<GRID_WIDTH; j++)
		//		if(gridObjects[i][j] != 0)
		//		{
		//			gridObjects[i][j]->batch->Draw();
		//		}
		//modelViewMatrix.PushMatrix();
		//	m3dLoadIdentity44(playerMatrix);
		//	m3dRotationMatrix44(playerMatrix, (GLfloat)m3dDegToRad(90.0f), 0.0f, 0.0f, 1.0f);
		//	//m3dTranslationMatrix44(playerMatrix, 0.5, 0.7, 0);
		//	
		//	//modelViewMatrix.Translate(0.5, 0.5, 0.1);
		//	//m3dRotationMatrix44()
		//	//modelViewMatrix.Rotate();
		//	modelViewMatrix.MultMatrix(playerMatrix);
		//	shaderManager.UseStockShader(GLT_SHADER_SHADED, modelViewMatrix.GetMatrix());
		//	
		//	if(playerBatch != 0 )
		//		playerBatch->Draw();
		//modelViewMatrix.PopMatrix();
		//		

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
		glFlush();
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
    glEnable( GL_DEPTH_TEST );
		
		groundGrid = new GroundGridLayer(grid);
		layers.push_back(groundGrid);

		for(std::vector<ILayer*>::iterator it = layers.begin(); it<layers.end(); it++)
		{
			(*it)->Init();
		}

		//grid.generateBashGrid(-1, 1, -1, 1, -0.01f,  0.0f);
		
		modelViewMatrix.LoadIdentity();
		viewFrustum.SetOrthographic(-1, 1, -1, 1, -1, 1);
    // w³¹czenie mechanizmów u¿ywanych podczas renderingu tekstu
    //InitDrawText();
	}

	//////////////////////////////////////////////////////////////////////
	// zmiana wielkoœci okna
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::Reshape( int width, int height )
	{
		// obszar renderingu - ca³e okno
		glViewport( 0, 0, width, height );
		viewFrustum.SetOrthographic(-1, 1, -1, 1, -1, 1);
	}

	void GraphicEng::DeleteScene()
	{
		for(std::vector<ILayer*>::iterator it = layers.begin(); it<layers.end(); it++)
		{
			(*it)->Dispose();
		}

		// usuniêcie obiektów shadera

		// usuniêcie obiektu programu

		// usuniêcie obiektów bufora wierzcho³ków

		// usuniêcie obiektu tablic wierzcho³ków
		
    // usuniêcie mechanizmów u¿ywanych podczas renderingu tekstu
    //DeleteDrawText();
	}