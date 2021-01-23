//

#pragma once

#include "CoreMinimal.h"

class FShooterGameEngine : public FEngine
{
	friend FEngineManager;

protected:
	FShooterGameEngine();
	virtual ~FShooterGameEngine() override;

public:
	virtual void PreInit() override;
	virtual void Init() override;
	virtual void PostInit() override;

	virtual void Tick() override;
	virtual void PostSecondTick() override;

protected:
	FWindow* GameWindow;
};

