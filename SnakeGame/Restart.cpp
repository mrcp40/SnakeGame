#include"SnakeGame.h"

void SnakeGame::Restart()
{
	for (auto& row : grids)
	{
		for (auto& col : row)
		{
			col.Reset();
		}
	}

	
	player.clear();

	startPoint = &grids[ROWS/2][COLS/2];
	startPoint->fillColor = BLUE;  startPoint->isPlayer = true;
	Vector2 p = { startPoint->row,startPoint->col };
	player.push_back(p);

	pickup = GetRandomNode();
	pickup->fillColor = GREEN; pickup->blocked = false; pickup->isPickup = true;
	pickupActive = true;

	bfsTracedPath.clear();
	paths.clear();
	indexBFS = 0;
	indexDjistra = 0;
	indexAstra = 0;
	timer = 0;
}