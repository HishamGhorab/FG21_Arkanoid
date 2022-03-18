#pragma once
struct Ball {
	float x = 600/2; //x is my cos
	float y = 400; //y is my sin
	float radius = 10;

	float velocity_y = 200; //200
	float velocity_x = 200; //200

	void update();
	void draw();

	bool step(float dx, float dy);
	bool sweep(float dx, float dy);
};
