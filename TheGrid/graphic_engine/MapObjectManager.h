#pragma once


class MapObjectManager
{
public:
	MapObjectManager()
	{
		areaSurfaceHeight = -1;
		areaSurfaceWidth = -1;
	}

	std::vector<MapObject*> mapObjects;
	std::vector<Bullet*> bullets;
	MapObject *player;

	int **areaSurfaceType;
	int **areaSurfaceFreedom;	// 2x gestsza siatka z informacja o zajeciu jej przez creepy/przeszkody/gracza

	void RescaleAreaSufrace(int newX,int newY);
	int areaSurfaceWidth,areaSurfaceHeight;

	void addCreep(int posX,int posY,int str);
	void shoot(int startX,int startY, int angle);
}