#pragma region Header files

// Game files
#include "Sprite.h"

// SDL
#include <SDL.h>

#pragma endregion

#pragma region Prototypes

int init();
void listenForEvents();
void run();
int exitGame();

#pragma endregion

#pragma region vars

SDL_Window *window = NULL; // Main window for the game
SDL_Surface *surface = NULL;
int w = 800, h = 600; // Window dimensions
Uint32 backColor = NULL;

Uint32 blue = NULL;
Sprite *player;

bool u = false, d = false, l = false, r = false; // Booleans used for testing which key(s) are down

SDL_Event event;

bool running = true;

#pragma endregion vars

#define FPS 100 // Cap at 60 frames per second

using namespace std;
int main(int argc, char* args[]) {
	// If it fails to initialize everything then exit
	if (init() != 0) exitGame();
	if (window == NULL) exitGame();

	Uint32 starting_tick;
	// Game loop
	while (running) {
		listenAndUpdate(FPS, listenForEvents, run);
	}

	return exitGame();
}

//
//	Draw all of the game components and update things
//
void run()
{
	SDL_FillRect(surface, NULL, backColor);

	player->draw(surface);
	player->update(u, d, l, r);

	SDL_UpdateWindowSurface(window);
}

//
//	Check for events
//
void listenForEvents()
{
	while (SDL_PollEvent(&event)) {
		SDL_Keycode key = event.key.keysym.sym;
		if (event.type == SDL_KEYDOWN) {
			if (key == SDLK_d)
				r = true;
			if (key == SDLK_a)
				l = true;
			if (key == SDLK_w)
				u = true;
			if (key == SDLK_s)
				d = true;
		}
		if (event.type == SDL_KEYUP) {
			if (key == SDLK_d)
				r = false;
			if (key == SDLK_a)
				l = false;
			if (key == SDLK_w)
				u = false;
			if (key == SDLK_s)
				d = false;

			if (key == SDLK_ESCAPE) running = false;
		}
		if (event.type == SDL_QUIT) running = false;
	}
}

//
//	Initialize the game components
//
int init() {
	SDL_Init(SDL_INIT_EVERYTHING);

	getScreenRes(w, h);

	window = SDL_CreateWindow(
		"AlmostCrysis",			// title
		SDL_WINDOWPOS_CENTERED, // x pos
		SDL_WINDOWPOS_CENTERED, // y pos
		w, h,					// width and height of window
		SDL_WINDOW_FULLSCREEN	// Window style
	);

	surface = SDL_GetWindowSurface(window);
	backColor = SDL_MapRGB(surface->format, 0, 0, 0); // black
	blue = SDL_MapRGB(surface->format, 0, 0, 255); // blue

	player = &Sprite(blue, 10, 20, 64, 64);
	/*SDL_Surface *p = &player->getImage();
	p = SDL_LoadBMP("untitled.bmp");
	player->setImage(p);*/

	return 0;
}

//
//	Clean up memory and exit
//	Returns 0 if function successfully executes
//
int exitGame() {
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}