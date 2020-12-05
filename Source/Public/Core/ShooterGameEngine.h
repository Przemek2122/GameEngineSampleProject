//

#pragma once

#include "Core\Engine.h"

class FWindow;

class FShooterGameEngine : public FEngine
{
public:
	FShooterGameEngine();
	virtual ~FShooterGameEngine();

	virtual void GameInit() override;

protected:
	FWindow* GameWindow;
};

