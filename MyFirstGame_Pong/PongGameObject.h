#pragma once
#include <SDL.h>
class PongGameObject{
public:
	PongGameObject();
//private:
	double x, y;
	//positions 
	double width, height;
	//size
	double speed;
	double direction_x, direction_y;
	//directions
	void setPosition(double ,double); 
	void setSize(double,double);
	void setDirection(double, double);
	void setSpeed(double);
	void render(SDL_Surface);
	void move(double );
	const SDL_Rect getRectangle();

	void mesaj(char*,char *);
};