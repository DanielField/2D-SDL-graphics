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
Uint32 red = NULL;

Sprite *player;

Sprite *enemy;

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
//	Update the position of player depending on which button is pressed
//  bool u: W
//	bool l: A
//	bool d: S
//	bool r: D
//
void playerUpdate(bool u, bool d, bool l, bool r)
{
	if (player->getY() > 0 && u) {
		player->modY(-4);
	}
	else if (u)
		player->setY(0);
	if (player->getY() < h - player->rect->h && d) {
		player->modY(4);
	}
	else if (d)
		player->setY(h - player->rect->h);
	if (player->getX() > 0 && l) {
		player->modX(-4);
	}
	else if (l)
		player->setX(0);
	if (player->getX() < w - player->rect->w && r) {
		player->modX(4);
	}
	else if (r)
		player->setX(w - player->rect->w);
}

//
//	update the enemy position. (Moves along the x axis)
//
int xVel = 6;
void enemyUpdate(bool a, bool b, bool c, bool d) {
	if (enemy->getX() >= w - enemy->rect->w) {
		xVel = -6;
		enemy->setX(w - enemy->rect->w);
	}
	if (enemy->getX() <= 0) {
		xVel = 6;
		enemy->setX(0);
	}
	
	enemy->modX(xVel);
}

//
//	Draw all of the game components and update things
//
void run()
{
	SDL_FillRect(surface, NULL, backColor);

	player->draw(surface);
	player->update(u, d, l, r);
	
	enemy->draw(surface);
	enemy->update(0, 0, 0, 0);

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
	red = SDL_MapRGB(surface->format, 255, 0, 0); // red

	player = new Sprite(blue, 10, 20, 64, 64);
	player->setUpdateFunction(playerUpdate);

	enemy = new Sprite(red, 512, 512, 64, 64);
	enemy->setUpdateFunction(enemyUpdate);

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