#pragma once

#ifndef _GRAPHICSLASS_H_
#define _GRAPHICSLASS_H_

//INCLUDES
#include <Windows.h>

//GLOBALS
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render();

private:

};

#endif // !_GRAPHICSLASS_H_
