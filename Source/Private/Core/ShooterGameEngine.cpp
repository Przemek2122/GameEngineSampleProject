//

#include "GamePCH.h"
#include "CoreEngine.h"
#include "Core/ShooterGameEngine.h"
#include "Renderer/Window.h"

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
