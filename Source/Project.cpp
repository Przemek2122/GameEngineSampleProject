// Main project class

#include "GamePCH.h"
#include "CoreEngine.h"
#include "Core/ShooterGameEngine.h"

// Required to allow access for C#
extern "C"
{
	FEngineManager EngineManager;

	DLLEXPORT int __stdcall StartEngine(const int Argc = 0, char* Argv[] = nullptr)
	{
		EngineManager.Start<FShooterGameEngine>(Argc, Argv);
		
	    return 0;
	}
}

/*
int main(const int Argc, char* Argv[])
{
	StartEngine();
}
*/