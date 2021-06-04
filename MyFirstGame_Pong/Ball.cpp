#include "Ball.h"
#include <iostream>
#include "PongGame.h"
void Ball::move(double deltaTime) {


	PongGameObject::move(deltaTime);

	if (Ball::y<=0 && Ball::direction_y<0){
		Ball::direction_y *= -1;
	}
	if (Ball::y+ Ball::height >= PongGame::SCREEN_HEIGHT && Ball::direction_y > 0) {
		Ball::direction_y *= -1;
	}
	

};