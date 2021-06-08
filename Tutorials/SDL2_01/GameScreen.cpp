#define _CRT_SECURE_NO_WARNINGS
#include "GameScreen.h"
#include <sdl.h>
#include <iostream>
using namespace std;

GameScreen::GameScreen() :cnt{ 0 }, isRunning{ false }, renderer{ nullptr }, window{nullptr} {
	GameScreen::title = "My First GameScreen";
	GameScreen::xpos=SDL_WINDOWPOS_CENTERED;
	GameScreen::ypos= SDL_WINDOWPOS_CENTERED;
	GameScreen::w=800;
	GameScreen::h=600;
	GameScreen::fullscreen=false;

	GameScreen::r = 100;
	GameScreen::g = 150;
	GameScreen::b = 200;
	GameScreen::a = 10;

	//GameScreen::gameo = nullptr;

}

GameScreen::~GameScreen(){
}
void GameScreen::init() {
	Uint32 flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;

	}
	if (SDL_Init(SDL_INIT_EVERYTHING)==0) {
		cout << "Sistem Baþlatýlýyýor..." << endl;
		GameScreen::window = SDL_CreateWindow(title, xpos, ypos, w, h,flags);
		
		if (GameScreen::window) {
			cout << "Pencere Baþlatýlýyýor..." << endl;
			GameScreen::renderer = SDL_CreateRenderer(window,-1,0);
			
			if (GameScreen::renderer) {
				cout << "Ýþlenme Baþlatýlýyýor..." << endl;
				SDL_SetRenderDrawColor(
					GameScreen::renderer, 
					GameScreen::r, 
					GameScreen::g, 
					GameScreen::b, 
					GameScreen::a
				);
				GameScreen::isRunning = true;
			}
			else
			{
				GameScreen::isRunning = false;
			}
		}
	}

}
bool GameScreen::running()
{
	return GameScreen::isRunning;
}
void GameScreen::handleEvent() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT: GameScreen::isRunning = false; break;
	default:break;
		}
}
void GameScreen::render() {
	SDL_RenderClear(GameScreen::renderer);
	SDL_RenderPresent(GameScreen::renderer);

	cout << "screen ..." << endl;
}
void GameScreen::update() {
	cout << GameScreen::cnt++ << endl;
}
void GameScreen::clean() {
	SDL_DestroyWindow(GameScreen::window);
	SDL_DestroyRenderer(GameScreen::renderer);
	SDL_Quit();
	cout << "Sistem Kapatiliyor..." << endl;
	

}