#pragma once

// Typy elementow na mapie
enum MapItemType
{
	MapItemTypeCreep = 0,
	MapItemTypePlayer = 1
};

// Wektor 2D
struct Point2D
{
	// wspolrzedne wektora
	int x,y;
	// konstruktor
	Point2D(int a,int b)
	{
		x = a;
		y = b;
	}

	// standardowy konstruktor
	Point2D()
	{
		x = y = 0;
	}
};

// klasa obiektu na mapie
class mapItem
{
private:
	// pozycja na mapie
	Point2D mapPos;		
	// offset pozycji na mapie
	Point2D offset;	
	// Offset docelowego punktu na mapie
	Point2D destinationOffset; 
	// szybkosc poruszania
	int speed;	
public:
	// poziom zycia
	int hp;
	// punkt docelowy
	Point2D destination;
	// kat obrotu wzgledem osi z
	double angle;
	// typ obiektu
	MapItemType type;	
	// standardowy konstruktor :)
	mapItem(MapItemType typ, int posX,int posY, int speed);
	// pobieranie pozycji
	Point2D getPosition();
	// pobieranie offsetu
	Point2D getOffset();
	// pobieranie wektora kata obrotu
	Point2D getAngleVec();
	// wykonanie 'kroku', tj ruchu jesli jest mozliwy
	bool doStep(); 
	// oznaczenie punktu jako docelowego i sekwencyjny ruch w kolejnych wywolaniach
	void moveTo(int posX,int posY,int destoX=0,int destoY=0);
	// Przeniesienie do pozycji
	void teleportTo(int x,int y);
	// Przeniesienie o podany offset
	void teleportBy(int offsetx,int offsety);
	// pobranie szybkosci
	inline int getSpeed(){return speed;}
};