#pragma once

#include "Sprite.h"

class Player : public Sprite {
public:
	Player(Uint32 color, int x, int y, int w, int h);

	bool u, d, l, r;

	void playerUpdate();
};