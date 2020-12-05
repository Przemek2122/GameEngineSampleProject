// Main project class

#include <GamePCH.h>
#include <EngineMain.h>
#include "Core/ShooterGameEngine.h"

int main(int argc, char* argv[])
{
    RunEngine<FShooterGameEngine>(argc, argv);

    return 0;
}
