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
	// Shader Manager
	GLShaderManager		shaderManager;		
	// Modelview Matrix
	GLMatrixStack	modelViewMatrix;		
	// Projection Matrix
	GLMatrixStack	projectionMatrix;		
	// View Frustum
	GLFrustum	viewFrustum;			
	// Geometry Transform Pipeline
	GLGeometryTransform	transformPipeline;		
	// Camera frame
	GLFrame	cameraFrame;			

  static GraphicEng *instance;
	GraphicEng()
    {
			grid = new Grid(-1, 1, -1, 1, -0.001f, 0.0f);

    }
public:

	//warstwa najnizsza
	GroundGridLayer *groundGrid;
	//warstwa modeli (player, creepy, pociski)
	ModelsLayer *modelsLayer;
	//wszystkie warstwy
	std::vector<ILayer*> layers;
	//informacje o siatce
	Grid *grid;

	//singleton
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
  }

	//////////////////////////////////////////////////////////////////////
	// funkcja generuj¹ca scenê 3D
	//////////////////////////////////////////////////////////////////////
	void DisplayScene();
	//////////////////////////////////////////////////////////////////////
	// inicjalizacja sta³ych elementów maszyny stanu OpenGL
	//////////////////////////////////////////////////////////////////////
	void InitScene();
	//////////////////////////////////////////////////////////////////////
	// zmiana wielkoœci okna
	//////////////////////////////////////////////////////////////////////
	void Reshape( int width, int height );
	void DeleteScene();
};
#endif