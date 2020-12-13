//

#include "GamePCH.h"
#include "CoreEngine.h"
#include "Includes/Statics.h"
#include "Core/ShooterGameEngine.h"

FShooterGameEngine::FShooterGameEngine()
{
	GameWindow = new FWindow((char*)"Game window", 200, 200, 800, 600, SDL_WINDOW_RESIZABLE);

	if (GetEngine() != nullptr || Engine != nullptr)
	{
		LOG_DEBUG("Engine pointer is valid. Adress: " << GetEngine());
		LOG_DEBUG("Engine pointer is valid. Adress: " << Engine);
	}
	else
	{
		LOG_DEBUG("Engine pointer is invalid. Adress: " << GetEngine());
		LOG_DEBUG("Engine pointer is invalid. Adress: " << Engine);
	}
}

FShooterGameEngine::~FShooterGameEngine()
{
	delete GameWindow;
}

void FShooterGameEngine::PreInit()
{
}

void FShooterGameEngine::Init()
{
	LOG_DEBUG("Game init");
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


