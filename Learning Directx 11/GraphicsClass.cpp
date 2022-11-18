#include "GraphicsClass.h"
#include <iostream>
#include <fstream>

GraphicsClass::GraphicsClass()
{
	m_Direct3D = 0;
}

GraphicsClass::GraphicsClass(const GraphicsClass&)
{
}

GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	//Create the Direct3D object
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	//Initialize the direct 3D object
	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	//int memory;
	//char cringe[512];
	//m_Direct3D->GetVideoCardInfo(cringe, memory);
	//std::ofstream myfile;
	//myfile.open("example.txt");
	//myfile << cringe << std::endl;
	//myfile << memory << std::endl;
	//myfile.close();


	return true;
}

void GraphicsClass::Shutdown()
{
	//Release the direct 3D object
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	return;
}

bool GraphicsClass::Frame()
{
	bool result;

	//Render the graphics scene
	result = Render();
	if (!realloc)
	{
		return false;
	}

	return true;
}

bool GraphicsClass::Render()
{
	//Clear the buffers to begine the scene
	m_Direct3D->BegineScene(0.5f, 0.5f, 0.5f, 1.0f);

	//Present the rendered scene to the screen
	m_Direct3D->EndScene();

	return true;
}
