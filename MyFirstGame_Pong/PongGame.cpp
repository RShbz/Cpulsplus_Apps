#include "PongGame.h"
# include <SDL.h>
#include <iostream>
void PongGame::init() {
	double paddleSize_x = 20;
	//oyuncu  nesnesinin geniþiði
	double paddleSize_y = 100;
	//oyuncu nesnesinin yüksekliði
	double paddlePos_y = (PongGame::SCREEN_HEIGHT-paddleSize_y)/(2.0f);
	//nesnelerin ortada hizalanmasý
	double speed = 100;
	//oyuncu kayma hýzý
	 
	//player: kullanýcý oyuncusu
	PongGame::player = new PongGameObject;
	PongGame::player->setSize(paddleSize_x, paddleSize_y);
	PongGame::player->setPosition(0, paddlePos_y);
	PongGame::player->setSpeed(speed);
	
	//enemy: rakip oyuncu -> bilgisayar
	PongGame::enemy = new PongGameObject;
	PongGame::enemy->setSize(paddleSize_x, paddleSize_y);
	PongGame::enemy->setPosition(PongGame::SCREEN_WIDTH- paddleSize_x, paddlePos_y);	
	PongGame::enemy->setSpeed(speed);

	//oyun topu
	ball = new Ball();
	ball->setPosition(PongGame::SCREEN_WIDTH/2,PongGame::SCREEN_HEIGHT/2);
	ball->setSize(30,30);
	ball->setDirection(-1,-1);
	ball->setSpeed(speed);
};
void PongGame::render(SDL_Surface s) {
	PongGame::player->render(s);
	PongGame::enemy->render(s);
	PongGame::ball->render(s);
};
void PongGame::setPlayerDirection(double dy) {

	PongGame::player->setDirection(0, dy);
	PongGame::enemy->setDirection(0, dy);
};
void PongGame::update(double deltaTime) {

	PongGame::player->move(deltaTime);
	PongGame::enemy->move(deltaTime);
	PongGame::ball->move(deltaTime);
	PongGame::collistionDetection();
};
void PongGame::collistionDetection() {

	SDL_Rect playerRect = PongGame::player->getRectangle();
		SDL_Rect ballRect = PongGame::player->getRectangle();
		SDL_Rect enemyRect = PongGame::player->getRectangle();


		if (SDL_HasIntersection(&playerRect, &ballRect)) {
			//oyuncumuz ile top teams etti mi ?


				

			if (ball->direction_x < 0) {
				std::cout << "player temas--- " << ball->direction_x << std::endl;

				ball->direction_x *= -1;
				return;

			}
		}
		if (SDL_HasIntersection(&enemyRect, &ballRect)) {
			//rakip oyuncu ile top teams etti mi ?

			if (ball->direction_x > 0) {
				std::cout << "enemy temas" << std::endl;

				ball->direction_x *= -1;
				return;

			}
		}
};