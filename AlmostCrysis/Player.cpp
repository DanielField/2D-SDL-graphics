#include "Player.h"
#include "Utilities.h"

Player::Player(Uint32 color, int x, int y, int w, int h): 
  Sprite(color,x,y,w,h){
	// Do nothing for now
}

//
//	Update the position of player depending on which button is pressed
//  bool u: W
//	bool l: A
//	bool d: S
//	bool r: D
//
void Player::playerUpdate()
{
	int w, h;
	getScreenRes(w, h);

	if (getY() > 0 && u) {
		modY(-4);
	}
	else if (u)
		setY(0);
	if (getY() < h - rect->h && d) {
		modY(4);
	}
	else if (d)
		setY(h - rect->h);
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
