#include "stdafx.h"
#include "graphic_engine.h"

extern int framesPerSecond;
GraphicEng* GraphicEng::instance = NULL;



GLShaderManager		shaderManager;			// Shader Manager
GLMatrixStack		modelViewMatrix;		// Modelview Matrix
GLMatrixStack		projectionMatrix;		// Projection Matrix
GLFrustum			viewFrustum;			// View Frustum
GLGeometryTransform	transformPipeline;		// Geometry Transform Pipeline
GLFrame				cameraFrame;			// Camera frame

GLBatch b;
	//////////////////////////////////////////////////////////////////////
	// funkcja generuj¹ca scenê 3D
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::DisplayScene()
	{
    // czyszczenie bufora koloru, bufora g³êbokoœci i bufora szblonowego
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
		
		if(LogicLayer::getI()->graphicsShouldRefreshBullets || LogicLayer::getI()->graphicsShouldRefreshCreeps || LogicLayer::getI()->graphicsShouldRefreshPlayer)
		{
			groundGrid->rescanState(LogicLayer::getI()->grid);
		}
		glLineWidth(1);
		glPointSize(10);
		glEnable( GL_DEPTH_TEST );
		glEnable (GL_BLEND);
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_POINT_SMOOTH);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		modelViewMatrix.PushMatrix();	
		M3DMatrix44f mCamera;
		cameraFrame.GetCameraMatrix(mCamera);
		modelViewMatrix.MultMatrix(mCamera);
	
		// Draw the world upside down
		modelViewMatrix.PushMatrix();
		modelViewMatrix.Scale(1.0f, 1.0f, -1.0f); // Flips the Y Axis
		modelViewMatrix.Translate(0.0f, 0.0f, 2.5f); // Scootch the world down a bit...
		modelViewMatrix.Rotate(15, 1, 0, 0);

		shaderManager.UseStockShader(GLT_SHADER_FLAT, transformPipeline.GetModelViewProjectionMatrix(), clBlue);	
		b.Begin(GL_TRIANGLE_FAN, 10);
		b.Vertex3f(0,0,-1);
		b.Vertex3f(0.8f,0,-1);
		b.Vertex3f(2,1,-1);
		b.End();


		//groundGrid->Render((float*)transformPipeline.GetModelViewProjectionMatrix());
		
		//b.Draw();
		for(std::vector<ILayer*>::iterator it = layers.begin(); it<layers.end(); it++)
		{
			(*it)->Render((float*)transformPipeline.GetModelViewProjectionMatrix());
		}
		
		modelViewMatrix.PopMatrix();
		modelViewMatrix.PopMatrix();
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
			/*std::ostringstream txt;
			txt << "FPS: " << framesPerSecond;
			glDisable( GL_DEPTH_TEST );
			shaderManager.UseStockShader(GLT_SHADER_IDENTITY, clBlack);
			glColor3f(0, 0, 0); 
			glRasterPos4d(-1, -1, 0, 1);
			glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char *)txt.str().c_str());
			glEnable( GL_DEPTH_TEST );*/
		}

		// skierowanie poleceñ do wykonania
    // Do the buffer Swap
		//glFlush();
		glutSwapBuffers();
	}
	//////////////////////////////////////////////////////////////////////
	// inicjalizacja sta³ych elementów maszyny stanu OpenGL
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::InitScene()
	{
    // kolor t³a - zawartoœæ bufora koloru
    glClearColor( 0.0f, 0.0f,0.0f, 1.0f );
		shaderManager.InitializeStockShaders();
    glEnable( GL_DEPTH_TEST );
		
		groundGrid = new GroundGridLayer(&shaderManager, grid);
		layers.push_back(groundGrid);
		modelsLayer = new ModelsLayer(&shaderManager, grid);
		layers.push_back(modelsLayer);

		for(std::vector<ILayer*>::iterator it = layers.begin(); it<layers.end(); it++)
		{
			(*it)->Init();
		}

		//grid.generateBashGrid(-1, 1, -1, 1, -0.01f,  0.0f);
		
		modelViewMatrix.LoadIdentity();
		//viewFrustum.SetOrthographic(-1, 1, -1, 1, -1, 1);
	}

	//////////////////////////////////////////////////////////////////////
	// zmiana wielkoœci okna
	//////////////////////////////////////////////////////////////////////
	void GraphicEng::Reshape( int width, int height )
	{
		// obszar renderingu - ca³e okno
		glViewport( 0, 0, width, height );
		//viewFrustum.SetOrthographic(-1, 1, -1, 1, -1, 1);

		glViewport(0, 0, width, height);
		transformPipeline.SetMatrixStacks(modelViewMatrix, projectionMatrix);
	
		viewFrustum.SetPerspective(50.0f, float(width)/float(height), 1.0f, 100.0f);
		projectionMatrix.LoadMatrix(viewFrustum.GetProjectionMatrix());
		modelViewMatrix.LoadIdentity();

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