#pragma once

enum MapObjectTypes{
	MapObjectTypeCreep = 0,
	MapObjectTypePlayer = 1,
	MapObjectTypeBullet = 2
};

class MapObject
{
public:
	int mapX,mapY;
	int offsetX,offsetY;
	int angleZ; // obrot wokol osi
	int modelID;
	MapObjectTypes typeID;
	int speed;

	// uniwersalny tworca
	static MapObject* createObject(MapObjectTypes type,int x,int y,int speed, int angle);
};

class Player : public MapObject
{
public:
	int hp;
	int maxHp;
	int strength;
	
	// sterowanie?
};

class Creep : public MapObject
{
public:
	int hp;
	int maxHp;
	int strength;
	int nextX,nextY;
};

class Bullet : public MapObject
{
public:
	int strength;
};