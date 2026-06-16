#include"SnakeGame.h"

void SnakeGame::Start()
{
	for (int row = 0; row < ROWS; row++)
	{
		float y = row * NODE_SIZE;
		std::vector<Node> temp;
		for (int col = 0; col < COLS; col++)
		{
			float x = col * NODE_SIZE;
			Vector2 position = { x,y };
			Vector2 size = { NODE_SIZE,NODE_SIZE };
			Node newNode{ row, col, position, size, false };
			temp.push_back(newNode);
		}
		grids.push_back(temp);
	}
	Restart();
}