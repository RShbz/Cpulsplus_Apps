#pragma once

#include "PongGameObject.h"
#include "PongGame.h"
#include <iostream>

PongGameObject::PongGameObject(){
	PongGameObject::x = 0;
	PongGameObject::y = 0;
	PongGameObject::width = 0;
	PongGameObject::height = 0;
	PongGameObject::direction_x = 0;
	PongGameObject::direction_y = 0;
	PongGameObject::speed = 0;
}

void PongGameObject::setPosition(double x, double y) {

	PongGameObject::x = x;
	PongGameObject::y = y;

};
void PongGameObject::setSize(double w, double h) {

	PongGameObject::width = w;
	PongGameObject::height = h;

};
void PongGameObject::render(SDL_Surface s) {
	SDL_Rect rect;
	rect.x = PongGameObject::x;
	rect.y = PongGameObject::y;
	rect.w = PongGameObject::width;
	rect.h = PongGameObject::height;

	Uint64 color = SDL_MapRGB(s.format,100,125,255);
	SDL_FillRect(&s,&rect,color);

};
void PongGameObject::setDirection(double dx,double dy) {
	PongGameObject::direction_x = dx;
	PongGameObject::direction_y = dy;
};
void PongGameObject::setSpeed(double speed) {
	PongGameObject::speed = speed;

};
void PongGameObject::move(double deltaTime) {

	PongGameObject::x += PongGameObject::direction_x * PongGameObject::speed*deltaTime;
	PongGameObject::y += PongGameObject::direction_y * PongGameObject::speed*deltaTime;

	if (PongGameObject::y <= 0) {
		PongGameObject::y = 0;
	}
	else if (PongGameObject::y + PongGameObject::height>= PongGame::SCREEN_HEIGHT ) {

		PongGameObject::y = PongGame::SCREEN_HEIGHT - PongGameObject::height;
	}
};
void PongGameObject::mesaj(char* mesaj1,char *mesaj2) {
	//std::cout << mesaj1 <<" : "<<mesaj2 << std::endl;
};
const SDL_Rect PongGameObject:: getRectangle() {
	SDL_Rect rect;

	rect.x = PongGameObject::x;
	rect.y = PongGameObject::y;
	rect.w = PongGameObject::width;
	rect.h = PongGameObject::height;

	return rect;
};