//

#include "GamePCH.h"
#include "CoreEngine.h"
#include "Core/ShooterGameEngine.h"

FShooterGameEngine::FShooterGameEngine()
{
	GameWindow = new FWindow((char*)"Game window", 200, 200, 800, 600, SDL_WINDOW_RESIZABLE);

	if (Engine != nullptr)
	{
		LOG_DEBUG("Engine pointer is valid. Adress: " << 44);
	}
	else
	{
		LOG_INFO("Info test");
		LOG_ERROR("Error test");
		LOG_DEBUG("Engine pointer is invalid. Adress: " << 44);
		LOG_WARN("£arn");
	}
}

FShooterGameEngine::~FShooterGameEngine()
{
	delete GameWindow;
}

void FShooterGameEngine::GameInit()
{

}
