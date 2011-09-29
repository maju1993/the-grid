#include "stdafx.h"
#include "Grid.h"
#include "DrawHelper.h"

class Player
{
public:
	Player(Grid *grid)
	{
		this->grid = grid;
		playerBatch = 0 ;
	}
	Grid *grid;
	GLBatch *playerBatch;
	//wektor obrotu
	GLfloat playerZRotateX, playerZRotateY;
	//predkosc obrotu
	GLfloat playerZRotateSpeed;
	//predkosc ruchu
	GLfloat playerMoveSpeed;
	//macierz transformacji modelu
	M3DMatrix44f playerMatrix;
	
	void showPlayer(int x, int y, int offsetX, int offsetY, double zRotateX, double zRotateY)
	{
		playerBatch = new GLBatch();

		GLfloat* pos = grid->getPosition(x, y, offsetX, offsetY);
		m3dTranslationMatrix44(playerMatrix, pos[0], pos[1], -0.2f);
		
		
		DrawHelper::drawTriangle(*playerBatch, 0, 0, 0, 1, *this->grid);
	}
	void movePlayer(int x, int y, int offsetX, int offsetY)
	{
		GLfloat* pos = grid->getPosition(x, y, offsetX, offsetY);
		m3dTranslationMatrix44(playerMatrix, pos[0], pos[1], -0.2f);
	}
	void rotatePlayer(int rotateAngle)
	{


	}

};