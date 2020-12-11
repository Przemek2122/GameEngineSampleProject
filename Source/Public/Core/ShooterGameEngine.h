//

#pragma once

#include "CoreMinimal.h"
#include "Core\Engine.h"

class FShooterGameEngine : public FEngine
{
public:
	FShooterGameEngine();
	virtual ~FShooterGameEngine();

	virtual void GameInit() override;

protected:
	FWindow* GameWindow;
};

