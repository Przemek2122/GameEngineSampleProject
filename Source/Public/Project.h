// Main project class

#include "GamePCH.h"
#include "Core/ShooterGameEngine.h"

// Required to allow access for C#
//extern "C"
//{
	FEngineManager EngineManager;

	int StartEngine(const int Argc = 0, char* Argv[] = nullptr) // const int Argc, char* Argv[]
	{
		EngineManager.Start<FShooterGameEngine>(Argc, Argv);
		
	    return 0;
	}
//}

/*
int main(const int Argc, char* Argv[])
{
	StartEngine();
}
*/