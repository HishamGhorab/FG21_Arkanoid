#include <stdio.h>
#include <SDL/SDL.h>
#include "Engine.h"
#include "Game.h"
#include "Player.h"
#include "Collision.h"
#include "Ball.h";

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAMESIZE_X, GAMESIZE_Y, 0);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	bool running = true;
	Uint64 previous_ticks = SDL_GetPerformanceCounter();

	loadMap();

	while (running)
	{
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 delta_ticks = ticks - previous_ticks;
		previous_ticks = ticks;
		delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency();

		frame_number++;

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
			{
				if (event.key.repeat)
					break;

				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE)
					running = false;

				keys[scancode].state = true;
				keys[scancode].change_frame = frame_number;

				break;
			}
			case SDL_KEYUP:
			{
				int scancode = event.key.keysym.scancode;
				keys[scancode].state = false;
				keys[scancode].change_frame = frame_number;

				break;
			}
			}
		}

		SDL_SetRenderDrawColor(render, 100, 87, 166, 255);
		SDL_RenderClear(render);

		player.update();
		player.draw();

		for (int i = 0; i < balls.size(); i++)
		{
			balls[i].update();
			balls[i].draw();
		}

		for (int i = 0; i < NUM_BLOCKS; i++)
		{
			Block* block = blocks[i];
			if (block == nullptr)
				continue;

			block->draw();
		}

		SDL_Delay(16);

		SDL_RenderPresent(render);
	}
}