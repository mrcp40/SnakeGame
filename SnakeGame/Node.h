#pragma once
#include<raylib.h>
#include<string>
#include<float.h>


inline void DrawRectLinesVec(Vector2 pos, Vector2 size, Color color)
{

	DrawRectangleLines(pos.x, pos.y, size.x, size.y, color);
}


struct Node
{
#undef DrawText;
	Node(int r, int c, Vector2 pos, Vector2 size, bool b, Color fc = RAYWHITE, Color oc = BLACK)
	{
		this->row = r;
		this->col = c;
		this->position = pos;
		this->size = size;
		this->fillColor = fc;
		this->outlineColor = oc;
		this->blocked = b;
	}

	int row, col;
	Vector2 position;
	Vector2 size = { 25,25 };
	Color fillColor;
	Color outlineColor;
	bool blocked = false;
	std::string dispTxt;
	float weight = 1.0;
	bool isVisted = false;
	Node* parent = nullptr;
	int step = 0;
	float waitTime = 1;
	float gCost = FLT_MAX;
	float hCost = FLT_MAX;


	bool isPickup = false;
	bool isPlayer = false;
	bool selfPathing = false;


	void Draw()
	{
		if (blocked || isPickup||isPlayer)
		{
			if (isPickup && isPlayer)
			{
				this->fillColor = BLUE;
			}
			DrawRectangleV(position, size, fillColor);
		}
		DrawRectLinesVec(position, size, outlineColor);

		if (dispTxt.empty())
		{
			return;
		}

		int textHeight = 20;
		int textWidth = MeasureText(dispTxt.c_str(), textHeight);

		Vector2 txtPos = Vector2{ position.x + size.x / 2 - textWidth / 2, position.y + size.y / 2 - textHeight / 2 };
		DrawText(dispTxt.c_str(), txtPos.x, txtPos.y, textHeight, BLACK);
	}

	void DrawPath()
	{
		auto GetPosition = [&](Vector2 p, Vector2 s, float scale)->Vector2
			{
				return { (s.x - s.x * scale) / 2 + p.x ,(s.y - s.y * scale) / 2 + p.y };
			};

		auto GetSize = [&](Vector2 s, float scale)->Vector2
			{
				return{ s.x * scale,s.y * scale };
			};

		waitTime -= GetFrameTime();

		if (waitTime >= 0.75)
		{

			DrawRectangleV(GetPosition(this->position, this->size, 0.25), GetSize(this->size, 0.25), fillColor);
			return;
		}
		if (waitTime >= 0.5)
		{
			DrawRectangleV(GetPosition(this->position, this->size, 0.5), GetSize(this->size, 0.5), fillColor);
			return;
		}
		if (waitTime >= 0.25)
		{

			DrawRectangleV(GetPosition(this->position, this->size, 0.75), GetSize(this->size, 0.75), fillColor);
			return;
		}
		if (waitTime < 0.25)
			DrawRectangleV(position, size, fillColor);
	}

	void Reset(bool visitation = false)
	{
		if (!visitation)
		{
			this->blocked = false;
			this->dispTxt = "";
			this->fillColor = GRAY;
			this->isPickup = false;
			this->isPlayer = false;
		}

		this->isVisted = false;
		this->parent = nullptr;
		this->step = 0;
		this->waitTime = 1;
		this->gCost = FLT_MAX;
		this->hCost = FLT_MAX;
	}
}; 
