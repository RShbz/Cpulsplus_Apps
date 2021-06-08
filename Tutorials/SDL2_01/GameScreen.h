#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef GameScreen_h
#define GameScreen_h
#include <SDL.h>
#include "GameObject.h"
class GameScreen {

public:
	GameScreen();
	~GameScreen();
	void init();
	void handleEvent();
	void update();
	void render();
	void clean();
	bool running();

//	GameObject* gameo;
	SDL_Renderer* renderer;
	SDL_Window* window;
private:
	const char* title;
	int xpos;
	int ypos;
	int w;
	int h;
	bool fullscreen;
	Uint8 r, g, b, a;
	int cnt;

	bool isRunning;
	

	

};


#endif // !1
