#include"SnakeGame.h"
#include<string>
#include<iostream>

void SnakeGame::Draw()
{
	std::string logo = "Snake Game";
	int logoFont = 60;
	int logoWidth = MeasureText("Snake Game", logoFont);
	std::string start = "Start";
	int startFont = 40;
	int startWidth = MeasureText("Start", startFont);

	int endHeight = 60;
	int endWidth = MeasureText("Game Over", endHeight);
	Vector2 txtPos = Vector2{ (float)(screenW - endWidth) / 2,(float)(screenH - endHeight) / 2 };

	std::string restart = "Restart";
	int restartHeight = 40;
	int restartWidth = MeasureText("Restart", restartHeight);

	std::string pause = "PAUSE";
	int pauseHeight = 100;
	int pauseWidth = MeasureText("PAUSE", pauseHeight);

	switch (scene)
	{
	case 0:


		DrawText(logo.c_str(), (screenW - logoWidth) / 2, screenH / 3 - logoFont / 2, logoFont, BLACK);


		startButton.width = startWidth + 10;
		startButton.height = startFont + 10;
		startButton.x = (screenW - startButton.width) / 2;
		startButton.y = screenH * 2 / 3 - startButton.height / 2;
		DrawRectangleRounded(startButton, 0.1f, 8, buttomC);
		DrawText(start.c_str(), (screenW - startWidth) / 2, screenH * 2 / 3 - startFont / 2, startFont, BLACK);

		break;
	case 1:
		for (auto row : grids)
		{
			for (auto col : row)
			{
				col.Draw();
			}
		}

		

		/*for (auto row : paths)
		{
			for (auto col : row)
			{
				col->DrawPath();
			}
		}*/

		if (selfPlay)
		{
			std::string txt = "Auto-Pathing!!";
			DrawText(txt.c_str(), 0, 0, 40, RED);
		}

		if (gameIsPaused)
		{
			DrawText(pause.c_str(), (screenW - pauseWidth) / 2, (screenH - pauseHeight) / 2, pauseHeight, WHITE);
		}

		break;
	case 2:

		DrawText("Game Over", txtPos.x, txtPos.y, endHeight, BLACK);

		restartButton.width = restartWidth + 10;
		restartButton.height = restartHeight + 10;
		restartButton.x = (screenW - restartButton.width) / 2;
		restartButton.y = screenH * 2 / 3 - restartButton.height / 2;
		DrawRectangleRounded(restartButton, 0.1f, 8, buttomC);
		DrawText(restart.c_str(), (screenW - restartWidth) / 2, screenH * 2 / 3 - restartHeight / 2, restartHeight, BLACK);
		break;
	default:
		break;
	}



}