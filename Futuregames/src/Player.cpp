#include "Player.h"
#include "Engine.h"
#include "Game.h"
#include "Collision.h"


Player::Player()
{
	x = 100.0f;
	y = 100.0f;
}

Player::Player(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Player::step(float dx)
{
	if (sweep(dx))
		return false;
	
	x += dx;
	//move?
	return true;
}

bool Player::sweep(float dx)
{
	if (x + dx < 0 || x + dx > GAMESIZE_X - w)
		return true;

	return false;
}

void Player::update()
{
	
	//Movement
	if (get_key(SDL_SCANCODE_D))
		x_velocity = 500;
	if (get_key(SDL_SCANCODE_A))
		x_velocity = -500;

	if (get_key_released(SDL_SCANCODE_D) || get_key_released(SDL_SCANCODE_A))
		x_velocity = 0;

	step(x_velocity * delta_time);

}

void Player::draw()
{
	SDL_SetRenderDrawColor(render, 239, 118, 122, 255);
	SDL_Rect rect = { (int)x, (int)y - 16, w, h };
	SDL_RenderFillRect(render, &rect);
}
