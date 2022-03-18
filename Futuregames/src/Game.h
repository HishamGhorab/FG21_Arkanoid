#pragma once
#include "Player.h"
#include "Collision.h"
#include "Block.h"
#include "Ball.h"
#include <vector>
#include <iostream>

using namespace std;

#define GAMESIZE_X 600
#define GAMESIZE_Y 720
#define MAP_COLS 5
#define MAP_ROWS 16
#define NUM_BLOCKS (MAP_COLS * MAP_ROWS)

extern Player player;
extern Block* blocks[MAP_COLS * MAP_ROWS]; //cant we just use numblocks? :D

//extern Ball ball; //list of balls?

extern vector<Ball> balls;

void loadMap();
