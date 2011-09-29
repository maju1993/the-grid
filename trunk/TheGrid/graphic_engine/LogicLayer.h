#pragma once



class LogicLayer
{
public:
	mapItem* player;
	std::vector<mapItem*> creepy;
	std::vector<Bullet*> bullets;
	int **plansza; // kolory !


	void MovePlayer(Point2D newPos);
	void TeleportPlayer(Point2D newPos);

	void addCreep(Point2D pos,int speed);
}