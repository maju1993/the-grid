#include "StdAfx.h"
#include "ModelsLayer.h"


ModelsLayer::ModelsLayer(GLShaderManager *shaderManager, Grid *_grid):shaderManager(*shaderManager),grid(_grid)
{
	player = 0;
}
//dep
void ModelsLayer::addCreep(int id)
{
	GridObject *creep = new GridObject(id); 
	//wczytywane z tablicy informacje o pozycji creepa


	models.push_back(creep);
}
//dep
void ModelsLayer::delModel(int id)
{	
	for(std::vector<GridObject*>::iterator it = models.begin(); it<models.end(); it++)
	{
		if((*it)->id == id)
		{
			delete (*it);
			models.erase(it);
		}
	}
}
void ModelsLayer::updateBullets(std::vector<Bullet*> _bullets)
{
	for(int i=0; i<(int)bullets.size(); i++)
		delete bullets[i];
	bullets.clear();

	GridObject *bullet;
	for(int i=0; i<(int)_bullets.size(); i++)
	{
		bullet = new GridObject();
		bullet->fill(_bullets[i]);
		bullet->move(grid);
		
		bullet->setBatch(new GLBatch());
		DrawHelper::drawTriangle(*bullet->batch, 0, 0, 1, 1, *grid);
		
		bullets.push_back(bullet);
	}
}
void ModelsLayer::updateCreeps(std::vector<mapItem*> creeps)
{
	for(int i=0; i<(int)models.size(); i++)
		delete models[i];
	models.clear();

	GridObject *creep;
	for(int i=0; i<(int)creeps.size(); i++)
	{
		creep = new GridObject();
		creep->fill(creeps[i]);
		creep->move(grid);
		
		creep->setBatch(new GLBatch());
		DrawHelper::drawTriangle(*creep->batch, 1, 0, 0, 1, *grid);
		
		models.push_back(creep);
	}
}
void ModelsLayer::updatePlayer(mapItem* _player)
{
	delete this->player;
	player = new GridObject();
	player->fill(_player);
	player->move(this->grid);

	player->setBatch(new GLBatch());
	DrawHelper::drawTriangle(*player->batch, 0, 0, 0, 1, *grid);
}
void ModelsLayer::moveModel(int id, int x, int y, int offsetX, int offsetY, GLfloat rotateAngle)
{
	for(int i=0; i<(int)models.size(); i++)
	{
		if(models[i]->id == id)
		{
			GridObject &model = *(models[i]);
			model.fill(x, y, offsetX, offsetY, rotateAngle);
			model.move(grid);
		}
	}
}
void ModelsLayer::Init()
{
}
void ModelsLayer::Render(M3DMatrix44f modelViewMatrix)
{
	M3DMatrix44f productMatrix;
	if(LogicLayer::getI()->graphicsShouldRefreshCreeps == true)
	{
		this->updateCreeps(LogicLayer::getI()->creepy);
	}
	if(LogicLayer::getI()->graphicsShouldRefreshPlayer == true)
	{
		this->updatePlayer(LogicLayer::getI()->player);
	}
	if(LogicLayer::getI()->graphicsShouldRefreshBullets == true)
	{
		this->updateBullets(LogicLayer::getI()->bullets);
	}


	for(std::vector<GridObject*>::iterator it = models.begin(); it<models.end(); it++)
	{
		m3dMatrixMultiply44(productMatrix, modelViewMatrix, (*it)->transformMatrix);
		shaderManager.UseStockShader(GLT_SHADER_SHADED, productMatrix);
		(*it)->batch->Draw();
	}
	for(std::vector<GridObject*>::iterator it = bullets.begin(); it<bullets.end(); it++)
	{
		m3dMatrixMultiply44(productMatrix, modelViewMatrix, (*it)->transformMatrix);
		shaderManager.UseStockShader(GLT_SHADER_SHADED, productMatrix);
		(*it)->batch->Draw();
	}
	m3dMatrixMultiply44(productMatrix, modelViewMatrix, player->transformMatrix);
	shaderManager.UseStockShader(GLT_SHADER_SHADED, productMatrix);
	player->batch->Draw();
}
void ModelsLayer::Dispose()
{	
	for(int i=0; i<(int)bullets.size(); i++)
		delete bullets[i];
	bullets.clear();
	for(int i=0; i<(int)models.size(); i++)
		delete models[i];
	models.clear();
	delete player;
}

ModelsLayer::~ModelsLayer(void)
{
}
