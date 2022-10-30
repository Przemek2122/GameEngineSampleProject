// Created by Przemys³aw Wiewióra 2020-2022 https://github.com/Przemek2122/GameEngine

#pragma once

#include "CoreMinimal.h"

class FShooterGameEngine : public FEngine
{
	friend FEngineManager;

protected:
	FShooterGameEngine();

public:
	void PreInit() override;
	void Init() override;
	void PostInit() override;

	void Tick() override;
	void PostSecondTick() override;

	void MakeWidgets();
	void MakeEntities();

protected:
	FWindow* GameWindow;
};

