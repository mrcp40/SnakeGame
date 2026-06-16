#include"SnakeGame.h"
#include<queue>

bool SnakeGame::BFS(Node* s, Node* e)
{
	bfsTracedPath.clear();

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			grids[i][j].Reset(true);
		}
	}
	std::queue<Node*> openSet;
	openSet.push(s);
	s->isVisted = true;

	Node* tailNode = &grids[player.back().x][player.back().y];

	while (!openSet.empty())
	{
		Node* current = openSet.front();
		openSet.pop();

		if (current == e)
		{
			while (current != s)
			{
				bfsTracedPath.push_back(current);
				current = current->parent;
			}
			

			return true;
		}

		for (Node* n : GetNeighbors(current))
		{
			if (n->blocked || n->isVisted) continue;
			if (n->isPlayer && n != tailNode) continue;
			n->isVisted = true;
			n->parent = current;
			n->step = current->step + 1;
			openSet.push(n);
		}

	}

	return false;
}