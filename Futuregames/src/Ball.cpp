#include <stdio.h>
#include <SDL/SDL.h>
#include "Ball.h"
#include "engine.h"
#include "Game.h"
#include "Collision.h"

const float PI = 3.1415;

void Ball::update()
{
	if (!step(0, velocity_y * delta_time))
	{
		velocity_y *= -1;
	}

	if (!step(velocity_x * delta_time, 0))
	{
		velocity_x *= -1;
	}
}

void Ball::draw()
{
	int resolution = 48;
	float step = (2 * PI) / resolution;

	for (int i = 0; i < resolution; ++i)
	{
		float angle = step * i;

		float x1 = cos(angle);
		float y1 = sin(angle);

		float next_angle = step * (i + 1);

		float x2 = cos(next_angle);
		float y2 = sin(next_angle);

		SDL_RenderDrawLine(
			render,
			x1 * radius + x,
			y1 * radius + y,
			x2 * radius + x,
			y2 * radius + y
		);
	}
}

bool Ball::step(float dx, float dy)
{
	if (sweep(dx, dy))
		return false;

	y += dy;
	x += dx;

	return true;
}

bool Ball::sweep(float dx, float dy) // sweep checks if next step is gonna collide and should stop us before going inside of the collider
{
	if (y + dy < 0 || x + dx < 0 || x + dx > GAMESIZE_X)
	{
		return true;
	}

	AABB playerBox;
	playerBox.x_min = player.x;
	playerBox.x_max = player.x + player.w;
	playerBox.y_min = player.y;
	playerBox.y_max = player.y + player.h;


	Circle ballCircle;
	ballCircle.x = x + dx;
	ballCircle.y = y + dy;
	ballCircle.radius = radius;

	if (aabb_circle_intersect(playerBox, ballCircle))
	{
		return true;
	}

	for (int i = 0; i < NUM_BLOCKS; i++)
	{
		Block* block = blocks[i];

		if (block == nullptr)
			continue;

		AABB box;
		box.x_min = block->x;
		box.x_max = block->x + block->w;
		box.y_min = block->y;
		box.y_max = block->y + block->h;

		if (aabb_circle_intersect(box, ballCircle))
		{
			blocks[i]->take_damage();

			if (blocks[i]->health <= 0)
			{
				blocks[i] = nullptr;
				if(balls.size() < 3)
				{ 
					Ball ball;
					balls.push_back(ball);
				}
			}
			return true;
		}
	}

	return false;
}

