#pragma once



class LogicLayer
{
private:
	LogicLayer()
    {
			
    }
public:
	mapItem* player;
	std::vector<mapItem*> creepy;
	std::vector<Bullet*> bullets;
	int **plansza; // kolory !

	bool graphicsShouldRefreshPlayer;
	bool graphicsShouldRefreshCreeps;
	bool graphicsShouldRefreshBullets;

	void MovePlayer(Point2D newPos);
	void TeleportPlayer(Point2D newPos);

	void addCreep(Point2D pos,int speed);


	// funkcja
	void doLogic(); 

	// sing

	static LogicLayer* getI()
	{
		static LogicLayer tmp;
		return &tmp;
	}

};