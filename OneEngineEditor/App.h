#pragma once
#include "Window.h"
#include "EngineTimer.h"

class App {

public:
	App();
	//start fun 
	int Go();
private:
	//each frame
	void DoFrame();
private:
	Window wnd;
	EngineTimer timer;
};