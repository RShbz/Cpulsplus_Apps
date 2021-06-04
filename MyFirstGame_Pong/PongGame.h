#pragma once
#include "PongGameObject.h"
#include "Ball.h"
class PongGame {
public:
	static const int  SCREEN_WIDTH = 700;
	static const int  SCREEN_HEIGHT = 450;

	void init();
	void render(SDL_Surface);
	void setPlayerDirection(double);
	void update(double);
	void collistionDetection();
private:
	
	PongGameObject* player;
	PongGameObject* enemy;
	Ball * ball;


};