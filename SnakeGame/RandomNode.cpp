#include"SnakeGame.h"

Node* SnakeGame::GetRandomNode()
{
	int randomRow = GetRandomValue(0, ROWS - 1);
	int randomCol = GetRandomValue(0, COLS - 1);
	auto isSnakeBody = [&](int r, int c) -> bool {
		for (auto& p : player) {
			if ((int)p.x == r && (int)p.y == c) return true;
		}
		return false;
		};

	while (grids[randomRow][randomCol].blocked  || grids[randomRow][randomCol].isPlayer|| isSnakeBody(randomRow, randomCol))
	{
		randomRow = GetRandomValue(0, ROWS - 1);
		randomCol = GetRandomValue(0, COLS - 1);
	}
	return &(grids[randomRow][randomCol]);
}