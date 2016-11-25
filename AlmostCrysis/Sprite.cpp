#include "Sprite.h"

Sprite::Sprite(Uint32 color, int x = 0, int y = 0, int w = 64, int h = 64)
{
	image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_FillRect(image, NULL, color);

	rect = &image->clip_rect;

	rect->x = x;
	rect->y = y;
}

//
//	Update the position depending on which button is pressed
//  bool u: W & Up
//	bool l: A & Left
//	bool d: S & Down
//	bool r: D & Right
//
void Sprite::update(bool u, bool d, bool l, bool r)
{
	int w, h;
	getScreenRes(w, h);

	if (getY() > 0 && u) {
		modY(-4);
	}
	else if (u)
		setY(0);
	if (getY() < h-rect->h && d) {
		modY(4);
	}
	else if (d)
		setY(h-rect->h);
	if (getX() > 0 && l) {
		modX(-4);
	}
	else if (l)
		setX(0);
	if (getX() < w - rect->w && r) {
		modX(4);
	}
	else if (r)
		setX(w - rect->w);
}

//
//	Draw the sprite
//
void Sprite::draw(SDL_Surface *destination)
{
	SDL_BlitSurface(image, NULL, destination, rect);
}

SDL_Rect Sprite::getRect()
{
	return *rect;
}

void Sprite::setRect(SDL_Rect *rectangle)
{
	rect = rectangle;
}

//
//	Increment the x position of the sprite by the number specified
//	Example: modX(-5);
//
void Sprite::modX(int num)
{
	SDL_Rect *rect2 = rect;
	rect2->x += num;
	rect = rect2;
}

//
//	Increment the y position of the sprite by the number specified
//	Example: modY(14);
//
void Sprite::modY(int num)
{
	SDL_Rect *rect2 = rect;
	rect2->y += num;
	rect = rect2;
}

void Sprite::setY(int num)
{
	SDL_Rect *rect2 = rect;
	rect2->y = num;
	rect = rect2;
}

void Sprite::setX(int num)
{
	SDL_Rect *rect2 = rect;
	rect2->x = num;
	rect = rect2;
}

int Sprite::getX()
{
	return rect->x;
}
int Sprite::getY()
{
	return rect->y;
}

SDL_Surface Sprite::getImage()
{
	return *image;
}

void Sprite::setImage(SDL_Surface* s)
{
	image = s;
}