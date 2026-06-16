#pragma once
#include<raylib.h>
#include<vector>
#include"Node.h"


class SnakeGame
{
#define ROWS 32
#define COLS 18
#define NODE_SIZE  40//每一格的长宽
public:
	static const int screenW = NODE_SIZE*COLS;
	static const int screenH = NODE_SIZE*ROWS;

	int framecount = 0;

	std::vector<std::vector<Node>> grids;
	std::vector<std::vector<Node*>> paths;
	Node* startPoint;
	std::vector<Vector2> player;
	Node* pickup;
	bool disableRandomSearch;

	Vector2 speed = { 0,1 };
	bool gameOver = false;
	bool canMove = true;
	bool gameIsPaused = false;
	bool pickupActive = false;
	bool selfPlay = false;
	float selfPlayTime = 0.0f;
	int scene = 0;
	Color buttomC = WHITE;

	Rectangle startButton;
	Rectangle restartButton;

	float duration = 0.1;
	float timer = 0;
	int snakeSpeed = 40;

	int indexBFS = 0;
	int indexDjistra = 0;
	int indexAstra = 0;

	bool startBFS = false;
	bool startDjistra = false;
	bool startAstar = false;
	
	void End();
	void MainMenu();
	void Main();
	void Start();
	void Update();
	void Draw();
	void Interaction();
	void Restart();
	bool RedOrGreen();
	std::vector<Node*> GetNeighbors(Node* node);
	Node* GetRandomNode();

	bool BFS(Node* s, Node* e);
	std::vector<Node*> bfsTracedPath;

	bool CheckPickUp()
	{
		for (auto& row : grids)
		{
			for (auto& col : row)
			{
				if (col.isPickup)
				{

				return true;
				}
			}
		}
		return false;
	}
};