#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include "GameObject.h"
#include "GameScreen.h"
#include <iostream>
using namespace std;

GameObject::GameObject() {

		GameObject::x = 0;
		GameObject::y = 0;
		GameObject::w = 0;
		GameObject::w = 0;
		GameObject::direction_x = 0;
		GameObject::direction_y = 0;
		GameObject::speed = 0;		
}
void GameObject::init(SDL_Renderer *r) {

	GameObject::setSize(50,50);
	GameObject::setPosition(10, 10);
	GameObject::setDirection(0, -1);
	GameObject::render(r);
	cout << "nesne Baþlatýldý.." << endl;
	
}
void GameObject::setSize(double w, double h){
	GameObject::w = w;
	GameObject::h = h;
}
void GameObject::setPosition(double x, double y){
	GameObject::x = x;
	GameObject::y = y;
}
void GameObject::setDirection(double dx,double dy) {
	GameObject::direction_x = dx;
	GameObject::direction_y = dy;
}


void GameObject::setSpeed(double s) {
	GameObject::speed = s;
}
void GameObject::render(SDL_Renderer *renderer){
	//SDL_Surface* s = SDL_GetWindowSurface(window);

	SDL_Rect rect;
	rect.x = GameObject::x;
	rect.y = GameObject::y;
	rect.w = GameObject::w;
	rect.h = GameObject::h;


	/*Uint32 color = SDL_MapRGB(s->format, 150, 100, 255);
	SDL_FillRect(s, &rect,color);*/

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xb0, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &rect);

	SDL_RenderPresent(renderer);
	//SDL_UpdateWindowSurface(window);
	//SDL_FreeSurface(s);

}
const SDL_Rect GameObject::getRectangle(){
	SDL_Rect rect;

	rect.x = GameObject::x;
	rect.y = GameObject::y;
	rect.w = GameObject::w;
	rect.h = GameObject::h;

	return rect;
}
void GameObject::move(double deltatime) {

}
void GameObject::update(double deltatime) {

}

