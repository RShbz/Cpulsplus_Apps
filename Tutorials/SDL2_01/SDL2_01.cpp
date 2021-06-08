#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <SDL.h>
#include "GameScreen.h"
#include "GameObject.h"

using namespace std;

int main(int argc, char* argv[]){
    GameScreen* games = nullptr;
    GameObject *gameo = nullptr;

    games = new GameScreen();
    gameo = new GameObject();

	games->init();

	games->running();
    games->handleEvent();
	games->update();
	games->render();

   gameo->init(games->renderer);
	while (games->running()) 
    {
 
        games->handleEvent();
	    games->update();
	    games->render();

        gameo->init(games->renderer);
       // gameo->render(games->window);
     
	}
	games->clean();


   /* SDL_Window* win = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* bitmapTex = NULL;
    SDL_Surface* bitmapSurface = NULL;
    int posX = 100, posY = 100, width = 320, height = 240;

    SDL_Init(SDL_INIT_VIDEO);

    win = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    bitmapSurface = SDL_LoadBMP("img/..");
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);

    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();*/


	return 0;
}
