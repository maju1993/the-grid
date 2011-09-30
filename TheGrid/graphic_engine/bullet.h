#pragma once

// Klasa pocisku
class Bullet
{
public:
	// szybkosc pocisku
	static const int bulletSpeed = 10;
	// pozycja na mapie
	Point2D mapPos;
	// przesuniecie w pozycji
	Point2D offset;
	// pozycja docelowa
	Point2D destination;
	// offset pozycji docelowej
	Point2D destinationOffset;
	// podstawowy schemat konstruktora
	Bullet(int posX,int posY,int offsetX,int offsetY,int destX,int destY)
	{
		mapPos =  Point2D(posX,posY);
		offset = Point2D(offsetX,offsetY);
		destination = Point2D(destX,destY);
		destinationOffset = Point2D(0,0);
	}
	// skrocony konstruktor
	Bullet(Point2D pos,Point2D off,Point2D dest)
	{
		destination = dest;
		mapPos = pos;
		offset = off;
		destinationOffset = Point2D(0,0);
	}

// Wykonanie "kroku", tj podstawowa mechanika
// true == wyszlo poza zakres
// false = siedzi w zakresie, ma dalej istniec
bool doStep();

};