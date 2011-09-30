#pragma once

#ifndef __GRAPHICENGINE_H__
#define __GRAPHICENGINE_H__
#include "Grid.h"
#include "ILayer.h"
#include "GroundGridLayer.h"
#include "ModelsLayer.h"


class GraphicEng
{
private:
  static GraphicEng *instance;
	GraphicEng()
    {
			grid = new Grid(-1, 1, -1, 1, -0.001f, 0.0f);

			playerBatch = 0 ;
    }
public:
	GLShaderManager	shaderManager;
	GLFrustum viewFrustum;

	//warstwa najnizsza
	GroundGridLayer *groundGrid;
	//warstwa modeli (player, creepy, pociski)
	ModelsLayer *modelsLayer;
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
#endif