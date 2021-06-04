#define main SDL_main

#include <iostream>
#include <SDL.h>
#include"PongGameObject.h"
#include "PongGame.h"

using namespace std;


int main(int arcg, char* args[])
{
SDL_Window* window;
SDL_Surface* surface;
PongGame *pgame;


	///std::cout << "Selam Aleykum";
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("PONG OYUNU",10,20, PongGame::SCREEN_WIDTH, PongGame::SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);

	bool quit = false;
	SDL_Event event;

	pgame = new PongGame();
	pgame->init();



	//hareket ettirirken daha kararlý hareket etmesini saðlamak için
	//iki frame arasý zamaný hesaplayýp speed ile çarpýp direction a ekledik.
	Uint64 nowTime = SDL_GetPerformanceCounter();
	Uint64 lastTime = 0;
	double deltaTime = 0;

	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if(event.type== SDL_QUIT)
			{
				quit = true;
				std::cout << "Kapatýldý";
			}

			const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
			//herhangi bir tuþa basýlýp basýlmadýðýný kontrol eder
			if (keyboardState[SDL_SCANCODE_ESCAPE])
			{
				quit = true;
			}
			if (keyboardState[SDL_SCANCODE_UP]) {
				pgame->setPlayerDirection(-1);
			}
			else if (keyboardState[SDL_SCANCODE_DOWN]) {
				pgame->setPlayerDirection(+1);
			}
			else
			{
				//pgame->setPlayerDirection(0);
			}
		}
		lastTime = nowTime;
		nowTime = SDL_GetPerformanceCounter();
		deltaTime = (nowTime - lastTime) / ((double)SDL_GetPerformanceFrequency());

		Uint32 backgroundColor = SDL_MapRGB(surface->format,0,0,50);
		SDL_FillRect(surface, NULL,backgroundColor);

		pgame->update(deltaTime);
		pgame->render(*surface);
		SDL_UpdateWindowSurface(window);

	}

	SDL_DestroyWindow(window);
	SDL_FreeSurface(surface);
	

	pgame = nullptr;;
	window = NULL;
	surface = NULL;
	return 0;

}