#include"SnakeGame.h"

bool SnakeGame::RedOrGreen()
{
	int rnd = GetRandomValue(1, 4);
	if (rnd == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}