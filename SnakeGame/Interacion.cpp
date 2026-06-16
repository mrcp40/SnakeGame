#include"SnakeGame.h"

void SnakeGame::Interaction()
{
	switch (scene)
	{
	case 0:
		break;
	case 1:
		if (IsKeyPressed(KEY_P))
		{
			gameIsPaused = !gameIsPaused;
		}

		if (!canMove || gameIsPaused || gameOver)
		{
			return;
		}

		if (IsKeyPressed(KEY_DOWN) && speed.x == 0)
		{
			speed = { 1,0 };
			canMove = false;
		}
		if (IsKeyPressed(KEY_UP) && speed.x == 0)
		{
			speed = { -1,0 };
			canMove = false;
		}
		if (IsKeyPressed(KEY_LEFT) && speed.y == 0)
		{
			speed = { 0,-1 };
			canMove = false;
		}
		if (IsKeyPressed(KEY_RIGHT) && speed.y == 0)
		{
			speed = { 0,1 };
			canMove = false;
		}
		if (IsKeyDown(KEY_SPACE))
		{
			snakeSpeed = 20;
		}
		if (IsKeyReleased(KEY_SPACE))
		{
			snakeSpeed = 40;
		}
		break;
	case 2:
		break;
	default:
		break;
	}
	
}