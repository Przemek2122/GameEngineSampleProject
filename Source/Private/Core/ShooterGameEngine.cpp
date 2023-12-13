// Created by Przemys³aw Wiewióra 2020-2022 https://github.com/Przemek2122/GameEngine

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

void FShooterGameEngine::PreInit()
{
}

void FShooterGameEngine::Init()
{
	LOG_DEBUG("Game init");

	GameWindow = Engine->GetEngineRender()->CreateWindow<FWindow>(TEXT_CHAR("Game window"), 200, 200, 800, 600);
	if (GameWindow != nullptr)
	{
		MakeWidgets();

		MakeEntities();
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

void FShooterGameEngine::MakeWidgets()
{
	// Add sample 'FMouseSparkWidget' widget
	GameWindow->GetWidgetManager()->CreateWidget<FMouseSparkWidget>("TestSparkWidget", 100);

	FVerticalBoxWidget* VerticalBoxWidget = GameWindow->GetWidgetManager()->CreateWidget<FVerticalBoxWidget>("TestVerticalBoxWidget");
	VerticalBoxWidget->SetWidgetLocation({200, 200});
	VerticalBoxWidget->SetWidgetSize({400, 400});

	FButtonWidget* MainButtonWidget = VerticalBoxWidget->CreateWidget<FButtonWidget>("TestButton");
	FTextWidget* FirstTextWidget = MainButtonWidget->CreateWidget<FTextWidget>("TextWidget");
	//MainButtonWidget->SetWidgetSize({ 250, 100 });
	FButtonWidget* SecondButtonWidget = MainButtonWidget->CreateWidget<FButtonWidget>("TestButton");
	FTextWidget* TextWidget = SecondButtonWidget->CreateWidget<FTextWidget>("TextWidget");

	FirstTextWidget->SetText("Test button m");
	//TextWidget->SET_TEXT_ADV("Test button " << "s");
}

void FShooterGameEngine::MakeEntities()
{
	FEntityManager* EntityManager = GameWindow->GetEntityManager();
}
