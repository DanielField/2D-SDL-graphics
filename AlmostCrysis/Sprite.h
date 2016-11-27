#pragma once
// SDL
#include <SDL.h>

// Other
#include <math.h>
#include <string>
#include "Utilities.h"

class Sprite {
	public:
		SDL_Surface *image;
		SDL_Rect *rect;
		Sprite(Uint32 color, int x, int y, int w, int h);
		void draw(SDL_Surface *destination);
		SDL_Rect getRect();
		void setRect(SDL_Rect *rectangle);
		void modX(int num);
		int getX();
		void modY(int num);
		int getY();
		void setX(int num);
		void setY(int num);
		SDL_Surface getImage();
		void setImage(SDL_Surface* s);
		functionB update;
		void setUpdateFunction(functionB update);
};