// Created by Przemysław Wiewióra 2020-2022 https://github.com/Przemek2122/GameEngine

#include "GamePCH.h"
#include "Core/ShooterGameEngine.h"

#include "GameMode.h"
#include "Renderer/Widgets/Samples/ButtonWidget.h"
#include "Renderer/Widgets/Samples/MouseSparkWidget.h"
#include "Renderer/Widgets/Samples/TextWidget.h"
#include "Renderer/Widgets/Samples/VerticalBoxWidget.h"

FShooterGameEngine::FShooterGameEngine()
	: GameWindow(nullptr)
	, TextFPSWidget(nullptr)
	, GameModePtr(FAutoDeletePointer<FGameMode>())
{
}

void FShooterGameEngine::PreInit()
{
}

void FShooterGameEngine::Init()
{
	LOG_DEBUG("Game init");

	FWindowCreationData WindowCreationData(false);
	const FVector2D<int32> NewWindowLocation = { 200, 200 };
	const FVector2D<int32> NewWindowSize = { 800, 600 };
	GameWindow = GEngine->GetEngineRender()->CreateWindow<FWindow>(WindowCreationData, "Sample window", NewWindowLocation, NewWindowSize);
	if (GameWindow != nullptr)
	{
		LOG_DEBUG("Init() started: '" << "MakeWidgets()" << "' starting ...");
		const size_t Nanosecond_Start = FUtil::GetNanoSeconds();

		MakeWidgets();

		const size_t Nanosecond_End = FUtil::GetNanoSeconds();
		const size_t Nanosecond_TestDuration = Nanosecond_End - Nanosecond_Start;
		const std::string ActualTimeString = std::to_string(FUtil::NanoSecondToSecond(Nanosecond_TestDuration));
		LOG_DEBUG("MakeWidgets() duration (nanoseconds): " + ActualTimeString + "s.");
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
	VerticalBoxWidget->SetAnchor(EAnchor::Center);

	FButtonWidget* StartButtonWidget = VerticalBoxWidget->CreateWidget<FButtonWidget>();
	FTextWidget* StartTextWidget = StartButtonWidget->CreateWidget<FTextWidget>();
	StartTextWidget->SetText("Start");
	StartButtonWidget->OnLeftClickPress.BindLambda([this, VerticalBoxWidget]
		{
			LOG_DEBUG("Start requested!");

			GameWindow->DestroyWidget(VerticalBoxWidget);

			GameModePtr->StartGame();
		});

	FButtonWidget* ExitButtonWidget = VerticalBoxWidget->CreateWidget<FButtonWidget>();
	FTextWidget* ExitTextWidget = ExitButtonWidget->CreateWidget<FTextWidget>();
	ExitTextWidget->SetText("Exit");
	ExitButtonWidget->OnLeftClickPress.BindLambda([this]
		{
			LOG_DEBUG("Exit requested!");

			RequestExit();
		});
}
