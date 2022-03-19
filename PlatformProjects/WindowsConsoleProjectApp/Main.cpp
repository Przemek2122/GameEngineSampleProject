#include <iostream>
#include <Windows.h>

typedef int (__stdcall *Function_StartEngine)(const int Argc, char* Argv[]);

int main(const int Argc, char* Argv[])
{
    std::cout << "Hello World!\n";

    const HMODULE DllModule = LoadLibrary(L"E:\\Repos\\SimpleShooterGame\\x64\\Debug\\Project.dll");

    if (DllModule == nullptr) 
    {
		std::cout << "cannot locate the .dll file" << std::endl;

    	return EXIT_FAILURE;
	}
	else 
    {
	    std::cout << "it has been called" << std::endl;

	    const auto StartEngine = reinterpret_cast<Function_StartEngine>(GetProcAddress(DllModule, "StartEngine"));
		if (!StartEngine) 
		{
		    std::cout << "could not locate the function" << std::endl;

		    return EXIT_FAILURE;
		}
		else
		{
			return StartEngine(Argc, Argv);
		}
	}
}