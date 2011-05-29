#include "cGameMgr.h"
#include <iostream>


int main()
{
	// ...
	cGameMgr *tmp = cGameMgr::get();

	tmp->initGraphics();
	tmp->initGameSystems();

	// game : D
	while ( tmp->RunGameLoop() ) ;

	tmp->deinitGameSystems();
	tmp->deinitGraphics();


	using namespace std;
	cout << "Jestem zajebisty : D "<<endl;
	system("pause");
	return 0;
}