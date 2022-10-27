#include <iostream>
#include <Windows.h>
#include "Project.cpp"

//int __stdcall StartEngine(const int Argc = 0, char* Argv[] = nullptr);

int main(const int Argc, char* Argv[])
{
	std::cout << "it has been called" << std::endl;
	
	StartEngine(Argc, Argv);

	return 0;
}