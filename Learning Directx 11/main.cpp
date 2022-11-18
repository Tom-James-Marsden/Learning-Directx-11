#include "SystemClass.h"
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	SystemClass* System;
	bool result;

	//Create System Object.
	System = new SystemClass;

	//Init and run the system obj
	result = System->Initialze();
	if (result)
	{
		System->Run();
	}

	//Shutdown and release the system OBJ
	System->Shutdown();
	delete System;
	System = 0;

	return 0;
}
