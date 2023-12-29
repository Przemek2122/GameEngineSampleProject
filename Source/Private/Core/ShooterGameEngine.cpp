// Created by Przemysław Wiewióra 2020-2022 https://github.com/Przemek2122/GameEngine

#include "GamePCH.h"
#include "Core/ShooterGameEngine.h"

#include "Renderer/Widgets/Samples/ButtonWidget.h"
#include "Renderer/Widgets/Samples/MouseSparkWidget.h"
#include "Renderer/Widgets/Samples/TextWidget.h"
#include "Renderer/Widgets/Samples/VerticalBoxWidget.h"

FShooterGameEngine::FShooterGameEngine()
	: GameWindow(nullptr)
	, TextFPSWidget(nullptr)
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
	if (TextFPSWidget != nullptr)
	{
		TextFPSWidget->SetText(std::to_string(GetFramesThisSecond()));
	}
}

void FShooterGameEngine::MakeWidgets()
{
	// Add sample 'FMouseSparkWidget' widget
	FWidgetManager* GameWindowWidgetManager = GameWindow->GetWidgetManager();

	GameWindowWidgetManager->CreateWidget<FMouseSparkWidget>("TestSparkWidget", 100);
	TextFPSWidget = GameWindowWidgetManager->CreateWidget<FTextWidget>("TextFPS");
	TextFPSWidget->SetText("FPS");
	TextFPSWidget->SetAnchor(EAnchor::RightTop);

	FVerticalBoxWidget* VerticalBoxWidget = GameWindow->GetWidgetManager()->CreateWidget<FVerticalBoxWidget>("TestVerticalBoxWidget");
	VerticalBoxWidget->SetScaleToContent(true);
	//VerticalBoxWidget->SetWidgetSize({400, 400});

	FButtonWidget* MainButtonWidget = VerticalBoxWidget->CreateWidget<FButtonWidget>();
	FTextWidget* FirstTextWidget = MainButtonWidget->CreateWidget<FTextWidget>();

	FButtonWidget* SecondButtonWidget = VerticalBoxWidget->CreateWidget<FButtonWidget>();
	FTextWidget* TextWidget = SecondButtonWidget->CreateWidget<FTextWidget>();

	VerticalBoxWidget->AlignWidgets();

	FirstTextWidget->SetText("Test button mmmjkkjk");
	TextWidget->SetText("Test button ");
	//TextWidget->SET_TEXT_ADV("Test button " << "s");
}

void FShooterGameEngine::MakeEntities()
{
	FEntityManager* EntityManager = GameWindow->GetEntityManager();
}
