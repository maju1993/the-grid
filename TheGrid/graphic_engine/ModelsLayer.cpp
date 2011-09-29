#include "StdAfx.h"
#include "ModelsLayer.h"


ModelsLayer::ModelsLayer(GLShaderManager *shaderManager, Grid *_grid):shaderManager(*shaderManager),grid(_grid)
{

}
void ModelsLayer::addCreep(int id)
{
	GridObject *creep = new GridObject(id); 
	//wczytywane z tablicy informacje o pozycji creepa


	models.push_back(creep);
}

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
void ModelsLayer::moveModel(int id, int x, int y, int offsetX, int offsetY, GLfloat rotateAngle)
{
	for(int i=0; i<(int)models.size(); i++)
	{
		if(models[i]->id == id)
		{
			GridObject &model = *(models[i]);
			m3dLoadIdentity44(model.transformMatrix);
			float* pos = grid->getPosition(x, y, offsetX, offsetY);

			m3dTranslationMatrix44(model.transformMatrix, pos[0], pos[1], pos[2]);
			m3dRotationMatrix44(model.transformMatrix, rotateAngle, 0, 0, -1);

		}
	}
}
void ModelsLayer::Init()
{
}
void ModelsLayer::Render(M3DMatrix44f modelViewMatrix)
{
	M3DMatrix44f productMatrix;

	for(std::vector<GridObject*>::iterator it = models.begin(); it<models.end(); it++)
	{
		m3dMatrixMultiply44(productMatrix, modelViewMatrix, (*it)->transformMatrix);
		shaderManager.UseStockShader(GLT_SHADER_SHADED, productMatrix);
		(*it)->batch->Draw();
	}
}
void ModelsLayer::Dispose()
{
	for(int i=0; i<(int)models.size(); i++)
	{
		delete models[i];
	}
}

ModelsLayer::~ModelsLayer(void)
{
}
