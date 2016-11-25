#include "Utilities.h"

//
//	Calls the update and event listener functions specified, and caps the framerate
//
void listenAndUpdate(int FPS, func f, func f2) {
	Uint32 starting_tick = SDL_GetTicks();

	f();
	f2();

	if ((1000 / FPS) > SDL_GetTicks() - starting_tick)
		SDL_Delay(1000 / FPS - (SDL_GetTicks() - starting_tick));
}

//
//	Get the screen dimensions and store them in the specified variables
//
void getScreenRes(int &w, int &h) {
	SDL_DisplayMode DM;
	SDL_GetDesktopDisplayMode(0, &DM);
	w = DM.w;
	h = DM.h;
}