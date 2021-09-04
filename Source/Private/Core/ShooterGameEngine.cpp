// Created by Przemys³aw Wiewióra 2020

#include "GamePCH.h"
#include "Core/ShooterGameEngine.h"

#include "Renderer/Widgets/Samples/ButtonWidget.h"
#include "Renderer/Widgets/Samples/MouseSparkWidget.h"
#include "Renderer/Widgets/Samples/TextWidget.h"
#include "Renderer/Widgets/Samples/VerticalBoxWidget.h"

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
		FMouseSparkWidget* MouseSparkWidget = GameWindow->GetWidgetManager()->CreateWidget<FMouseSparkWidget>("TestSparkWidget", 100);

		FButtonWidget* ButtonWidget = GameWindow->GetWidgetManager()->CreateWidget<FButtonWidget>("TestButton");
		FTextWidget* TextWidget = ButtonWidget->CreateWidget<FTextWidget>("TextWidget");
		TextWidget->SetText("Test button 1_123456789, 2_123456789");
		ButtonWidget->AddChild(TextWidget);

		FButtonWidget* ButtonWidget2 = GameWindow->GetWidgetManager()->CreateWidget<FButtonWidget>("TestButton2");
		

		FVerticalBoxWidget* VerticalBoxWidget = GameWindow->GetWidgetManager()->CreateWidget<FVerticalBoxWidget>("TestVerticalBoxWidget");
		VerticalBoxWidget->SetWidgetLocationRelative({0, 0});
		VerticalBoxWidget->SetWidgetSize({200, 200}, false);
		VerticalBoxWidget->AddChild(ButtonWidget);
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
