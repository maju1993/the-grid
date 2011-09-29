#pragma once
#include "stdafx.h"
#include "ILayer.h"
#include "DrawHelper.h"

class GridObject
{
public:
	int id;
	//
	int posX, posY;
	int offsetX, offsetY;
	GLfloat ZRotateX, ZRotateY;
	GLfloat rotateAngle;
	//
	GLfloat ZRotateSpeed;
	GLfloat moveSpeed;
	GLBatch* batch;
	M3DMatrix44f transformMatrix;
	void setBatch(GLBatch *batch)
	{
		this->batch = batch;
	}
	void fill(mapItem *item)
	{
		//fill(item->getPosition().x, item->getPosition().y, item->getOffset().x, item->getOffset().y, item->getAngle());
	}
	void fill(Bullet *bullet)
	{
		//fill(bullet->position.x, bullet->position.y, bullet->offset.x, bullet->offset.y, ...);
	}
	void fill(int x, int y, int offsetX, int offsetY, GLfloat rotateAngle)
	{
		this->posX = x;
		this->posY = y;
		this->offsetX = offsetX;
		this->offsetY = offsetY;
		this->rotateAngle = rotateAngle;
		
	}
	void move(Grid *grid)
	{
		m3dLoadIdentity44(this->transformMatrix);
		float* pos = grid->getPosition(posX, posY, offsetX, offsetY);

		m3dTranslationMatrix44(this->transformMatrix, pos[0], pos[1], pos[2]);
		m3dRotationMatrix44(this->transformMatrix, rotateAngle, 0, 0, -1);
		
	}
	GridObject(int _id=0):id(_id),offsetX(0),offsetY(0),ZRotateSpeed(0),ZRotateX(0),ZRotateY(0),moveSpeed(0),posX(0), posY(0)
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
	std::vector<GridObject *> bullets;
	GridObject *player;
	GLShaderManager &shaderManager;
	Grid *grid;
public:
	void updateBullets(std::vector<Bullet*> _bullets);
	void updateCreeps(std::vector<mapItem*> creeps);
	void updatePlayer(mapItem* player);
	void addCreep(int id);
	void delModel(int id);
	void moveModel(int id, int x, int y, int offsetX, int offsetY, GLfloat rotateAngle);
	void Init();
	void Render(M3DMatrix44f modelViewMatrix);
	void Dispose();
	ModelsLayer(GLShaderManager*, Grid*);
	~ModelsLayer(void);
};

