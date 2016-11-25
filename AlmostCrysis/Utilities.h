#pragma once

#include "SDL.h"

typedef void(*func)();

//
//	Calls the update and event listener functions specified, and caps the framerate
//
void listenAndUpdate(int FPS, func f, func f2);

//
//	Get the screen dimensions and store them in the specified variables
//
void getScreenRes(int &w, int &h);