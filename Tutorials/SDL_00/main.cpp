#include <SDL.h>
#include <iostream>


int main(int arg) {

	SDL_Window* w = nullptr;
	SDL_Surface* s = nullptr;
	SDL_Renderer * r = nullptr;
	SDL_Event event;

	bool run = true;
	SDL_Init(SDL_INIT_VIDEO);

	w = SDL_CreateWindow("merhaba",10,10,500,600,SDL_WINDOW_OPENGL);
	r = SDL_CreateRenderer(w,-1,0);

	SDL_SetRenderDrawColor(r,152,155,157,159);

	while (run)
	{

		SDL_RenderClear(r);
		SDL_RenderPresent(r);

	}
	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);
	SDL_Quit();

	return 0;

}