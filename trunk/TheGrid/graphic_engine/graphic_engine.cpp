#include "stdafx.h"
#include "graphic_engine.h"

extern int framesPerSecond;
GraphicEng* GraphicEng::instance = NULL;
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

	/*shaderManager.UseStockShader(GLT_SHADER_FLAT, transformPipeline.GetModelViewProjectionMatrix(), clBlue);	
	b.Begin(GL_TRIANGLE_FAN, 10);
	b.Vertex3f(0,0,-1);
	b.Vertex3f(0.8f,0,-1);
	b.Vertex3f(2,1,-1);
	b.End();*/

	//groundGrid->Render((float*)transformPipeline.GetModelViewProjectionMatrix());
		
	//b.Draw();
	for(std::vector<ILayer*>::iterator it = layers.begin(); it<layers.end(); it++)
	{
		(*it)->Render((float*)transformPipeline.GetModelViewProjectionMatrix());
	}

	modelViewMatrix.PopMatrix();

	modelViewMatrix.PopMatrix();
		
	glDisable( GL_DEPTH_TEST );
	std::ostringstream txt;
		
	if(LogicLayer::getI()->gameover)
	{
		txt<<"Koniec gry\nNacisnij enter aby wyjsc";
		shaderManager.UseStockShader(GLT_SHADER_IDENTITY, clWhite);
		glRasterPos3f(-0.15, -0.1, 0);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)txt.str().c_str());
	}
		
	txt = std::ostringstream();
	txt<<"HP: "<<LogicLayer::getI()->player->hp<<"\nPoints: "<<LogicLayer::getI()->points;
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, clWhite);
	glRasterPos3f(-1, 0.95, 0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, (unsigned char *)txt.str().c_str());
	if(LogicLayer::getI()->showFPSinfo)
	{
		txt = std::ostringstream();
		txt << "FPS: " << framesPerSecond;
		glDisable( GL_DEPTH_TEST );
		shaderManager.UseStockShader(GLT_SHADER_IDENTITY, clWhite);
		glColor3f(0, 0, 0); 
		glRasterPos4d(-1, -1, 0, 1);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char *)txt.str().c_str());
		glEnable( GL_DEPTH_TEST );
	}
	glEnable( GL_DEPTH_TEST );

	glutSwapBuffers();
}
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