// Defines the entry point for the application.
//
#include "stdafx.h"
#include "graphic_engine.h"

void reshapeFunc(int x,int y)
{
  GraphicEng::getI()->Reshape(x, y);
}
void keyboardFun(unsigned char key,int x,int y)
{
	//UniverseDraw::get()->KeyPressFunc(key,x,y);
}
void specialFunc(int key,int x,int y)
{

}
// wartoœæ FPS
int framesPerSecond = 0;
// licznik ramek
int frames = 0;
// licznik czasu
long startTime = 0;
void displayFunc()
{
	
  // licznik czasu
  if( !frames++ )
    startTime = clock();

	// zliczanie iloœci ramek rysowanych na sekundê (FPS)
  if( clock() - startTime >= 0.5 * CLOCKS_PER_SEC )
  {
    framesPerSecond = static_cast <int> ( frames * CLOCKS_PER_SEC/static_cast<float>( clock() - startTime ) );
    frames = 0;
  }

	GraphicEng::getI()->DisplayScene();
}
///////////////////////////////////////////////////////////////////////////////
// Main entry point for GLUT based programs
int main(int argc, char* argv[])
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(900, 900);
	glutCreateWindow("The Grid");
	glutReshapeFunc(reshapeFunc);
  glutKeyboardFunc(keyboardFun);
  glutSpecialFunc(specialFunc);

  glutDisplayFunc(displayFunc);

	GraphicEng::getI()->InitScene();
	//SetupRC();

	glutMainLoop();
}