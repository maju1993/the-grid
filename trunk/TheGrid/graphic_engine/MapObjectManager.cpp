#include "stdafx.h"
#include "MapObjectManager.h"
#include "mapObject.h"

void MapObjectManager::RescaleAreaSufrace(int newX,int newY)
{
	if ((areaSurfaceHeight > 0)&&(areaSurfaceWidth>0))
	{
		for (int i=0;i<areaSurfaceWidth;i++)
			delete [] areaSurfaceType[i];
		delete [] *areaSurfaceType;
	}
	
	areaSurfaceType = new int *[newX];	
    for(int i=0; i<newX; i++)
	{
		areaSurfaceType[i] = new int [newY];
	}

	for (int i=0;i<newX;i++)
		for (int j=0;j<newY;j++)
			areaSurfaceType[i][j] = 0;
	areaSurfaceWidth = newX;
	areaSurfaceHeight = newY;
}