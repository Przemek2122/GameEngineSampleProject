// Main project class

#include "GamePCH.h"
#include "CoreEngine.h"
#include "Core/ShooterGameEngine.h"

int main(const int Argc, char* Argv[])
{
	FEngineManager EngineManager;

	EngineManager.Start<FShooterGameEngine>(Argc, Argv);
	
    return 0;
}
