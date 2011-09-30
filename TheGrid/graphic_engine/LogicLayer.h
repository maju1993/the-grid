#pragma once

#define GRID_START_W 20 /* startowa szerokosc */
#define GRID_START_H 20 /* startowa wysokosc */

// Klasa - singleton - zarzadzajaca warstwa danych (mechanika i sterowanie)
class LogicLayer
{
private:
	// konstruktor inicjalizujacy 
	LogicLayer()
    {	
		for (int i=0;i<256;i++)
			keyStates[i] = false;
		showFPSinfo = false;
		//Bullet::bulletSpeed = 10;

		grid = new int*[GRID_START_W];
		for (int i=0;i<GRID_START_W;i++)
			grid[i] = new int[GRID_START_H];
		gridWidth = GRID_START_W;
		gridHeight = GRID_START_H;
		for (int i=0;i<gridWidth;i++)
			for (int j=0;j<gridHeight;j++)
				grid[i][j] = 0;

		player = new mapItem(MapItemTypePlayer,10,10,5);
		creepRespawnCounter = 0;
		creepHardcore = 0;
		// wymuszenie startowego odswiezenia pozycji
		graphicsShouldRefreshBullets = true;
		graphicsShouldRefreshCreeps = true;
		graphicsShouldRefreshPlayer = true;
		// startowe dane
		addCreep(Point2D(10,1),1);
		addCreep(Point2D(1,19),1);
		addCreep(Point2D(18,19),1);
		// punkty
		points = 0;
		// nie, jeszcze nie konczymy ;]
		gameover = false;
    }
public:
	// tablica stanow klawiszy klawiatury
	bool keyStates[256]; 
	// tablica dla znakow specjalnych
	bool specialKeystates[256];
	// licznik ilosci przejsc funkcji doLogic od ostatniego respawnu creepa
	int creepRespawnCounter;
	// 'wzmacniacz wrazen' - z kazdym dodanym creepem licznik zwieksza sie, zmniejszajac oczekiwanie na kolejny respawn. Limitowany na poziomie 20.
	int creepHardcore;
	// punkty zdobyte przez gracza
	int points;
	// kontrola konca gry
	bool gameover;
	// instancja gracza
	mapItem* player;
	// creepy
	std::vector<mapItem*> creepy;
	// pociski
	std::vector<Bullet*> bullets;
	// THE GRID, czyli plansza - int poniewaz liczylismy na dodanie specjalnych wlasciwosci zaleznie od pola
	int **grid; 
	// parametry grida
	int gridWidth,gridHeight;
	// informacja dla silnika graficznego by odswiezyl model i pozycje gracza
	bool graphicsShouldRefreshPlayer;
	// tutaj informacja by odswiezyc liste creepow
	bool graphicsShouldRefreshCreeps;
	// i pociskow
	bool graphicsShouldRefreshBullets;
	// czy pokazywac informacje o ilosci fps?
	bool showFPSinfo;
	// Funkcja okreslania celu dla gracza
	void MovePlayer(Point2D newPos); 
	// Funkcja przesuwajaca gracza wzgledem jego aktualnej pozycji
	void MovePlayer(float x,float y);
	// Funkcja przenoszaca gracza bezposrednio na miejsce docelowe
	void TeleportPlayer(Point2D newPos);
	// Funkcja spawnujaca creepa w podanej pozycji
	void addCreep(Point2D pos,int speed);
	// Funkcja "sztucznej inteligencji", czyli w tym momencie podazania za graczem po skracaczu ukladu wspolrzednych	
	void siCreepFollowPlayer();
	// Funkcja powodujaca aktualizacje pozycji pociskow
	void moveBullets();
	// Glowna funkcja modulu - wywoluje pozostale i odpowiada za cala logike	
	void doLogic(); 
	// Funkcja odpowiadajaca za sterowanie
	void doSteering();
	// Pobieranie instancji singletona
	static LogicLayer* getI()
	{
		static LogicLayer tmp;
		return &tmp;
	}
	// Funkcja deinicjujaca
	void deinit();
	// funkcja strzalu
	void shot();
};