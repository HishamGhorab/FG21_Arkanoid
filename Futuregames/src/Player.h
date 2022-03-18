#pragma once
struct Player
{
	//make player spawn in the middle?
	float x = 1280.0f / 2.0f;
	float y = 720.0f / 2.0f;

	float w = 130.0f;
	float h = 32.0f;

	float x_velocity = 0;

	Player();
	Player(int x, int y);

	bool step(float dx);
	bool sweep(float dx);

	void update();
	void draw();

};