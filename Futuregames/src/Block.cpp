#include "Block.h"
#include "Engine.h"
#include "Game.h"

void Block::draw()
{
	SDL_Rect rect = { (int)x, (int)y, w, h };
	
	SDL_SetRenderDrawColor(render, rgb.x, rgb.y, rgb.z, 255);
	SDL_RenderFillRect(render, &rect);
	
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderDrawRect(render, &rect);
}

void Block::take_damage()
{
	if (health == 0)
		return;

	health--;

	switch (health)
	{
		case 1:
			rgb.x = 255, rgb.y = 227, rgb.z = 71;
	}
}
