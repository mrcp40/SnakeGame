#include"SnakeGame.h"

void SnakeGame::Main()
{
	InitWindow(screenW, screenH, "Snake Game");
	SetTargetFPS(120);
	Start();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		Interaction();
		Update();
		Draw();

		EndDrawing();
	}

	CloseWindow();
}