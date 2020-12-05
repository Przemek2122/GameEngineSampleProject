//

#include "GamePCH.h"
#include "Engine.PCH.h"
#include "..\..\Public\Core\ShooterGameEngine.h"
#include <Render/Window.h>

FShooterGameEngine::FShooterGameEngine()
{
	GameWindow = new FWindow((char*)"Game window", 200, 200, 800, 600, SDL_WINDOW_RESIZABLE);
}

FShooterGameEngine::~FShooterGameEngine()
{
	delete GameWindow;
}

void FShooterGameEngine::GameInit()
{

}
