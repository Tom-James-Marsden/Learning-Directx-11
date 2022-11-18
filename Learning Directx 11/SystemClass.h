#pragma once

#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_

//PRE-PROCESSING DIRECTIVES//
#define WIN32_LEAN_AND_MEAN


//INCLUDES//
#include <Windows.h>

//MY CLASS INCLUDES//
#include "InputClass.h"
#include "GraphicsClass.h"

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialze();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	GraphicsClass* m_Graphics;
};

//FUNCTION PROTOTYPES//
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


//GLOBALS//

static SystemClass* ApplicationHandle = 0;

#endif // _SYSTEMCLASS_H_