#include "Game.h"

const char* LEVEL =
"....."
"....."
"#####"
"#.#.#"
"#...#"
"#...#"
"....."
"#####"
"....."
"....."
"....."
"....."
"....."
"....."
"....."
"#####";

Player player(GAMESIZE_X/2, GAMESIZE_Y/2 + 300);
Block* blocks[MAP_COLS * MAP_ROWS] = { nullptr };

vector<Ball> balls;



void loadMap()
{
	Ball ball;
	balls.push_back(ball);

	const char* ptr = LEVEL;
	for (int y = 0; y < MAP_ROWS; ++y)
	{
		for (int x = 0; x < MAP_COLS; ++x, ++ptr)
		{
			if (*ptr != '#')
				continue;

			Block* block = new Block();
			block->x = x * 117;
			block->y = y * 32;

			blocks[y * MAP_COLS + x] = block;
		}
	}
}
