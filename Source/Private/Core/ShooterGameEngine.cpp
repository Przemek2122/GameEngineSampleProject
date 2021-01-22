//

#include "GamePCH.h"
#include "Core/ShooterGameEngine.h"
#include "Renderer/Widgets/Samples/MouseSparkWidget.h"

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

	GameWindow = new FWindow(TEXT("Game window"), 200, 200, 800, 600);
	if (GameWindow != nullptr)
	{
		// Register window to engine so it's updated
		Engine->GetEngineRender()->AddWindow(GameWindow);

		// Add sample widget
		GameWindow->GetWidgetManager()->CreateWidget<FMouseSparkWidget>("TestSparkWidget");
	}
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
	LOG_DEBUG("Game Tick" << " " << GetFramesThisSecond());
}
