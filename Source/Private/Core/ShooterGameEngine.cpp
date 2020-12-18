//

#include "GamePCH.h"
#include "CoreEngine.h"
#include "Includes/Statics.h"
#include "Core/ShooterGameEngine.h"

FShooterGameEngine::FShooterGameEngine()
	: GameWindow(nullptr)
{
}

FShooterGameEngine::~FShooterGameEngine()
{
	Engine->GetEngineRender()->RemoveWindow(GameWindow);
	
	delete GameWindow;
}

void FShooterGameEngine::PreInit()
{
}

void FShooterGameEngine::Init()
{
	LOG_DEBUG("Game init");

	GameWindow = new FWindow(TEXT("Game window"), 200, 200, 800, 600, SDL_WINDOW_RESIZABLE);

	Engine->GetEngineRender()->AddWindow(GameWindow);
}

void FShooterGameEngine::PostInit()
{
}

void FShooterGameEngine::Tick()
{
	//LOG_DEBUG("Game Tick" << " " << SDL_GetTicks());
}

void FShooterGameEngine::PostSecondTick()
{
	//LOG_DEBUG("Game Tick" << " " << GetFramesThisSecond());
}
