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
		if(item->type == MapItemType::MapItemTypeCreep)
		{
			fill(item->getPosition().x, item->getPosition().y, item->getOffset().x, item->getOffset().y, item->getAngleVec().x, item->getAngleVec().y);
		}else if(item->type == MapItemType::MapItemTypePlayer)
		{
			fill(item->getPosition().x, item->getPosition().y, item->getOffset().x, item->getOffset().y, item->angle);
		}
	}

	void fill(Bullet *bullet)
	{
		//fill(bullet->position.x, bullet->position.y, bullet->offset.x, bullet->offset.y, bullet-);
	}
	void fill(int x, int y, int offsetX, int offsetY, GLfloat rotateVecX, GLfloat rotateVecY)
	{
		M3DVector3f rotateVec;
		m3dLoadVector3(rotateVec, rotateVecX, -rotateVecY, 0);
		m3dNormalizeVector3(rotateVec);
		M3DVector3f os;
		m3dLoadVector3(os, 0, 1, 0);
		m3dNormalizeVector3(os);
		if(m3dGetVectorX(rotateVec) > 0)
			this->rotateAngle = m3dGetAngleBetweenVectors3(rotateVec, os) + m3dDegToRad(180) ;
		else
			this->rotateAngle = m3dGetAngleBetweenVectors3(rotateVec, os);
		double r = m3dRadToDeg(this->rotateAngle);
		fill(x, y, offsetX, offsetY, r);
	}
	void fill(int x, int y, int offsetX, int offsetY, int rotateAngle)
	{
		this->posX = x;
		this->posY = y;
		this->offsetX = offsetX;
		this->offsetY = offsetY;
		this->ZRotateX = ZRotateX;
		this->ZRotateY = ZRotateY;
		this->rotateAngle = rotateAngle;
	}
	void move(Grid *grid)
	{
		M3DMatrix44f mat;
		m3dLoadIdentity44(this->transformMatrix);
		float* pos = grid->getPosition(posX, posY, offsetX, offsetY);

		m3dTranslationMatrix44(this->transformMatrix, pos[0], pos[1], pos[2]);
		m3dLoadIdentity44(mat);
		m3dRotationMatrix44(mat, rotateAngle, 0, 0, -1);
		m3dMatrixMultiply44(this->transformMatrix, this->transformMatrix, mat);
		
	}
	GridObject(int _id=0):id(_id),offsetX(0),offsetY(0),ZRotateSpeed(0),ZRotateX(0),ZRotateY(0),moveSpeed(0),posX(0), posY(0),rotateAngle(0)
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
	//aktualizacja polozenia i obrotu pocisków pobierana z wektora logiki
	void updateBullets(std::vector<Bullet*> _bullets);
	//aktualizacja polozenia i obrotu creepow pobierana z wektora logiki
	void updateCreeps(std::vector<mapItem*> creeps);
	//aktualizacja polozenia i obrotu playera pobierana z logiki
	void updatePlayer(mapItem* player);
	void addCreep(int id);
	void delModel(int id);
	void moveModel(int id, int x, int y, int offsetX, int offsetY, GLfloat rotateVecX, GLfloat rotateVecY);
	void Init();
	void Render(M3DMatrix44f modelViewMatrix);
	void Dispose();
	ModelsLayer(GLShaderManager*, Grid*);
	~ModelsLayer(void);
};

