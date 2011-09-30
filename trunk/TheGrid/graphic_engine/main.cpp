// Defines the entry point for the application.
//
#include "stdafx.h"
#include "graphic_engine.h"


// Funkcja wcisniecia klawiszy specjalnych
void keyPressed (int key, int x, int y) {
	LogicLayer::getI()->specialKeystates[key] = true; // Set the state of the current key to pressed
}

// Funkcja zwolnienia klawiszy specjalnych
void keyUp (int key, int x, int y) {
	LogicLayer::getI()->specialKeystates[key] = false; // Set the state of the current key to not pressed
}

// Funkcja wcisniecia klawiszy 
void keyPressedS (unsigned char key, int x, int y) {
	LogicLayer::getI()->keyStates[key] = true; // Set the state of the current key to pressed
}

// Funkcja zwolnienia klawiszy
void keyUpS (unsigned char key, int x, int y) {
	LogicLayer::getI()->keyStates[key] = false; // Set the state of the current key to not pressed
}



// Funkcja reshape'ujaca view
void reshapeFunc(int x,int y)
{
  GraphicEng::getI()->Reshape(x, y);
}



// wartoœæ FPS
int framesPerSecond = 0;
// licznik ramek
int frames = 0;
// licznik czasu
long startTime = clock();
long lastTime = clock();
int logicTimeCounter = 0;
long graphicLastTime = clock();
int graphicTimeCounter = 0;
void displayFunc()
{
	logicTimeCounter += clock() - lastTime;
	lastTime = clock();
	if((double)logicTimeCounter/CLOCKS_PER_SEC > 0.1)
	{
		logicTimeCounter = 0;
		LogicLayer::getI()->doLogic();
	}
	
	graphicTimeCounter += (clock() - graphicLastTime);
	graphicLastTime = clock();
	if((double)graphicTimeCounter/CLOCKS_PER_SEC >= 0.02)
	{
		graphicTimeCounter = 0;
		//licznik czasu
		if( !frames++ )
			startTime = clock();
		//zliczanie iloœci ramek rysowanych na sekundê (FPS)
		if( clock() - startTime >= 0.5 * CLOCKS_PER_SEC )
		{
			framesPerSecond = static_cast <int> ( frames * CLOCKS_PER_SEC/static_cast<float>( clock() - startTime ) );
			frames = 0;
		}

		GraphicEng::getI()->DisplayScene();
	}
	//wymuszenie przejscia kolejnej klatku petli gry
	glutPostRedisplay();
}
///////////////////////////////////////////////////////////////////////////////
// Main entry point for GLUT based programs
int main(int argc, char* argv[])
{
	gltSetWorkingDirectory(argv[0]);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(900, 500);
	glutCreateWindow("The Grid");
	

	GLenum err = glewInit();
	if (GLEW_OK != err)
		{
		// Problem: glewInit failed, something is seriously wrong.
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return 1;
		}

	glutReshapeFunc(reshapeFunc);
	glutDisplayFunc(displayFunc);
  
	glutSpecialFunc(keyPressed);
	glutKeyboardFunc(keyPressedS);
	glutSpecialUpFunc(keyUp);
	glutKeyboardUpFunc(keyUpS);


	GraphicEng::getI()->InitScene();	

	glutMainLoop();
}