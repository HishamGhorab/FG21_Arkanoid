#pragma once
struct Block
{
	float x;
	float y;

	float w = 117;
	float h = 32;

	int health = 2;

	void draw();

	void take_damage();

	struct v3
	{
		int x;
		int y;
		int z;
	};

	v3 rgb{ 35, 240, 199 };
};
