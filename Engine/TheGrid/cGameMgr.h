
/*
	Singleton - zarz�dca ca�ej gry
*/
class cGameMgr
{
private:
	// zmienne "globalne"
public:
	static cGameMgr* get();				// metoda dost�powa

	// metody g��wne

	void initGraphics();			// inicjalizacja system�w graficznych openGL
	void initGameSystems();			// inicjalizacja pozosta�ych podsystem�w


	bool RunGameLoop();				// Uruchomienie g��wnej p�tli gry


	void deinitGameSystems();		// deinicjalizacja system�w
	void deinitGraphics();			// deinicjalizacja grafiki	

	// metody dostepowe
};