#include "cGameMgr.h"

cGameMgr* cGameMgr::get()
{
	static cGameMgr mgr;
	return &mgr;
}

void cGameMgr::initGraphics()
{
}

void cGameMgr::deinitGraphics()
{
}

void cGameMgr::initGameSystems()
{
}

void cGameMgr::deinitGameSystems()
{
}

bool cGameMgr::RunGameLoop()
{
	return false;
}