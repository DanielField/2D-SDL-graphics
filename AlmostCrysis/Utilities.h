#pragma once

#include "SDL.h"
typedef void(*function)();
typedef void(*functionB)(bool a, bool b, bool c, bool d);

//
//	Calls the update and event listener functions specified, and caps the framerate
//
void listenAndUpdate(int FPS, function f, function f2);

//
//	Get the screen dimensions and store them in the specified variables
//
void getScreenRes(int &w, int &h);