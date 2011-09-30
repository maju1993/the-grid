#pragma once
#include "stdafx.h"
#include "ILayer.h"
#include "DrawHelper.h"

//Obiekt z informacjami potrzebnymi do wyrenedrwania go na siatce
class GridObject
{
public:
	int id;
	//pozycja
	int posX, posY;
	//offset <-10; 10>
	int offsetX, offsetY;
	//wektor obrotu
	GLfloat ZRotateX, ZRotateY;
	//kat obrotu
	GLfloat rotateAngle;
	//kontener z wektorami do renderowania
	GLBatch* batch;
	//macierz transformacji
	M3DMatrix44f transformMatrix;
	void setBatch(GLBatch *batch)
	{
		this->batch = batch;
	}
	//wypelnianie obiektu 
	void fill(mapItem *item)
	{
		if(item->type == MapItemType::MapItemTypeCreep)
		{
			fill(item->getPosition().x, item->getPosition().y, item->getOffset().x, item->getOffset().y, item->getAngleVec().x, item->getAngleVec().y);
		}else if(item->type == MapItemType::MapItemTypePlayer)
		{
			float rotateAngle = float(item->angle);
			rotateAngle = (int)rotateAngle % 360;
			fill(item->getPosition().x, item->getPosition().y, item->getOffset().x, item->getOffset().y, m3dDegToRad(rotateAngle) );
		}
	}
	//wypelnianie obiektu pociskiem
	void fill(Bullet *bullet)
	{
		fill(bullet->mapPos.x, bullet->mapPos.y, bullet->offset.x, bullet->offset.y, 0, 0);
	}
	//wypelnianie obiektu customowe
	void fill(int x, int y, int offsetX, int offsetY, GLfloat rotateVecX, GLfloat rotateVecY)
	{
		double rotateAng;
		if(rotateVecX == 0 && rotateVecY == 0)
		{
			rotateAng = this->rotateAngle;
		}
		else
		{
			M3DVector3f rotateVec;
			m3dLoadVector3(rotateVec, rotateVecX, -rotateVecY, 0);
			m3dNormalizeVector3(rotateVec);
			M3DVector3f os;
			m3dLoadVector3(os, 0, 1, 0);
			m3dNormalizeVector3(os);
			double m = m3dRadToDeg(m3dGetAngleBetweenVectors3(rotateVec, os));
			if(m3dGetVectorX(rotateVec) > 0)
				if(m3dGetVectorY(rotateVec) > 0)
				{
					rotateAng = m3dGetAngleBetweenVectors3(rotateVec, os) ;
					rotateAng += m3dDegToRad(360) - (2 * rotateAng);
				}
				else
				{
					rotateAng = m3dGetAngleBetweenVectors3(rotateVec, os);
					rotateAng += (2 * (m3dDegToRad(180)-rotateAng));
				}
			else
				rotateAng = m3dGetAngleBetweenVectors3(rotateVec, os);
		}
		double r = m3dRadToDeg(rotateAng);
		fill(x, y, offsetX, offsetY, rotateAng);
	}
	//wypelnianie obiektu customowe
	void fill(int x, int y, int offsetX, int offsetY, double rotateAngle)
	{
		this->posX = x;
		this->posY = y;
		this->offsetX = offsetX;
		this->offsetY = offsetY;
		this->ZRotateX = ZRotateX;
		this->ZRotateY = ZRotateY;
		this->rotateAngle = rotateAngle;
	}
	//uruchomienie przesuniecia obiektu z danymi wpisanymi wczeœniej
	void move(Grid *grid)
	{
		M3DMatrix44f mat;
		m3dLoadIdentity44(this->transformMatrix);
		float* pos = grid->getPosition(posX, posY, offsetX, offsetY);

		m3dTranslationMatrix44(this->transformMatrix, pos[0], pos[1], pos[2]);
		m3dLoadIdentity44(mat);
		m3dRotationMatrix44(mat, rotateAngle, 0, 0, 1);
		m3dMatrixMultiply44(this->transformMatrix, this->transformMatrix, mat);
		
	}
	GridObject(int _id=0):id(_id),offsetX(0),offsetY(0),ZRotateX(0),ZRotateY(0),posX(0), posY(0),rotateAngle(0)
	{
		m3dLoadIdentity44(transformMatrix);
		batch = 0;
	}
	~GridObject()
	{
		delete batch;
	}
};
//Klasa obslugujaca warstwê odpowiedzialn¹ za obs³ugê modeli ruchomych (player, enemy, bullet)
class ModelsLayer :
	public ILayer
{
private:
	//lista wrogow
	std::vector<GridObject *> models;
	//lista pociskow
	std::vector<GridObject *> bullets;
	//gracz
	GridObject *player;
	//shadery
	GLShaderManager &shaderManager;
	//informacja o siatce
	Grid *grid;
public:
	//aktualizacja polozenia i obrotu pocisków pobierana z wektora logiki
	void updateBullets(std::vector<Bullet*> _bullets);
	//aktualizacja polozenia i obrotu creepow pobierana z wektora logiki
	void updateCreeps(std::vector<mapItem*> creeps);
	//aktualizacja polozenia i obrotu playera pobierana z logiki
	void updatePlayer(mapItem* player);
	//przestarzaly
	void addCreep(int id);
	//przestarza³y
	void delModel(int id);
	//przestarza³y
	void moveModel(int id, int x, int y, int offsetX, int offsetY, GLfloat rotateVecX, GLfloat rotateVecY);
	void Init();
	void Render(M3DMatrix44f modelViewMatrix);
	void Dispose();
	ModelsLayer(GLShaderManager*, Grid*);
	~ModelsLayer(void);
};

