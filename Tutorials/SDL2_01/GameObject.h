#pragma once

#define _CRT_SECURE_NO_WARNINGS
#ifndef GameObject_h
#define GameObject_h
#include <SDL.h>
#include "GameScreen.h"

class GameObject {
public:
	GameObject();
	void init(SDL_Renderer*);
	void setPosition(double, double);
	void setSize(double, double);
	void setDirection(double, double);
	void setSpeed(double);
	void render(SDL_Renderer* renderer);
	void render(SDL_Window* window);
	void update(double deltatime);
	void move(double deltaTime);

	const SDL_Rect getRectangle();

private:
	double x, y, w, h;
	double speed;
	double direction_x, direction_y;

	//GameScreen *gscreen;
};











#endif