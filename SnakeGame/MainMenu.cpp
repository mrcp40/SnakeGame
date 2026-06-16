#include"SnakeGame.h"

void SnakeGame::MainMenu()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

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