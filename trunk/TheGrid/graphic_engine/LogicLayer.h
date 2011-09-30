#pragma once

#define GRID_START_W 20
#define GRID_START_H 20

class LogicLayer
{
private:
	LogicLayer()
    {	
		for (int i=0;i<256;i++)
			keyStates[i] = false;

		//Bullet::bulletSpeed = 10;

		grid = new int*[GRID_START_W];
		for (int i=0;i<GRID_START_W;i++)
			grid[i] = new int[GRID_START_H];
		gridWidth = GRID_START_W;
		gridHeight = GRID_START_H;
		for (int i=0;i<gridWidth;i++)
			for (int j=0;j<gridHeight;j++)
				grid[i][j] = 0;

		player = new mapItem(MapItemTypePlayer,10,10,5);//gridWidth/2,gridHeight/2,2); // 2 "wirtualne pola" na 1/3s
		creepRespawnCounter = 0;
		creepHardcore = 0;
		graphicsShouldRefreshBullets = true;
		graphicsShouldRefreshCreeps = true;
		graphicsShouldRefreshPlayer = true;

		addCreep(Point2D(1,1),1);
		addCreep(Point2D(5,1),2);
		addCreep(Point2D(1,10),1);
		
		points = 0;
		gameover = false;
    }
public:
	bool keyStates[256]; // don't ask
	int creepRespawnCounter;
	int creepHardcore;

	int points;

	bool gameover;

	mapItem* player;
	std::vector<mapItem*> creepy;
	std::vector<Bullet*> bullets;
	int **grid; // kolory !
	int gridWidth,gridHeight; // parametry grida !

	bool graphicsShouldRefreshPlayer;
	bool graphicsShouldRefreshCreeps;
	bool graphicsShouldRefreshBullets;

	void MovePlayer(Point2D newPos); // wersja z wspolrzednymi
	void MovePlayer(float x,float y); // wersja relatywna
	void TeleportPlayer(Point2D newPos);

	void addCreep(Point2D pos,int speed);

	
	void siCreepFollowPlayer();

	void moveBullets();

	// funkcja spawnowania

	// funkcja lotu bulletow

	// funkcja
	void doLogic(); 
	void doSteering();
	// sing
	static LogicLayer* getI()
	{
		static LogicLayer tmp;
		return &tmp;
	}

	void deinit();

	void shot();
};