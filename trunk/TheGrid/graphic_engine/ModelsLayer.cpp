#include "StdAfx.h"
#include "ModelsLayer.h"


ModelsLayer::ModelsLayer(GLShaderManager *shaderManager):shaderManager(*shaderManager)
{

}
void ModelsLayer::moveModel(int id, int x, int y, int offsetX, int offsetY, GLfloat rotateAngle)
{
	for(int i=0; i<(int)models.size(); i++)
	{
		if(models[i]->id == id)
		{
			GridObject &model = *(models[i]);
			m3dLoadIdentity44(model.transformMatrix);
			


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
}

ModelsLayer::~ModelsLayer(void)
{
}
