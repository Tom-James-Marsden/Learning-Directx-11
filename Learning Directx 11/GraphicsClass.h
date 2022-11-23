#pragma once

#ifndef _GRAPHICSLASS_H_
#define _GRAPHICSLASS_H_

//MY CLASS INCLUDES
#include "D3DClass.h"
#include "CameraClass.h"
#include "ModelClass.h"
#include "LightShaderclass.h"
#include "LightClass.h"

//GLOBALS
const bool FULL_SCREEN = false;
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
	bool Render(float);

private:

	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	ModelClass* m_Model;
	LightShaderclass* m_LightShader;
	LightClass* m_Light;
};

#endif // !_GRAPHICSLASS_H_
