#include"SnakeGame.h"

std::vector<Node*> SnakeGame::GetNeighbors(Node* node)
{
	std::vector<Node*> temp;

	auto isWithinGrid = [&](int row, int col)->bool
		{
			return row >= 0 && col >= 00 && row < ROWS && col < COLS;
		};

	if (isWithinGrid(node->row - 1, node->col))
		temp.push_back(&grids[node->row - 1][node->col]);

	if (isWithinGrid(node->row + 1, node->col))
		temp.push_back(&grids[node->row + 1][node->col]);

	if (isWithinGrid(node->row, node->col - 1))
		temp.push_back(&grids[node->row][node->col - 1]);

	if (isWithinGrid(node->row, node->col + 1))
		temp.push_back(&grids[node->row][node->col + 1]);


	return temp;
}