#pragma once

#include "Grid.h"
#include <vector>
#include "ILayer.h"
#include "GroundGridLayer.h"


class GridObject
{
public:
	int id;
	int offsetX;
	int offsetY;
	GLfloat ZRotateX, ZRotateY;
	GLfloat ZRotateSpeed;
	GLfloat MoveSpeed;
	GLBatch* batch;
	GridObject():id(0),offsetX(0),offsetY(0),ZRotateSpeed(0),ZRotateX(0),ZRotateY(0),MoveSpeed(0)
	{
		batch = 0;
	}
	~GridObject()
	{
		if(batch!=0)
			delete batch;
	}
};
class GraphicEng
{
private:
  static GraphicEng *instance;
	GraphicEng()
    {
			grid = new Grid(-1, 1, -1, 1, -0.01f, 0.0f);

			playerBatch = 0 ;
    }
public:
	GLShaderManager	shaderManager;
	GLFrustum viewFrustum;

	//warstwa najnizsza
	GroundGridLayer *groundGrid;
	std::vector<ILayer*> layers;

	Grid *grid;

	void setTriangle(GLBatch &batch, int x, int y, int offsetX, int offsetY, double zRotateX, double zRotateY,
		GLfloat r, GLfloat g, GLfloat b)
	{
		batch.Begin(GL_TRIANGLES, 3);

		GLfloat* pos = grid->getPosition(x, y, offsetX, offsetY);
		batch.Vertex3f(pos[0], pos[1]+grid->fieldH/2, -0.1f);
		batch.Color4f(r, g, b, 1);
		batch.Vertex3f(pos[0]+grid->fieldW, pos[1]+grid->fieldH/2, -0.1f);
		batch.Color4f(r, g, b, 1);
		batch.Vertex3f(pos[0]+grid->fieldW/2, pos[1]+grid->fieldH, -0.5f);
		batch.Color4f(r, g, b, 1);
		
		batch.End();
	}

	GLBatch *playerBatch;
	GLfloat playerX, playerY;
	GLfloat playerZRotateX, playerZRotateY;
	GLfloat playerZRotateSpeed;
	GLfloat playerMoveSpeed;
	M3DMatrix44f playerMatrix;

	GridObject* gridObjects[GROUND_GRID_H][GROUND_GRID_W];

	
	//int generateGridEnemy(int type, int initX, int initY)
	//{
	//	delete gridObjects[initY][initY];
	//	GridObject *go = new GridObject();
	//	GLfloat* pos = grid.getPosition(initX, initY, 0 ,0);
	//	go->batch = new GLBatch();
	//	go->batch->Begin(GL_TRIANGLES, 3);
	//	go->batch->Color4f(1, 0, 0, 1);
	//	go->batch->Vertex3f(pos[0], pos[1]+grid.offsetY/2, 0);
	//	go->batch->Color4f(1, 0, 0, 1);
	//	go->batch->Vertex3f(pos[0]+grid.offsetX, pos[1]+grid.offsetY/2, 0);
	//	go->batch->Color4f(1, 0, 0, 1);
	//	go->batch->Vertex3f(pos[0]+grid.offsetX/2, pos[1]+grid.offsetY, -0.5f);
	//	go->batch->End();
	//	//todo:
	//	//ustawianie pozycji wroga
	//	//pozycja playera
	//	//przesuwanie za pomoca klawiszy i usytawianie offsetu ew, speedow i rotacji
	//	
	//	go->id = rand();
	//	gridObjects[initY][initY] = go;

	//	return go->id;
	//}
	//void showPlayer(int x, int y, int offsetX, int offsetY, double zRotateX, double zRotateY)
	//{
	//	playerBatch = new GLBatch();
	//	//setTriangle(*playerBatch, x, y, offsetX, offsetY, zRotateX, zRotateY,
	//	//	0, 0, 0);
	//	GLfloat* pos = grid.getPosition(x, y, offsetX, offsetY);
	//	m3dTranslationMatrix44(playerMatrix, pos[0], pos[1], -0.2f);

	//	drawTriangle(*playerBatch, 0, 0, 0, 1);
	//}
	void rotatePlayer(int rotateAngle)
	{

	}

	bool showFpsInfo;

  static GraphicEng* getI()
	{
		if(instance == NULL)
		{
			instance = new GraphicEng();
			return instance;
		}
		else
		{
			return instance;
		}
	}
  void method();
  ~GraphicEng()
  {
		showFpsInfo = true;
  }

	//OpenGL funkcje
	void DisplayScene();
	void InitScene();
	void Reshape( int width, int height );
	void DeleteScene();
};