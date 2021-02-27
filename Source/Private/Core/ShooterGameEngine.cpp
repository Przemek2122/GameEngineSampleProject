// Created by Przemys³aw Wiewióra 2020

#include "GamePCH.h"
#include "Core/ShooterGameEngine.h"

#include "Renderer/Widgets/Samples/ButtonWidget.h"
#include "Renderer/Widgets/Samples/MouseSparkWidget.h"
#include "Renderer/Widgets/Samples/TextWidget.h"

FShooterGameEngine::FShooterGameEngine()
	: GameWindow(nullptr)
{
}

FShooterGameEngine::~FShooterGameEngine()
{
	Engine->GetEngineRender()->RemoveWindow(GameWindow);
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
		FMouseSparkWidget* MouseSparkWidget = GameWindow->GetWidgetManager()->CreateWidget<FMouseSparkWidget>("TestSparkWidget");
		FButtonWidget* ButtonWidget = GameWindow->GetWidgetManager()->CreateWidget<FButtonWidget>("TestButton");
		//ButtonWidget->SetWidgetLocationRelative({50, 60});
		FTextWidget* TextWidget = ButtonWidget->CreateWidget<FTextWidget>("TextWidget");
		TextWidget->SetText("Test text");
	}
}

void FShooterGameEngine::PostInit()
{
}

void FShooterGameEngine::Tick()
{
}

void FShooterGameEngine::PostSecondTick()
{
	// Test print ticks per second
	//LOG_DEBUG("Game Tick" << " " << GetFramesThisSecond());
}
