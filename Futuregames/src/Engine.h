#pragma once
#include <SDL/SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* render;

struct Key_State
{
	bool state = false;
	int change_frame = 0;
};

//we are now creating an array with the size of all possible scancodes
extern Key_State keys[SDL_NUM_SCANCODES];

bool get_key(SDL_Scancode key);
bool get_key_pressed(SDL_Scancode key);
bool get_key_released(SDL_Scancode key);

extern float delta_time;
extern int frame_number;