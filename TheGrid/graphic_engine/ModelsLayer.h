#pragma once
#include "stdafx.h"
#include "ILayer.h"

class GridObject
{
public:
	int id;
	//
	GLfloat posX, posY;
	int offsetX, offsetY;
	GLfloat ZRotateX, ZRotateY;
	//
	GLfloat ZRotateSpeed;
	GLfloat moveSpeed;
	GLBatch* batch;
	M3DMatrix44f transformMatrix;
	GridObject(int _id):id(_id),offsetX(0),offsetY(0),ZRotateSpeed(0),ZRotateX(0),ZRotateY(0),moveSpeed(0),posX(0), posY(0)
	{
		m3dLoadIdentity44(transformMatrix);
		batch = 0;
	}
	~GridObject()
	{
		delete batch;
	}
};
class ModelsLayer :
	public ILayer
{
private:
	std::vector<GridObject *> models;
	GLShaderManager &shaderManager;
	Grid *grid;
public:
	void addCreep(int id);
	void delModel(int id);
	void moveModel(int id, int x, int y, int offsetX, int offsetY, GLfloat rotateAngle);
	void Init();
	void Render(M3DMatrix44f modelViewMatrix);
	void Dispose();
	ModelsLayer(GLShaderManager*, Grid*);
	~ModelsLayer(void);
};

