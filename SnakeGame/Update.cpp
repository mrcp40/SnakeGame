#include"SnakeGame.h"
#include<raymath.h>
#include<iostream>

void SnakeGame::Update()
{
	switch (scene)
	{
	case 0:
		if (CheckCollisionPointRec(GetMousePosition(), startButton))
		{
			buttomC = LIGHTGRAY;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				scene = 1;
				Restart();
			}
		}
		else
		{

			buttomC = WHITE;
		}
		break;
	case 1:

		if (gameIsPaused)
		{
			return;
		}
		if (timer <= duration && (startBFS || startDjistra || startAstar))
		{
			timer += GetFrameTime();
		}

		framecount++;
		if (!CheckPickUp())
		{
			pickupActive = false;
		}



		if (player[0].x == pickup->row && player[0].y == pickup->col)
		{
			if (pickup->selfPathing)
			{
				selfPlay = true;
				selfPlayTime = 0;
				pickup->selfPathing = false;

			}
			Vector2 temp = player.back();
			pickup->isPickup = false;
			pickupActive = false;
			pickup = nullptr;
			player.push_back(temp);
		}

		if (!pickupActive)
		{
			pickup = GetRandomNode();
			pickup->isPickup = true;
			pickup->selfPathing = RedOrGreen();
			if (pickup->selfPathing)
			{
				pickup->fillColor = RED;
			}
			else
			{
				pickup->fillColor = GREEN;
			}

			pickupActive = true;
		}

		if (selfPlay)
		{
			selfPlayTime += GetFrameTime();
			if (selfPlayTime > 10)
			{
				selfPlay = false;
				selfPlayTime = 0;
			}
			if (framecount % 20 == 0)
			{
				bool b = BFS(&grids[player[0].x][player[0].y], pickup);

				if (b && !bfsTracedPath.empty())
				{

					grids[player.back().x][player.back().y].isPlayer = false;
					grids[player.back().x][player.back().y].fillColor = DARKGRAY;
					for (int i = player.size() - 1; i > 0; i--)
					{
						player[i] = player[i - 1];
						grids[player[i].x][player[i].y].isPlayer = true;
						grids[player[i].x][player[i].y].fillColor = SKYBLUE;
					}
					speed = { (float)bfsTracedPath.back()->row - player[0].x ,(float)bfsTracedPath.back()->col - player[0].y };
					player[0] = { (float)bfsTracedPath.back()->row ,(float)bfsTracedPath.back()->col };
					grids[player[0].x][player[0].y].isPlayer = true;
					grids[player[0].x][player[0].y].fillColor = BLUE;
					canMove = true;
				}
				else
				{
					selfPlay = false;
					selfPlayTime = 0;
				}

			}
			if (selfPlayTime > 10)
			{
				selfPlay = false;
				selfPlayTime = 0;
			}

		}

		if (!selfPlay)
		{

			if (framecount % snakeSpeed == 0)
			{
				if (player[0].x + speed.x > ROWS - 1 || player[0].y + speed.y > COLS - 1 || player[0].x + speed.x < 0 || player[0].y + speed.y < 0 || grids[player[0].x + speed.x][player[0].y + speed.y].isPlayer)
				{
					scene = 2;
					return;
				}

				grids[player.back().x][player.back().y].isPlayer = false;
				grids[player.back().x][player.back().y].fillColor = DARKGRAY;
				for (int i = player.size() - 1; i > 0; i--)
				{
					player[i] = player[i - 1];
					grids[player[i].x][player[i].y].isPlayer = true;
					grids[player[i].x][player[i].y].fillColor = SKYBLUE;
				}
				player[0] += speed;
				grids[player[0].x][player[0].y].isPlayer = true;
				grids[player[0].x][player[0].y].fillColor = BLUE;
				canMove = true;
			}
		}

		break;
	case 2:
		if (CheckCollisionPointRec(GetMousePosition(), restartButton))
		{
			buttomC = LIGHTGRAY;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				scene = 0;
			}
		}
		else
		{

			buttomC = WHITE;
		}
		break;
	default:
		break;
	}

}

