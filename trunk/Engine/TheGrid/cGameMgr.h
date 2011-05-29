
/*
	Singleton - zarz¹dca ca³ej gry
*/
class cGameMgr
{
private:
	// zmienne "globalne"
public:
	static cGameMgr* get();				// metoda dostêpowa

	// metody g³ówne

	void initGraphics();			// inicjalizacja systemów graficznych openGL
	void initGameSystems();			// inicjalizacja pozosta³ych podsystemów


	bool RunGameLoop();				// Uruchomienie g³ównej pêtli gry


	void deinitGameSystems();		// deinicjalizacja systemów
	void deinitGraphics();			// deinicjalizacja grafiki	

	// metody dostepowe
};