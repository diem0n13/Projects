#pragma once
class RectangleN
{
public:
	int LeftTopX = 0;
	int LeftTopY = 0;
	
	int RightBottomX = 0;
	int RightBottomY = 0;

	bool IsActivated = true;
	bool IsShootActivated = true;
	bool IsJumped = false;
	
	unsigned int PTimer;

	RectangleN(int leftTopX, int leftTopY, int rightBottomX, int rightBottomY, unsigned int timer = 0);
	void SetRectangle(const int& step);
};

